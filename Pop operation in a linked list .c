#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d —> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void reverse(struct Node** head)
{
	struct Node* previous = NULL;
	struct Node* current = *head;

	while (current != NULL)
	{
		struct Node* next = current->next;

		current->next = previous;

		previous = current;
		current = next;
	}

	*head = previous;
}

int main(void)
{
	int keys[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node* head = NULL;
	for (int i = n - 1; i >=0; i--) {
		push(&head, keys[i]);
	}

	reverse(&head);

	printList(head);

	return 0;
}
