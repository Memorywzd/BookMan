#include "bookman.h"
#include "filedata.h"
#include "fileio.h"

#include <iostream>

int main()
{
	filedata book_data_obj;
	fileio book_io("book.txt", book_data_obj);
	if (!book_io.read_in())cout << "�ļ���ʧ�ܣ�" << endl;
	else cout << "�ļ��Ѿ����룡" << endl;
	

}