#pragma once
#include<string>
class FileManager;
class File
{
	friend FileManager;
protected:
	FileManager& manger_;
	int handle_;
	int count_;
	bool isErernal_;
	std::wstring path_;
	virtual void Delete() = 0;//ImageFileやSoundeFile側で実装
public:
	File(FileManager& manager);

  virtual int GetHandle()const;//持ってるハンドルを返す
  
  virtual ~File();
};

