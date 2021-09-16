#include "filedata.h"

#include <iostream>
#include <iomanip>

bool filedata::show_book()
{
	if (books_data[0].isNull)
	{
		cout << "数据为空无法输出！" << endl;
		return false;
	}
	for (int i = 0; !books_data[i].isNull; i++)
	{
		cout << setw(15) << left << "ISBN" << '\t';
		cout << setw(26) << left << "书名" << '\t';
		cout << "定价" << endl;
		cout << setw(15) << left << books_data[i].ISBN << '\t';
		cout << setw(26) << left << books_data[i].book_name << '\t';
		cout << books_data[i].book_price << endl;
	}
	return true;
}

bool filedata::init_data_rand(int index, string src_data)
{
	for (int i = 0; i < src_data.length(); i++)
	{
		if (src_data[i] == '\t')books_data[index].ISBN = src_data.substr(i - 1);
	}
}