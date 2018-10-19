#include "SoNguyenLon.h"



SoNguyenLon::SoNguyenLon()
{
	AddHead(0);
}
SoNguyenLon::SoNguyenLon(const int &n) {
	 int temp = n;
	 pHead = pTail = NULL;
	while (temp >= 1) {		
		AddHead(temp % 10);
		temp = temp / 10;	
	}
}

SoNguyenLon::~SoNguyenLon()
{
}

Node * SoNguyenLon::CreateNode(const int & n)
{
	Node* node = new Node;
	if (node == NULL) {
		cout << "khong du bo nho cap phat";
	}
	if (node) {
		node->info = n;
		node->pNext = NULL;
	}
	return node;
}

Node * SoNguyenLon::AddHead(const int &n)
{
	Node *node = new Node;
	node = CreateNode(n);
	if (pHead == NULL) 
	{
		pHead = pTail = node;// nếu danh sách rỗng
	}
	else {
		node->pNext = pHead;// cho node tham gia vào danh sách node->pHead->......->pTail.(thên vào đầu nên đứng trước pHead).
		pHead = node;// cập nhật lại pHead.
	}
	return pHead;
}

Node* SoNguyenLon::AddTail(const int &n) {
	Node *node = new Node;
	node = CreateNode(n);
	if (node == NULL) {
		cout << "khong du bo nho cap phat";
	}
	else if (pHead == NULL) {
		pHead = pTail = node;
	}
	else {
		pTail->pNext = node;
		pTail = node;
	}
	return pTail;
}
ostream & operator<<(ostream & os, const SoNguyenLon & snl)
{
	for (Node *p = snl.pHead;p!=NULL; p = p->pNext) {
		os << p->info;
}
	return os;
}
