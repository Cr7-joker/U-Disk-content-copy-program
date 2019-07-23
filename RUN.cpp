#include"UDisk.h"
int main() {
	string path = CreateDirc();	
	if (CreateDirectory(path.c_str(), NULL)) {	// //创建用于保存Copy文件的文件夹
		while (1) { // every 3 seconds to estimate if there is a USB device
			DWORD first = GetLogicalDrives();	// 检索表示当前可用磁盘驱动器的位掩码。
			cout << " waiting…… " << endl;
			Sleep(3000);
			if (UDisk_Path(first) != NO_UDisk)
			{
				copyfiles(UDisk_Path(first), (char*)path.c_str());	//Copy
				return 0;
			}
		}
	}
}