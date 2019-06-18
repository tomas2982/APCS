//
// Created by kelleyf on 6/17/2019.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <iostream>
#include <list>
#include <fstream>
class user{
protected:
    std::string name;
};

class student : public user {
protected:
    std::string major;
    std::list<int> crn;
public:
    student(){
    }
    ~student(){}

    void setName(std::string n){
        name = n;
    }
    void setMajor(std::string m){
        major = m;
    }
    void setCrn(int number){
        crn.push_back (number);

    }

    void print(){
        std::cout << "Name: " + name + "\nMajor: " + major + "\nRegistered classes:";
        for(std::list<int>::iterator it=crn.begin(); it != crn.end(); it++){
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

};

#endif //UNTITLED_STUDENT_H
