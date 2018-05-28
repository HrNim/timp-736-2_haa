#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;
typedef enum {false,true} bool;

list head=NULL;
list tail=NULL;

int init(list *root) {
	*root=NULL;
	return 1;
}

int destroy(list *root) {
	list a;
	a=*root;
	while(a != NULL)
	{
		*root = a -> next;
		free (a);
		a = *root;
	}
	return 1;	
}

bool isEmpty(list root) {
	if (root == NULL) {
		return true;
	}
	else {
		return false;
	}
}

list find(list root, int data) {
	list tmp = root;
	while (tmp != NULL) {
		if ((tmp -> value) == data) {
			return tmp;
		}
		else {
			tmp = tmp -> next;
		}
	}
	return 0;
}

int append(list *lst, int data) {
	list tmp = malloc(sizeof(node));
	tmp -> value = data;
	tmp -> prev = (*lst);
	if ((*lst) == NULL) {
		head = tmp;
		tail = tmp;
	}
	else if ((*lst) == tail) {
		((*lst) -> next) = tmp;
		tmp -> next = NULL;
		tail = tmp;
	}
	else {
		tmp -> next = ((*lst) -> next);
		((*lst) -> next) -> prev = tmp;
		((*lst) -> next) = tmp;
	}
	return 1;
}

int prepend(list *lst, int data) {
	list tmp = malloc(sizeof(node));
	tmp -> value = data;
	tmp -> next = (*lst);
	if ((*lst) == NULL) {
                head = tmp;
                tail = tmp;
        }
	else if ((*lst) == head) {
		((*lst) -> prev) = tmp;
		tmp -> next = (*lst);
		head = tmp;
	}
	else {
		tmp -> next = (*lst);
		tmp -> prev = ((*lst) -> prev);
		((*lst) -> prev) -> next = tmp;
		(*lst) -> prev = tmp;
	}
	return 1;
}

int removea(list *lst) {
	list x = (*lst);
	if ((*lst) == head) {
		((*lst) -> next) -> prev = NULL;
		head = ((*lst) -> next);
		free(x);
	}
	else if ((*lst) == tail) {
		((*lst) -> prev) -> next = NULL;
		tail = ((*lst) -> prev);
		free (x);
	}
	else {
	((*lst) -> next) -> prev = ((*lst) -> prev);
	((*lst) -> prev) -> next = ((*lst) -> next);
	free((x));
	}
	return 1;
}

int print(list *lst) {
	while ((*lst) != NULL) {
		printf ("%d ", (*lst) -> value);
		lst = &((*lst) -> next);
	}
	return 1;
}

int main () {
	int n,b,k,m,i,c,d,e,f;
	scanf ("%d", &n);

	for (i=0; i<n; i++) {
		scanf("%d", &b);
		append(&tail, b);
	}

	print(&head);
	printf("\n");

	scanf ("%d", &k);
	list v = head;
	for (i=1;i<k;i++) {
		if (v == NULL) {
			break;
		}
		v = v -> next;
	}
	removea(&v);

	print(&head);	
	printf("\n");

	scanf ("%d", &m);
	v = head;
	while(v != NULL) {
		if(v -> value == m) {
			removea(&v);
			break;
		}
		v = v -> next;
	}
	print(&head);
	printf("\n");
	
	scanf ("%d %d", &f,&e);
	v = head;
	for (i=1;i<f;i++) {
                if (v == NULL) {
                        break;
                }
                v = v -> next;
    	}

	append(&v,e);
	print(&head);
	printf("\n");

	scanf("%d %d", &c,&d);
	v = head;
	for (i=1;i<c;i++) {
                if (v == NULL) {
                        break;
                }
                v = v -> next;
        }
	prepend(&v,d);
	print(&head);
	printf("\n");

	return 0;
}
	
	
	
	
 
