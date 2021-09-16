#include "fileio.h"

bool fileio::read_in()
{
	char buffer[64] = { '\0' };//�ȶ��뻺������У���д��ṹ������
	int line_flag = 0, data_index = 0;
	ifstream in_fs(path_to_read_file);
	if (!in_fs.is_open())return false;
	while (!in_fs.eof())
	{
		line_flag++;
		in_fs.getline(buffer, 64);
		/*for (int i = 0; buffer[i] != '\0'; i++)
		{
			cout << buffer[i];
			if (buffer[i + 1] == '\0')cout << " line: " << line_flag << endl;
		}�����ô���*/
		if (line_flag > 2)
		{
			data_obj.init_data_rand(data_index, buffer);
			data_index++;
		}
		else
		{
			data_obj.init_tabel_head(line_flag, buffer);
		}
	}
	data_obj.set_length(data_index);
	cout << endl;
	//data_obj.show_book();�����ô���
}

bool fileio::write_out(string path_to_write_file)
{
	ofstream out_fs(path_to_write_file);//�ӽṹ������д�����ݵ��ļ�
	if (!out_fs.is_open())return false;
	out_fs << data_obj.get_table_head(0) << endl << data_obj.get_table_head(1) << endl;
	for (int i = 0; !data_obj.get_books_data(i).isNull; i++)
	{
		out_fs << data_obj.get_books_data(i).ISBN << ' ' << '\t';
		out_fs << data_obj.get_books_data(i).book_name<< '\t';
		out_fs << data_obj.get_books_data(i).book_price << endl;
	}
	return true;
}