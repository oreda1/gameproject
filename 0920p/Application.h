#pragma once
/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// </summary>


class Application
{
private:
	Application(const Application& app) = delete;

	
	void Terminate();
public:
	static Application& GetInstance() {}

	bool Init();
	void Run();


};

