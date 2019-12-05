#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Person
{
public:

	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name; //姓名
	int m_Score; //平均分数
};


void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		//10个评委给每个人打分
		deque<int>d; //存放10个评委的打分
		for (int i = 0; i < 10;i++)
		{
			//随机分  60 ~100
			int random = rand() % 41 + 60;
			d.push_back(random);
		}

		//cout << "姓名：" << it->m_Name << " 具体打分： " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//排序
		sort(d.begin(), d.end());

		//去除最高分 最低分
		d.pop_back();   //最高
		d.pop_front();  //最低

		//求总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		//将分数 赋值给对应的选手
		it->m_Score = avg;
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 分数： " << it->m_Score << endl;
	}
}

int main(){

	//随机数种子
	srand((unsigned int)time(NULL));

	//准备存放选手的容器
	vector<Person>v;

	//创建5名选手
	createPerson(v);

	//打分
	setScore(v);

	//打印分数
	showScore(v);


	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 分数： " << it->m_Score << endl;
	//}

	system("pause");
	return EXIT_SUCCESS;
}