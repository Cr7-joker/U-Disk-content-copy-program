#include"UDisk.h"
// 拷贝文件

void copyfiles(string source, char* target) {
	WIN32_FIND_DATA FindFileData;	// 包含文件的信息
	HANDLE hFind;	// 句柄
	string str = source + "*";
	hFind = FindFirstFile(str.c_str(), &FindFileData); //find the target dirctory's frist file;
	while (1) {
		if (hFind == INVALID_HANDLE_VALUE || hFind == (HANDLE)ERROR_FILE_NOT_FOUND) { //file found error
			cout << " 没有找到文件 " << endl;
			break;
		}

		else {
			char tempPath[200], tempSource[200];
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 判断是否为文件夹
				if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..") && strcmp(FindFileData.cFileName, "System Volume Information")) { //take out . & .. & System Volume Information dirc
					strcpy(tempSource, source.c_str());
					strcat(tempSource, FindFileData.cFileName);
					strcpy(tempPath, target);
					strcat(tempPath, FindFileData.cFileName);
					if (CreateDirectory(tempPath, NULL) == 0) {	// 创建文件夹目录
						cout << "创建目录失败" << endl;
					}
					strcat(tempSource, "\\");
					strcat(tempPath, "\\");
					copyfiles(tempSource, tempPath); //Recursion 递归函数
				}
			}
			else { //if is a file,copy to target dirc
				strcpy(tempSource, source.c_str());
				strcpy(tempPath, target);
				strcat(tempPath, FindFileData.cFileName);
				strcat(tempSource, FindFileData.cFileName);
				if (CopyFile(tempSource, tempPath, false))	// 表示将文件tempSource拷贝到tempPath，如果B已经存在则覆盖（第三参数为TRUE时表示不覆盖）
				{
					cout << tempSource << " ----------拷贝成功!!! " << endl;
				}
				else
				{
					cout << tempSource << " ----------拷贝失败!!! " << endl;
				}
			}
			if (FindNextFile(hFind, &FindFileData) == 0) break; //found the next file
		}
	}
	FindClose(hFind); //handle closed;
}