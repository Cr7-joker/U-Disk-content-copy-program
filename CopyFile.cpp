#include"UDisk.h"
// �����ļ�

void copyfiles(string source, char* target) {
	WIN32_FIND_DATA FindFileData;	// �����ļ�����Ϣ
	HANDLE hFind;	// ���
	string str = source + "*";
	hFind = FindFirstFile(str.c_str(), &FindFileData); //find the target dirctory's frist file;
	while (1) {
		if (hFind == INVALID_HANDLE_VALUE || hFind == (HANDLE)ERROR_FILE_NOT_FOUND) { //file found error
			cout << " û���ҵ��ļ� " << endl;
			break;
		}

		else {
			char tempPath[200], tempSource[200];
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // �ж��Ƿ�Ϊ�ļ���
				if (strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..") && strcmp(FindFileData.cFileName, "System Volume Information")) { //take out . & .. & System Volume Information dirc
					strcpy(tempSource, source.c_str());
					strcat(tempSource, FindFileData.cFileName);
					strcpy(tempPath, target);
					strcat(tempPath, FindFileData.cFileName);
					if (CreateDirectory(tempPath, NULL) == 0) {	// �����ļ���Ŀ¼
						cout << "����Ŀ¼ʧ��" << endl;
					}
					strcat(tempSource, "\\");
					strcat(tempPath, "\\");
					copyfiles(tempSource, tempPath); //Recursion �ݹ麯��
				}
			}
			else { //if is a file,copy to target dirc
				strcpy(tempSource, source.c_str());
				strcpy(tempPath, target);
				strcat(tempPath, FindFileData.cFileName);
				strcat(tempSource, FindFileData.cFileName);
				if (CopyFile(tempSource, tempPath, false))	// ��ʾ���ļ�tempSource������tempPath�����B�Ѿ������򸲸ǣ���������ΪTRUEʱ��ʾ�����ǣ�
				{
					cout << tempSource << " ----------�����ɹ�!!! " << endl;
				}
				else
				{
					cout << tempSource << " ----------����ʧ��!!! " << endl;
				}
			}
			if (FindNextFile(hFind, &FindFileData) == 0) break; //found the next file
		}
	}
	FindClose(hFind); //handle closed;
}