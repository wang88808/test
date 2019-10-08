#include<iostream>
using namespace std;

	//定义结构体
struct Hero
{
	string name;
	int age;
	string sex;
};

int main(void)
{
	Hero her[5] =
	{
		//存放五位英雄
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
	};
	
	//对英雄进行排序
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (her[j].age > her[j + 1].age)
			{
				Hero temp = her[j + 1];
				her[j + 1] = her[j];
				her[j] = temp;
			}
		}
	}
	//打印输出
	for (int i = 0; i < 5; i++)
	{
		cout << "name: " << her[i].name << " age: " << her[i].age << "sex: " << her[i].sex << endl;
	}

	return 0;
}
