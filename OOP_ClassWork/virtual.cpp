#include <iostream>
using namespace std;

// class Base
// {
// private:
//     /* data */
// public:
//     Base(/* args */);
//     ~Base();
// };

// Base::Base(/* args */)
// {
//     cout << "CB" << endl;
// }

// Base::~Base()
// {
//     cout << "DB" << endl;
// }

// class derivede : public Base
// {
// private:
//     /* data */
// public:
//     derivede(/* args */);
//     ~derivede();
// };

// derivede::derivede(/* args */)
// {
//     cout << "CD" << endl;
// }

// derivede::~derivede()
// {
//     cout << "DD" << endl;
// }

// int main() {
//     Base *var = new derivede();
//     delete var;
//     // int a = 5, b =10;
//     // int *arr[] = {&a, &b};
//     // cout << arr[1];
//     // return 0;
// }

// class Base
// {
// public:
//     virtual void show() = 0;
// };
// class Derived : public Base { };
// int main(void)
// {
//     Derived q;
//     return 0;
// }

// class A
//   {
//   public:
//       virtual void fun();
//   };
//   class B : public A
//   {
// public:
//      void fun();
//   };
//   int main()
//   {
//       int a = sizeof(A), b = sizeof(B);
//     cout << a << " " << b;
//     if (a == b) cout <<"a == b";

//     else if (a >b) cout <<"a >b";

//     else cout <<"a <b";

//     return 0;
//   }

// class Test
// {
// private:
//     int x;
// public:
//     Test(int x = 0);
//     ~Test();
//     void change(Test *ptr){
//         this = ptr;   //!assignment to this anachronism
//     }
// };

// Test::Test(int x = 0)
// {
//     this->x = x;
// }

// Test::~Test()
// {
// }

// class Base
//   {
//   public:
//       virtual void show() = 0;
//   };
// int main(void)
//   {
//       Base b;  //!object of abstract class type "Base" is not allowed: -- function "Base::show" is a pure virtual function
//       Base *bp;
//       return 0;
//   }

// int main() {
//     string* x, y; //!here x is pointer y is string!
//     x = new string("hello");
//     y = new string("world");
//     cout << x << endl;
//     cout << y;

//     int* p, q;

// }

class A
{
public:
    virtual void fun() { cout << "A::fun() "; }
    virtual void fun(int x) { cout << "A"; \
    
    }
};

class B : public A
{
public:
    virtual void fun() { cout << "B::fun() "; }
    virtual void fun(int a)
    {
        cout << "Virtual with int" << endl;
    }
};

// class C: public B
// {
// public:
//    void fun() { cout <<"C::fun() "; }
// };

int main()
{
    A *bp;
    B b;
    bp = &b;
    bp->fun();
    bp->fun(1);
}

//  class Base
// {
// public:
//     virtual void show() { cout<<" In Base \t"; }
// };

// class Derived: public Base
// {
// public:
//     void show() { cout<<"In Derived \t"; }
// };

// int main(void)
// {
//     Base *bp = new Derived;
//     bp->show();

//     Base &br = *bp;
//     br.show();

//     return 0;
// }