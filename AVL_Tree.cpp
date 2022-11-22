#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
/*
Reference:
1. https://visualgo.net/en/bst?slide=3-1
2. https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
3. https://programmerbay.com/avl-tree-a-height-balancing-bst/
*/

typedef struct nod
{
    int data;
    struct nod *left,*right;
    
}bnode;

typedef struct nod1
{
    int data,bf;
    struct nod1 *left,*right;
}abnode;

abnode* cr_abn()
{
    abnode* t = (abnode*)malloc(sizeof(abnode));
    t->left = NULL;
    t->right = NULL;
    t->bf = 0;
    t->data = 0;
    return t;
}

void print_ABinT(abnode* m)
{
    if(m == NULL)
        return;
    printf("[[%d %d] [%d %d] [%d %d] ]\n",m->data,m->bf,(m->left!=NULL)?m->left->data:-1,(m->left!=NULL)?m->left->bf:-10,(m->right!=NULL)?m->right->data:-1,(m->right!=NULL)?m->right->bf:-10);
    print_ABinT(m->left);
    print_ABinT(m->right);
}

void height(abnode* r,int* m,int k)
{
    if(r == NULL)
        return;
    if(k>(*m))
        *m = k;
    height(r->left,m,k+1);
    height(r->right,m,k+1);
}

void Balance_Dat(abnode* t)
{
    if(t == NULL)
        return;
    int h1=0,h2=0;
    if(t->left!=NULL)
        height(t->left,&h1,1);
    if(t->right!=NULL)
        height(t->right,&h2,1);
    t->bf = (h1-h2);
    printf("[%d %d %d %d]\n",t->data,t->bf,h1,h2);
    Balance_Dat(t->left);
    Balance_Dat(t->right);
}

abnode* Balance_Check(abnode* n)
{
    if(n == NULL)
        return NULL;
    if(n->bf>1 || n->bf<-1 && (n->left==NULL || n->right==NULL))
    {
        abnode *t;
        if(n->bf == 2)
        {
            printf("case 1 : [%d %d]",n->data,n->left->data);
            if(n->left->right == NULL)
            {
                printf("[%d]\n",n->left->left->data);
                
                t = n->left;
                n->left->right = n;
                n->left = NULL;
                
            }
            else 
            {
                printf("[%d]\n",n->left->right->data);
                t = n->left->right;
                t->left= n->left;
                n->left->right = NULL;
                t->right = n;
                n->left= NULL;
            }
            return t;
        }
        else if(n->bf == -2)
        {
            printf("case 2 : [%d %d]\n",n->data,n->right->data);
            if(n->right->left == NULL)
            {
                t = n->right;
                n->right->left = n;
                n->right = NULL;
            }
            else 
            {
                t = n->right->left;
                t->left= n;
                t->right = n->right;
                n->right->left = NULL;
                n->right= NULL;
            }
            return t;
        }
    }
    n->left = Balance_Check(n->left);
    n->right = Balance_Check(n->right);
    return n;
}


void AVL_insert(abnode** r,int n)
{
    int c=0,tem;
    abnode *t,*t1,*root = *r;
    t = cr_abn();
    t->data = n;
    //cin>>t->data;
    tem = t->data;
    if(root == NULL)
    {
        *r =t;
        print_ABinT(root);
        printf("\n");
    }
    else 
    {
        t1 = root;
        while(c==0)
        {
            if(t1->left==NULL && t1->data>tem)
            {
                t1->left = t;
                c=1;
                Balance_Dat(root);
                root = Balance_Check(root);
                Balance_Dat(root);
                print_ABinT(root);
                //printf("\n");
            }
            else if(t1->right == NULL && t1->data<tem)
            {
                t1->right = t;
                c = 1;
                Balance_Dat(root);
                root = Balance_Check(root);
                Balance_Dat(root);
                print_ABinT(root);
                //printf("\n");
            }
            else if(t1->left != NULL && t1->data>tem)
            {
                t1 = t1 = t1->left;
            }
            else if(t1->right!=NULL && t1->data<tem)
            {
                t1 = t1->right;
            }
        }
    }   
    
}


int main()
{
    // Height Calculation of a Tree:
    /*
    abnode *root1 = NULL,*root2 = NULL;
    int a[] = {21,2,4343,20,33,25,213,322,1244,2232,123,3};
    int b[] = {21,2,4343,20,33,25,213,322,1244,123,3};
    for(int i=0;i<12;i++)
    {
        AVL_insert(&root1,a[i]);
    }
    for(int i=0;i<11;i++)
    {
        AVL_insert(&root2,b[i]);
    }
    print_ABinT(root1);
    int h1,h2;
    height(root1,&h1,0);
    height(root2,&h2,0);
    printf("root1 Height : %d\n",h1);
    printf("root2 Height : %d\n",h2);
    printf("\n");
    */
    abnode *root = NULL;
    int a[] = {21,2,4343,20,33,25,213,322,1244,2232,123,3};
    int a1[] = {21,2,4343,20,33,25};
    for(int i=0;i<12;i++)
    {
        AVL_insert(&root,a[i]);
        printf("\n\n\n\n");
    }
    print_ABinT(root);
    int h;
    height(root,&h,0);
    printf("root Height : %d\n",h);
}
/*
static void print_BinT(bnode* m)
{
    if(m == NULL)
        return;
    printf("[%d %d %d]",m->data,(m->left!=NULL)?m->left->data:-1,(m->right!=NULL)?m->right->data:-1);
    print_BinT(m->left);
    print_BinT(m->right);
}





int main()
{
    int n;
    //cout<<"Enter the Number of Elements : \n";
    scanf("%d",&n);
    tree tree(n);
    tree.Create_AVL();
    //tree.Create_AVL();
    //avl.print_tree();
    //tree.print_BinT(tree.root);
    tree.print_ABinT(tree.Aroot);
    printf("\n");
    ////avl.print_tree(avl.root,0,0,2);
}*/
/*
Test Cases:
BST:
15
10
6
12
5
7
11
14
3
44
13
123
23123
1232
22
23124
*/
