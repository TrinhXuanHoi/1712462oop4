#include"LinkedList.h"

void main()
{
	srand(1234);
	LinkedList l;
	for (int i = 0; i<10; ++i)
	{
		if (rand() % 2 == 0)
		{
			l.AddHead(rand() % 1001);
		}
		else
		{
			l.AddTail(rand() % 1001);
		}
	}
	cout << l << endl;
	l.RemoveHead();
	l.RemoveTail();
	l[-1] = 9000;
	l[4] = 2000;
	l[100] = 10000;
	cout << l << endl;
	system("pause");
}