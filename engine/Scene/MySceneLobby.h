#pragma once
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyCamera.h"
#include "MyButton.h"

namespace MyProject
{
	class MySceneLobby : public MyScene
	{
	private:
		MyObject mTitle;
		MyObject mBackground;
		int mCurrentButton;

	public:
		using MyScene::MyScene;

		
		virtual void Init() override;
		virtual void Update(float _deltaTime) override;
		virtual void Render() override;
		virtual void Release() override;
		virtual void Reset() override;
		virtual void Start() override;
		virtual void End() override;
	};
}

