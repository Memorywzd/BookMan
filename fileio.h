#pragma once

#include "filedata.h"

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

class fileio//��װ�ļ������������
{
public:
	fileio(string path, filedata& src_obj) :path_to_read_file(path), data_obj(src_obj) {  }
	//���幹�캯�������ñ������ʼ��˽�г�Ա
	bool read_in();//����
	bool write_out(string);//д��
private:
	string path_to_read_file;//��������ļ���·��
	filedata& data_obj;//ͨ�����ö�����롢д�����ڴ�����
};
