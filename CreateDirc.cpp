#include"UDisk.h"
//����һ���ļ���·���������濽�����ļ�
string CreateDirc() {
	char path[100] = "D:\\CopyFile\\";
	while (_access(path, 0) == 0) { // if directory already exist,this will auto add '\1' back it;
		strcat(path, "1\\");
	}
	return path;
}