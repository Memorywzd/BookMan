#pragma once

#include <cstring>
#include <string>
#include <string.h>

using namespace std;

const int BOOKNUM = 200;

struct book_data//定义结构体
{
	string ISBN;
	string book_name;
	double book_price;
	bool isNull = true;
};

class filedata//封装数据结构
{
public:
	filedata() {  }//置空默认构造函数
	bool init_data_rand(int, string);//遍历初始化结构体数组，从文件读入数据
	bool init_tabel_head(int, char*);//读入原始表头，即文件前两行
	book_data get_books_data(int index) { return books_data[index]; }//随机读取结构体数组数据
	char* get_table_head(int index) { return table_head[index]; }//读取表头
	bool show_book();//打印数据
	int insert_book(int, book_data);//插入数据
	int del_book(int);//删除数据
	int find_book_pos(int);//按照位置查找数据
	int find_book_name(string);//按照名字查找数据
	void change_book();//修改价格
	void sort_book();//冒泡法排序
	int get_length() { return length; }//获取结构体数组长度
	void set_length(int src) { length = src; }//设置结构体数组长度
private:
	book_data books_data[BOOKNUM];//定义结构体数组
	char table_head[2][64] = { '\0' };//定义表头数据
	int length;//定义结构体数组实际长度
};