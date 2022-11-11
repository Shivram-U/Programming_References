#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Expression Tree CODE:
/*
                                The Expression tree is a tree formed by storing the Operaors and operands in the Tree Nodes.
                                The Postfix,Infix and Prefix Traversals of the tree can be used to form the appropriate Versions of the Expression.

Test Cases:
    1.ab*e+er*+ere+++                                               -Output Validated
                ((((a*b)+e)+(e*r))+(e+(r+e)))
                a b * e + e r * + e r e + + + 
                + + + * a b e * e r + e + r  e
    2.ab*e+er*+ere+++gt++rth++*                                     -Output Validated
                ((((((a*b)+e)+(e*r))+(e+(r+e)))+(g+t))*(r+(t+h)))
                a b * e + e r * + e r e + + + g t + + r t h + + * 
                * + + + + * a b e * e r + e + r e + g t + r + t h 
            
    3.ab+cde+**                                                     -Output Validated
                ((a+b)*(c*(d+e)))
                a b + c d e + * * 
                * + a b * c + d e 
References:
	1. https://www.web4college.com/converters/postfix-to-prefix-to-postfix.php
	2. https://www.web4college.com/converters/postfix-prefix-to-infix.php
*/

// Code:
struct Node                                                         // Struct Declaration
{
    char data;
    struct Node *left,*right;
};

int str_len(char* a)                                                // Length of the Char Array Function
{
    int i=0;
    while(a[i]!='\0')
        i++;
    return i;
}

int check_var(char a)                                               // Function to check whether the given character is a Alphabet or Number or not Both of them.
{
    if((a>=48 && a<=57) || (a<=90 && a>=65) || (a<=122 && a>=97))
        return 1;
    return 0;
}

struct Node* cr_n()                                                 // Node Creation Function
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->left = NULL;
    t->right = NULL;
    return t;
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

void printPostfix(struct Node* r)
{
    if(r == NULL)
        return;
    printPostfix(r->left);
    printPostfix(r->right);
    printf("%c",r->data);
}


void printPrefix(struct Node* a)
{
    if(a!=NULL)
    {
        printf("%c",a->data);
        printPrefix(a->left);
        printPrefix(a->right);
    }
}

void print_exp(struct Node* t,int ord)
{
    if(ord == 0)
    {
        printf("Infix Form   : ");
        printInfix(t);                                                  // Infix Representation of the Expression tree.
        printf("\n");
    }
    else if(ord == 1)
    {
        printf("Prefix Form  : ");
        printPrefix(t);                                                 // Prefix Representation of the Expression tree.
        printf("\n");
    }
    else
    {
        printf("Postfix Form : ");    
        printPostfix(t);                                                // Postfix Representation of the Expression tree.
        printf("\n");
    }
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


int main() 
{
    char a[100];
    //printf("Enter the Expression : ");
    scanf("%[^\n]",&a);               
    struct Node* exp = ConstructExpressionTree_from_PostFix(a);               // Construction of the Expression tree from the Char Array Expression.
    print_exp(exp,0);
    print_exp(exp,1);
    print_exp(exp,2);
}
