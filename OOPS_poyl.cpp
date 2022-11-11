// Polymorphism in C++
#include <iostream>
using namespace std;

// Polymorphism
/*
Polymorphis means Many forms, IOn OOPs, a Entitiy can be represented and utilized in many Forms.
        Entity => [functions,Operators]
   Types :
    1. Compile time Polymorphism:
                1. Operator Overloading
                        2. Function Overloading
                2. Run Time Polymorphism:
                1. Virtual Function(Overriding).
   OverLoading:
    The Overloading ccan be performed with ?Respect totwo Scopes.
                1. Global Scope.
                                2. Local Scope.
Operator Overloading:
The Operator Overloading is used to enable a Operator, to perform Operations, other than the Basic Operations.
                The Operator, which is Overloaded, does not loose the Basic Operation assigned to it, but, it accepts a new Operation, to perform.
Example:
          1.'+'
                -> used for Mathematical Addition.
                    -> used for Concatenation of Strings.
    In C++, The operator Overloading is performed, with only User-Defined Datatypes(Class,Struct,enum,Union) as Operands.
               
The operator Overloading is basically a Compile-time Polymorphism.
       
        Operator Overloading Provisions:
    All Operators can be Overloaded, except
            1.sizeof()
                        2.typeid
                        3.dot (.) Operator
                        4.Scope Resolution Operator(::)
                        5.ternary Operator
                     
Note:
1.Since, ternary Operator is out-of Option for Operator Overloading, hence only Unary and Binary Operators can be Overloaded.
                2.In C++, the OPERATOR OVERLOADING requires, atleast one of the operands to be USER-DEFINED DATATYPE.
3.Operator Overloading can be performed with,
                                            1.Assignment operator with class
                                            2.Conversion operator.
                                            3.Constructors
               
*/
// Access Specifiers and Inheritance in C++
//CODE:
#include <iostream>
using namespace std;

class temp
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

class temp1:public temp
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

class temp2:protected temp
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
class temp3:private temp
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

int main()
{
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
   
    // For private Inheritance, none of the Members inherited can be accessed, since they are inherited, private into the Derived Class.
    printf("\n%d",tp1->k);
    printf("\n%d",tp1->l);
   
}
Reference :
        1.  Polymorphism : https://forgetcode.com/cpp/715-cast-operator-overloading
                                       https://www.geeksforgeeks.org/cpp-polymorphism/
