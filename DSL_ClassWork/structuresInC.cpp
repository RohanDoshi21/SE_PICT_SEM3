// !Author: Rohan Doshi

#include <iostream>
#include <map>
using namespace std;

struct Student {
    string name;
    int rollNo;
    int marks[5];
};

float calPercentage(Student &sample){
        float total = 0;
        for (int i = 0; i < 5; i++){
            total += sample.marks[i];
        }
        total = total/5;
        return total;
}

void enterName(Student &sample){
    cout << "Enter name ";
    cin >> sample.name;
}

void enterRollNo(Student &sample){
    cout << "Enter roll ";
    cin >> sample.rollNo;
}

void enterMarks(Student &sample){
    cout << "Enter marks for 5 subjects (out of 100)";
    for (size_t i = 0; i < 5; i++)
    {
        cin >> sample.marks[i];
    }
    
}

int main() {
    Student s1, s2, s3, s4, s5;
    float markList[5];
    cout << "**********************\n";
   cout << "For student 1 \n";
    enterName(s1);
    enterRollNo(s1);
    enterMarks(s1);
    markList[0] = calPercentage(s1);
    cout << "**********************\n";

   cout << "For student 2 \n";
    enterName(s2);
    enterRollNo(s2);
    enterMarks(s2);
    markList[1] = calPercentage(s2);
    cout << "**********************\n";

   cout << "For student 3 \n";
    enterName(s3);
    enterRollNo(s3);
    enterMarks(s3);
    markList[2] = calPercentage(s3);
    cout << "**********************\n";

   cout << "For student 4 \n";
    enterName(s4);
    enterRollNo(s4);
    enterMarks(s4);
    markList[3] = calPercentage(s4);
    cout << "**********************\n";

   cout << "For student 5 \n";
    enterName(s5);
    enterRollNo(s5);
    enterMarks(s5);
    markList[4] = calPercentage(s5);

    cout << "**********************\n";

    int largest = markList[0];
    int indexLargest = 0;
    for (int i = 1; i < 5; i++){
        if (largest < markList[i]){
            largest = markList[i];
            indexLargest = i;
        }
    }
    int highestMarks = markList[indexLargest];
    markList[indexLargest] = -1;
    int secondLargest = markList[0];
    int secondIndexLargest = 0;
    for (int i = 0; i < 5; i++){
        if (secondLargest < markList[i]){
            secondLargest = markList[i];
            secondIndexLargest = i;
        }
    }
    

    if (indexLargest == 0 ){
        cout << "Highest is " << s1.name << endl;
        cout << "Roll No: " << s1.rollNo << endl;
        cout << "Marks: " << highestMarks << endl;
    }
    else if  (indexLargest == 1 ){
        cout << "Highest is " << s2.name << endl;
        cout << "Roll No: " << s2.rollNo << endl;
        cout << "Marks: " << highestMarks << endl;
    }
    else if (indexLargest == 2 ){
        cout << "Highest is " << s3.name << endl;
        cout << "Roll No: " << s3.rollNo << endl;
        cout << "Marks: " << highestMarks << endl;
    }
    else if (indexLargest == 3 ){
        cout << "Highest is " << s4.name << endl;
        cout << "Roll No: " << s4.rollNo << endl;
        cout << "Marks: " << highestMarks << endl;
    }
    else if (indexLargest == 4 ){
        cout << "Highest is " << s5.name << endl;
        cout << "Roll No: " << s5.rollNo << endl;
        cout << "Marks: " << highestMarks << endl;
    }

    cout << "****************\n"; 
    
    if (secondIndexLargest == 0 ){
        cout << "Second Highest is " << s1.name << endl;
        cout << "Roll No: " << s1.rollNo << endl;
        cout << "Marks: " << markList[0] << endl;
    }
    else if  (secondIndexLargest == 1 ){
        cout << "Second Highest is " << s2.name << endl;
        cout << "Roll No: " << s2.rollNo << endl;
        cout << "Marks: " << markList[1] << endl;
    }
    else if (secondIndexLargest == 2 ){
        cout << "Second Highest is " << s3.name << endl;
        cout << "Roll No: " << s3.rollNo << endl;
        cout << "Marks: " << markList[2] << endl;
    }
    else if (secondIndexLargest == 3 ){
        cout << "Second Highest is " << s4.name << endl;
        cout << "Roll No: " << s4.rollNo << endl;
        cout << "Marks: " << markList[3] << endl;
    }
    else if (secondIndexLargest == 4 ){
        cout << "Second Highest is " << s5.name << endl;
        cout << "Roll No: " << s5.rollNo << endl;
        cout << "Marks: " << markList[4] << endl;
    }
    cout << "****************\n"; 
    return 0;
}