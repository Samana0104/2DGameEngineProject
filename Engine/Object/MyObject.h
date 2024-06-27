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
		COLOR_F				mColor;

		MyResourceManager&	mManager = MyResourceManager::GetInstance();

	protected:
		MyObject();

	public:
		void SetColor(COLOR_F _color);
		void SetTextureKey(TEXTURE_KEY _key);
		void SetMeshKey(MESH_KEY _key);

		const MyTransformer2D& GetTransform() const;
		const COLOR_F&		GetColor() const;
		const MESH_KEY&		GetMeshKey() const;
		const TEXTURE_KEY&  GetTextureKey() const;

		MyTransformer2D* operator->(); // ��ġ ��ȯ ���ϰ� �Ϸ��� �����ε� ��
		
		virtual void Update(const float _deltaTime) = 0;
		virtual void Render(const mat3& _viewMat) = 0;
	};
}
