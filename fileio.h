#pragma once

#include "filedata.h"

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

class fileio//封装文件输入输出操作
{
public:
	fileio(string path, filedata& src_obj) :path_to_read_file(path), data_obj(src_obj) {  }
	//定义构造函数，利用变量表初始化私有成员
	bool read_in();//读入
	bool write_out(string);//写出
private:
	string path_to_read_file;//定义读入文件的路径
	filedata& data_obj;//通过引用定义读入、写出的内存数据
};
