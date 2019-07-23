#include"UDisk.h"

string UDisk_Path(DWORD first) {
	DWORD second = 0;
	char n = 0;
	string UDiskPath = "0";
	second = GetLogicalDrives();	//检索表示此时可用磁盘驱动器的位掩码。
	if (second > first) {	// 若检测到插入磁盘
		second -= first;
		while (second >>= 1) n++;	//进行右移1位操作，判断盘符
		UDiskPath[0] = n + 65;	//获取盘符
		UDiskPath += ":\\";
		return UDiskPath;
	}
	else
	{
		return NO_UDisk;
	}
}