#pragma once
#include "Component.h"
namespace MyProject
{
	class MyShader : public Component
	{
	private:
		ComPtr<ID3D11VertexShader>	mVertexShader;
		ComPtr<ID3D11PixelShader>	mPixelShader;
		ComPtr<ID3D11InputLayout>	mVertexLayout;
		ComPtr<ID3DBlob>			VS_Bytecode;
		ComPtr<ID3DBlob>			PS_Bytecode;
		
	protected:
		inline static D3Device& mDevice = D3Device::GetInstance();
	
	public:
		MyShader();

		bool LoadVertexShader();
		bool LoadPixelShader();
		bool CreateInputLayout();

		virtual void UpdateComponent() override;
		virtual void RenderComponent() override;
	};
}