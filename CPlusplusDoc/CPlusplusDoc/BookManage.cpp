#include <iostream>
#include <string>
using namespace std;

//#define MAX_SIZE 1000

class Book
{
public:
	string name;
	double price;
};

class Manager
{
public:
	Book books[1000];
	unsigned int size;

};


void print_item()
{
	cout << "1.����鼮" << endl;
	cout << "2.�����鼮" << endl;
	cout << "3.ɾ���鼮" << endl;
	cout << "4.�޸��鼮" << endl;
	cout << "5.����鼮" << endl;
	cout << "6.�˳�����" << endl;
}
void AddBook(Manager *manager)
{
	if (manager->size >= 1000)
	{
		cout << "�鼮�����洢����" << endl;
		return;
	}
	Book book;
	string name;
	cout << "�������鼮����:    " << endl;
	cin >> name;
	book.name = name;
	double price;
	while (true)
	{
		cout << "�������    " << endl;
		cin >> price;
		if (price <= 0)
		{
			cout << "����������Ч�����������룺    " << endl;
		}
		else
		{
			book.price = price;
			break;
		}
	}

	manager->books[manager->size] = book;
	manager->size++;
}

void findBook(Manager *manager)
{
	if (manager->size <= 0)
	{
		cout << "��ǰû���κ����ݴ���" << endl;
		return;
	}
	string name;
	cout << "�������鼮���ƣ�";
	cin >> name;
	for (int i = 0; i <= manager->size; i++)
	{
		if (manager->books[i].name == name)
		{
			cout << "�鼮���ƣ�" << manager->books[i].name << endl;
			cout << "�鼮�۸�" << manager->books[i].price << endl;
		}
	}
}

int searchIndex(Manager * manager, string name)
{
	for (int i = 0; i <= manager->size; i++)
	{
		if (manager->books[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void removeBook(Manager * manager)
{
	if (manager->size <= 0)
	{
		cout << "��ǰû���κ��鼮" << endl;
		return;
	}

	string name;
	cout << "�������鼮���ƣ�" << endl;
	cin >> name;
	int res = searchIndex(manager, name);
	if (res < 0)
	{
		cout << "�Ҳ������鼮" << endl;
		return;
	}

	cout << "�鼮���ƣ� " << manager->books[res].name << endl;
	cout << "�鼮�� " << manager->books[res].price << endl;
}

void updateBook(Manager * manager)
{
	cout << "�������鼮���ƣ�";
	string name;
	cin >> name;
	int res = searchIndex(manager, name);
	if (res <= 0)
	{
		cout << "���޴���" << endl;
		return;
	}

	manager->books[res].name = name;
	cout << "�������" << endl;

	double price;
	cin >> price;

	manager->books[res].price = price;
}


void cleanBook(Manager * manager)
{
	manager->size = 0;
}


int main()
{
	int item;
	Manager manager;
	manager.size = 0;
	while (true)
	{
		print_item();
		cin >> item;
		switch (item)
		{
		case 1:
			AddBook(&manager);
			cout << "�������κ������ز˵�" << endl;
			int a;
			cin >> a;
			system("cls");
			break;
		case 2:
			findBook(&manager);
			break;
		case 3:
			removeBook(&manager);
			break;
		case 4:
			updateBook(&manager);
			break;
		case 5:
			cleanBook(&manager);
			break;
		case 6:
			return 0;

		}
	}



    system("pause");
	return 0;
}
