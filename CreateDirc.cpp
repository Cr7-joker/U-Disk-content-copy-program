#include"UDisk.h"
//创建一个文件夹路径用来保存拷贝的文件
string CreateDirc() {
	char path[100] = "D:\\CopyFile\\";
	while (_access(path, 0) == 0) { // if directory already exist,this will auto add '\1' back it;
		strcat(path, "1\\");
	}
	return path;
}