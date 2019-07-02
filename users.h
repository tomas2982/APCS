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
    void setName(std::string n) {
        name = std::move(n);
    }
    void setEmail(std::string e){
        email = e;
    }
    std::string getName(){
        return name;
    }
    std::string getEmail(){
        return email;
    }
};

class student : public user {
protected:
    std::string major;
    std::list<int> crn;
public:
    student() = default;

    ~student() = default;



    void setMajor(std::string m) {
        major = std::move(m);
    }

    void setCrn(int number) {
        crn.push_back(number);

    }

    void print() {
        std::cout << "Name: " + name + "\nMajor: " + major + "\nRegistered classes:";
        for (int &it : crn) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }

};

class admin : public user{

};

class instructor : public user{

};
#endif //UNTITLED_STUDENT_H
