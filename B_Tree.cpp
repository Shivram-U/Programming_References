#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

// B Tree:
/*

*/

typedef struct Bnode
{
    int data,deg,k=0;
    struct Bnode **keys;
    /*
        Array of Pointers is more prefrred than a pointer to the array of variables
    */
}bn;

bn* Create_BNode(int a,int d)
{
    bn* r = (bn*)malloc(sizeof(bn));
    r->data = a;
    r->deg = d;
    r->keys = NULL;
    return r;
}

void print_BT(bn *r)
{
    printf("%d:",r->data);
    for(int i=0;i<r->k;i++)
    {
        if(r->keys[i]!=NULL)
            printf("%d ",r->keys[i]->data);
        else
            printf("X ");
    } 
}

bn* BT_Insert(bn* r,int a,int d)
{
    if(r == NULL)
    {
        bn *t = Create_BNode(-1,d);
        t->keys = (bn**)malloc(8*(2*d-1));
        return t;
    }
    else
    {
        bn *t = Create_BNode(a,d);
        if(r->k+2 <= (2*r->deg - 1))
        {
            if(r->k%2==0)
            {
                r->keys[r->k++] = NULL;
                r->keys[r->k++] = t;
                r->keys[r->k++] = NULL;
            }
            else
            {
                r->keys[r->k++] = t;
                r->keys[r->k++] = NULL; 
            }
        }
    }
    return r;
}

bn* Create_B_Tree(int* arr,int n,int d)
{
    int i=0;
    bn* root = NULL;
    while(i<n)
    {
        root = BT_Insert(root,arr[i++],d);
    }
    return root;
}

void deal(bn *t)
{
	if(t!=NULL)
	{
	    for(int i=0;i<t->k;i++)
	    {
	        deal(t->keys[i]);
	    }
		free(t);
	}
}
int main()
{
    // <Check Run Algorithm>
    bn *root = NULL;
    int deg = 6,arr[100],num = 7;
    for(int i=0;i<num;i++)
    {
        arr[i] = i;
    }
    root = Create_B_Tree(arr,num,deg);
    print_BT(root);
    printf("[%d %d %d]",root->data,root->k,root->deg);
    deal(root);
    // <\Check Run Algorithm>
}
