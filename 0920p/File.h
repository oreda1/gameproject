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
	virtual void Delete() = 0;//ImageFile��SoundeFile���Ŏ���
public:
	File(FileManager& manager);

  virtual int GetHandle()const;//�����Ă�n���h����Ԃ�
  
  virtual ~File();
};

