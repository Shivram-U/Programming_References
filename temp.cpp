	194634-478170-655578-712910-630113-543719-485716-705705
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define temp Arith_OP_OL
#define temp1 Relat_OP_OL
#define temp2 Log_OP_OL
#define temp3 Ass_OP_OL
#define temp4 Spec_OP_OL
using namespace std;

// Type Conversion Operator Overloading
// ostream istream
//Bitwise operator
// typecast operator
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
        
        SYNTAX:
                       returnType operator symbol (arguments) 
                       {
                            … .. …
                       } 
Reference:
    1. https://stackoverflow.com/questions/58010917/scope-operator-in-operator-overloading#:~:text=If%20you%20define%20the%20operator,)%20%7B%20%2F%2F%20...%20%7D
    2.Types of Operators:
        https://www.geeksforgeeks.org/operators-in-cpp/
    2. Diferent types of Operaqtors Voerload:
        https://www.datatrained.com/post/types-of-operator-overloading-in-c/?utm_source=rss&utm_medium=rss&utm_campaign=types-of-operator-overloading-in-c
*/



class Arith_OP_OL                                                                                           // Arithmetic Operators Overloading
{
    public:
    int t[10];
    temp(int a,int b,int c)
    {
        this->t[0] = a;
        this->t[1] = b;
        this->t[2] = c;
    }
    temp(){}
    
    void print()
    {
        cout<<"t[0] : "<<this->t[0]<<" t[1] : "<<this->t[1]<<" t[2] : "<<this->t[2]<<'\n';
    }
    
    void operator ++()
    {
        cout<<"++ - Unary Operator Overloaded \n";
        this->t[0]++;
        this->t[1]++;
        this->t[2]++;
    }
    
    temp operator +(temp& t)                                                            // Operator Overloaded inside CLASS SCOPE.
    {
        cout<<"+ - Binary Operator Overloaded in 'temp' Scope to add Data Members of two Objects"<<'\n';
        temp t1;
        t1.t[0] = this->t[0]+t.t[0];
        t1.t[1] = this->t[1]+t.t[1];
        t1.t[2] = this->t[2]+t.t[2];
        return t1;
    }
    void operator +(int a)                                                          // Both the operator Overloading are overlodade, with the kind of parameters.
    {
        cout<<"+ - Binary Operator Overloaded 'temp' Scope to display :"<<a<<'\n';
    }
    //int operator +()                                                              // Invalid, Since '+' is a Binary Operator.
   
    temp operator/(temp&);
    friend temp operator *(temp&,temp&);
};

temp operator *(temp &t1,temp &t2)                                               // Operator overloaded using, friend function, takes one argument extra.
{
    cout<<"+ Operator overloaded in class 'temp' Scope\n";
    temp te;
    for(int i=0;i<3;i++)    
        te.t[i] = t1.t[i]*t2.t[i];
    return te;
}

temp temp::operator /(temp &t1)                                                  // access the Class Scope, without proper Provision is Unauthorized. // It also takes one argument less than friend Function method.
{
    cout<<"- Operator overloaded in class 'temp' Scope\n";
    temp te;
    for(int i=0;i<3;i++)    
        te.t[i] = this->t[i]/t1.t[i];
    return te;
}


class Relat_OP_OL                                                                                           // Relational Operator Overloading
{
    public :
    int main;
    int t[4];
    temp1(int a,int b,int c)
    {
        main = a+b+c;
        t[0] = a;
        t[1] = b;
        t[2] = c;
    }
    
    bool operator <(int a)
    {
        cout<<"'<' operator is overloaded in class 'temp1'\n";
        if(this->main<a)
            return true;
        else
            return false;
    }
    
    int operator <(temp1 a)
    {
        cout<<"'<' operator is overloaded in class 'temp1'\n";
        if(this->main<=a.main)
            return 1;
        else
            return 0;
    }
    void operator <=(int a)
    {
        cout<<"'<=' operator is overloaded in class 'temp1'\n";
    }
    
    bool operator >(int a)
    {
        cout<<"'>' operator is overloaded in class 'temp1'\n";
        if(this->main>a)
            return true;
        else
            return false;
    }
    
    int operator >(temp1 a)
    {
        cout<<"'>' operator is overloaded in class 'temp1'\n";
        if(this->main>a.main)
            return 1;
        else
            return 0;
    }
    
    int operator ==(temp1 t)
    {
        return (t.main == main)?1:0;
    }
};

class Log_OP_OL                                                                                         // Logical Operator Overloading
{
    public:
    int main;
    temp2(int a)
    {
        main = a ;
    }
    
    void display()
    {
        cout<<"Main : "<<main<<'\n';
    }
    void operator && (int b)
    {
        cout<<"&& Operator overloaded int class temp3"<<" passed Data: "<<main<<','<<b<<'\n';
        if(this->main == b)
            cout<<"Equal\n";
        else
            cout<<"Not Equal\n";
    }
    //int operator && (int b)                                                     // Causes Ambiguity Error
    int operator && (temp2 t1)
    {
        if(this->main == t1.main)
            return 1;
        else
            return 0;
    }
    
    bool operator || (temp2 t)
    {
        if(this->main>0 ||  t.main>0)
            return true;
        else
            return false;
    }
    
    void operator ! ()
    {
        this->main = -main;
    }
};

class Ass_OP_OL                                                                                     // Assignment Operator Overloading
{
    public:
    int t[10];
    temp3(int k)
    {
        for(int i=0;i<10;i++)
        {
            t[i] = i+k;
        }
    }
    void display()
    {
        for(int i=0;i<10;i++)
            cout<<t[i]<<' ';
        cout<<'\n';
    }
    
    void operator =(temp3 t1)
    {
        for(int i=0;i<10;i++)
            this->t[i] = t1.t[i];
    }
    
    void operator +=(int x)
    {
        for(int i=0;i<10;i++)
            this->t[i]+=x;
    }
};

class Spec_OP_OL                                                                                    // Special Operators Overloading
{
    public:
    int t[4];
    temp4(int a,int b,int c)
    {
        this->t[0] = a;
        this->t[1] = b;
        this->t[2] = c;
    }                                                                               // Default Constructor, if not Declared, a Default constructor will be provided by the Compiler itself,
    temp4(){}                                                                       // Default Constructor is requred to use the 'new y=temp4()'.
    void print()
    {
        cout<<"t[0] : "<<this->t[0]<<" t[1] : "<<this->t[1]<<" t[2] : "<<this->t[2]<<'\n';
    }
    
    /*
    void* operator new (size_t size)
    {
        return (void*)::new long int(10);                                           // Memory Management, NEW SCENARIO 
    }*/
    
    void* operator new(size_t size)
    {
        cout<<"New Operator Overloaded with respect to Class 'temp4'\n";
        return ::operator new(size);
        //  Here the Point is, we are returning only the ADDRESS of the MEMORY allocated, no type is specified, inside the function, Since the return type is 'VOID*'.
        //  return (void*)::operator new(size);                                           // Valid
        //  return (void*):: new int(10);                                                 // Valid
        //  return new temp1;                                                             // Invalid, Calls the Same Overloaded new Operator in the Class, resulting in Recursive Call.
        //  return (::new temp1);                                                         // Valid Since, it calls Global(Actual) new Operator.
        //  return *(:: new temp1) or return temp1()                                     // ERROR, since, there is only provision to return a Void pointer, in the Operator Overloading Function, hence cannot return a Solid Object. 
    }
    
    void operator delete(void* p)
    {
        cout<<"Delete Operator Overloaded with respect to Class 'temp4'\n";
        free(p);
        //delete p;
    }
    
};


// Global Operator Overloading:
/*
                                    The Global Operator Overloading inside a Namespace, is allowed, only if the Overloading Function is associated with a User-Defined Datatypes such as Class,Enum etc.
*/

void operator +(temp t)
{
    cout<<" '+' Operator Overloaded in the Global Scope "<<'\n';    
}
/*
void operator +(int t)              // _ERROR, since it is not associated with a user defined Datatype.
{
    cout<<" '+' Operator Overloaded in the Global Scope "<<'\n';    
}*/

void* operator new(size_t size)
{
    cout<<"New Operator is overloaded Globally\n";
    return (void*)malloc(size);
    //return new(size);
}

int main()
{
    // Operator Overloading
        // GLobal Scope:
            +3;
    //Local(Class) Scope        
        // Arithmetic Operators Overloading:
        /*
        temp t1(10,100,1000),t2(1,2,3);                                                 // Object Creation
            temp t3 = t1+t2,t4,t5;          
        t1.print();
        t2.print();
        t3.print();
            +t2;
            t1+3;
            ++t3;
            t2+=1000;
            //t3+;                                                                          // Invalid Syntax.
        t1.print();
        t2.print();
        t3.print();
            t4 = t1*t2;                                                 // using FRIEND FUNCTION
            t5 = t2/t2;                                                 // using SCOPE RESOLUTION                                                         
        t4.print();
        t5.print();
        //printf("[%d]",t3);
        */
        
        //Relational Operator Overloading:
        /*
        temp1 t11(10,20,30),t12(100,200,300), t13(10,20,30);
        printf("Data Member Main in t11 is %s\n",(t11 > t12)?"Less":"Greater");
        printf("Data Member Main int t11 is %s\n",(t11 < t12)?"Greater":"Less");
        printf("Data Member Main is %s\n",(t11 == t13)?"Equal":"Not Equal");
        t11<=10;
        */
        
        //Logical Operator Overloading:
        /*
        temp2 t21(100),t22(1000),t23(10000);
        t21 && 1023;                                                    // && operator Overloaded
        cout<<((t21 && t22)?"Equal":"Not Equal")<<'\n';
        cout<<((t21 || t22)?"true":"false")<<'\n';
        t21.display();
        !t21;
        t21.display();
        */
        
        //Assignment Operator Overloading
        /*
        temp3 t31(0),t32(5);
        t31.display();
        t32.display();
        t31 = t32;
        t31.display();
        t31+=123;
        t31.display();
        */
        
        // Special Operators Overloading: 
        
        // New and Delete Operator Overload:
        /*
            temp4 t41(1,2,3),t42(4,5,6),*tp1,*tp2;
            t41.print();
            t42.print();
            tp1 = new temp4;
            tp2 = new temp4();
            delete(tp1);
            delete(tp2);
        */
        
    // Overloading Methodologies:
    /*
    temp1 t11(9,8,7),t12(6,5,4);
    t11.print();
    t12.print();
    temp1 t13 = t11-t12;
    temp1 t14 = t11+t12;
    t13.print();
    t14.print();
    t13.print();
    temp1 *t15 = new temp1();
    t15->print();
    *(t15)+=4;
    t15->print();
    delete(t15);
    int* a = (int*)new temp1();
    char* a1 = (char*)new temp1();
    char* a2 = (char*)new temp1();
    //printf("[%d]",sizeof(a));
    *//*
    for(int i=0;i<50;i++)
    {
        a[i] = i;
        a1[i] = i+48;
        a2[i] = i+65;
        cout<<i<<' '<<a[i]<<' '<<a1[i]<<' '<<a2[i]<<'\n';
    }
      */  
    /*
    for(int i=0;i<240;i++)                                                        // Entire ASCII System
            printf("| %d %c|",i,i);
    printf("\n%d",'\n');*/
}
