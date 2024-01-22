/*
* 系统需求
* 通讯录是一个可以记录亲人、好有信息的工具。
* 本教程主要利用C++来实现一个通讯录管理系统
* 系统中需要实现的功能如下：
* 1、添加联系人：
*				向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
* 2、显示联系人：
*				显示通讯录中所有联系人信息
* 3、删除联系人：
*				按照姓名惊醒删除指定联系人
* 4、查找联系人：
*				按照姓名查看指定联系人
* 5、修改联系人：
*				按照姓名重新修改指定联系人
* 6、清空联系人：
*				清空通讯录中所有信息
* 7、退出通讯录
*/

#include<iostream>
#define MAX 1000
using namespace std;

// 菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
// 1、设计联系人结构体（姓名、性别、年龄、联系电话、家庭住址）
struct Person
{
	string name;// 姓名
	string sex;// 性别
	unsigned short age = 0;// 年龄
	string phoneNumber;// 电话
	string address;// 家庭住址
};
// 设计通讯录结构体
struct Addressbooks
{

};
// 3.1 添加联系人
void addContact(struct Person* ab, int len)
{
	for (int i = 0; i <= len; i++)
	{
		if (i == len)
		{
			cout << "添加失败：储存已满！！！" << endl;
			return;
		}
		if (ab->name == "") {
			// name
			cout << "请输入姓名：";
			cin >> ab->name;

			// sex
			bool isSex = true;
			do
			{
				unsigned short sex = 0;
				cout << "请选择性别(输入1为男，输入2为女)：_\b";
				cin >> sex;
				switch (sex)
				{
				case 1:
					ab->sex = "男";
					isSex = false;
					break;
				case 2:
					ab->sex = "女";
					isSex = false;
					break;
				default:
					cout << "您的输入有误!" << endl;
					isSex = true;
					break;
				}
			} while (isSex);

			// age
			cout << "请输入年龄：";
			cin >> ab->age;

			// phoneNumber
			cout << "请输入电话号码：";
			cin >> ab->phoneNumber;

			// address
			cout << "请输入家庭地址:";
			cin >> ab->address;
			cout << "添加成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			ab++;
			continue;
		}
	}
}
// 3.2 显示联系人
void showContact(struct Person* ab, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (ab->name != "")
		{
			cout << "姓名：" << ab->name << " 性别：" << ab->sex << " 年龄：" << ab->age << " 联系电话：" << ab->phoneNumber << " 家庭地址：" << ab->address << endl;
			ab++;
		}
		else
		{
			continue;
		}
	}
}
int main()
{
	// 2、创建联系人数组（长度1000）
	struct Person ab[MAX] = {};
	int len = sizeof(ab) / sizeof(ab[0]);
	// 3、实现功能：
	char choose;
	do
	{
		showMenu();
		cout << "请输入您的选择：";
		cin >> choose;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choose)
		{
		case '1':	// 添加联系人
			addContact(ab, len);
			break;
		case '2':	// 显示联系人
			showContact(ab, len);
			break;
		case '3':	// 删除联系人
			cout << "删除联系人" << endl;
			break;
		case '4':	// 查找联系人
			cout << "查找联系人" << endl;
			break;
		case '5':	// 修改联系人
			cout << "修改联系人" << endl;
			break;
		case '6':	// 清空联系人
			cout << "清空联系人" << endl;
			break;
		case '0':	// 退出通讯录
			cout << "退出" << endl;
			return 0;
		default:
			cout << "您的输入有误请重新输入！" << endl;
			break;
		}
	} while (true);

	return 0;
}