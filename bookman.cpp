#include "bookman.h"
#include "filedata.h"
#include "fileio.h"

#include <iostream>

int main()
{
	filedata book_data_obj;
	fileio book_io("book.txt", book_data_obj);
	if (!book_io.read_in())cout << "文件打开失败！" << endl;
	else cout << "文件已经读入！" << endl;
	

}