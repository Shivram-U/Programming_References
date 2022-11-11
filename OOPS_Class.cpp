// Access Specifiers and Inheritance in Class in C++
//CODE:
#include <iostream>
#include <stdlib.h>
using namespace std;

// Inheritance:
/*
    Public Inheritance:
                    Base Class Members => Derived Class Members
                    Public                  Public
                    Protected               Protected
                    Private                 Not Inherited
    Protected Inheritance:
                    Base Class Members => Derived Class Members
                    Public                  Protected
                    Protected               Protected
                    Private                 Not Inherited
    Private Inheritance:
                    Base Class Members => Derived Class Members
                    Public                  Private
                    Protected               Private
                    Private                 Not Inherited
*/
/*
Reference :
        1.  Polymorphism : https://forgetcode.com/cpp/715-cast-operator-overloading
                           https://www.geeksforgeeks.org/cpp-polymorphism/
*/

class temp                                            // Base Class
{
    public:
        int pub_i = 10,pub_j=20;
        void pub_print()
        {
            printf("\n%d %d",pub_i,pub_j);
        }    
    protected:
        int prot_i = 100,prot_j=200;
        void prot_print()
        { 
        printf("\n%d %d",prot_i,prot_j);
        }    
    private:
        int priv_i = 1000,priv_j=2000;
        void priv_print()
        {
          printf("\n%d %d",priv_i,priv_j);
        }    
};

class temp1:public temp                               // Public Inheritance                   
{
    public:
        int k = 300,l = 400;
        void pub_print1()
        {
            printf("\n$ %d %d",pub_i,pub_j);  
        }
        void prot_print1()
        {
            printf("\n$ %d %d",prot_i,prot_j);  
            prot_print();
        }
        void priv_print1()
        {
            //printf("\n $ %d %d",priv_i,priv_j);  
        }
};

class temp2:protected temp                          // Protected Inheritance
{
    public:
        int k = 300,l = 400;
        void pub_print1()
        {
            printf("\n$ %d %d",pub_i,pub_j);  
            pub_print();
        }
        void prot_print1()
        {
            printf("\n$ %d %d",prot_i,prot_j);  
            prot_print();
        }
        void priv_print1()
        {
            //printf("\n $ %d %d",priv_i,priv_j);  
        }
};

class temp3:private temp                            // Private Inheritance                          
{
    public:
        int k = 300,l = 400;
        void pub_print1()
        {
            printf("\n$ %d %d",pub_i,pub_j);  
        }
        void prot_print1()
        {
            printf("\n$ %d %d",prot_i,prot_j);  
            prot_print();
        }
        void priv_print1()
        {
            //printf("\n $ %d %d",priv_i,priv_j);  
        }
};

int main()                                          // Main Function
{
// Normal Class
    temp *tp,t;
    tp = &t;
    // public:
    printf("%d %d\n",tp->pub_i,tp->pub_j);
        tp->pub_print();
    // Protected:
        //printf("%d %d\n",tp->prot_i,tp->prot_j);
        //tp->prot_print();
    // Private
        //printf("%d %d\n",tp->priv_i,tp->priv_j);
        //tp->priv_print();
       
// Inheritance Concept:
  //Public Inheritance Member Access:
    temp1 *tp1,t1;
    tp1 = &t1;
    printf("\n%d",tp1->pub_i);
    printf("%d",tp1->pub_j);
    tp1->pub_print();
    tp1->pub_print1();
   
    //printf("%d\n",t->prot_i);
    //printf("%d\n",t->prot_j);
    //t->prot_print();
    tp1->prot_print1();
   
    //printf("%d\n",t->priv_i);
    //printf("%d\n",t->priv_j);
    //t->priv_print();
    //tp1->priv_print1();
   
  //Protected Inheritance Member Access:
    temp2 *tp2,t2;
    tp2 = &t2;
    //printf("\n%d",tp2->pub_i);
    //printf("%d",tp2->pub_j);
    //tp2->pub_print();
    tp2->pub_print1();
   
    //printf("%d\n",t->prot_i);
    //printf("%d\n",t->prot_j);
    //t->prot_print();
    tp2->prot_print1();
   
    //printf("%d\n",t->priv_i);
    //printf("%d\n",t->priv_j);
    //t->priv_print();
    //tp1->priv_print1();
   
   // For private Inheritance, none of the Members are inherited.
    printf("\n%d",tp1->k);
    printf("\n%d",tp1->l);
   
}
