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
	bool show_book();
	int insert_book();
	int del_book();
	int find_book_pos();
	int find_book_name();
	int change_book();
	int sort_book();
private:
	book_data books_data[BOOKNUM];
};

