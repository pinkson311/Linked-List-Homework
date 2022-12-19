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

void moveNode(struct Node** destRef, struct Node** sourceRef)
{
	if (*sourceRef == NULL) {
		return;
	}

	struct Node* newNode = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	newNode->next = *destRef;
	*destRef = newNode;
}

void rearrange(struct Node* head)
{
	if (head == NULL) {
		return;
	}
	struct Node* odd = head;
	struct Node *even = NULL, *prev = NULL;

	while (odd && odd->next)
	{
		moveNode(&even, &(odd->next));

		prev = odd;
		odd = odd->next;
	}

	if (odd) {
		odd->next = even;
	}
	else {
		prev->next = even;
	}
}

int main(void)
{
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node* head = NULL;
	for (int i = n-1; i >= 0; i--) {
		push(&head, keys[i]);
	}

	printf("Before: ");
	printList(head);

	rearrange(head);

	printf("After: ");
	printList(head);

	return 0;
}
