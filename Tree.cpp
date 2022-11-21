#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

typedef struct nod
{
    int data;
    struct nod *left,*right;
    
}bnode;

class tree
{
    public:
    bnode *root;
    int num;
    tree(int n)
    {
        root = NULL;
        num = n;
    }
    bnode* cr_bn()
    {
        bnode *t = (bnode*)malloc(sizeof(bnode));
        t->left= NULL;
        t->right= NULL;
        return t;
    }
    void Create_BST()
    {
        bnode *t,*t1,*t2;
        int tem;
        int c=0;
        while(num>0)
        {
            c=0;
            t1 = root;
            t = cr_bn();
            cin>>t->data;
            tem = t->data;
            if(root == NULL)
            {
                root =t;
                //print_BinT(root);
                //printf("\n");
            }
            else 
            {
                while(c==0)
                {
                    if(t1->left==NULL && t1->data>tem)
                    {
                        t1->left = t;
                        c=1;
                        //print_BinT(root);
                        //printf("\n");
                    }
                    else if(t1->right == NULL && t1->data<tem)
                    {
                        t1->right = t;
                        c = 1;
                        //print_BinT(root);
                        //printf("\n");
                    }
                    else if(t1->left != NULL && t1->data>tem)
                    {
                        t1 = t1->left;
                    }
                    else if(t1->right!=NULL && t1->data<tem)
                    {
                        t1 = t1->right;
                    }
                }
            }
            num--;
        }
    }
    void Create_AVL()
    {
        bnode *t,*t1,*t2;
        int tem;
        int c=0;
        while(num>0)
        {
            c=0;
            t1 = root;
            t = cr_bn();
            cin>>t->data;
            tem = t->data;
            if(t1 == NULL)
            {
                root =t;
                print_BinT(root);
                printf("\n");
            }
            else 
            {
                while(c==0)
                {
                    if(t1->left==NULL && t1->data>tem)
                    {
                        t1->left = t;
                        c=1;
                        print_BinT(root);
                        printf("\n");
                    }
                    else if(t1->right == NULL && t1->data<tem)
                    {
                        t1->right = t;
                        c = 1;
                        print_BinT(root);
                        printf("\n");
                    }
                    else if(t1->left != NULL && t1->data>tem)
                    {
                        t1 = t1->left;
                    }
                    else if(t1->right!=NULL && t1->data<tem)
                    {
                        t1 = t1->right;
                    }
                    
                }
            }
            num--;
        }
    }
    static void print_tree(bnode* r,int c,int k,int n)
    {
        if(r == NULL)
            return;
        cout<<'['<<r->data<<']';
        c++;
        if(k == 0 || pow(n,k) == c)
        {
            cout<<'\n';
            k++;
        }
        cout<<'['<<r->left->data<<']';
        cout<<'['<<r->right->data<<']';
        print_tree(r->left,c,k,n);
        print_tree(r->right,c,k,n);
    }
    static void print_BinT(bnode* m)
    {
        if(m == NULL)
            return;
        printf("[%d %d %d]",m->data,(m->left!=NULL)?m->left->data:-1,(m->right!=NULL)?m->right->data:-1);
        print_BinT(m->left);
        print_BinT(m->right);
    }
};

int main()
{
    int n;
    cout<<"Enter the Number of Elements : \n";
    scanf("%d",&n);
    tree tree(n);
    tree.Create_BST();
    //avl.Create_AVL();
    //avl.print_tree();
    tree.print_BinT(tree.root);
    //tree.printt(avl.root);
    printf("\n");
    //avl.print_tree(avl.root,0,0,2);
}

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
