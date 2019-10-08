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
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�ͨѶ¼   *****" << endl;
	cout << "*****************************" << endl;
}

void AddPerson(Addressbooks *abs)
{
	if (abs->size >= 1000)
	{
		cout << "ͨѶ¼�������޷�����¼��" << endl;
	}
	else
	{
		cout << "��������ϵ�������� " << endl;
		string name;
		cin >> name;
		abs->Personarray[abs->size].name = name;

		cout << "��������ϵ���Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (1)
		{
			int sex;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->Personarray[abs->size].sex = sex;
				break;
			}
			else cout << "������������������" << endl;
		}

		cout << "��������ϵ�����䣺 " << endl;
		int age;
		cin >> age;
		abs->Personarray[abs->size].age = age;

		cout << "��������ϵ�˵绰���룺 " << endl;
		string number;
		cin >> number;
		abs->Personarray[abs->size].number = number;

		cout << "��������ϵ�˵�ַ�� " << endl;
		string address;
		cin >> address;
		abs->Personarray[abs->size].addr = address;

		abs->size++;
		cout << "��ϲ����¼��ɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void ShowPerson(Addressbooks *abs)
{
	if (abs->size == 0)
	{
		cout << "��ϵ���б�Ϊ�գ� " << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "����: " << abs->Personarray[i].name << "\t";
			cout << "�Ա�" << (abs->Personarray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->Personarray[i].age << "\t";
			cout << "�绰���룺" << abs->Personarray[i].number << "\t";
			cout << "��ַ " << abs->Personarray[i].addr << endl;
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
	cout << "������Ҫɾ������ϵ�������� " << endl;
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
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���!" << endl;
	}

	system("pause");
	system("cls");
}

void FindPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->Personarray[ret].name << "\t";
		cout << "�Ա� " << (abs->Personarray[ret].sex==1?"��":"Ů") << "\t";
		cout << "���䣺 " << abs->Personarray[ret].age << "\t";
		cout << "�绰���룺 " << abs->Personarray[ret].number << "\t";
		cout << "��ַ�� " << abs->Personarray[ret].addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

void ModifyPerson(Addressbooks *abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "��������ϵ��������" << endl;
		string name;
		cin >> name;
		abs->Personarray[ret].name = name;

		cout << "��������ϵ���Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		cin >> sex;
		abs->Personarray[ret].sex = sex;

		cout << "��������ϵ�����䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->Personarray[ret].age = age;

		cout << "��������ϵ�˵绰���룺 " << endl;
		string number;
		cin >> number;
		abs->Personarray[ret].number = number;

		cout << "��������ϵ�˵�ַ�� " << endl;
		string addr;
		cin >> addr;
		abs->Personarray[ret].addr = addr;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

void CleanPerson(Addressbooks* abs)
{
	cout << "���Ƿ�Ҫ������������ϵ�ˣ�" << endl;
	cout << "1---ȷ�� " << endl;
	cout << "2---ȡ��" << endl;
	int num = 0;
	while (1)
	{
		cin >> num;
		if (num == 1 || num == 0)
		{
			if (num == 1)
			{
				abs->size = 0;
				cout << "ɾ���ɹ�" << endl;
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "�����������������룡" << endl;
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
		//��ʾ��ʼ�˵�
		MenuShow();

		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			AddPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			DelectPerson(&abs);
			break;
		case 4://������ϵ��
			FindPerson(&abs);
			break;
		case 5://�޸���ϵ��
			ModifyPerson(&abs);
			break;
		case 6://�����ϵ��
			CleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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