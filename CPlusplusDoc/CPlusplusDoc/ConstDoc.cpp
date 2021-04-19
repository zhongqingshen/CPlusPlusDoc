#include <iostream>

//const目的是防止对象或者变量被修改
//编译器编译时会在所用使用了const常量的地方，进行值替换:eg:row 11
void test3()
{
	//const int i;//const修饰的常量必须初始化
	const int *p;
	int i = 10;
	//*p = 0; //错误，不能被修改
	const int a = 10;
	int b = a; //编译器编译时会将语句修改为int b = 10;

	//const引用
	const int c = 10;
	const int &r = c;

	//r = 100; 被const修饰的变量不能编辑
	//int &r1 = c;引用变量不能指向一个常量，因为引用变量可以修改，但是引用常量不能修改


}
//指向常量的指针不能修改其指向对象的值
//想要存放常量对象的地址，只能使用指向常量的指针
void testcons()
{
	const int a = 10;
	//int *p = &a; //错误：p是一个普通指针
	const int *cp = &a; // 可以指向a
	//*cp = 12;//错误：不能给*cp赋值
	//指针的类型必须与其所指向的类型一致
	//但是有两种例外：
	//1. 允许一个指向常量的指针指向一个非常量对象
	int va = 12; //va的值可以修改
	cp = &va;//正确：但是不能通过cp来修改va的值
	//*cp = 10; 错误
	//常量指针必须初始化,一旦完成初始化就不能修改它的值（存放的指针地址）
	int err = 0;
	//以下三种区分非常重要
	int * const cur = &err; //这是一个常量指针
	const int *cur1 = &err; // 这是一个指针常量
	const int * const cur2 = &err; //这是一个指向常量的常量指针
	int err1 = 12;
	cur1 = &err1;//由于是一个常量指针
	//*cur1 = 100;
	double d = 100;


}


//int main()
//{
//	system("pause");
//	return 0;
//}