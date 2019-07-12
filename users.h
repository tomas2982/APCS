//
// Created by kelleyf on 6/17/2019.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>

class user {
public:
    std::string name, email;
    int id;

    void setId(int idNum) {
        id = idNum;
    }

    int getId() { return id; }

    void setName(std::string n) {
        name = n;
    }

    void setEmail(std::string e) {
        email = e;
    }

    std::string getName() {
        return name;
    }

    std::string getEmail() {
        return email;
    }
};

class student : public user {
protected:
    std::string major;
    std::list<int> crn;
public:
    student(){}

    ~student() {}

    void setMajor(std::string m) {
        major = m;
    }

    void setCrn(int number) {
        crn.push_back(number);

    }
    std::list<int> getCrnList(){
        return crn;
    }
    int studentInCourse(int numbers){
        for (std::list<int>::iterator t = crn.begin(); t != crn.end(); ++t){
            if( *t == numbers){
                return numbers;
            }
            else{
                return 0;}
        }
    }
    void print() {
        std::cout << "ID: " << getId() << "\n" << "Name: " + name + "\nMajor: " + major + "\nRegistered classes:";
        for (std::list<int>::iterator it = crn.begin(); it != crn.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

};

class admin : public user {

};

class instructor : public user {

};

#endif //UNTITLED_STUDENT_H
