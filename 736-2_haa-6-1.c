#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;        
	int key;       
	struct node *left;
	struct node *right;
} node;

typedef node *tree;

typedef struct snode 
{
	tree actual;       
	struct snode* next;
} snode;

typedef snode* queue;

int init(tree* root)
{
	*root = NULL;       
	return 1;
}

int initq(queue* top)
{
	*top = NULL;       
	return 1;
}

int isEmpty(queue top)
{
	if (top == NULL) 
	{
		return 1;
	}       
	else
	{
		return 0;
	}
}

int push(queue* top, tree root )
{
	queue tmp =  malloc(sizeof(snode));       
	(tmp -> actual) = root;
	(tmp -> next) = NULL;
	if ((*top) == NULL)
	{
		(*top) = tmp;
	}
	else
	{    
		while ((*top)->next != NULL)       
		{
			top = &((*top) -> next);
		}
		(*top) -> next = tmp;
	}
	return 1;
}

tree pop( queue *top )
{       
	queue tmp = (*top);       
	tree actual = tmp -> actual;
	(*top) = (*top) -> next;
	free( tmp );
	return actual;
}

int add(tree* root, int key, int data)
{
	tree tmp = malloc(sizeof(node));       
	tmp -> data = data;
	tmp -> key = key;
	tmp -> left = NULL;
	tmp -> right = NULL;
	if ((*root) == NULL)
	{
		*root = tmp;
		return 1;        
	}
	while ( 1 )
	{
		if ((*root) -> key < key)
		{
			if ((*root) -> right == NULL)
			{
				(*root) -> right = tmp;
                                return 1;
                        }
                        root=&((*root) -> right);
                }
                else if ((*root) -> key > key)
                {
                        if ((*root) -> left == NULL)
                        {
                                (*root) -> left = tmp;
                                return 1;
                        }
                        root=&((*root) -> left);
                }
                else return 1;
        }
}

int width(tree lst)
{
        queue w;
        tree tmp = lst;
        initq(&w);
        printf("%d ", tmp -> data);
        if((tmp -> right != NULL) || (tmp -> left != NULL))
 	{
        	do{
                	if (tmp -> left != NULL)
                        	push(&w, tmp -> left);
                	if (tmp -> right != NULL)
                       		push(&w, tmp -> right);
                	if (isEmpty(w) != 1)
                        	tmp = pop(&w);
                	printf("%d ", tmp -> data);
        	} while ( (isEmpty(w) != 1) || (tmp->right!=NULL) || (tmp->left!=NULL));
	}        
	return 1;
}

int main()
{
        tree m,tmp;
        init(&m);
        int i,n, val, k;
        scanf("%d", &n);
        for (i=0; i<n; i++)
        {
                scanf("%d %d", &k, &val);
                add(&m, k, val);
        }
        width(m);
        printf("\n");
        return 0;

}



