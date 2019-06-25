//Student main
//Written by Forrest Kelley for Applied Programing Concepts with Professor Aaron Carpenter
//https://codereview.stackexchange.com/questions/41525/creating-objects-and-putting-them-into-stdlist for including and initializing syntax
//http://www.cplusplus.com/forum/beginner/107842/ for get and set syntax refresher in class
//http://www.cplusplus.com/reference/list/list/begin/ used for iterator in for loop
//https://www.geeksforgeeks.org/getline-string-c/ for getline()

#include "users.h"
#include "courses.h"


int login();

int main() {
    //list of students
    std::list<student> students;
    std::list<course> courses;
    int choice = 0;
    int x = 0;
    int loggedInCred = 0;
    bool loggedIn = 1;
    loginfunc:
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
                       "\nEnter 0 to exit"
                       "\nEnter 1 to add a student"
                       "\nEnter 2 to print all students"
                       "\nEnter 3 to add new course"
                       "\nEnter 4 to print courses"
                       "\nEnter 5 to logout\n";
            std::cin >> choice;
            if (choice == 1) {
                //add student
                student stu;
                std::cout << "You wish to add a student\n"
                             "Please enter the name\n";
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
            }
            else if (choice == 3){//add course
                course c;
                std::cout <<"You wish to enter a course\n"
                            "Please Enter the course name\n";
                std::string n = "";
                std::cin.ignore();
                std::getline(std::cin, n);
                c.setName(n);
                courses.push_back(c);

                }
            else if(choice == 4){
                for (std::list<course>::iterator it = courses.begin(); it != courses.end(); ++it){
                    it->print();
                    std::cout << "-----------------\n";
                }
            }
            else if (choice == 0) {
                std::cout << "exiting\n";
                break;
            } else if (choice == 5) {
                goto loginfunc;
            } else { std::cout << "Invalid input\n"; }

        }//while
    }//if for admin
    else if (loggedInCred == 2) {
        bool run = 1;
        int in = 0;
        while (run){
                std::cout << "Enter 1 to register for courses\nEnter 2 to view your schedule\nEnter 0 to logout\n";
                std::cin >> in;
                if(in == 1)
                {
                    student stu;
                    std::cout << "Enter the number of courses to enter\n";
                    std::cin >> x;
                    std::cout << "Enter the " << x << " course(s) crn numbers followed by a newline or space\n";
                    int crns = 0;
                    //need to know which student to add crn to
//                    for (std::list<student>::iterator it = students.begin(); it != students.end(); ++it) {
//                        std::cin >> crns;
//                        stu.setCrn(crns);
//                    }
                    //add student to list
                    students.push_back(stu);
                }//if
                else if(in == 2)
                {
                    //this prints for all students -> should just print the courses for the studen
                    for (std::list<student>::iterator it = students.begin(); it != students.end(); ++it) {
                        it->print();
                        std::cout << "-----------------------\n";
                    }
                }//if
                else if(in == 0)
                {
                    std::cout << "logging out\n";
                    goto loginfunc;
                }
                else
                {
                    std::cout << "Invalid input\n";
                }
        }
    }
     else if (loggedInCred == 3) {
        bool run = 1;
        while (run) {
            std::cout << "Enter 0 to log out\n";
            int in = 0;
            std::cin >> in;
            if (in == 0) {
                goto loginfunc;

            }
        }
    }
    return 0;

}//main

int login() {
    while (1) {
        std::cout << "Enter 1 for admin 2 for student and 3 for instructor\n";
        int choice = 0;
        std::cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        } else { std::cout << "Invalid Entry. Please try again\n"; }
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
