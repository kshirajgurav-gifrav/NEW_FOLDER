#include <iostream>
#include <string>
using namespace std;
// Base Class
class Student {
protected:
    int id;
    string name;
public:
    Student(int i, string n) {
        id = i;
        name = n;
    }
void displayStudent() {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};
// Virtual Base Class 1
class AcademicRecord : virtual public Student {
protected:
    float assignmentMarks;
public:
    AcademicRecord(int i, string n, float a)
        : Student(i, n) {
        assignmentMarks = a;
    }
};
// Virtual Base Class 2
class ExamRecord : virtual public Student {
protected:
    float examMarks;
public:
    ExamRecord(int i, string n, float e)
        : Student(i, n) {
        examMarks = e;
    }
};
// Multiple Inheritance
class Result : public AcademicRecord, public ExamRecord {
public:
    Result(int i, string n, float a, float e)
        : Student(i, n),
          AcademicRecord(i, n, a),
          ExamRecord(i, n, e) {
    }
// Virtual Function
    virtual void calculateResult() {
        float total = assignmentMarks + examMarks;
        displayStudent();
        cout << "Assignment Marks: " << assignmentMarks << endl;
        cout << "Exam Marks: " << examMarks << endl;
        cout << "Bonus Marks: 0" << endl;
        cout << "Total Marks: " << total << endl;
       if (total >= 40)
            cout << "Status: Pass" << endl;
        else
            cout << "Status: Fail" << endl;
    }};
// Regular Student
class RegularStudent : public Result {
public:
    RegularStudent(int i, string n, float a, float e)
: Student(i, n), Result(i, n, a, e) {
    }
void calculateResult() override {
        cout << "\n--- Regular Student Result ---" << endl;
        Result::calculateResult();
    }
};
// Scholarship Student
class ScholarshipStudent : public Result {
public:
    ScholarshipStudent(int i, string n, float a, float e)
        : Student(i, n), Result(i, n, a, e) {
    }
void calculateResult() override {
        cout << "\n--- Scholarship Student Result ---" << endl;
 displayStudent();
 float total = assignmentMarks + examMarks + 5;
  cout << "Assignment Marks: " << assignmentMarks << endl;
  cout << "Exam Marks: " << examMarks << endl;
  cout << "Bonus Marks: 5" << endl;
  cout << "Total Marks: " << total << endl;

     if (total >= 40)
            cout << "Status: Pass" << endl;
     else
            cout << "Status: Fail" << endl;
    }
};
// Main Function
int main() {
    int id;
    string name;
    float assignmentMarks, examMarks;
    Result* ptr;

    // Regular Student Input
    cout << "Enter Regular Student 1 Details:" << endl;
    cin >> id >> name >> assignmentMarks >> examMarks;
    RegularStudent s1(id, name, assignmentMarks, examMarks);
    ptr = &s1;
    ptr->calculateResult();

    // Scholarship Student Input
cout << "\nEnter Scholarship Student 1 Details:" << endl;
cin >> id >> name >> assignmentMarks >> examMarks;
ScholarshipStudent s2(id, name, assignmentMarks, examMarks);
ptr = &s2;
ptr->calculateResult();
return 0;
}

