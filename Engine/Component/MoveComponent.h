#pragma once
#include "MyCoreAPI.h"

namespace MyProject
{
	class MoveComponent
	{
	private:
		float	mSpeed;
		float	mAcceleration;
		vec2	mDirection;

	public:
		MoveComponent(float _speed, float _acceleration, vec2 _dir);

		void SetSpeed(const float _speed);
		void SetAcceleration(const float _acceleration);
		void SetDirection(const vec2 _direction);

		float GetSpeed() const;
		float GetAcceleration() const;
		vec2  GetDirection() const;

		vec2  Update(float _deltaTime);
	};
}

