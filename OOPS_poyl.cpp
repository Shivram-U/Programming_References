/*                                                        Polymorphism in C++  
    Polymorphism:
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
                                            
Reference :
        1.  Polymorphism : https://forgetcode.com/cpp/715-cast-operator-overloading
                           https://www.geeksforgeeks.org/cpp-polymorphism/
*/

