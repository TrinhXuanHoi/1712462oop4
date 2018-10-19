#pragma once
#include<iostream>
#include<conio.h>
using namespace std;


struct Node {
	int info;
	Node *pNext;
};

class LinkedList
{
private:
	Node * pHead;
	Node* pTail;
	int curN;
public:
	LinkedList(void);
	~LinkedList(void);
	static Node* CreateNode(const int& n);
	Node* AddHead(const int& n);
	Node *AddTail(const int &n);
	Node* RemoveHead();
	Node* RemoveTail();
	friend ostream& operator<<(ostream& os, const LinkedList &ll);
	int& operator[](const int &n);
};

