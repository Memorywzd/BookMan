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
	system("cls");
	cout << "\n\n\t" << "功能菜单：" << endl;
	cout << "\n\n\t" << "1 ----------显示所有图书数据" << endl;
	cout << "\n\t" << "2 ----------向指定位置插入图书数据" << endl;
	cout << "\n\t" << "3 ----------删除指定位置图书数据" << endl;
	cout << "\n\t" << "4 ----------查找图书信息" << endl;
	cout << "\n\t" << "5 ----------修改图书信息" << endl;
	cout << "\n\t" << "6 ----------排序图书信息" << endl;
	cout << "\n\n" << "请输入功能前的序号：";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> input;
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
		char pos;
		cout << "请输入希望插入的位置（大于1小于等于" << data_obj.get_length() << "）：";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin >> pos;
		if (!isdigit(pos))
		{
			cout << "非法输入！请输入希望插入的位置" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else insert_menu(data_obj, io_obj, pos);
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
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> newbook.ISBN;
	if (newbook.ISBN.length() != 13 && !isint(newbook.ISBN))
	{
		cout << "请输入合法的ISBN号！" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	cout << "请输入书本名称：";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> newbook.book_name;
	cout << "请输入书本价格：";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> temp;
	if (!isdouble(temp))
	{
		cout << "请输入合法的书本价格！" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	else newbook.book_price = stod(temp);
	newbook.isNull = false;
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