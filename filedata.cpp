#include "filedata.h"

#include <iostream>
#include <iomanip>
#include <sstream>

bool filedata::show_book()
{
	if (books_data[0].isNull)
	{
		cout << "数据为空无法输出！" << endl;
		return false;
	}
	cout << setw(15) << left << "ISBN" << '\t';
	cout << setw(35) << left << "书名" << '\t';
	cout << "定价" << endl;
	for (int i = 0; !books_data[i].isNull; i++)
	{
		cout << setw(15) << left << books_data[i].ISBN << '\t';
		cout << setw(35) << left << books_data[i].book_name << '\t';
		cout << books_data[i].book_price << endl;
	}
	return true;
}

bool filedata::init_data_rand(int index, string src_data)
{
	if (index > BOOKNUM)return false;
	stringstream src_s(src_data);
	string item[3];
	for (int i = 0; getline(src_s, item[i], '\t'); i++)
	{
		switch (i)
		{
		case 0:
			books_data[index].ISBN = item[0].substr(0, 13);
			break;
		case 1:
			books_data[index].book_name = item[1];
			break;
		case 2:
			books_data[index].book_price = atof(item[2].c_str());
		}
	}
	books_data[index].isNull = false;
	return true;
}

bool filedata::init_tabel_head(int index,char *buffer)
{
	if (index !=1&&index!=2)return false;
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		table_head[index-1][i] = buffer[i];
	}
	return true;
}

int filedata::insert_book(int pos, book_data e)
{
	if ((pos < 1) || (pos > length + 1))return -1;
	if (length == BOOKNUM)return -1;
	for (int i = length - 1; i >= pos - 1; i--)
	{
		books_data[i + 1] = books_data[i];
	}
	books_data[pos - 1] = e;
	length++;
	return 0;
}

int filedata::del_book(int pos)
{
	if ((pos < 1) || (pos > length))return -1;
	for (int i = pos; i < length - 1; i++)
	{
		books_data[i - 1] = books_data[i];
	}
	length--;
	return 1;
}

int filedata::find_book_pos(int pos)
{
	if ((pos < 1) || (pos > length))return -1;
	cout << setw(15) << left << "ISBN" << '\t';
	cout << setw(35) << left << "书名" << '\t';
	cout << "定价" << endl;
	cout << setw(15) << left << books_data[pos].ISBN << '\t';
	cout << setw(35) << left << books_data[pos].book_name << '\t';
	cout << books_data[pos].book_price << endl;
	return 0;
}

int filedata::find_book_name(string name)
{
	int suc_num = 0, suc_index[50] = { -1 };
	for (int i = 0; i < length; i++)
	{
		if (books_data[i].book_name == name)
		{
			suc_index[suc_num] = i;
			suc_num++;
		}
	}
	if (suc_num == 0)return -1;
	cout << setw(15) << left << "ISBN" << '\t';
	cout << setw(35) << left << "书名" << '\t';
	cout << "定价" << endl;
	for (int i = 0; i< suc_num; i++)
	{
		cout << setw(15) << left << books_data[i].ISBN << '\t';
		cout << setw(35) << left << books_data[i].book_name << '\t';
		cout << books_data[i].book_price << endl;
	}
	return 0;
}

void filedata::change_book()
{
	for (int i = 0; i < length; i++)
	{
		if (books_data[i].book_price < 25)books_data[i].book_price *= 1.25;
		else books_data[i].book_price *= 1.1;
	}
}

void filedata::sort_book()
{
	book_data temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - j; j++)
		{
			if (books_data[j].book_price > books_data[j + 1].book_price)
			{
				temp = books_data[j];
				books_data[j] = books_data[j + 1];
				books_data[j + 1] = temp;
			}
		}
	}
}