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
    /// ���\�[�X�̍폜���s���܂�
	/// ���ۂɂ͓����J�E���g�����āA0�ɂȂ����炻�ꂼ��̃��\�[�X��
	/// �폜�𖽗߂��܂�
    /// </summary>
    void  Delete(const std::wstring & path);

	
	
	//void FileManeger();
};
