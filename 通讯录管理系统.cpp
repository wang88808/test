#include<iostream>
using namespace std;

#define MAX 1000

struct Person
{
	string name;
	int sex=0;
	int age=0;
	string number;
	string addr;
};

struct Addressbooks
{
	struct Person Personarray[MAX];
	int size=0;
};

void MenuShow()
{
	cout << "*****************************" << endl;
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出通讯录   *****" << endl;
	cout << "*****************************" << endl;
}

void AddPerson(Addressbooks *abs)
{
	if (abs->size >= 1000)
	{
		cout << "通讯录已满，无法继续录入" << endl;
	}
	else
	{
		cout << "请输入联系人姓名： " << endl;
		string name;
		cin >> name;
		abs->Personarray[abs->size].name = name;

		cout << "请输入联系人性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (1)
		{
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->Personarray[abs->size].sex = sex;
				break;
			}
			else cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入联系人年龄： " << endl;
		int age;
		cin >> age;
		abs->Personarray[abs->size].age = age;

		cout << "请输入联系人电话号码： " << endl;
		string number;
		cin >> number;
		abs->Personarray[abs->size].number = number;

		cout << "请输入联系人地址： " << endl;
		string address;
		cin >> address;
		abs->Personarray[abs->size].addr = address;

		abs->size++;
		cout << "恭喜您！录入成功" << endl;

		system("pause");
		system("cls");
	}
}

void ShowPerson(Addressbooks *abs)
{
	if (abs->size == 0)
	{
		cout << "联系人列表为空！ " << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名: " << abs->Personarray[i].name << "\t";
			cout << "性别：" << (abs->Personarray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->Personarray[i].age << "\t";
			cout << "电话号码：" << abs->Personarray[i].number << "\t";
			cout << "地址 " << abs->Personarray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->Personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void DelectPerson(Addressbooks *abs)
{
	cout << "请输入要删除的联系人姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->Personarray[i] = abs->Personarray[i + 1];
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人!" << endl;
	}

	system("pause");
	system("cls");
}

void FindPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->Personarray[ret].name << "\t";
		cout << "性别： " << (abs->Personarray[ret].sex==1?"男":"女") << "\t";
		cout << "年龄： " << abs->Personarray[ret].age << "\t";
		cout << "电话号码： " << abs->Personarray[ret].number << "\t";
		cout << "地址： " << abs->Personarray[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void ModifyPerson(Addressbooks *abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		abs->Personarray[ret].name = name;

		cout << "请输入联系人性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		cin >> sex;
		abs->Personarray[ret].sex = sex;

		cout << "请输入联系人年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->Personarray[ret].age = age;

		cout << "请输入联系人电话号码： " << endl;
		string number;
		cin >> number;
		abs->Personarray[ret].number = number;

		cout << "请输入联系人地址： " << endl;
		string addr;
		cin >> addr;
		abs->Personarray[ret].addr = addr;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

void CleanPerson(Addressbooks* abs)
{
	cout << "您是否要真的清空所有联系人？" << endl;
	cout << "1---确定 " << endl;
	cout << "2---取消" << endl;
	int num = 0;
	while (1)
	{
		cin >> num;
		if (num == 1 || num == 0)
		{
			if (num == 1)
			{
				abs->size = 0;
				cout << "删除成功" << endl;
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}

int main(void)
{
	Addressbooks abs;
	abs.size = 0;
	int select = 0;

	while (1)
	{
		//显示初始菜单
		MenuShow();

		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			AddPerson(&abs);
			break;
		case 2://显示联系人
			ShowPerson(&abs);
			break;
		case 3://删除联系人
			DelectPerson(&abs);
			break;
		case 4://查找联系人
			FindPerson(&abs);
			break;
		case 5://修改联系人
			ModifyPerson(&abs);
			break;
		case 6://清空联系人
			CleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}