#include "FileManeger.h"
#include "DxLib.h"
#include "ImageFile.h"
#include <cassert>
std::shared_ptr<File>FileManager::LoadGraphic(const std::wstring& path)
{

	if (fileTable_.find(path) != fileTable_.end())
	{
		auto file = fileTable_.at(path);
		std::shared_ptr<ImageFile>imgFile = std::dynamic_pointer_cast<ImageFile>(file);
	
		assert(imgFile!= nullptr);
		++file->count_;//所有者アカウントを増やします
		return std::make_shared<ImageFile>(*imgFile);
	}
	int handle=LoadGraph(path.c_str());
	assert(handle > 0);
	std::shared_ptr<File>ret = std::make_shared<ImageFile>(*this);
	ret->handle_ = handle;
	ret->path_ = path;
	ret->count_ = handle;
	file->count_ = 1;
	//file->isEtrtnal_=isetrtnal;
	return std::make_shared<ImageFile>(*std::dynamic_pointer_cast);

     //return std::shared_ptr <File>();
	
	


}

void FileManager::Delete(const std::wstring& path)
{
	if (fileTable_.find(path) == fileTable_.end()) 
	{
		return;
	}
	auto file = FileTable_t.at(path);
	--file->count_;
	if (File->isEternal_)
	{
		return;
	}
	if (file->count_==0)
	{
		fileTable_.erase(path);
		file->Delete();
	}

}


