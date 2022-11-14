#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*
int operator +(int a,int b)
{
    cout<<" '+' Operator Overloaded in the Global Scope "<<'\n';    
    return a+b;
}*/

/*
Operator Overloading:
                    The Operator Overloading, is a compile time Polymorphism, which is translated, at the Compile time itself.
                    
                    The Operator Overloading can be performed, with respect to particular Scopes.
                            
                    
                    Types of Operator:
                                        Athematic operations: + – * / %
                                        Logical operations:  && and ||
                                        Relational operations: == != >= <=
                                        Pointer operators: & and *
                                        Memory management operator: new, delete []
                                        
                            In Class Scope:
                                        Overloading Methodologies: 
                                                            1. Inside Class Scope (either using Scope resolution Operator or not).
                                                            2. using Member Function.
                
            Features:
                        1. The Operator is given a different Meaning, other than it's default,
                                hence   Returning values is not Compulsory
                                        No restriction in Process to be given.
                                
                                The above mentioned Features are restricted, to the Situation, in which the Operator is used.
Reference:
    1. https://stackoverflow.com/questions/58010917/scope-operator-in-operator-overloading#:~:text=If%20you%20define%20the%20operator,)%20%7B%20%2F%2F%20...%20%7D
*/

class temp
{
    public:
    int a,b,c;
    temp(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    temp(){}
    temp operator +(temp& t)                                                            // Operator Overloaded inside CLASS SCOPE.
    {
        cout<<"+ Operator Overloaded in 'temp' Scope to add Data Members of two Objects"<<'\n';
        temp t1;
        t1.a = this->a+t.a;
        t1.b = this->b+t.b;
        t1.c = this->c+t.c;
        return t1;
    }
    void operator +(int a)
    {
        cout<<"+ Operator Overloaded 'temp' Scope to display :"<<a<<'\n';
    }
    //int operator +()                                                              // Invalid, Since '+' is a Binary Operator.
    void print()
    {
        cout<<"a : "<<this->a<<" b : "<<this->b<<" c : "<<this->c<<'\n';
    }
};

class temp1
{
    public:
    int t[4];
    temp1(int a,int b,int c)
    {
        this->t[0] = a;
        this->t[1] = b;
        this->t[2] = c;
    }
    temp1(){}                                                                                // Default Constructor, if not Declared, nomral Object Declaration is not allowed.
    void print()
    {
        cout<<"t[0] : "<<this->t[0]<<" t[1] : "<<this->t[1]<<" t[2] : "<<this->t[2]<<'\n';
    }
    void operator +=(int a)
    {
        for(int i=0;i<3;i++)
            this->t[i]+=a;
    }
    void* operator new (size_t size)
    {
        return (void*)::new long int(20);                                           // Memory Management, NEW SCENARIO 
    }
    temp1 operator-(temp1&);
    friend temp1 operator +(temp1&,temp1&);
};

temp1 operator +(temp1 &t1,temp1 &t2)                                               // Operator overloaded using, friend function, takes one argument extra.
{
    temp1 te;
    for(int i=0;i<3;i++)    
        te.t[i] = t1.t[i]+t2.t[i];
    return te;
}

temp1 temp1::operator -(temp1 &t1)                                                  // access the Class Scope, without proper Provision is Unauthorized. // It also takes one argument less than friend Function method.
{
    temp1 te;
    for(int i=0;i<3;i++)    
        te.t[i] = this->t[i]-t1.t[i];
    return te;
}

int main()
{
    
    temp t1(10,100,1000),t2(1,2,3);
    temp t3 = t1+t2;
    t1+3;
    //t3+;                                                                          // Invalid Syntax.
    t1.print();
    t2.print();
    t3.print();
    //printf("[%d]",t3);
    
    // Overloading Methodologies:
    temp1 t11(9,8,7),t12(6,5,4);
    t11.print();
    t12.print();
    temp1 t13 = t11-t12;
    temp1 t14 = t11+t12;
    t13.print();
    t14.print();
    t13+=100;
    t13.print();
    int* a = (int*)new temp1();
    char* a1 = (char*)new temp1();
    char* a2 = (char*)new temp1();
    //printf("[%d]",sizeof(a));
    for(int i=0;i<50;i++)
    {
        a[i] = i;
        a1[i] = i+48;
        a2[i] = i+65;
        cout<<i<<' '<<a[i]<<' '<<a1[i]<<' '<<a2[i]<<'\n';
    }
    for(int i=0;i<240;i++)                                                        // Entire ASCII System
            printf("| %d %c|",i,i);
    printf("\n%d",'\n');
}
