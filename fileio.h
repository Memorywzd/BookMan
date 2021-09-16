#pragma once

#include "filedata.h"

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

class fileio
{
public:
	fileio(string path, filedata& src_obj) :path_to_read_file(path), data_obj(src_obj) {  }
	bool read_in();
	bool write_out(string);
private:
	string path_to_read_file;
	filedata& data_obj;
};
