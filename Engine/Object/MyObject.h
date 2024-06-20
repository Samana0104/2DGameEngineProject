#pragma once
#include "Component.h"
#include "D3Device.h"
#include "MyTransformer2D.h"
#include "MyResourceManger.h"

namespace MyProject
{
	class MyObject
	{
	private:
		MyTransformer2D		mTransform;

		TEXTURE_KEY	mTextureKey;
		MESH_KEY	mMeshKey;

		MyResourceManager& mManager = MyResourceManager::GetInstance();

	public:
		MyObject();

		MyTransformer2D* operator->(); // ��ġ ��ȯ ���ϰ� �Ϸ��� �����ε� ��

		virtual void Update(float _deltaTime);
		virtual void Render(const mat3 _viewMat);
	};
}
