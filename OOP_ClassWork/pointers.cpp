#include <iostream>
using namespace std;

class student{
    string* name;
    public:
        student(){
            name = new string;
        }
        student(student&test){
            name = test.name;
        }
        void set(string name){
            this->name = &name;
        }
        void print(){
            cout << *name << endl;
        }
        ~student(){
            delete name;
        }
};
int main() {
    student s1;
    string s2;
    s2 = "rohan";
    s1.set(s2);
    student s3 = s1;
    s3.print();
    return 0;
}