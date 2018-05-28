#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	int key;
	struct node *left;
	struct node *right;
} node;

typedef node* tree;

int init(tree* root)
{
	*root = NULL;
	return 1;
}

int add(tree* root, int key, int value)
{
	tree tmp = malloc(sizeof(node));
	tmp -> value = value ;
	tmp -> key = key;
	tmp -> left = NULL;
	tmp -> right = NULL;
	if ((*root) == NULL)
	{
		*root = tmp;
		return 1;
	}
	else while ( 1 )
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

int find(tree* root, int key)
{
	int level = 0;
	while ( 1 )
	{
		if ((*root) == NULL)
		{
			printf("-1\n");
			return -1;
		}
		if ((*root) -> key == key)
		{
			printf("%d %d\n", level, (*root) -> value);
			return 1;
		}
		else if ((*root) -> key < key)
		{
			level=level+1;
			root=&((*root) -> right);
		}
		else if ((*root) -> key > key)
		{
			level = level + 1;
			root=&((*root) -> left);
		}
	}
}
int main()
{
	tree r;
	init(&r);
	int i, n, dat, k, a, b, c;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d %d", &k, &dat);
		add(&r, k, dat);
	}
	scanf("%d %d %d", &a, &b, &c);
	find(&r, a);
	find(&r, b);
	find(&r, c);
	return 0;
}
