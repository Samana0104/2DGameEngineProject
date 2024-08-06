#pragma once
#include "MyResourceManger.h"
#include "MyInput.h"
#include "ObjectCode.h"

namespace MyProject
{
	using OBJECT_ID	 = UINT;

	class MyObjectManager;

	class MyObject
	{
	private:
		OBJECT_ID			mObjectID; // ������Ʈ �Ŵ������� ������ ���̵�
		ObjectCode			mObjectCode = ObjectCode::NOT;

	protected:
		TEXTURE_KEY			mTextureKey = L"Default.jpg";
		MESH_KEY			mMeshKey	= L"DEFAULT_MESH";
		SHADER_KEY			mShaderKey	= L"PixelShader.hlsl";
		vec4				mColor		= { 1.f, 1.f, 1.f, 1.f };
		MyTransformer2D		mTransform;

		
		MyResourceManager&	mManager = MyResourceManager::GetInstance();
		MyInput&			mInput	 = MyInput::GetInstance();

	private:

	protected:
		void SetObjectCode(const ObjectCode _objCode);

	public:
		MyObject() = default;

		void SetColor(const vec4 _color);
		void SetTextureKey(const TEXTURE_KEY _key);
		void SetMeshKey(const MESH_KEY _key);
		void SetShaderKey(const SHADER_KEY _key);
		void SetObjectID(const OBJECT_ID _objID); // ������Ʈ �Ŵ��� ����� �ǵ�� ����

		// �̰Ŵ� ������Ʈ�� �־�� �� �Լ��ΰ�...
		void SetImageScale();

		const vec4&			GetColor() const;
		const MESH_KEY&		GetMeshKey() const;
		const TEXTURE_KEY&  GetTextureKey() const;
		const SHADER_KEY&	GetShaderKey() const;
		const ObjectCode&	GetObjectCode() const;
		const OBJECT_ID&	GetObjectID() const;

		MyTransformer2D& GetTransform();
		MyTransformer2D* operator->(); // ��ġ ��ȯ ���ϰ� �Ϸ��� �����ε� ��
		
		virtual void Update(const float _deltaTime);
		virtual void Render();
	};
}
