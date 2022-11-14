#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int operator +(int a,int b)
{
    cout<<" '+' Operator Overloaded inthe Global Scope "<<'\n';    
    return a+b;
}

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
}
