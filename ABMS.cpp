#include<iostream>
#include<string>

using namespace std;

#define MAX 1000


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
<<<<<<< HEAD
	
	// person结构体数组
	//struct Person abs[];
=======
	// Person结构体数组
	struct Person personArray[MAX];
	// 数组中个联系人个数
	int m_Size = 0;
>>>>>>> f5b4f2bb551cb8062ee39ccdea2c7dd88ad81703
};
// 3.1 添加联系人
void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "添加失败：储存已满！！！" << endl;
		return;
	}
	else
	{
		// name
		cout << "请输入姓名：";
		cin >> abs->personArray[abs->m_Size].name;

		// sex
		bool isSex = true;
		unsigned short sex = 0;
		while (true)
		{
			cout << "请选择性别(输入1为男，输入2为女)：_\b";
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].sex = (sex == 1) ? "男" : "女";
				break;
			}
			cout << "您的输入有误!" << endl;
		}

		// age
		cout << "请输入年龄：";
		cin >> abs->personArray[abs->m_Size].age;

		// phoneNumber
		cout << "请输入电话号码：";
		cin >> abs->personArray[abs->m_Size].phoneNumber;

		// address
		cout << "请输入家庭地址:";
		cin >> abs->personArray[abs->m_Size].address;

		// 更新通讯录人数
		abs->m_Size++;
		cout << "添加成功!" << endl;
		return;
	}
}
// 3.2 显示联系人
void showContact(Addressbooks * abs)
{
	if (abs->m_Size > 0)
	{
		cout << "一共有" << abs->m_Size << "个联系人" << endl;
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << " 性别：" << abs->personArray[i].sex
				<< " 年龄：" << abs->personArray[i].age << " 联系电话：" << abs->personArray[i].phoneNumber
				<< " 家庭地址：" << abs->personArray[i].address << endl;
		}
	}
	else
	{
		cout << "无联系人！" << endl;
	}
	
}
void showContact(int index, Addressbooks* abs)
{
	if (index != -1)
	{
		cout << "姓名：" << abs->personArray[index].name << " 性别：" << abs->personArray[index].sex
			<< " 年龄：" << abs->personArray[index].age << " 联系电话：" << abs->personArray[index].phoneNumber
			<< " 家庭地址：" << abs->personArray[index].address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
}

// 3.3 删除联系人
void deleteByName(int index, Addressbooks* abs)
{
	if (index!=-1)
	{
		for (index; index < abs->m_Size;index++) 
		{
			abs->personArray[index] = abs->personArray[index + 1];
		}
		abs->m_Size--;
		cout << "成功！" << endl;
	}
	else
	{
		cout << "失败！(联系人不存在。)" << endl;
	}
}

// 3.4 查找联系人
int findeByName(string name, Addressbooks* abs)
{
	int index = -1;
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].name) 
		{
			return i;
		}
	}
	return -1;
}

// 3.5 修改联系人
void modifyPersonByName(int index,Addressbooks* abs)
{
	if (index != -1)
	{
		// name
		cout << "请输入姓名：";
		cin >> abs->personArray[index].name;

		// sex
		bool isSex = true;
		unsigned short sex = 0;
		while (true)
		{
			cout << "请选择性别(输入1为男，输入2为女)：_\b";
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[index].sex = (sex == 1) ? "男" : "女";
				break;
			}
			cout << "您的输入有误!" << endl;
		}

		// age
		cout << "请输入年龄：";
		cin >> abs->personArray[index].age;

		// phoneNumber
		cout << "请输入电话号码：";
		cin >> abs->personArray[index].phoneNumber;

		// address
		cout << "请输入家庭地址:";
		cin >> abs->personArray[index].address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
}

// 3.6 清空联系人
void cleanPerson(Addressbooks* abs)
{
	if (abs->m_Size > 0)
	{
		cout << "确定要清空通讯录吗？(Y or N):";
		char ch;
		cin.get(ch);
		if (ch == 'y' || ch == 'Y')
		{
			abs->m_Size = 0;
			cout << "清空成功！" << endl;
		}
	}
	else
	{
		cout << "无联系人！" << endl;
	}
}

int main()
{
	// 2、创建联系人对象
	Addressbooks abs;
	abs.m_Size = 0;
	string name;
	int index;
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
			addPerson(&abs);
			break;
		case '2':	// 显示联系人
			showContact(&abs);
			break;
		case '3':	// 删除联系人
			cout << "请输入联系人姓名： ";
			cin >> name;
			index = findeByName(name, &abs);
			deleteByName(index, &abs);
			break;
		case '4':	// 查找联系人
			cout << "请输入联系人姓名： ";
			cin >> name;
			index = findeByName(name, &abs);
			showContact(index, &abs);
			break;
		case '5':	// 修改联系人
			cout << "请输入联系人姓名： ";
			cin >> name;
			index = findeByName(name, &abs);
			modifyPersonByName(index, &abs);
			break;
		case '6':	// 清空联系人
			cleanPerson(&abs);
			break;
		case '0':	// 退出通讯录
			cout << "退出" << endl;
			system("exit");
			return 0;
		default:
			cout << "您的输入有误请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (true);

	return 0;
}
