#include"UDisk.h"

string UDisk_Path(DWORD first) {
	DWORD second = 0;
	char n = 0;
	string UDiskPath = "0";
	second = GetLogicalDrives();	//������ʾ��ʱ���ô�����������λ���롣
	if (second > first) {	// ����⵽�������
		second -= first;
		while (second >>= 1) n++;	//��������1λ�������ж��̷�
		UDiskPath[0] = n + 65;	//��ȡ�̷�
		UDiskPath += ":\\";
		return UDiskPath;
	}
	else
	{
		return NO_UDisk;
	}
}