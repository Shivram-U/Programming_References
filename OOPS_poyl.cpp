/*                                                        Polymorphism in C++  

Polymorphism:
                            Polymorphis means Many forms, IOn OOPs, a Entitiy can be represented and utilized in many Forms.
                            Entity => [functions,Operators]
   Types :
    1. Compile time Polymorphism:
                1. Operator Overloading
                        2. Function Overloading
                2. Run Time Polymorphism:
                    1. Function Overriding.

    Compile - Time Polymorphism:
        OverLoading:
            The Overloading ccan be performed with ?Respect totwo Scopes.
                    1. Global Scope.
                    2. Local Scope.

            Function Overloading:
                    The Function Overloading is done by,
                                        1. Argument Number Differentiation.
                                        2. Argument Type Differentiation.
                    
                    Types:
                                Based on Scope:
                                                    1. Local Scope.
                                                    2. Global Scope.
                                Based on Function type,
                                                    1.Constructor OL
                                                    2.Function OL
            Operator Overloading:
                The Operator Overloading is used to enable a Operator, to perform Operations, other than the Basic Operations.
                The Operator, which is Overloaded, does not loose the Basic Operation assigned to it, but, it accepts a new Operation, to perform.
                
                Example:
                        1.'+'
                -               > used for Mathematical Addition.
                                -> used for Concatenation of Strings.
                                
                In C++, The operator Overloading is performed, with only User-Defined Datatypes(Class,Struct,enum,Union) as Operands.
               
            T   he operator Overloading is basically a Compile-time Polymorphism.
       
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
                                            
Reference :
        1.  Polymorphism : https://forgetcode.com/cpp/715-cast-operator-overloading
                           https://www.geeksforgeeks.org/cpp-polymorphism/
*/

//CODE:
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int add_gs(int a,int b)
{
    cout<<"Global Scope Function"<<'\n';
    return a+b;
}

double add_gs(double a,double b)                        // Type Of arguments Differentiated Overloading
{
    cout<<"Global Scope Function"<<'\n';
    return a+b;
}

/*
float add_gs(float a,float b)               - Ambiguity Error
{
    cout<<"Global Scope Function"<<'\n';
    return a+b;
}*/

int add_gs(int a,int b,int c)                           // Number Of arguments Differentiated Overloading
{
    cout<<"Global Scope Function"<<'\n';
    return a+b+c;
}
int add_gs(int a,int b,int c,int d)
{
    cout<<"Global Scope Function"<<'\n';
    return a+b+c+d;
}

class temp
{
    public:
    int add_temp_Scope(int a,int b)      
    {
        cout<<"Class temp Scope Function"<<'\n';
        return a+b;
    }
    int add_temp_Scope(int a,int b,int c)
    {
        cout<<"Class temp Scope Function"<<'\n';
        return a+b+c;
    }
    int add_temp_Scope(int a,int b,int c,int d)      
    {
        cout<<"Class temp Scope Function"<<'\n';
        return a+b+c+d;
    }
};

class temp2
{
    int a,b,c,d;
    public:
    temp2(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    temp2(int a,int b,int c,int d)                                          // Constructor Overloading, Compiler time Polymorphism.
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    temp2(){}
    void operator ++()                                                 // Prefix Increment
    {
        printf("++ Operator Overloaded inside the Class temp2 Scope\n");
        this->a++;
        this->b++;
        this->c++;
        //return this->a+a;
    }
    void operator ++(int a)                                                 // Postfix Increment
    {
        printf("++ Operator Overloaded inside the Class temp2 Scope\n");
        this->a++;
        this->b++;
        this->c++;
        //return this->a+a;
    }
    void operator +()                                                   // Cannot be Called
    {
        printf("+ Operator Overloaded inside the Class temp2 Scope\n");
        //return this->a+a;
    }
    void operator +(int a)
    {
        printf("+ Operator Overloaded inside the Class temp2 Scope\n");
        this->a+=a;
        this->b+=a;
        this->c+=a;
        //return this->a+a;
    }
    temp2 operator +(temp2 b)
    {
        temp2 t;
        t.a = this->a+b.a;
        t.b = this->b+b.b;
        t.c = this->c+b.c;
        return t;
    }
    void print()
    {
        cout<<a<<' ' <<b<<' '<<c<<'\n';
    }
};

int main()
{
    temp t;
    
    // Global Scope Function Overloading
    cout<<add_gs(10,10)<<'\n';
    cout<<add_gs(19.423,15.554)<<'\n';
    cout<<add_gs(10,10,10)<<'\n';
    cout<<add_gs(10,10,10,10)<<"\n\n";
    
    //Class Scope Function Overloading
    cout<<t.add_temp_Scope(10,10)<<'\n';
    cout<<t.add_temp_Scope(10,10,10)<<'\n';
    cout<<t.add_temp_Scope(10,10,10,10)<<'\n';
    
    temp2 t1(10,100,1000),t2(20,200,2000);
    temp2 t3 = t1+t2;
    t3.print();
    t1+5; t2+5;
    t1.print();
    t2.print();
    ++t1; ++t2;
    t1.print();
    t2.print();
    t1++; t2++;
    t1.print();
    t2.print();
    //t1+;                                          -- ERROR - Since the Operator '+' is a Binary Operator, Invalid Syntax.
    
}
