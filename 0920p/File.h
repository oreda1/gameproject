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
	virtual void Delete() = 0;//ImageFile‚âSoundeFile‘¤‚ÅÀ‘•
public:
	File(FileManager& manager);

  virtual int GetHandle()const;//‚Á‚Ä‚éƒnƒ“ƒhƒ‹‚ğ•Ô‚·
  
  virtual ~File();
};

