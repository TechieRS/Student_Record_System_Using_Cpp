#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
private:
    string name;
    int id;
    float grade;

public:
    Student() {
        name = "";
        id = -1;
        grade = 0;
    }

    void setStudent(string n, int i, float g) {
        name = n;
        id = i;
        grade = g;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    float getGrade() {
        return grade;
    }

    void setGrade(float g) {
        grade = g;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

class Course {
private:
    string courseName;
    Student students[MAX_STUDENTS];
    int studentCount;

public:
    Course(string name) {
        courseName = name;
        studentCount = 0;
    }

    void addStudent(string name, int id, float grade) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount].setStudent(name, id, grade);
            studentCount++;
        } else {
            cout << "Course is full." << endl;
        }
    }

    void removeStudent(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student removed." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void updateGrade(int id, float newGrade) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getId() == id) {
                students[i].setGrade(newGrade);
                cout << "Grade updated." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayStudents() {
        cout << "Course: " << courseName << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }

    void report() {
        float total = 0;
        for (int i = 0; i < studentCount; i++) {
            total += students[i].getGrade();
        }
        if (studentCount > 0)
            cout << "Class Average: " << total / studentCount << endl;
        else
            cout << "No students enrolled." << endl;
    }
};

int main() {
    Course c("C++ Programming");

    c.addStudent("Ravi", 101, 85.5);
    c.addStudent("Bob", 102, 90.0);
    c.addStudent("Jhon", 103, 78.5);

    c.displayStudents();
    c.report();

    c.updateGrade(102, 95.0);
    c.removeStudent(101);

    c.displayStudents();
    c.report();

    return 0;
}
