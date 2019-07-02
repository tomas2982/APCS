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
    std::list<instructor> instructors;
    int choice = 0;
    int x = 0;
    int loggedInCred = 0;
    bool loggedIn = true;
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
                           "\nEnter 6 to add instructor\n";
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
                    std::cout <<"Enter the instructor\n";
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
                    if (courses.size() == NULL) { std::cout << "The course list is already empty\n"; }
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
                }
                else if(choice == 6){

                }
                else if (choice == 0) {
                    std::cout << "exiting\n";
                    break;
                } else { std::cout << "Invalid input\n"; }

            }//while
        }//end admin if
            /**
             * Menu for Student
             */
        else if (loggedInCred == 2) {
            bool run = 1;
            int in = 0;
			//Name of student should be assoc. with credentials.
			std::cout <<"Please enter the name\n"; 
			std::string n = "";
			std::cin.ignore();
            std::getline(std::cin, n);
			stu.setName(n);
            while (run) {
                std::cout << "Enter 1 to register for courses\nEnter 2 to view your schedule\nEnter 0 to logout\n";
                std::cin >> in;
                if (in == 1) {
                    std::cout << "Enter the number of courses to enter\n";
                    std::cin >> x;
                    std::cout << "Enter the " << x << " course(s) crn numbers followed by a newline or space\n";
                    int crns = 0;
                    for (std::list<student>::iterator it = students.begin(); it != students.end(); ++it) 
					{
						if(it->getName()==n)//if name of iterator is set to input name
						{
							std::cin >> crns;
							stu.setCrn(crns);
						}//if
                    }//for loop to go through list of students
                }//if
                else if (in == 2) {
                    //this prints for all students -> should just print the courses for the student
                    for (std::list<student>::iterator it = students.begin(); it != students.end(); ++it) 
					{
						if(it->getName()==n)//if name of iterator is set to input name
						{
							it->print();
							std::cout << "-----------------------\n";
						}//if
                    }
                }//if
                else if (in == 0) {
                    std::cout << "logging out\n";
                    break;
                } else {
                    std::cout << "Invalid input\n";
                }
            }
        }
            /**
             * menu for instructor
             */
        else if (loggedInCred == 3) {
            bool run = 1;
            while (run) {
                std::cout << "Enter 0 to log out\nEnter 1 to print courses\n";
                int in = 1;
                std::cin >> in;
                if (in == 0) {
                    break;

                } else if (in == 1) {
                    //print classes that teacher is teaching
                    for (std::list<course>::iterator it = courses.begin(); it != courses.end(); ++it) {
                        //find if course is for instructor
                        it->print();
                    }
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
        } else if (choice == 4) { exit(0); }
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
