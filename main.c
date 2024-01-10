/*
 * A very simple Linked List implentation
 * 2024-01-09
 * */

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	struct Node *next_ptr;
	int value;
} Node;

Node *make_node(int value) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->next_ptr = NULL;
	n->value = value;
	return n;
}

Node* iter(Node* n) {
	return n->next_ptr;
}

void append(Node* head, int value) {
	Node *current = head;
	Node* prev;

	while (current != NULL) {
		prev = current;
		current = iter(current);
	}

	prev->next_ptr = make_node(value);
}

void print_list(Node* head) {
	Node* current = head;

	while(current != NULL) {
		printf("%d\n", current->value);
		current = iter(current);
	}
}

int slice(Node* head, int i) {
	int count;
	Node* n = head;

	for (count = 0; count < i; count++) {
		n = iter(n);
	}

	return n->value;
}

void deallocate(Node* head) {
	Node* next = head;
	Node* prev;

	while(next != NULL) {
		prev = next;
		next = iter(next);
		free(prev);
	}
}

int main() {
	Node *xs = make_node(10);
	append(xs, 20);
	append(xs, 5);
	append(xs, 100);
	print_list(xs);

	printf("\n");
	printf("%d\n", slice(xs, 2));
	
	deallocate(xs);

	return 0;
}
