#include <iostream>
#include <fstream>
using namespace std;

// // // int main()
// // // {
// // //     int p = 1000;
// // //     double q = 3.14;
// // //     cout << p;
// // //     cout << endl;
// // //     cout << q << endl
// // //          << p * q;
// // //     return 0;
// // // }

// // // #include<iostream>
// // //   using namespace std;
// // class Base
// // {
// // public:
// //     Base() { cout << "Constructor: Base"
// //                   << "\t"; }
// //     virtual ~Base() { cout << "Destructor : Base"
// //                            << "\t"; }
// // };
// // class Derived : public Base
// // {
// // public:
// //     Derived() { cout << "Constructor: Derived"
// //                      << "\t"; }
// //     ~Derived() { cout << "Destructor : Derived"
// //                       << "\t"; }
// // };

// // int main()
// // {
// //     Base *Var = new Derived();
// //     delete Var;
// //     return 0;
// // }

// #include <iostream>
// using namespace std;
// class Base
// {
// public:
//     virtual void show() { cout << " In Base \t"; }
// };

// class Derived : public Base
// {
// public:
//     void show() { cout << "In Derived \t"; }
// };

// int main(void)
// {
// Base *bp = new Derived;
// bp->show();

// Base &br = *bp;
// br.show();

// return 0;
// }
// void show(int p)
// {
//    try
//    {
//       if(p== 0) throw p; if(p==1) throw 'p'; if(p==1) throw 1.0;
//     }
//     catch (int m)
//     {
//       cout<<"Caught1";
//     }
//     catch (int m)
//     {
//       cout<<"Caught2";
//     }
// }
// int main()
// {
// show(0);
// }
// int main()
// {
//     ofstream ofile;
//     ofile.open("find.txt");

//     ofile << "letsfindcourse" << endl;

//     cout << "Data written to file" << endl;
//     ofile.close();
//     return 0;
// }
int main()
{
    FILE *fp;
    char x[1024];
    fp = fopen("find.txt", "r"); // "ayushjain and prateek"
    x[0] = getc(fp);
    fseek(fp, 0, SEEK_END);
    fseek(fp, -7L, SEEK_CUR);
    fgets(x, 6, fp);
    puts(x);
    return 0;
}