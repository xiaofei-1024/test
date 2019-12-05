#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>
#include <string>

/*
3.5.3.1 queue���캯��
queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
queue(const queue &que);//�������캯��
3.5.3.2 queue��ȡ�������ɾ������
push(elem);//����β���Ԫ��
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��

3.5.3.3 queue��ֵ����
queue& operator=(const queue &que);//���صȺŲ�����
3.5.3.4 queue��С����
empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С
*/

class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age)
	{
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	queue<Person>q;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "size = " << q.size() << endl;

	//ֻҪ���в�Ϊ�գ��鿴��ͷ����β��ִ�г���
	while ( !q.empty())
	{
		cout << "��ͷ - ������ " << q.front().m_Name << " ���䣺 " << q.front().m_Age << endl;
	
		cout << "��β - ������ " << q.back().m_Name << " ���䣺 " << q.back().m_Age << endl;

		q.pop();
	}

	cout << "size = " << q.size() << endl;

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}