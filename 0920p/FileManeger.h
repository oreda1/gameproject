#pragma once
#include<unordered_map>
#include<string>
#include <memory>
class File;

class FileManager
{
private:
	std::unordered_map<std::wstring, std::shared_ptr<File>>
		fileTable_;
public:
	std::shared_ptr<File>FileManager::LoadGraphic(const std::wstring& path);
	{
		
	void 
};
