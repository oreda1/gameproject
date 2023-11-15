#pragma once
/// <summary>
/// アプリケーション全体を管理するクラス
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

