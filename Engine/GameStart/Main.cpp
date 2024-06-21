#include "pch.h"
#include "MyCore.h"
using namespace MyProject;

class Sample : public MyCore 
{
private:
	POINT_F myPos;
	//Box2D	myBox;
	//Box2D	myBox2;
	MyObject mObject;
	MyObject mObject2;
	MyCamera mCamera;

public:
	Sample()
		: myPos({ 0, 0 })
		//myBox({ 200, 200 }, L"KGCA1.png"),
		//myBox2({ 300, 200 }, L"KGCA1.png"),
	{
	}

	virtual void InitComponent() override
	{
		mObject->SetScale({ 10.f, 10.f });
		mObject2->SetScale({ 40.f, 10.f });
		mObject2->AddMovement({ 20.f, 10.f });
	}
	virtual void UpdateComponent() override
	{
		if (mInput.GetCurrentKeyState(VK_UP) == KeyState::KEY_HOLD)
		{
			mCamera.mTransform.AddMovement({0.f, 100.f* mTimer.GetDeltaTime() });
		}
		if (mInput.GetCurrentKeyState(VK_RIGHT) == KeyState::KEY_HOLD)
		{
			mCamera.mTransform.AddMovement({100.f* mTimer.GetDeltaTime(), 0.f});
		}
		if (mInput.GetCurrentKeyState(VK_LEFT) == KeyState::KEY_HOLD)
		{
			mCamera.mTransform.AddMovement({ 100.f*-mTimer.GetDeltaTime(), 0.f});
		}
		if (mInput.GetCurrentKeyState(VK_DOWN) == KeyState::KEY_HOLD)
		{
			mCamera.mTransform.AddMovement({ 0.f, 100.f*-mTimer.GetDeltaTime()});
		}

		if(mInput.GetCurrentKeyState(VK_F1) == KeyState::KEY_HOLD)
			mCamera.ZoomIn(0.01f);
		else if(mInput.GetCurrentKeyState(VK_F2) == KeyState::KEY_HOLD)
			mCamera.ZoomOut(0.01f);
		
		mObject2->AddRotation(0.1f);
	}

	virtual void RenderComponent() override
	{
		mObject.Render(mCamera.GetViewMat());
		mObject2.Render(mCamera.GetViewMat());
		//DrawTextForDebugging(L"ī�޶� ��ǥ�� : %f %f\n ���콺 ��ǥ�� :  %f %f",
		//	mCamera.mTransform.GetLocation().x,
		//	mCamera.mTransform.GetLocation().y,
		//	MyTransformer2D::PixelToCartesian(mInput.GetCurrentMousePosVec2()).x,
		//	MyTransformer2D::PixelToCartesian(mInput.GetCurrentMousePosVec2()).y);
		DrawTextForDebugging(mTimer.m_csBuffer.c_str());
	}

	virtual void ReleaseComponent() override
	{
	}
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR
	pCmdLine, int nCmdShow)
{
	MyCore::INITIAL_SETUP(hInstance, 1200, 800);
	Sample sample;

	sample.GameRun();
	return 0;
}