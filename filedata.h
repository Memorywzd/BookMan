#pragma once

#include <cstring>
#include <string>
#include <string.h>

using namespace std;

const int BOOKNUM = 200;

struct book_data
{
	string ISBN;
	string book_name;
	double book_price;
	bool isNull = true;
};

class filedata
{
public:
	filedata() {  }
	bool init_data_rand(int, string);
	bool init_tabel_head(int, char*);
	book_data get_books_data(int index) { return books_data[index]; }
	char* get_table_head(int index) { return table_head[index]; }
	bool show_book();
	int insert_book(int, book_data);
	int del_book(int);
	int find_book_pos(int);
	int find_book_name(string);
	void change_book();
	void sort_book();
	int get_length() { return length; }
	void set_length(int src) { length = src; }
private:
	book_data books_data[BOOKNUM];
	char table_head[2][64] = { '\0' };
	int length;
};