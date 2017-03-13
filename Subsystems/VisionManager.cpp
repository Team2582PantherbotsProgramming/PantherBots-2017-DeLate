#include "VisionManager.h"

VisionManager::VisionManager() :
	frc::Subsystem("Vision Manager")
{
	CenterX = 0;
	ProcessingTime = 0;
	TargetsNum = 0;
/*
	m_cs = frc::CameraServer::GetInstance();

		m_cam = m_cs->StartAutomaticCapture(0);
		m_cam.SetResolution(640, 480);
		m_cam.SetFPS(20);

		//cs::CvSink sink = frc::CameraServer::GetInstance()->GetVideo();
		//cv::Mat mat;
		while(true){
		m_vision = new frc::VisionRunner<grip::GripPipeline>(
				m_cam,
				new grip::GripPipeline(),
				[&](grip::GripPipeline& pipeline)
				{
					//pipeline.Process(mat);
					//grip::CameraStuff camstuff = grip::CameraStuff();
					pipeline.setStuff(PEG);
					CenterX = pipeline.getTargetCenterX(0);
					ProcessingTime = pipeline.getProcTime();
					TargetsNum = pipeline.getTargets();
					//frc::SmartDashboard::PutBoolean("Getting Target", pipeline.getTarget());
					//frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
					//frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
					//frc::SmartDashboard::PutNumber("Targets", pipeline.getTargets());
					frc::SmartDashboard::PutNumber("Center X", CenterX);
					frc::SmartDashboard::PutNumber("Processing Time", ProcessingTime);
					frc::SmartDashboard::PutNumber("Targets", TargetsNum);
				});
		m_lock = new std::mutex();
		}*/
}

VisionManager::~VisionManager()
{
	delete m_vision;
	delete m_visionThread;
}

void VisionManager::InitDefaultCommand()
{
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_cs = frc::CameraServer::GetInstance();

	m_cam = m_cs->StartAutomaticCapture();
	m_cam.SetResolution(640, 480);
	m_cam.SetFPS(20);

	//cs::CvSink sink = frc::CameraServer::GetInstance()->GetVideo();
	//cv::Mat mat;
	while(true){
	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_cam,
			new grip::GripPipeline(),
			[&](grip::GripPipeline& pipeline)
			{
				//pipeline.Process(mat);
				//grip::CameraStuff camstuff = grip::CameraStuff();
				pipeline.setStuff(PEG);
				CenterX = pipeline.getTargetCenterX(0);
				ProcessingTime = pipeline.getProcTime();
				TargetsNum = pipeline.getTargets();
				//frc::SmartDashboard::PutBoolean("Getting Target", pipeline.getTarget());
				//frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				//frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
				//frc::SmartDashboard::PutNumber("Targets", pipeline.getTargets());
				frc::SmartDashboard::PutNumber("Center X", CenterX);
				frc::SmartDashboard::PutNumber("Processing Time", ProcessingTime);
				frc::SmartDashboard::PutNumber("Targets", TargetsNum);
			});
	m_lock = new std::mutex();
	}
}

void VisionManager::DashboardOutput(bool verbose)
{
	m_lock->lock();
	frc::SmartDashboard::PutBoolean("Vision Processing Running", m_isRunning);
	frc::SmartDashboard::PutNumber("CenterX", CenterX);
	frc::SmartDashboard::PutNumber("Processing Time", ProcessingTime);
	frc::SmartDashboard::PutNumber("Targets", TargetsNum);
	m_lock->unlock();

	if (verbose)
	{

	}
}

void VisionManager::vision_thread()
{
	while (true)
	{
		m_vision->RunOnce();

		m_lock->lock();
		if (!m_isRunning)
		{
			m_lock->unlock();
			break;
		}
		m_lock->unlock();
		//sleep(20);
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

void VisionManager::StartProc()
{
	m_isRunning = true;
	m_visionThread = new std::thread(&VisionManager::vision_thread, this);
	m_visionThread->detach();
}
