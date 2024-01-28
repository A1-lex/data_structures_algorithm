#include <iostream>
#include <string>

class Course {
public:
    std::string course_code;
    std::string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;

    void calculateGrade() {
        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;

    void addMarksAndCalculateGrade() {
        if (!grades_calculated) {
            std::cout << "Enter marks: ";
            std::cin >> grades.mark;

            grades.calculateGrade();
            grades_calculated = true;

            std::cout << "Marks and grades added successfully!" << std::endl;
        } else {
            std::cout << "Grades already calculated for this student!" << std::endl;
        }
    }
};

class StudentSystem {
private:
    static const int max_students = 40;
    Student students[max_students];
    int num_students;

public:
    StudentSystem() : num_students(0) {}

    void addStudent() {
        if (num_students < max_students) {
            Student newStudent;
            std::cout << "Enter registration number: ";
            std::cin >> newStudent.reg_number;
            std::cout << "Enter name: ";
            std::cin >> std::ws;  
            std::getline(std::cin, newStudent.name);
            std::cout << "Enter age: ";
            std::cin >> newStudent.age;
            std::cout << "Enter course code: ";
            std::cin >> newStudent.course.course_code;
            std::cout << "Enter course name: ";
            std::cin >> std::ws;  
            std::getline(std::cin, newStudent.course.course_name);

            students[num_students] = newStudent;
            num_students++;
            std::cout << "Student added successfully!" << std::endl;
        } else {
            std::cout << "Maximum number of students reached!" << std::endl;
        }
    }

    void editStudent() {
        std::string reg_number;
        std::cout << "Enter registration number of the student to edit: ";
        std::cin >> reg_number;

        for (int i = 0; i < num_students; ++i) {
            if (students[i].reg_number == reg_number) {
                std::cout << "Enter new name: ";
                std::cin >> std::ws;
                std::getline(std::cin, students[i].name);
                std::cout << "Enter new age: ";
                std::cin >> students[i].age;
                std::cout << "Student details updated successfully!" << std::endl;
                return;
            }
        }

        std::cout << "Student not found!" << std::endl;
    }

    void addMarksAndCalculateGrade() {
        std::string reg_number;
        std::cout << "Enter registration number of the student: ";
        std::cin >> reg_number;

        for (int i = 0; i < num_students; ++i) {
            if (students[i].reg_number == reg_number) {
                students[i].addMarksAndCalculateGrade();
                return;
            }
        }

        std::cout << "Student not found!" << std::endl;
    }
};

int main() {
    StudentSystem studentSystem;

    int choice;
    do {
        std::cout << "\n1. Add a student\n2. Edit student details\n3. Add marks and calculate grades\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                studentSystem.addStudent();
                break;
            case 2:
                studentSystem.editStudent();
                break;
            case 3:
                studentSystem.addMarksAndCalculateGrade();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}