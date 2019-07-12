//Student main
//Written by Forrest Kelley for Applied Programing Concepts with Professor Aaron Carpenter
//https://codereview.stackexchange.com/questions/41525/creating-objects-and-putting-them-into-stdlist for including and initializing syntax
//http://www.cplusplus.com/forum/beginner/107842/ for get and set syntax refresher in class
//http://www.cplusplus.com/reference/list/list/begin/ used for iterator in for loop
//https://www.geeksforgeeks.org/getline-string-c/ for getline()

#include "users.h"
#include "courses.h"


int login();

bool loggedIn = true;

int main() {
    //list of students
    std::list<student> students;
    std::list<course> courses;
    std::list<instructor> instructors;
    int choice = 0;
    int x = 0;
    int loggedInCred = 0;

    while (loggedIn) {
        loggedInCred = login();

        /**
         * menu for admin
         *
         */
        if (loggedInCred == 1) {

            bool keepRunning = 1;
            while (keepRunning) {
                std::cout
                        << "Welcome to course registration main menu!"
                           "\nEnter 0 to logout"
                           "\nEnter 1 to add a student"
                           "\nEnter 2 to print all students"
                           "\nEnter 3 to add new course"
                           "\nEnter 4 to print courses"
                           "\nEnter 5 to remove course(s)"
                           "\nEnter 6 to add instructor"
                           "\nEnter 7 to print instructors\n";
                std::cin >> choice;
                if (choice == 1) {
                    //add student
                    student stu;
                    std::cout << "You wish to add a student\n";
                    std::cout << "Please enter ID Number\n";
                    int id;
                    std::cin >> id;
                    stu.setId(id);
                    std::cout << "Please enter the name\n";
                    //store input of name and later major
                    std::string n = "";
                    std::string m = "";
                    //cin.ignore() needed for the cin to get the correct user input
                    std::cin.ignore();
                    std::getline(std::cin, n);
                    stu.setName(n);
                    std::cout << "Please enter major\n";
                    std::getline(std::cin, m);
                    stu.setMajor(m);
                    //number of courses to initially enter
                    std::cout << "Enter the number of courses to enter\n";
                    std::cin >> x;
                    std::cout << "Enter the " << x << " course(s) crn numbers followed by a newline or space\n";
                    int crns = 0;
                    for (int i = 0; i < x; i++) {
                        std::cin >> crns;
                        stu.setCrn(crns);
                    }
                    //add student to list
                    students.push_back(stu);

                } else if (choice == 2) {
                    //iterator of type student to access each objects print function
                    for (std::list<student>::iterator it = students.begin(); it != students.end(); ++it) {
                        it->print();
                        std::cout << "-----------------------\n";
                    }
                } else if (choice == 3) {//add course
                    course c;
                    std::cout << "You wish to enter a course\n"
                                 "Please Enter the course name\n";
                    std::string n = "";
                    std::string in = "";
                    int crn = 0;
                    int level = 0;
                    std::cin.ignore();
                    std::getline(std::cin, n);
                    c.setName(n);
                    std::cout << "Enter the level for the course\n";
                    std::cin >> level;
                    c.setLevel(level);
                    std::cout << "Enter the CRN number for the course\n";
                    std::cin >> crn;
                    c.setCrn(crn);
                    std::cout << "Enter the instructor\n";
                    std::cin.ignore();
                    std::getline(std::cin, in);
                    c.setInstructor(in);
                    courses.push_back(c);

                } else if (choice == 4) {
                    for (std::list<course>::iterator it = courses.begin(); it != courses.end(); ++it) {
                        it->print();
                        std::cout << "\n-----------------\n";
                    }
                } else if (choice == 5) {
                    if (courses.size() == 0) { std::cout << "The course list is already empty\n"; }
                    else {
                        std::cout << "You wish to remove a course\nPlease enter CRN number for course\n";
                        int num = 0;
                        std::cin >> num;
                        std::list<course>::iterator it2 = courses.end();
                        for (std::list<course>::iterator it = courses.begin(); it != it2; ++it) {
                            if (it->getCrn() == num) {
                                courses.erase(it);
                                //reset head and tail
                                it = courses.begin();
                                it2 = courses.end();
                            }
                        }
                    }
                } else if (choice == 6) {
                    instructor inst;
                    std::cout << "Please Enter Name:\n";
                    std::string nam;
                    std::cin.ignore();
                    std::getline(std::cin, nam);
                    inst.setName(nam);
                    instructors.push_back(inst);
                } else if (choice == 7) {
                    for (std::list<instructor>::iterator it = instructors.begin(); it != instructors.end(); ++it) {
                        std::cout << it->getName() << "\n";
                    }

                } else if (choice == 0) {
                    std::cout << "exiting\n";
                    break;
                } else { std::cout << "Invalid input\n"; }

            }//while
        }//end admin if
            /**
             * Menu for Student
             */
        else if (loggedInCred == 2) {
            student stu;
            bool run = 1;
            int in = 0;
            //Name of student should be assoc. with credentials.
            std::cout << "Please enter your ID number\n";
            int id_num;
            std::string n = "";
            std::cin >> id_num;
            for (std::list<student>::iterator student_it = students.begin(); student_it != students.end(); ++ student_it){
                if(student_it -> getId() == id_num){
            while (run) {
                std::cout << "Enter 1 to register for courses\nEnter 2 to view your schedule\nEnter 0 to logout\n";
                std::cin >> in;
                if (in == 1) {
                    std::cout << "Enter the number of courses to enter\n";
                    std::cin >> x;
                    std::cout << "Enter the " << x << " course(s) crn numbers followed by a newline or space\n";
                    int crn;
                    for (int i = 0; i<x; i++){
                        std::cin >> crn;
                        student_it->setCrn(crn);
                    }
                }//if
                else if (in == 2) {
                    std::cout << student_it->getName() <<" is registered for classes: ";
                    student_it->printCourses();
                    std::cout << "\n";
                }//if
                else if (in == 0) {
                    std::cout << "logging out\n";
                    break;
                } else {
                    std::cout << "Invalid input\n";
                }
            }}
            else{std::cout << "Student ID doesn't exist";}}
        }
            /**
             * menu for instructor
             */
        else if (loggedInCred == 3) {
            bool run = 1;
            while (run) {
                std::cout << "\nEnter 0 to log out\nEnter 1 to display courses\nEnter 2 to display course rosters\n";
                int in = 1;
                std::cin >> in;
                if (in == 0) {
                    std::cout << "Logging out\n";
                    break;

                } else if (in == 1) {
                    //prints all courses
                    for (std::list<course>::iterator it = courses.begin(); it != courses.end(); ++it) {
                        //find if course is for instructor
                        it->print();
                        std::cout << "\n-----------------\n";
                    }

                } else if (in == 2) {

                    //prints courses and their rosters
                    int temp_crn;
                    for (std::list<course>::iterator it = courses.begin(); it != courses.end(); ++it) {
                        temp_crn = it->getCrn();
                        for (std::list<student>::iterator i = students.begin(); i != students.end(); ++i) {
                            std::list<int> temp_crn_list = i->getCrnList();
                            for (std::list<int>::iterator j = temp_crn_list.begin(); j != temp_crn_list.end(); ++j) {
                                if (*j == temp_crn) {
                                    std::cout << "Class: " << it->getName() << "Has student " << i->getName() << "\n";
                                }
                            }
                        }
                        std::cout << "\n-----------------\n";
                    }
                } else {
                    std::cout << "Invalid Input";
                }
            }
        }
    }
    return 0;

}//main

int login() {
    while (1) {
        std::cout << "Enter 1 for admin 2 for student 3 for instructor and 4 to exit\n";
        int choice = 0;
        std::cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        } else if (choice == 4) {
            loggedIn = false;
            break;
        }
        else { std::cout << "Invalid Entry. Please try again\n"; }
    }
}


//    std::cout << "Enter Username: \n";
//    std::string username;
//    std::cin >> username;
//    std::cout << "Enter Password: \n";
//    std::string password;
//    std::cin >> password;
//    if (username == "Admin" && password == "password") {
//        std::cout << "Authenticated\n";
//        return 1;
//    } else {
//        std::cout << "Please try again\n";
//        return 0;
//    }
//}
