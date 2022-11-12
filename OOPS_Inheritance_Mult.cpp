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

class Base2 : public Base1
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

class derived1: public Base2                                                                      // MUTLTIPLE INHERITANCE
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
            dpub = a;
            dprot = b;
            dpriv = c;
        }
        void display()
        {
            cout<<"\nderived1 Class Method Call"<<'\n';
            //cout<<"pub :"<<pub<<"prot :"<<' '<<prot<<"priv :"<<' '<<priv<<'\n';               -- ERR // Since the The private member 'priv' is not inhereted.
            cout<<"pub  : "<<pub<<' '<<"prot : "<<prot<<' '<<'\n';
            //cout<<"pub3 : "<<pub3<<' '<<"prot3 : "<<prot3<<' '<<'\n';
            cout<<"dpub : "<<dpub<<' '<<"dprot : "<<dprot<<' '<<"dpriv : "<<' '<<dpriv<<'\n';            
        }
};

int main() 
 {
    //Base1 b1(1,11,111);
    //Base2 b2(2,22,222);
    derived1 d1(10,100,1000);
    d1.display1();
    d1.display2();
    d1.display();
}
