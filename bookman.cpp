#include "bookman.h"

int main()
{
	welcom();

	filedata book_data_obj;
	fileio book_io("book.txt", book_data_obj);
	if (!book_io.read_in())cout << "δ�ҵ�ϵͳ�����ļ���" << endl;
	else cout << "��ɳ�ʼ�����ļ��Ѿ����룡" << endl;
	system("pause");

	menu(book_data_obj, book_io);
}

void menu(filedata& data_obj, fileio& io_obj)
{
	char input;
	string pos;
	system("cls");
	cout << "\n\n\t" << "���ܲ˵���" << endl;
	cout << "\n\n\t" << "1 ----------��ʾ����ͼ������" << endl;
	cout << "\n\t" << "2 ----------��ָ��λ�ò���ͼ������" << endl;
	cout << "\n\t" << "3 ----------ɾ��ָ��λ��ͼ������" << endl;
	cout << "\n\t" << "4 ----------����ͼ����Ϣ" << endl;
	cout << "\n\t" << "5 ----------�޸�ͼ����Ϣ" << endl;
	cout << "\n\t" << "6 ----------����ͼ����Ϣ" << endl;
	cout << "\n\t" << "7 ----------�˳�ϵͳ" << endl;
	cout << "\n\n" << "�����빦��ǰ����ţ�";
	cin >> input;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	switch (input)
	{
	case '1':
		system("cls");
		data_obj.show_book();
		system("pause");
		cout << "��������������˵�..." << endl;
		menu(data_obj, io_obj);
		break;
	case '2':
		system("cls");
		cout << "������ϣ�������λ�ã�����1С�ڵ���" << data_obj.get_length() << "����";
		cin >> pos;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		if (!isint(pos))
		{
			cout << "�Ƿ����룡������ϣ�������λ��" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else insert_menu(data_obj, io_obj, stoi(pos));
		break;
	case '3':
		cout << "������ϣ��ɾ����λ�ã�����1С�ڵ���" << data_obj.get_length() << "����";
		cin >> pos;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		if (!isint(pos))
		{
			cout << "�Ƿ����룡������ϣ��ɾ����λ��" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else
		{
			data_obj.del_book(stoi(pos) - 48);
			io_obj.write_out("test.txt");
			system("pause");
			cout << "��������������˵�..." << endl;
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
		cout << "��������������˵�..." << endl;
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
		cout << "�Ƿ����룡������˵�ǰ�����֣�" << endl;
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
	cout << "������ISBN�ţ�";
	cin >> newbook.ISBN;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	if (newbook.ISBN.length() != 13 && !isint(newbook.ISBN))
	{
		cout << "������Ϸ���ISBN�ţ�" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	cout << "�������鱾���ƣ�";
	cin >> newbook.book_name;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "�������鱾�۸�";
	cin >> temp;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	if (!isdouble(temp))
	{
		cout << "������Ϸ����鱾�۸�" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	else newbook.book_price = stod(temp);
	newbook.isNull = false;

	data_obj.insert_book(posi, newbook);
	io_obj.write_out("test.txt");
	system("pause");
	cout << "��������������˵�..." << endl;
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
	cout << "��������������˵�..." << endl;
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