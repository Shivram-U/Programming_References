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
typedef struct nod1
{
    int data,bf;
    struct nod1 *left,*right;
    
}abnode;

class tree
{
    public:
    bnode *Broot;
    abnode *Aroot;
    int num;
    tree(int n)
    {
        Broot = NULL;
        Aroot = NULL;
        num = n;
    }
    bnode* cr_bn()
    {
        bnode *t = (bnode*)malloc(sizeof(bnode));
        t->left= NULL;
        t->right= NULL;
        return t;
    }
    abnode* cr_abn()
    {
        abnode *t = (abnode*)malloc(sizeof(abnode));
        t->data = -1;
        t->bf = 0;
        t->left= NULL;
        t->right= NULL;
        return t;
    }
    void Create_BST()                                                       // -- COMP
    {
        bnode *t,*t1,*t2;
        int tem;
        int c=0;
        while(num>0)
        {
            c=0;
            t1 = Broot;
            t = cr_bn();
            cin>>t->data;
            tem = t->data;
            if(Broot == NULL)
            {
                Broot =t;
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
    }                                                                       // --
    
    void Create_AVL()
    {
        abnode *t,*t1,*t2;
        int tem;
        int c=0;
        while(num>0)
        {
            c=0;
            t1 = Aroot;
            t = cr_abn();
            cin>>t->data;
            tem = t->data;
            if(t1 == NULL)
            {
                Aroot =t;
                print_ABinT(Aroot);
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
                        print_ABinT(Aroot);
                        printf("\n");
                    }
                    else if(t1->right == NULL && t1->data<tem)
                    {
                        t1->right = t;
                        c = 1;
                        print_ABinT(Aroot);
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
    static void print_ABinT(abnode* m)
    {
        if(m == NULL)
            return;
        printf("[[%d %d] [%d %d] [%d %d] ]",m->data,m->bf,(m->left!=NULL)?m->left->data:-1,(m->left!=NULL)?m->left->bf:-1,(m->right!=NULL)?m->right->data:-1,(m->right!=NULL)?m->right->bf:-1);
        print_ABinT(m->left);
        print_ABinT(m->right);
    }
};

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
