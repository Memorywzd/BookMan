#pragma once

#include "bookman.h"
#include "filedata.h"
#include "fileio.h"

#include <iostream>

using namespace std;

void welcom()
{
	cout << "�������204�� ���ص� 190601209" << endl;
	cout << "\n\n\n\n\n" << '\t' << "��ӭʹ��ͼ�����ϵͳ��" << "\n\n\n\n\n" << endl;
	cout << '\t' << "���������ʼ��ϵͳ......" << "\n\n\n\n\n" << endl;
	system("pause");
	system("cls");
}

void menu(filedata& data_obj, fileio& io_obj);
void insert_menu(filedata& data_obj, fileio& io_obj, char pos);
bool isdouble(string x);
bool isint(string x);