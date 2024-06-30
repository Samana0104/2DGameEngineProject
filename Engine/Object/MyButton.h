#pragma once
#include "MyObject.h"
#include "CollisionComponent.h"

namespace MyProject
{
	enum SelectState
	{
		DEFAULT = 0,  // Ŀ���� ���� ���� ��(T_FOCUS���¿��� �ٸ� ���� T_ACTIVE�ϸ� ��ȯ�ȴ�.)
		HOVER = 1,	// Ŀ���� ���� ���� ��
		FOCUS = 2,	// T_ACTIVE���¿��� ���� ��ư�� �ٸ� ������ ������ ��(���)
		ACTIVE = 3,	// ���콺 ���� ��ư ������ ���� ��
		SELECTED = 4, // T_ACTIVE ���¿��� ���ʹ�ư ������ ��
	};

	class MyButton : public MyObject
	{
	private:
		SelectState mCurrentState = DEFAULT;
		bool mIsMovable = true;

		CALLBACK_ID mOnMouseMoveID;
		CALLBACK_ID mOnMousePushID;
		CALLBACK_ID mOnMouseUpID;

	private:
		void OnMouseMove(POINT_L _prePos, POINT_L _postPos);
		void OnMousePush(vec2 _pos, MOUSE_FLAGS _flag);
		void OnMouseUp(vec2 _pos, MOUSE_FLAGS _flag);
		
	protected:
		virtual void SetDefaultMode();
		virtual void SetHoverMode();
		virtual void SetFocusMode();
		virtual void SetActiveMode();
		virtual void SetSelectedMode();

	public:
		MyButton();
		virtual ~MyButton();

		SelectState GetCurrentState() const;
		void SetMovable(bool _isMovable);

		virtual void SelectMouseState(SelectState _state);
		virtual void Update(const float _deltaTime) override;
		virtual void Render() override;
	};
}

