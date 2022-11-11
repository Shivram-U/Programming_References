#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Inheritance:
                    The Inheritance is the process of inheriting the Members of a Class, from One Class(BASE CLASS) to another Class(DERIVED CLASS).
                    
        Single Inheritance:
                    The Inheritance of Members of a Class, from One Class(BASE) to another(DERIVED) Class.
        
        Multiple Inheritance:
                    The Inheritance of Members of One/More than One Base Classes to a Single DERIVED Class.
*/

class Base1
{
    public:
        int pub;
    protected:
        int prot;
    private:
        int priv;
    public:
        Base1(int a,int b,int c)
        {
            pub = a;
            prot = b;
            priv = c;
        }
        Base1()                                         // Without an explicit Default Constructor Declaration, the Inheritance process will request will request the Declaration of the Existing Constructor inside the Base Class.
        {}
        void display1()
        {
            cout<<"\nBase1 Class Method Call"<<'\n';
            cout<<"pub : "<<pub<<' '<<"prot :"<<prot<<' '<<"priv :"<<' '<<priv<<'\n';
        }
};

class Base2
{
    public:
        int pub;
    protected:
        int prot;
    private:
        int priv;
    public:
        Base2(int a,int b,int c)
        {
            pub = a;
            prot = b;
            priv = c;
        }
        Base2()
        {}
        void display2()
        {
            cout<<"\nBase2 Class Method Call"<<'\n';
            cout<<"pub : "<<pub<<' '<<"prot :"<<prot<<' '<<"priv :"<<' '<<priv<<'\n'; 
        }
};

class Base3
{
    public:
        int pub3;
    protected:
        int prot3;
    private:
        int priv3;
    public:
        Base3(int a,int b,int c)
        {
            pub3 = a;
            prot3 = b;
            priv3 = c;
        }
        Base3()
        {}
        void display3()
        {
            cout<<"\nBase3 Class Method Call"<<'\n';
            cout<<"pub3 : "<<pub3<<' '<<"prot3 :"<<prot3<<' '<<"priv3 :"<<' '<<priv3<<'\n'; 
        }
};

class derived:public Base1                                                                                      // Single Inheritance
{
    public:
        derived(int a,int b,int c)
        {
            pub = a;
            prot = b;
            //priv = c;                         // Since the Member 'priv' is declared private, hence it cannot be inherited.
            //Base1::priv = c;
        }
        // But since the Display Method inherited from the 'Base1' class, prints the Private Data Member, hence it prints a Garbage Value.
};
//class derived1: public Base1,public Base2     // This kind of Inheritance is going to cause an Ambiguity Error. Since, both the classes 'Base1','Base2' have similar Variables like [pub,prot,priv]       
//class derived1: public Base1,Base3            // In this kind, of Multiple Inheritance, if the class is Simply given without Access Specification, it will be Considered 'Private'.     
    // Inorder to resolve this Ambiguity of Members of a Class, The 'Virtual Base Class' was introduced.
class derived1: public Base1,public Base3                                                                       // MUTLTIPLE INHERITANCE
{  
    public:
        int dpub;
    protected:
        int dprot;
    private:
        int dpriv;
    public:
        derived1(int a,int b,int c)
        {
            pub = a+b;
            prot = a-b;
            pub3 = a*b;
            prot3 = a*10;
            dpub = a;
            dprot = b;
            dpriv = c;
        }
        void display()
        {
            cout<<"\nderived1 Class Method Call"<<'\n';
            //cout<<"pub :"<<pub<<"prot :"<<' '<<prot<<"priv :"<<' '<<priv<<'\n';               -- ERR // Since the The private member 'priv' is not inhereted.
            cout<<"pub  : "<<pub<<' '<<"prot : "<<prot<<' '<<'\n';
            cout<<"pub3 : "<<pub3<<' '<<"prot3 : "<<prot3<<' '<<'\n';
            cout<<"dpub : "<<dpub<<' '<<"dprot : "<<dprot<<' '<<"dpriv : "<<' '<<dpriv<<'\n';            
        }
};

int main() 
 {
    Base1 b1(1,11,111);
    Base2 b2(2,22,222);
    derived1 d1(10,100,1000);
    //derived1 d1;
    b1.display1();
    b2.display2();
    printf("\nSingle Inheritance  => derived Class:\n");
    derived d(1,2,3);
    d.display1();
    printf("\nMultiple Inheritance derived1 Class:\n");
    d1.display();
    d1.display1();
    d1.display3();
    //printf("Public Data Members of the derived Class : pub :%d dpub : %d pub3: %d\n",d1.prot,d1.dprot,d1.prot3);      - ERR Since the Protected Members of a Class cannot be accessed Outside, either the Base or derived Class Scope.
    printf("Public Data Members of the derived Class : pub :%d dpub : %d pub3: %d\n",d1.pub,d1.dpub,d1.pub3);
}
