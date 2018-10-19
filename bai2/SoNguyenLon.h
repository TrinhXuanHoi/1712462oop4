#include<iostream>
using namespace std;
#pragma once
struct Node {
	int info;
	Node *pNext;
};

class SoNguyenLon
{
private:

	Node * pHead;
	Node *pTail;
public:
	SoNguyenLon();
	SoNguyenLon(const int &n);
	~SoNguyenLon();
	static Node *CreateNode(const int& n);
	Node *AddHead(const int &n);
	Node* AddTail(const int &n);
	
	friend ostream& operator<<(ostream &os, const SoNguyenLon &snl);
};

