#pragma once
#ifndef _UDisk_
#define _UDisk_

#include <iostream>
#include <stdlib.h>
#include <io.h>
#include <windows.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
constexpr auto NO_UDisk = "There is no new UDisk";
string CreateDirc(); // 创建用于接收拷贝文件的路径
string UDisk_Path(DWORD first);	// 获得磁盘路径
void copyfiles(string source, char* target);	//CopyFiles

#endif // !_UDisk_
