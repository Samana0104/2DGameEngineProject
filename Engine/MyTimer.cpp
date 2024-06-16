#include "pch.h"
#include "MyTimer.h"
using namespace MyProject;

MyTimer::MyTimer(int _maxFPS)
{
	mMaxFPS = _maxFPS;
	mMaxFPSTime = 1.0 / _maxFPS;
	ResetTimer();
}

void MyTimer::ResetTimer()
{
	mStartTimeTick = steady_clock::now();
	mCurrentFPS = 0;
	mFPS = 0;
	mSecondPerMaxFPS = 0.0;
	mOneSecond = 0.0;
	mDeltaTime = 0.0;
    mElapsedTime = duration<double>(0);
    mFrameDuration = duration<double>(0);
    mSecondPerFrame = duration<double>(0);
}

void MyTimer::UpdateSPFAndElapsedTime()
{
	mCurrentTimeTick = steady_clock::now();
	mFrameDuration = mCurrentTimeTick - mStartTimeTick;
	mSecondPerFrame = mFrameDuration - mElapsedTime;
	mElapsedTime = mFrameDuration;
}

bool MyTimer::CanExecuteFrame()
{
	mSecondPerMaxFPS += mSecondPerFrame.count();

	if (mSecondPerMaxFPS >= mMaxFPSTime) 
	{
		mDeltaTime = mSecondPerMaxFPS;
		mSecondPerMaxFPS = 0.;
		return true;
	}

	return false;
}

bool MyTimer::HasPassedTime() 
{
	UpdateSPFAndElapsedTime();
	mOneSecond += mSecondPerFrame.count();

	if (CanExecuteFrame()) // ������ ��� ���� �߰�
	{
		mFPS++;
		if (mOneSecond >= 1.)
		{
			mOneSecond = 0.;
			mCurrentFPS = mFPS;
			mFPS = 0;
		}
		return true;
	}
	return false;
}

void MyTimer::SetMaxFPS(int _fps)
{
	mMaxFPSTime = 1.0/_fps;
	mMaxFPS = _fps;
}

float MyTimer::GetDeltaTime() const
{
	return static_cast<float>(mDeltaTime);
}

int MyTimer::GetMaxFPS() const
{
	return mMaxFPS;
}

float MyTimer::GetElapsedTime() const
{
	return static_cast<float>(mElapsedTime.count());
}

void MyTimer::UpdateComponent()
{
#ifdef _DEBUG
	TCHAR msgKey[MAX_PATH] = { 0, };
	_stprintf_s(msgKey,
		L" FPS=%ld \n FPS=%ld \n %.10f \n GameTimer=%10.10f \n SPF=%10.10f\n",
		mCurrentFPS, mFPS, mDeltaTime, mElapsedTime.count(),
		mOneSecond);
	OutputDebugString(msgKey);
	m_csBuffer = msgKey;
#endif
}

void MyTimer::RenderComponent()
{
}
