#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>

//list是双向循环链表
void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++){
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead){
			node = node->_Next;

			//node->_Prev  前一个结点指针域 证明双向
		}
	}

}

/*
3.6.4.1 list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void printList(list<int>&L)
{
	for (list<int>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	// 300 200 100 10 20 30
	printList(L1);


	L1.pop_back();
	// 300 200 100 10 20 
	printList(L1);

	L1.pop_front();
	// 200 100 10 20
	printList(L1);

	L1.insert(L1.begin(), 1000);
	// 1000 200 100 10 20
	printList(L1);

	L1.erase(L1.begin());
	// 200 100 10 20
	printList(L1);

	L1.push_back(100);
	L1.push_back(100);
	L1.push_back(100);
	L1.remove(100); //删除所有100
	// 200  10 20 
	printList(L1);

}

/*
3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
*/

void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	if (!L1.empty())
	{
		cout << "L1不为空，大小：" << L1.size() << endl;
	}
	else
	{
		cout << "L1为空" << endl;
	}
	// 300 200 100 10 20 30
	cout << "front = " << L1.front() << endl;
	cout << "back = " << L1.back() << endl;
}

/*
3.6.4.6 list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/

void test04()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	cout << "反转链表前：" << endl;
	printList(L1);

	L1.reverse();

	cout << "反转链表后：" << endl;
	printList(L1);
}

bool myCompare(int v1,int v2)
{
	return v1 > v2;
}

//排序
void test05()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	cout << "排序前： " << endl;
	printList(L1);

	//全局sort函数 支持随机访问迭代器的容器才可以用
	//不支持随机访问的迭代器的容器，内部会提供 成员函数的算法

	list<int>::iterator it = L1.begin();
	//it = it + 1; list容器迭代器不支持随机访问


	//sort(L1.begin(), L1.end());
	L1.sort();
	L1.sort(myCompare);
	cout << "排序后： " << endl;
	printList(L1);
}

//对自定义数据类型排序
class Person
{
public:

	Person(string name, int age , int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	//重载 ==
	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name  && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};


bool comparePerson(Person &p1 , Person &p2)
{
	//按年龄 升序  如果年龄相同  按照身高  降序

	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

void test06()
{
	list<Person>L;

	Person p1("张飞", 20, 180);
	Person p2("刘备", 21, 177);
	Person p3("关羽", 19, 178);
	Person p4("赵云", 18, 170);
	Person p5("吕布", 22, 190);
	Person p6("貂蝉", 22, 160);
	Person p7("黄月英", 22, 165);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	L.sort(comparePerson);

	for (list<Person>::iterator it = L.begin(); it != L.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： "<< it->m_Height << endl;
	}


	//删除黄月英
	L.remove(p7);
	cout << "删除黄月英后遍历结果为：" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
	}

}

int main(){

	test06();

	system("pause");
	return EXIT_SUCCESS;
}