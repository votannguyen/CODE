// Đồ Án.cpp : Defines the entry point for the console application.
#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include"iostream"
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};

//typedef struct Node NODE;
struct List
{
	struct Node *PHead;
	struct Node *PTail;
};

int Random(int n);

void Input(List &L, int n);

void printList(struct Node *node);

void push(struct Node** head_ref, int new_data);

void MergeSort(struct Node** headRef);

struct Node* SortedMerge(struct Node* a, struct Node* b);

void PhanHoach(struct Node* source, struct Node** frontRef, struct Node** backRef);

int main()
{
	struct Node* res = NULL;
	struct Node* a = NULL;
	int n;
	List L;
	printf_s("Nhap So Node Ban Muon Tao: ");
	scanf_s("%d", &n);
	Input(L, n);

	return 0;
}

int Random(int n)
{
	return rand() % (n);
}

void Input(List &L, int n)
{
	struct Node *res = NULL;
	struct Node *p = NULL;
	int x;
	srand((unsigned)(NULL));
	for (int i = 0; i<n; i++)
	{
		/*scanf_s("%d", &x);*/
		x = Random(n+10);
		push(&p,x);
	}
	printf_s("Danh sach truoc khi sap xep:  \n");
	printf("\n");
	printList(p);
	printf("\n");
	printf("\n");
	MergeSort(&p);
	printf("\n");
	printf("Danh sach da sap xep bang Merge Sort: \n");
	printList(p);
	printf("\n");
}

/* Hàm in các nút trong danh sách liên kết */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		printf("%p \n", node->next);
		node = node->next;
	}
	printf("\n");
}

/* Hàm chèn nút vào đầu của danh sách liên kết */
void push(struct Node** head_ref, int new_data)
{
	/* Cấp phát Nút */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  
	/* malloc là hàm cấp phát bộ nhớ động trong C
	Khi sử dụng malloc phải tính toán kích thước
	vùng nhớ cần cấp phát trước rồi truyền vào cho malloc*/

	/* Đưa dữ liệu vào */
	new_node->data = new_data;

	/* Dưa danh sách liên kết cũ vào nút mới */
	new_node->next = (*head_ref);

	/* Di chuyển đầu con trỏ đến nút mới */
	(*head_ref) = new_node;
}


void PhanHoach(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
