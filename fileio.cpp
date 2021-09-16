#include "fileio.h"

bool fileio::read_in()
{
	char buffer[64] = { '\0' };
	int line_flag = 0, data_index = 0;
	ifstream in_fs(path_to_file);
	if (!in_fs.is_open())return false;
	while (!in_fs.eof())
	{
		line_flag++;
		in_fs.getline(buffer, 64);
		for (int i = 0; buffer[i] != '\0'; i++)
		{
			cout << buffer[i];
			if (buffer[i + 1] == '\0')cout << " line: " << line_flag << endl;
		}
		if (line_flag > 2)
		{
			data_obj.init_data_rand(data_index, buffer);
			data_index++;
		}
	}
	
}

bool fileio::write_out()
{
	ofstream out_fs(path_to_file);
	if (!out_fs.is_open())return false;

}