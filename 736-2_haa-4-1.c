#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *prev;
} node;

typedef node* list;
typedef enum {false,true} bool;

list head=NULL;

int init(list *root) {
	*root=NULL;
	return 1;
}

int destroy(list *root) {
	list a;
	a=*root;
	while(a != NULL)
	{
		*root = a -> prev;
		free (a);
		a = *root;
	}
	return 1;	
}

bool isEmpty(list root) {
	if (root == NULL) {
		printf("true\n");
		return true;
	}
	else {
		printf("false\n");
		return false;
	}
}

int push(list *lst, int data) {
	list tmp = malloc(sizeof(node));
	tmp -> value = data;
	tmp -> prev = (*lst);
	(*lst) = tmp;
	return 1;
}

int pop(list *lst) {
	list x = (*lst);
	(*lst) = ((*lst) -> prev);
	int d = x -> value;
	free(x);
	return d;
}

int por(list *lst) {
        list x = (*lst);
        (*lst) = ((*lst) -> prev);
        free(x);
        return 1;
}

int print(list *lst) {
	while ((*lst) != NULL) {
		printf ("%d ", (*lst) -> value);
		lst = &((*lst) -> prev);
	}
	return 1;
}

int top(list *lst) {
	 printf ("%d ", head -> value);
	return 1;	
}
int  main () {
	int i, n,b,k;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &k);
		push(&head,k);
	}
	print(&head);
	printf("\n");

	pop(&head);
	print(&head);
	printf("\n");	

	scanf("%d", &b);
	push(&head,b);
	print(&head);
	printf("\n");

	top(&head);
	printf("\n");

	destroy(&head);
	
	isEmpty(head);
	
	return 0;
}
	
	
	
	
 
