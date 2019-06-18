//Student main
//Written by Forrest Kelley for Applied Programing Concepts with Professor Aaron Carpenter
//https://codereview.stackexchange.com/questions/41525/creating-objects-and-putting-them-into-stdlist for including and initializing syntax
//http://www.cplusplus.com/forum/beginner/107842/ for get and set syntax refresher in class
//http://www.cplusplus.com/reference/list/list/begin/ used for iterator in for loop
//https://www.geeksforgeeks.org/getline-string-c/ for getline()

#include "student.h"


int login();

int main() {
    int choice = 0;
    int x = 0;
    int loggedIn = 0;
    while (!loggedIn) {
        loggedIn = login();
    }
    //list of students
    std::list<student> students;
    while (1) {
        std::cout
                << "Welcome to course registration main menu!\nEnter 1 to add a student\nEnter 2 to print all\nEnter 0 to exit\n";
        std::cin >> choice;
        if (choice == 1) {
            //add student
            student stu;
            std::cout << "You wish to add a student\nPlease enter the name\n";
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
                std::cout << "---------------------\n";
            }
        } else if (choice == 0) {
            std::cout << "exiting\n";
            break;
        } else { std::cout << "Invalid input\n"; }

    }//while
    return 0;
}//main

int login() {
    std::cout << "Enter Username: \n";
    std::string username;
    std::cin >> username;
    std::cout << "Enter Password: \n";
    std::string password;
    std::cin >> password;
    if (username == "Admin" && password == "password") {
        std::cout << "Authenticated\n";
        return 1;
    } else {
        std::cout << "Please try again\n";
        return 0;
    }
}