#pragma once
#include "MyTransformer2D.h"
#include "MyMesh2D.h"
#include "MyResourceManger.h"

namespace MyProject
{
	// ���߿� ���� �浹 ������ ���� �޽� ����� ����
	class CollisionComponent
	{
	public:
		static bool IsAABBCollision(const MyTransformer2D& _objM, const MyTransformer2D& _targetM);
		static bool IsOBBCollision(const MyTransformer2D& _objM, const MyTransformer2D& _targetM);
	};
}

