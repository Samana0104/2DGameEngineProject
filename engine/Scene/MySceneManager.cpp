#include "pch.h"
#include "MySceneManager.h"
#include "MySceneLobby.h"
using namespace MyProject;

void MySceneManager::AddScene(std::shared_ptr<MyScene> _scene, SCENE_KEY _key)
{
	_scene->Init();
	AddResource(_key, _scene);
}
void MySceneManager::SetCurrentScene(SCENE_KEY _key)
{
	mQueueForWaiting.push(GetResource(_key));
}

void MySceneManager::SetCurrentScene(std::shared_ptr<MyScene> _scene)
{
	mQueueForWaiting.push(_scene);
}

void MySceneManager::Init()
{
	AddScene(std::make_shared<MySceneLobby>(*this), L"LOBBY");

	mCurrentScene = GetResource(L"LOBBY");
	mCurrentScene->Start();
}

void MySceneManager::Update(const float _deltaTime)
{
	// �̰� ������ ���� ����ǰ� �ִ� �� �����⵵ ���� �ٲ�
	if (!mQueueForWaiting.empty()) 
	{
		mCurrentScene->End();
		mCurrentScene = mQueueForWaiting.front();
		mCurrentScene->Start();
		mQueueForWaiting.pop();
	}

	mCurrentScene->Update(_deltaTime);
}

void MySceneManager::Render()
{
	mCurrentScene->Render();
}

void MySceneManager::Release()
{
	auto& scenes = GetAllResources();

	for (auto& scene : scenes)
		scene.second->Release();

	ClearResources();
}
