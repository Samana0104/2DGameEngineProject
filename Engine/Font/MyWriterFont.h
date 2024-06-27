#pragma once
#include "MyCoreAPI.h"
#include "MyTransformer2D.h"

namespace MyProject
{
	struct FontDesc
	{
		std::wstring mFontName;
		std::wstring mFontLocalName;
		FLOAT		 mFontSize;

		DWRITE_FONT_WEIGHT	mFontWeight;
		DWRITE_FONT_STYLE	mFontStyle;
		DWRITE_FONT_STRETCH mFontStretch;
	};

	class MyWriterFont
	{
	private:
		D3Device& mDevice = D3Device::GetInstance();

		ComPtr<IDWriteFactory>			mWriteFactory;
		ComPtr<IDWriteTextFormat>		mWriteFont;
		ComPtr<ID2D1SolidColorBrush>	mBrush;

		FontDesc		mFontDesc;
		MyTransformer2D mTransform;

		D2D1_MATRIX_3X2_F mTempMat;

	private:
		void	DrawBegin();
		void	DrawEnd();
		bool	CreateBrushComponent();
		bool	CreateDWriteFactory();
		bool	CreateTextFormat();
		bool	CreateBrush();

		void	OnWMSize(UINT _weight, UINT _height);

	public:
		MyWriterFont(const FontDesc& _desc);

		void DrawTexts(const wstringV _msg, RECT_F _rect, COLOR_F _color);
		const ComPtr<ID2D1SolidColorBrush>& GetBrush() const;

		void SetBold();
		bool isBold() const;

		MyTransformer2D* operator->();
	};
}
