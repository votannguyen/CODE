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
int Random(int n);
int main()
{
	long int n, i, num;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	cout << "\nEnter the number of data element to be sorted: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		num = Random(n + 10);

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
int Random(int n)
{
	return rand() % (n);
}


