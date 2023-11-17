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
public:
	File(FileManager& manager);

  virtual int GetHandle()const;
  virtual void Delete();
  virtual ~File();
};

