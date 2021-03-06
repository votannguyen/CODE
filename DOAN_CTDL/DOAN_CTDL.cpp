// DOAN_CTDL.cpp : Defines the entry point for the console application.
// Đồ Án.cpp : Defines the entry point for the console application.
#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"iostream"
#include<assert.h> 
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct List
{
	struct Node *PHead;
	struct Node *PTail;
};
// hàm tạo số ngẫu nhiên 
int Random(int n);
// nhập ngẫu nhiên 1 danh sách liên kết
void Input(List &L, int n);
// in danh sách liên kết 
void printList(struct Node *node);
// thêm Node vào đầu danh sách liên kết 
void push(struct Node** head_ref, int new_data);
int IsEmptyList(List &L);
int main()
{
	struct Node* a = NULL;
	int n;
	List L;
	printf_s("Nhap So Node Ban Muon Tao: ");
	scanf_s("%d", &n);
	Input(L, n);
	printList(a);
	getchar();
	return 0;
}
// hàm tạo số ngẫu nhiên 
int Random(int n)
{
	return rand() % (n + 100);
}

void Input(List &L, int n)
{
	//struct Node *res = NULL;
	struct Node *p = NULL;
	int x;
	srand((unsigned)(NULL));
	for (int i = 0; i<n; i++)
	{
		x = Random(n + 100);
		push(&p, x);
	}
	printf_s("Danh sach truoc khi sap xep:  \n");
	printf("\n");
	printList(p);
	printf("\n");
	printf("\n");
}

/* Hàm in các nút trong danh sách liên kết */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
		printf("%p", node);
		cout << endl;
	}
	printf("\n");
}
/* Hàm chèn nút vào đầu của danh sách liên kết */
void push(struct Node** head_ref, int new_data)
{
	/* Cấp phát Nút */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));// malloc là hàm cấp phát bộ nhớ động trong C
	      															   //Khi sử dụng malloc phải tính toán kích thước vùng 
	                                                                   //nhớ cần cấp phát trước rồi truyền vào cho malloc
	/* Đưa dữ liệu vào */
	new_node->data = new_data; // gan du lieu của new_data vào cho dữ liệu của new_Node vừa tạo.

	/* Dưa danh sách liên kết cũ vào nút mới */
	new_node->next = (*head_ref); // gán địa chỉ của phần tử đầu trong danh sách bằng địa chỉ của Node mới 

	/* Di chuyển đầu con trỏ đến nút mới */
	(*head_ref) = new_node; // di chuyển con trỏ đến phần tử đầu danh sách nghĩa là Node mới được thêm vào 
}
// sắp xếp danh sách liên kết bằng cách thay đổi con trỏ tiếp theo (không phải thay đổi dữ liệu)
int IsEmptyList(List &L)
{
	if (L.PHead == NULL)
		return 1;
	return 0;
}
