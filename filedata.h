#pragma once

#include <cstring>
#include <string>
#include <string.h>

using namespace std;

const int BOOKNUM = 200;

struct book_data//����ṹ��
{
	string ISBN;
	string book_name;
	double book_price;
	bool isNull = true;
};

class filedata//��װ���ݽṹ
{
public:
	filedata() {  }//�ÿ�Ĭ�Ϲ��캯��
	bool init_data_rand(int, string);//������ʼ���ṹ�����飬���ļ���������
	bool init_tabel_head(int, char*);//����ԭʼ��ͷ�����ļ�ǰ����
	book_data get_books_data(int index) { return books_data[index]; }//�����ȡ�ṹ����������
	char* get_table_head(int index) { return table_head[index]; }//��ȡ��ͷ
	bool show_book();//��ӡ����
	int insert_book(int, book_data);//��������
	int del_book(int);//ɾ������
	int find_book_pos(int);//����λ�ò�������
	int find_book_name(string);//�������ֲ�������
	void change_book();//�޸ļ۸�
	void sort_book();//ð�ݷ�����
	int get_length() { return length; }//��ȡ�ṹ�����鳤��
	void set_length(int src) { length = src; }//���ýṹ�����鳤��
private:
	book_data books_data[BOOKNUM];//����ṹ������
	char table_head[2][64] = { '\0' };//�����ͷ����
	int length;//����ṹ������ʵ�ʳ���
};