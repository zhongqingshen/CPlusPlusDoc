#include <iostream>
using namespace std;
//复合类型
  //定义：是指基于其他类型定义的类型，例如：指针和引用
  //引用(reference)：为对象取一个别名，引用类型引用另外一种类型，通过将声明符写成&P的形式来定义引用，P表示声明的变量
  //引用变量初始化和一般变量初始化有区别，变量初始化会将初始值拷贝至新建对象。引用定义是和初始值进行绑定而不是将初始值
  //进行拷贝，初始化完成后引用就和初始值绑定在一起。因为不能将引用绑定修改至其他对象，所以引用必须初始化
void test()
{
	int value = 10;
	int &rValue = value;
	cout << "变量 value 的值：" << value << endl; // 10
	cout << "引用变量 rValue 的值：" << rValue << endl; // 10
	//int &rValue; //运行报错，&rValue必须被初始化 
	
	value = 20;
	cout << "变量 value 的值：" << value << endl; // 10
	cout << "引用变量 rValue 的值：" << rValue << endl; // 10
}

int main()
{
	test();
	system("pause");
	return 0;
}