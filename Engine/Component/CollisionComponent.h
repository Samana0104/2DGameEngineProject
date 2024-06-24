#pragma once
#include "MyTransformer2D.h"
#include "MyMesh2D.h"
#include "MyResourceManger.h"

namespace MyProject
{
	// ���߿� ���� �浹 ������ ���� �޽� ����� ����
	class CollisionComponent
	{
	private:
		MyTransformer2D& mObjMat;
		
	public:
		CollisionComponent(MyTransformer2D& _objMat);

		bool IsAABBCollision(MyTransformer2D& _targetM);
		bool IsOBBCollision(MyTransformer2D& _targetM);
	};
}

