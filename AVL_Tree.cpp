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
4. 1.https://stackoverflow.com/questions/40365437/c-how-to-use-free-to-free-a-struct-in-memory
*/


typedef struct nod
{
    int data;
    struct nod *left,*right;
    
}bnode;

typedef struct nod1                                 // AVL tree Node
{
    int data,bf;
    struct nod1 *left,*right;
}abnode;


void print_AVL_T(abnode* m)                         // AVL tree data print
{
    if(m == NULL)
        return;
    printf("\n[[%d %d] [%d %d] [%d %d]]",m->data,m->bf,(m->left!=NULL)?m->left->data:-1,(m->left!=NULL)?m->left->bf:-10,(m->right!=NULL)?m->right->data:-1,(m->right!=NULL)?m->right->bf:-10);
    print_AVL_T(m->left);
    print_AVL_T(m->right);
}

void print_AVL_Struct(abnode* r,int &k,int &n)              // requires Multi threading Concept
{
    if( r!=NULL )
    {
        printf("%d ",r->data);
        if(k == n)
        {
            printf("[%d %d]\n",n,k);
            (k==0)?k=1:1;
            k*=2;
            n=0;
        }
        n++;
        print_AVL_Struct(r->left,k,n);
        print_AVL_Struct(r->right,k,n);
    }
}

abnode* Create_AVL_Node()                                    // AVL tree Node Creation
{
    abnode* t = (abnode*)malloc(sizeof(abnode));
    t->left = NULL;
    t->right = NULL;
    t->bf = 0;
    t->data = 0;
    return t;
}

void height(abnode* r,int* m,int k)                     // height of an AVL tree.
{
    if(r!=NULL)
    {
        if(k>=(*m))
            (*m) = k;
        height(r->left,m,k+1);
        height(r->right,m,k+1);
    }
}

void deall(abnode* t)                               // Memory Deallocation of the Nodes in the AVL tree
{
    if(t!=NULL)
    {
        deall(t->left);
        deall(t->right);
        free(t);
    }
}


void Balance_Upd(abnode* t)                             // Balance Factor of a AVL tree
{
    if(t == NULL)
        return;
    int h1=0,h2=0;
    if(t->left!=NULL)
        height(t->left,&h1,1);
    if(t->right!=NULL)
        height(t->right,&h2,1);
    t->bf = (h1-h2);
    Balance_Upd(t->left);
    Balance_Upd(t->right);
}

abnode* Balance_Check(abnode* n)                            // Balance Factor Checking for all the Node in the AVL tree.              
{
    abnode *t = n;
    if(n == NULL)
        return NULL;
    n->left = Balance_Check(n->left);
    n->right = Balance_Check(n->right);
    Balance_Upd(n);
    if(n->bf>1  || (n->bf)<-1)
    {
        if(n->bf == 2)
        { 
            if(n->right == NULL)
            {
                if(n->left->right == NULL)
                {
                    t = n->left;
                    n->left->right = n;
                    n->left = NULL;
                }
                else if(n->left->left == NULL) 
                {
                    t = n->left->right;
                    t->left= n->left;
                    n->left->right = NULL;
                    t->right = n;
                    n->left= NULL;
                }
            }
            else
            {
                if(n->left->right->left == NULL && n->left->right->left == NULL)
                {
                    t = n->left;
                    n->left = n->left->right;
                    t->right = n;
                }
                else
                {
                    t = n->left;
                    n->left = t->right;
                    n->left->left = t;
                    t = n->left;
                    n->left = n->left->right;
                    t->right = n;
                }
            }
            return t;
        }
        else if(n->bf == -2)
        {
            
            if(n->left == NULL)
            {
                if(n->right->left == NULL)
                {
                    t = n->right;
                    t->left = n;
                    n->right = NULL;
                }
                else if(n->right->right == NULL) 
                {
                    t = n->right->left;
                    t->right = n->right;
                    n->right->left = NULL;
                    t->left = n;
                    n->right= NULL;
                }
            }
            else
            {
                if(n->right->right->right == NULL)
                {
                
                	if(t->right->left->left == NULL)
                	{
     
                	    t = n->right->left->right;
               		    t->right = n->right;
               		    t->left = n->right->left;
               		    n->right->left->right = NULL;
                    	n->right = t;
                    }
                    else
                	{
                		t = n->right->left;
                		t->right = n->right;
                		n->right->left = NULL;
                		n->right = t;
                	}
                }
                t = n->right;
                n->right = n->right->left;
                t->left = n;
            }
        }
    }
    return t;
}


void AVL_Insert(abnode** r,int n)                               // Insertion on AVL tree.
{
    int c=0,tem;
    abnode *t,*t1,*root = *r;
    t = Create_AVL_Node();
    t->data = n;
    tem = t->data;
    if(root == NULL)
    {
        root =t;
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
                Balance_Upd(root);
                root = Balance_Check(root);
                Balance_Upd(root);
            }
            else if(t1->right == NULL && t1->data<tem)
            {
                t1->right = t;
                c = 1;
                Balance_Upd(root);
                root = Balance_Check(root);
                Balance_Upd(root);
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
    *r = root;   
}
 
int AVL_Delete(abnode** r,int a)
{
    abnode *t = *r,*t1 = *r,*t2 = NULL,*t3;
    int c=0;
    while(true)
    {
        if(t == NULL)
            return 0;
        if(t->data == a)
        {
            //printf("[[ %d %d ]]\n",t->data,t1->data);
            if(t->right == NULL)
            {
                if(t != t1)
                {
                    if(c == 0)
                    {
                        t1->left = t->left;
                    }
                    else
                    {
                        t1->right = t->right;
                    }
                }
                else
                {
                    *r = t->left;
                }
                free(t);
            }
            else
            {
                //printf("\n");
                //print_AVL_T(*r);
                t2 = t->right;
                t3 = t;
                while(t2->left!=NULL)
                {
                    t3 = t2;
                    t2 = t2->left;
                }
                if(t3!=t)
                {
                    t3->left = NULL;
                    t2->right = t->right;
                }
                else
                {
                    t3->right = NULL;
                }
                //else
                    //t3->right = NULL;
                    t2->left = t->left;
                //printf("{{%d %d %d }}\n",t2->data,t3->data,t1->data);
                
                if(t1 != t)
                {
                    if(c == 0)
                        t1->left = t2;
                    else
                        t1->right = t2;
                    free(t);
                }
                else
                {
                    (*r) = t2;
                }
            }
            Balance_Upd(*r);
            (*r) = Balance_Check(*r);
            return 1;
        }
        else
        {
            t1 = t;
            if(t->data>a)
            {
                t = t->left;
                c = 0;
            }
            else
            {
                t = t->right;
                c = 1;
            }
        }
    }
}

int main()
{
    int h = 0;
    abnode *root = NULL;
    int a[30];
    for(int i=0;i<30;i++)
    {
        a[i] = i+1;
    }
    
    // Insertion of elements in AVL Tree.
    for(int i=0;i<10;i++)
    {
        cout << "\nInsertion of Element "<<a[i];
        AVL_Insert(&root,a[i]);
        print_AVL_T(root);
        printf("\n");
    }
    
    // Height of AVL Tree Created.
    height(root,&h,0);
    printf("Tree height : %d\n\n",h);
    
    // Deletion of elements in AVL Tree.
    for(int i=0;i<10;i++)
    {
        cout << "\nDeletion of Element "<<a[i];
        AVL_Delete(&root,a[i]);
        print_AVL_T(root);
        printf("\n");
    }
    cout << "Tree completely deleted\n";
    /*
    abnode *root = NULL;
    int a[30];
    try
    {
        for(int i=0;i<15;i++)
        {
        	a[i] = i+1;
        }
        int a1[] = {21,2,4343,20,33,25};
        for(int i=0;i<15;i++)
        {
            AVL_insert(&root,a[i]);    
        }
        print_AVL_T(root);
        /*
        int n=0,k=0;
        //print_AVL_Struct(root,k,n);
        int h=0;                                // Zero Value assignment is required for Height Analysis.
        height(root,&h,0);
        printf("root Height : %d\n",h);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        printf("Deal Done");
    }*/
        //deall(root);
    printf("Deal Done");
}

