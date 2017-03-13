#include "GripPipeline.h"
#include <cmath>
#include "RobotMap.h"

namespace grip {

GripPipeline::GripPipeline()
{
	timer = new frc::Timer();
}
/**
* Runs an iteration of the Pipeline and updates outputs.
*
* Sources need to be set before calling this method.
*
*/
void GripPipeline::Process(cv::Mat source)
{
	targets.clear();
	timer->Reset();
	timer->Start();
	// Resize
	cv::resize(source, resizeImageOutput, cv::Size(480, 360), 0.0, 0.0, cv::INTER_CUBIC);
	// HSL Threshold
	cv::Mat hslThresholdInput = resizeImageOutput;
	cv::cvtColor(resizeImageOutput, hslThresholdOutput, cv::COLOR_RGB2GRAY);
	//double hslThresholdHue[] = { 69.0, 115.5 };
	//double hslThresholdSaturation[] = { 186.0, 255.0 };
	//double hslThresholdLuminance[] = { 200.0, 255.0 };
	cv::inRange(hslThresholdOutput,
			cv::Scalar(69.0, 200, 186),
			cv::Scalar(115.5, 255, 255),
			hslThresholdOutput);
	// Contours
	findContours(hslThresholdOutput, false, this->findContoursOutput);
	// Filter Contours
	double solid[] = {80.0, 100.0};
	filterContours(
			findContoursOutput,
			30,
			20,
			5,
			1000,
			20,
			1000,
			solid,
			1000000,
			0,
			0,
			1000,
			this->filterContoursOutput);

	for (int i = 0; i < filterContoursOutput.size(); i++)
	{
		targets.push_back(cv::boundingRect(this->filterContoursOutput[i]));
	}

	timer->Stop();
	procTime = timer->Get();
}

/**
 * Finds contours in an image.
 *
 * @param input The image to find contours in.
 * @param externalOnly if only external contours are to be found.
 * @param contours vector of contours to put contours in.
 */
void GripPipeline::findContours(cv::Mat &input, bool externalOnly, std::vector<std::vector<cv::Point> > &contours)
{
	std::vector<cv::Vec4i> hierarchy;
	contours.clear();
	int mode = externalOnly ? cv::RETR_EXTERNAL : cv::RETR_LIST;
	int method = cv::CHAIN_APPROX_SIMPLE;
	cv::findContours(input, contours, hierarchy, mode, method);
}


/**
 * Filters through contours.
 * @param inputContours is the input vector of contours.
 * @param minArea is the minimum area of a contour that will be kept.
 * @param minPerimeter is the minimum perimeter of a contour that will be kept.
 * @param minWidth minimum width of a contour.
 * @param maxWidth maximum width.
 * @param minHeight minimum height.
 * @param maxHeight  maximimum height.
 * @param solidity the minimum and maximum solidity of a contour.
 * @param minVertexCount minimum vertex Count of the contours.
 * @param maxVertexCount maximum vertex Count.
 * @param minRatio minimum ratio of width to height.
 * @param maxRatio maximum ratio of width to height.
 * @param output vector of filtered contours.
 */
void GripPipeline::filterContours(
		std::vector<std::vector<cv::Point> >& inputContours,
		const double minArea,
		const double minPerimeter,
		const double minWidth,
		const double maxWidth,
		const double minHeight,
		const double maxHeight,
		const double solidity[],
		const double maxVertexCount,
		const double minVertexCount,
		const double minRatio,
		const double maxRatio,
		std::vector<std::vector<cv::Point> >& output)
{
	std::vector<cv::Point> hull;
	output.clear();
	for (std::vector<cv::Point> contour: inputContours) {
		cv::Rect bb = boundingRect(contour);
		if (bb.width < minWidth || bb.width > maxWidth) continue;
		if (bb.height < minHeight || bb.height > maxHeight) continue;
		double area = cv::contourArea(contour);
		if (area < minArea) continue;
		if (arcLength(contour, true) < minPerimeter) continue;
		cv::convexHull(cv::Mat(contour, true), hull);
		double solid = 100 * area / cv::contourArea(hull);
		if (solid < solidity[0] || solid > solidity[1]) continue;
		if (contour.size() < minVertexCount || contour.size() > maxVertexCount)	continue;
		double ratio = bb.width / bb.height;
		if (ratio < minRatio || ratio > maxRatio) continue;
		output.push_back(contour);
	}
}

bool grip::GripPipeline::getTarget(int idx, cv::Rect& rect)
{
	if (targets.size() <= 0) return false;
	rect = targets[idx];
	return true;
}

double grip::GripPipeline::getTargetCenterX(int idx)
{
	if (targets.size() <= 0) return -3;
	double center = -2;
	if (stuff.target == Target::kPeg && targets.size() > 1)
	{
		cv::Rect r1 = targets[idx];
		cv::Rect r2 = targets[idx + 1];
		if (r1.x < r2.x) // NOTE: may be reversed
			center = (r1.x + r2.x +r2.width) / 2;
		else
			center = (r2.x + r1.x +r1.width) / 2;
	}
	else if (stuff.target == Target::kPeg && targets.size() == 1)
	{
		cv::Rect r = targets[idx];
		center = r.x + r.width/2;
	}
	else if (stuff.target == Target::kBoiler)
	{

	}
	return center;
}

double grip::GripPipeline::getTargetCenterY(int idx)
{
	if (targets.size() <= 0) return -2;
	cv::Rect& r = targets[idx];
	return r.y + r.height / 2;
}

double grip::GripPipeline::getProcTime()
{
	return procTime * 1000;
}

double GripPipeline::getDistance()
{
	cv::Rect r;
	if (getTarget(0, r))
	return (stuff.targetHeight * (10/12) * 360) / (2 * r.height * (std::tan((float)stuff.angle)));
	else return -2;
}


void GripPipeline::setStuff(grip::CameraStuff cs)
{
	stuff = cs;
}

double GripPipeline::getOffsetCenter(double offset, double distance)
{
	return (90 - std::cos((float)(offset / distance))) / (68.5 / 2);
}

} // end grip namespace
