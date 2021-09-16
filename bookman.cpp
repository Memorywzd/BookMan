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
	system("cls");
	cout << "\n\n\t" << "���ܲ˵���" << endl;
	cout << "\n\n\t" << "1 ----------��ʾ����ͼ������" << endl;
	cout << "\n\t" << "2 ----------��ָ��λ�ò���ͼ������" << endl;
	cout << "\n\t" << "3 ----------ɾ��ָ��λ��ͼ������" << endl;
	cout << "\n\t" << "4 ----------����ͼ����Ϣ" << endl;
	cout << "\n\t" << "5 ----------�޸�ͼ����Ϣ" << endl;
	cout << "\n\t" << "6 ----------����ͼ����Ϣ" << endl;
	cout << "\n\n" << "�����빦��ǰ����ţ�";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> input;
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
		char pos;
		cout << "������ϣ�������λ�ã�����1С�ڵ���" << data_obj.get_length() << "����";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin >> pos;
		if (!isdigit(pos))
		{
			cout << "�Ƿ����룡������ϣ�������λ��" << endl;
			system("pause");
			menu(data_obj, io_obj);
		}
		else insert_menu(data_obj, io_obj, pos);
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
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> newbook.ISBN;
	if (newbook.ISBN.length() != 13 && !isint(newbook.ISBN))
	{
		cout << "������Ϸ���ISBN�ţ�" << endl;
		system("pause");
		menu(data_obj, io_obj);
	}
	cout << "�������鱾���ƣ�";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> newbook.book_name;
	cout << "�������鱾�۸�";
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin >> temp;
	if (!isdouble(temp))
	{
		cout << "������Ϸ����鱾�۸�" << endl;
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