#include "LinkedList.h"



LinkedList::LinkedList()
{
	pHead = NULL;
	pHead = NULL;
	curN = 0;
}
LinkedList::~LinkedList(void)
{
}
Node * LinkedList::CreateNode(const int & n)
{
	Node* node = new Node;
	if (node) {
		node->info = n;
		node->pNext = NULL;
	}
	return node;
}

Node *LinkedList::AddHead(const int &n) {
	Node* node;
	node = CreateNode(n);// gia tri cua node can them 
	if (pHead == NULL) // xet danh sach rong chi can xet pHead vi cai dau k co thi cai cuoi khong co.
	{
		pHead = pTail = node;
	}
	else {
		node->pNext = pHead;// nối từ cái node cần thêm qua pHead (node->pHead->.....->pTail) để thằng node đứng đầu 
		pHead = node; // cập nhật lại pHead là node.
	}
	return pHead;
}

Node *LinkedList::AddTail(const int &n) {
	Node *node;
	node = CreateNode(n);// gia tri cua node can them.
	if (pTail == NULL) // xet danh sach rong chi can xet pHead vi cai dau k co thi cai cuoi khong co. 
	{
		pHead = pTail = node;
	}
	else 
	{
		pTail->pNext = node;// nối thằng pTail qua thằng node để node đứng cuối (pHead->.....->pTail->node). 
		pTail = node;// cập nhật lại pTail.
	}
	return pTail;
}

Node*LinkedList::RemoveHead() {
	Node*node;
	if (pHead == NULL) // danh sach rong
	{
		pHead = pTail = NULL;
	}
	else if (pHead == pTail) // danh sach co 1 phan tu 
	{
		delete pHead;
		pHead = pTail = NULL;
	}
	else {
		Node *temp = pHead;// gắn thằng head bằng 1 node temp
		pHead = pHead->pNext;// chuyển head qua vị trí kế tiếp 
		delete temp;// xóa temp
	}
	return pHead;
}
Node*LinkedList::RemoveTail() {
	Node*node;
	if (pHead == NULL) // danh sach rong
	{
		pHead = pTail = NULL;
	}
	else if (pHead == pTail) // danh sach co 1 phan tu 
	{
		delete pHead;
		pHead = pTail = NULL;
	}
	else {
		Node*temp = pHead;
		while (temp->pNext != pTail) 
		{
			temp = temp->pNext; // cho temp chạy tới phần tử trước tail.
		}
		delete pTail;// xóa tail
		pTail = temp;// cập nhật tail
		temp->pNext = NULL;
	}
	return pTail;
}

int & LinkedList::operator[](const int &i)
{
	 curN = 0;
	LinkedList l;
	if (i<0) return pHead->info;
	for (Node*p = l.pHead; p != NULL; p = p->pNext)
	{
		curN++;
		if (curN == i)
			return p->info;
	}
	return pTail->info;
}


ostream & operator<<(ostream & os, const LinkedList & ll)
{
	for (Node *node = ll.pHead; node != NULL; node = node->pNext) {
		os << node->info << ' ';
	}
	return os;
}
