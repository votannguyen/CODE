// Đồ Án.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "iostream"
#include <sys/timeb.h>
#include <time.h>

using namespace std;

struct node
{
	long int data;
	node *next;
};
node* NewNode(int d);
node* AddToList(node *tail, int data);
int Random(int a, int b);
int main()
{
	long int n, i, num, a,b;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	cout << "\n Nhap so luong phan tu can sap xep: ";
	cin >> n;
	cout << "Nhap khoang [a,b] tao cac node ngau nhien de sap xep \n";
	cout << " Nhap khoang ";
	cin >> a;
	cin >> b;
	for (i = 0; i < n; i++)
	{
		num = Random(a,b);

		tail = AddToList(tail, num);

		if (head == NULL)
			head = tail;
	}

	return 0;
}


//Tạo node mới
node* NewNode(int d)
{
	struct node *temp = new node;
	temp->data = d;
	temp->next = NULL;

	return temp;
}

// Hàm thêm dữ liệu đã cho vào cuối danh sách liên kết.
node* AddToList(node *tail, int data)
{
	struct node *newnode;
	newnode = NewNode(data);

	if (tail == NULL)
	{
		tail = newnode;
	}
	// If tail is not null assign newnode to the next of tail.
	// Nếu đuôi không null gán nút mới cho đuôi tiếp theo.
	else
	{
		tail->next = newnode;
		// Shift tail pointer to the added node.
		// Chuyển con trỏ đuôi sang nút đã thêm.
		tail = tail->next;
	}

	return tail;
}

int Random(int a, int b)
{
	return a + rand() % (b - a + 1);
}



