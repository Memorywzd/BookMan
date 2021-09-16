#pragma once

#include "bookman.h"
#include "filedata.h"
#include "fileio.h"

#include <iostream>

using namespace std;

void welcom()
{
	cout << "计算机类204班 王肇丹 190601209" << endl;
	cout << "\n\n\n\n\n" << '\t' << "欢迎使用图书管理系统！" << "\n\n\n\n\n" << endl;
	cout << '\t' << "按任意键初始化系统......" << "\n\n\n\n\n" << endl;
	system("pause");
	system("cls");
}

void menu(filedata& data_obj, fileio& io_obj);
void insert_menu(filedata& data_obj, fileio& io_obj, char pos);
bool isdouble(string x);
bool isint(string x);