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
	cout << "1.添加书籍" << endl;
	cout << "2.查找书籍" << endl;
	cout << "3.删除书籍" << endl;
	cout << "4.修改书籍" << endl;
	cout << "5.清空书籍" << endl;
	cout << "6.退出程序" << endl;
}
void AddBook(Manager *manager)
{
	if (manager->size >= 1000)
	{
		cout << "书籍超出存储长度" << endl;
		return;
	}
	Book book;
	string name;
	cout << "请输入书籍名称:    " << endl;
	cin >> name;
	book.name = name;
	double price;
	while (true)
	{
		cout << "请输入金额：    " << endl;
		cin >> price;
		if (price <= 0)
		{
			cout << "请输入金额无效，请重新输入：    " << endl;
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
		cout << "当前没有任何数据存在" << endl;
		return;
	}
	string name;
	cout << "请输入书籍名称：";
	cin >> name;
	for (int i = 0; i <= manager->size; i++)
	{
		if (manager->books[i].name == name)
		{
			cout << "书籍名称：" << manager->books[i].name << endl;
			cout << "书籍价格：" << manager->books[i].price << endl;
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
		cout << "当前没有任何书籍" << endl;
		return;
	}

	string name;
	cout << "请输入书籍名称：" << endl;
	cin >> name;
	int res = searchIndex(manager, name);
	if (res < 0)
	{
		cout << "找不到此书籍" << endl;
		return;
	}

	cout << "书籍名称： " << manager->books[res].name << endl;
	cout << "书籍金额： " << manager->books[res].price << endl;
}

void updateBook(Manager * manager)
{
	cout << "请输入书籍名称：";
	string name;
	cin >> name;
	int res = searchIndex(manager, name);
	if (res <= 0)
	{
		cout << "查无此书" << endl;
		return;
	}

	manager->books[res].name = name;
	cout << "请输入金额：" << endl;

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
			cout << "请输入任何数返回菜单" << endl;
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
