#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>

using namespace std;


//�t�H���_���̃t�@�C�����
void get_filelist(string path, string filenamelist[], long &nn_max, string f_type) {
	HANDLE hFind;
	WIN32_FIND_DATA fd;
	//	FILETIME ft;
	//	SYSTEMTIME st;

	string type = "*" + f_type;
	path = path + type;

	/* �ŏ��̃t�@�C������ */
	hFind = FindFirstFile(path.c_str(), &fd);

	/* �������s? */
	if (hFind == INVALID_HANDLE_VALUE) {
		printf("�������s\n");
		return; /******** �G���[�I�� ********/
	}
	int num = 0;

	do {
		/* ���ʂ̕\�� */
		printf("�t�@�C����: %s\n", fd.cFileName);
		if (num<1000)
			filenamelist[num++] = fd.cFileName;

	} while (FindNextFile(hFind, &fd));

	nn_max = num;
	/* �����I�� */
	FindClose(hFind);
}