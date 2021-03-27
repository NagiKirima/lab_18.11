#include <iostream>
#include <list>
#include <queue>
#include <ctime>
#include <iterator>
#include "Pair.h"
using namespace std;
template <typename t>
void Makelist(list<t>& list, int size)
{
	for (int i = 0; i < size; i++)
		list.push_back(rand() % 100 + 1.0);
}
//overload for Pair (just a beauty)
void Makelist(list<Pair>& list, int size)
{
	for (int i = 0; i < size; i++)
	{
		Pair tmp(rand() % 50 + 1, rand() % 50 + 1.0);
		list.push_back(tmp);
	}
}
template <typename t>


void Showlist(list<t> list1)
{
	typename list<t> ::iterator iter = list1.begin(); //from stl-doc, "overload" iterator
	for (iter; iter != list1.end(); iter++)
		cout << *iter << "\t";
	cout << endl;
}
//overload for Pair (just a beauty)
void Showlist(list<Pair> list1) 
{
	list<Pair>::iterator iter = list1.begin();
	for (iter; iter != list1.end(); iter++)
		iter->Show(); cout << endl;
}

template <typename t>
t AVG(list <t> list1)
{
	t avg = 0;
	typename list<t> ::iterator iter = list1.begin();
	for (iter; iter != list1.end(); iter++)
		avg += *iter;
	return avg / list1.size();
}

//priority queue part
template <typename t>
void MakeQue(priority_queue<t>& q, int size) 
{
	for (int i = 0; i < size; i++)
		q.push(rand() % 50 + 1);
}
template <typename t>
void ShowQue(priority_queue<t> q) 
{
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}
template <typename t>
priority_queue<t> Delete_inRange(priority_queue<t> q, int left, int right) 
{
	vector<t> buffer;
	while (!q.empty()) 
	{
		buffer.push_back(q.top());
		q.pop();
	}
	
	buffer.erase(buffer.begin() + left, buffer.begin() + right);
	priority_queue<t> tmp;
	for (int i = 0; i < buffer.size(); i++)
		tmp.push(buffer[i]);
	return tmp;
}
template <typename t>
priority_queue<t> AddMax_Min(priority_queue<t> q) 
{
	vector<t> buffer;
	while (!q.empty())
	{
		buffer.push_back(q.top());
		q.pop();
	}
	int max = buffer[buffer.size() - 1];
	int min = buffer[0];
	cout << "Min:\t" << min << endl;
	cout << "Max:\t" << max << endl;
	for (int i = 0; i < buffer.size(); i++)
		buffer[i] += max + min;
	priority_queue<t> tmp;
	for (int i = 0; i < buffer.size(); i++)
		tmp.push(buffer[i]);
	return tmp;
}
int main() 
{
	srand(time(0));
	setlocale(LC_ALL,"rus");
	cout << "First Task:" << endl;
	cout << "Input list1 size" << endl;
	int size;
	cin >> size;
	list <double> list1;
	Makelist(list1, size);
	Showlist(list1);
	cout << "===============================================" << endl;
	cout << "Second Task:" << endl;
	cout << "Input list2 size" << endl;
	cin >> size;
	list <Pair> list2;
	Makelist(list2, size);
	Showlist(list2); 
	cout << "===============================================" << endl;
	cout << "Third Task:" << endl;
	cout << "Input list3 size" << endl;
	cin >> size;
	list <int> list3;
	Makelist(list3, size);
	Showlist(list3);
	int avg = AVG(list3);
	cout << "Average:\t" << avg << endl;
	list3.push_back(avg);
	Showlist(list3);
	cout << "===============================================" << endl;
	cout << "Fourth  Task:" << endl;
	size = 10;
	cout << "Size for priority_queue = " << size << " (*for example), " <<
		"erase range is: pos[4]->pos[7]" << endl;
	priority_queue <int> list4;
	MakeQue(list4, size);
	ShowQue(list4);
	list4 = Delete_inRange(list4, 4, 7);
	ShowQue(list4);
	cout << "===============================================" << endl;
	cout << "Fifth Task:" << endl;
	cout << "Size for priority_queue = " << size << " (*for example)" <<  endl;
	priority_queue <int> list5;
	MakeQue(list5, size);
	ShowQue(list5);
	list5 = AddMax_Min(list5);
	ShowQue(list5);
	cout << "===============================================" << endl;
}