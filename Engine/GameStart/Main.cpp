#include "pch.h"
#include "MyCore.h"
using namespace MyProject;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR
	pCmdLine, int nCmdShow)
{
	MyCore::ENGINE_BEGIN(hInstance, 1200, 800);
	std::shared_ptr<MyCore> core = std::make_shared<MyCore>();
	core->GameRun();

	core.reset(); // �޸� �ʱ�ȭ ������ �ֱ⿡ ������ ���� �ؾ���
	// ���߿� begin end���� �ڵ� ó�� �ϰ� ���鿹��
	MyCore::ENGINE_END();
	return 0;
}