#pragma once
#include "MyResourceManger.h"

namespace MyProject
{
	class MyObject
	{
	protected:
		MyTransformer2D		mTransform;
		TEXTURE_KEY			mTextureKey;
		MESH_KEY			mMeshKey;
		MyResourceManager&	mManager = MyResourceManager::GetInstance();


	protected:
		MyObject();

	public:

		void SetTextureKey(TEXTURE_KEY _key);
		void SetMeshKey(MESH_KEY _key);

		const MyTransformer2D& GetTransform() const;

		MyTransformer2D* operator->(); // ��ġ ��ȯ ���ϰ� �Ϸ��� �����ε� ��
		
		virtual void Update(const float _deltaTime) = 0;
		virtual void Render(const mat3 _viewMat) = 0;
	};
}
