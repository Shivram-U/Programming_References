// Expression tree:
CODE:*/
#include <iostream>
using namespace std;

//Expression Tree CODE:

struct Node
{
char data;
    struct Node *left,*right;
};

int str_len(char* a)
{
    int i=0;
    while(a[i]!='\0')
        i++;
    return i;
}

int check_var(char a)
{
    if((a>=48 && a<=57) || (a<=90 && a>=65) || (a<=122 && a>=97))
        return 1;
    return 0;
}

struct Node* cr_n()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->left = NULL;
    t->right = NULL;
    return t;
}

void print_arr(char* a,int l,int u)
{
    int i=l;
    while(i<u)
        printf("%c ",a[i++]);
    printf("||\n");
}

void shift(char* a,int i,int n)
{
    while(i<n-1)
    {
        a[i] = a[i+1];
        i++;
    }
}

void printInfix(struct Node* r)
{
    int c=0;
    if(r == NULL)
    {
        return;
    }
    if(!check_var(r->data) && r->left!=NULL)
    {
    printf("(");
    }
    printInfix(r->left);
    printf("%c",r->data);
    printInfix(r->right);
    if(!check_var(r->data) && c==0)
    printf(")");
}

struct Node* ConstructExpressionTree_from_PostFix(char* a)
{
    char var[100];
    struct Node* r = NULL,*t,*t1,**n_arr1,**n_arr2;
    n_arr1 = (struct Node**)malloc(8*10);
    n_arr2 = (struct Node**)malloc(8*10);
    int n = str_len(a),n1=0,n2=0,n3 = 0,c = 0;
    for(int i=0;i<n;i++)
    {
        c=0;
        print_arr(var,0,n1);
        if(r!=NULL)
        {
            printInfix(r);
            printf("\n");
            printf("YYTT");
            if(n2>0)
            {
            printInfix(n_arr1[0]);
            printf("{%c}",n_arr1[0]->data);
            }
            printf("\n");
        }
        print_arr(var,0,n1);
        if(check_var(a[i]))
        {
            var[n1++] = a[i];
        }
        else
        {
            t = cr_n();
            t->data = a[i];
            if(n1>1)
            {
                t->left = cr_n();
                t->left->data = var[n1-2];
                t->right = cr_n();
                t->right->data = var[n1-1];
                n1-=2;
                c = 0;
            }
            else if(n1>0)
            {
                if(n2>0)
                {
                t->left = cr_n();
                t->left->data = var[n1-1];
                }
                else
                {
                    t->right = cr_n();
                    t->right->data = var[n1-1];
                }
                n1--;
                c = 1;
            }
            else if(n2>0)
            {
                t->left = r;
                t->right = n_arr1[n2-1];
                n2--;
                r = t;
                c = 2;
            }
            if(r == NULL)
                r = t;
            else if(n2 == 0 && c!=2)
            {
                if(c == 1)
                {
                    t->left= r;
                    r = t;
                }
                else
                {
                    n_arr1[n2++] = t;
                }
            }
            else if(c!=2)
            {
                if(c == 1)
                {
                    t->right = n_arr1[n2-1];
                    n_arr1[n2-1] = t;
                }
                else
                {
                   
                }
            }
        }
    }
    return r;
}
/*
struct Node* constructExpressionTree(char* a)
{
    char var[100];
    struct Node* r = NULL,*t,*t1,**n_arr;
    n_arr = (struct Node**)malloc(8*10);
    int n = str_len(a),n1=0,n2=0,n3=0,i1=0,i2=0;
    for(int i=0;i<n;i++)
    {
        printInfix(r);
        printf("\n");
        //print_arr(var,0,n1);
        if(check_var(a[i]))
        {
            var[n1++] = a[i];
        }
        else
        {
            //printf("[ %d %d %d]\n",n1,n2,n3);
            t = cr_n();
            t->data = a[i];
            if(n1 == 0 && n3>0)
            {
                    t->left = r;
                    t->right = n_arr[0];
                    r =t;
                    n3--;
            }
            else
            {
            if(n1<2 && n>0)
            {
                if(r->left!=NULL)
                {
                    t->right = r;
                    t->left = cr_n();
                    t->left->data = var[n1-1];
                    r = t;
                   
                }
                else
                {
                t->right = cr_n();
                t->right->data = var[n1-1];
                }
                //shift(var,0,n1);
                n1--;
            }
            else if (n>0)
            {
                t->left = cr_n();
                t->right = cr_n();
                t->left->data = var[n1-2];
                t->right->data = var[n1-1];
                //shift(var,n1-1,n1);
                n1-=2;
                //shift(a,n1-1,n1);
            }
           
            if(r == NULL)
            {
                r = t;
            }
            else if(t->left == NULL)
            {
                t->left = r;
                r = t;
            }
            else
            {
                n_arr[n3++] = t;
            }
            }
            //printf("( %c %c)\n",t->data,t->right->data);
        }
        //printf("( %d %d %d %d)\n",i1,i2,n1,n2);
        //print_arr(var,0,n1);
        //printf("end\n");
    }
    return r;
   
}
*/


void printPostfix(struct Node* r)
{
    if(r == NULL)
        return;
    printPostfix(r->left);
    printPostfix(r->right);
    printf("%c ",r->data);
}


void printPrefix(struct Node* a)
{
    if(a!=NULL)
    {
        printf("%c ",a->data);
        printPrefix(a->left);
        printPrefix(a->right);
    }
}
int main() {
  char a[100];
  //printf("Enter the Expression : ");
  scanf("%[^\n]",&a);
  struct Node* exp = ConstructExpressionTree_from_PostFix(a);
  printInfix(exp);
  printf("\n");
  printPostfix(exp);
  printf("\n");
  printPrefix(exp);
}
//

/*
test cases:
1.ab*e+er*+ere+++                                               -Output Validated
            ((((a*b)+e)+(e*r))+(e+(r+e)))
            a b * e + e r * + e r e + + + 
            + + + * a b e * e r + e + r  e
2.ab*e+er*+ere+++gt++rth++*                                     -Output Validated
            ((((((a*b)+e)+(e*r))+(e+(r+e)))+(g+t))*(r+(t+h)))
            a b * e + e r * + e r e + + + g t + + r t h + + * 
            * + + + + * a b e * e r + e + r e + g t + r + t h 
            
3.ab+cde+**
            ((a+b)*(c*(d+e)))
            a b + c d e + * * 
            * + a b * c + d e 
*/

/*
References:
	1. https://www.web4college.com/converters/postfix-to-prefix-to-postfix.php
	2. https://www.web4college.com/converters/postfix-prefix-to-infix.php
*/
