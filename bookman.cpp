#include "bookman.h"

int main()
{
	welcom();

	filedata book_data_obj;
	fileio book_io("book.txt", book_data_obj);
	if (!book_io.read_in())cout << "未找到系统所需文件！" << endl;
	else cout << "完成初始化，文件已经读入！" << endl;
	system("pause");

	menu(book_data_obj, book_io);
}

void menu(filedata& data_obj, fileio& io_obj)
{
	char input;
	string pos;
	system("cls");
	cout << "\n\n\t" << "功能菜单：" << endl;
	cout << "\n\n\t" << "1 ----------显示所有图书数据" << endl;
	cout << "\n\t" << "2 ----------向指定位置插入图书数据" << endl;
	cout << "\n\t" << "3 ----------删除指定位置图书数据" << endl;
	cout << "\n\t" << "4 ----------查找图书信息" << endl;
	cout << "\n\t" << "5 ----------修改图书信息" << endl;
	cout << "\n\t" << "6 ----------排序图书信息" << endl;
	cout << "\n\t" << "7 ----------退出系统" << endl;
	cout << "\n\n" << "请输入功能前的序号：";
	cin >> input;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	switch (input)
	{
	case '1':
		system("cls");
		data_obj.show_book();
		system("pause");
		cout << "按任意键返回主菜单..." << endl;
		menu(data_obj, io_obj);
		break;
	case '2':
		system("cls");
		cout << "请输入希望插入的位置（大于1小于等于" << data_obj.get_length() << "）：";
		cin >> pos;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		if (!isint(pos))
		{
			cout << "非法输入！请输入希望插入的位置" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else insert_menu(data_obj, io_obj, stoi(pos));
		break;
	case '3':
		cout << "请输入希望删除的位置（大于1小于等于" << data_obj.get_length() << "）：";
		cin >> pos;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		if (!isint(pos))
		{
			cout << "非法输入！请输入希望删除的位置" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else
		{
			data_obj.del_book(stoi(pos) - 48);
			io_obj.write_out("test.txt");
			system("pause");
			cout << "按任意键返回主菜单..." << endl;
			menu(data_obj, io_obj);
		}
		break;
	case '4':
		seekmenu(data_obj, io_obj);
		break;
	case '5':
		data_obj.change_book();
		io_obj.write_out("book_newprice.txt");
		cout << "Done!" << endl;
		system("pause");
		cout << "按任意键返回主菜单..." << endl;
		menu(data_obj, io_obj);
		break;
	case '6':
		data_obj.sort_book();
		io_obj.write_out("book_newsort.txt");
		break;
	case '7':
		exit(0);
		break;
	default:
		cout << "非法输入！请输入菜单前的数字！" << endl;
		system("pause");
		menu(data_obj, io_obj);
		break;
	}
}

void insert_menu(filedata& data_obj, fileio& io_obj, char pos)
{
	int posi = pos - 48;
	book_data newbook;
	string temp;
	cout << "请输入ISBN号：";
	cin >> newbook.ISBN;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	if (newbook.ISBN.length() != 13 && !isint(newbook.ISBN))
	{
		cout << "请输入合法的ISBN号！" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	cout << "请输入书本名称：";
	cin >> newbook.book_name;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "请输入书本价格：";
	cin >> temp;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	if (!isdouble(temp))
	{
		cout << "请输入合法的书本价格！" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	else newbook.book_price = stod(temp);
	newbook.isNull = false;

	data_obj.insert_book(posi, newbook);
	io_obj.write_out("test.txt");
	system("pause");
	cout << "按任意键返回主菜单..." << endl;
	menu(data_obj, io_obj);
}

void seekmenu(filedata& data_obj, fileio& io_obj)
{
	string temp;
	cin >> temp;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	if (isint(temp) && (stoi(temp) >= 1) && (stoi(temp) <= data_obj.get_length()))data_obj.find_book_pos(stoi(temp));
	else data_obj.find_book_name(temp);
	system("pause");
	cout << "按任意键返回主菜单..." << endl;
	menu(data_obj, io_obj);
}

bool isdouble(string x)
{
	double y;
	try
	{
		y = stod(x);
	}
	catch (const exception&)
	{
		return false;
	}
	return true;
}

bool isint(string x)
{
	double y;
	try
	{
		y = stoi(x);
	}
	catch (const exception&)
	{
		return false;
	}
	return true;
}