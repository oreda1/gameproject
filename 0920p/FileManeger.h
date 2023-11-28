#pragma once
#include<unordered_map>
#include<string>
#include <memory>
class File;

class FileManager:
{
private:
	using FileTable_t = //std::unordered_map
		std::unordered_map<std::wstring, std::shared_ptr<File>>;
		FileTable_t fileTable_;
public:
	std::shared_ptr<File>LoadGraphic(const std::wstring& path,bool isEternal=false);
	

    /// <summary>
    /// リソースの削除を行います
	/// 実際には内部カウントを見て、0になったらそれぞれのリソースの
	/// 削除を命令します
    /// </summary>
    void  Delete(const std::wstring & path);

	
	
	//void FileManeger();
};
