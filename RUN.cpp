#include"UDisk.h"
int main() {
	string path = CreateDirc();	
	if (CreateDirectory(path.c_str(), NULL)) {	// //�������ڱ���Copy�ļ����ļ���
		while (1) { // every 3 seconds to estimate if there is a USB device
			DWORD first = GetLogicalDrives();	// ������ʾ��ǰ���ô�����������λ���롣
			cout << " waiting���� " << endl;
			Sleep(3000);
			if (UDisk_Path(first) != NO_UDisk)
			{
				copyfiles(UDisk_Path(first), (char*)path.c_str());	//Copy
				return 0;
			}
		}
	}
}