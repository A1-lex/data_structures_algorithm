#include <iostream>
#include <cstring>

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;  
};

char calculate_grade(int mark) {
    if (mark > 69) {
        return 'A';
    } else if (mark > 59) {
        return 'B';
    } else if (mark > 49) {
        return 'C';
    } else if (mark > 39) {
        return 'D';
    } else {
        return 'E';
    }
}

void add_student(Student students[], int& num_students, int max_students) {
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

void editStudent(Student students[], int num_students) {
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

void addMarksAndCalculateGrade(Student& student) {
    std::cout << "Enter marks: ";
    std::cin >> student.grades.mark;

    student.grades.the_grade = calculate_grade(student.grades.mark);
    student.grades_calculated = true;

    std::cout << "Marks and grades added successfully!" << std::endl;
}

int main() {
    const int max_students = 40;
    Student students[max_students];
    int num_students = 0;

    int choice;
    do {
        std::cout << "\n1. Add a student\n2. Edit student details\n3. Add marks and calculate grades\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string reg_number;

        switch (choice) {
            case 1:
                add_student(students, num_students, max_students);
                break;
            case 2:
                editStudent(students, num_students);
                break;
            case 3:
                
                std::cout << "Enter registration number of the student: ";
                std::cin >> reg_number;

                for (int i = 0; i < num_students; ++i) {
                    if (students[i].reg_number == reg_number) {
                        if (!students[i].grades_calculated) {
                            addMarksAndCalculateGrade(students[i]);
                        } else {
                            std::cout << "Grades already calculated for this student!" << std::endl;
                        }
                        break;
                    }
                }
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