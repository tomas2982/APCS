//
// Created by kelleyf on 6/21/2019.
//

#ifndef CURSE_COURSES_H
#define CURSE_COURSES_H

class course{
public:
    std::string name, instructor;
    int level = 0;
    int crn =0;
    course() = default;
    ~course() = default;

    void setName(std::string n){
        name = n;
    }
    void setInstructor(std::string in){
        instructor = in;
    }
    void setLevel(int l){
        level = l;
    }
    void setCrn(int crnNum){
        crn = crnNum;
    }
    int getCrn(){
        return crn;
    }
    int getLevel(){
        return level;
    }
    std::string getInstructor(){
        return instructor;
    }
    void print(){
        std::cout << "Course name: " + name + "\nCrn: ";
        std::cout << getCrn();
        std::cout << "\nCourse Level: ";
        std::cout << getLevel();
        std::cout << "\nInstructor: " + getInstructor();
    }
};

#endif //CURSE_COURSES_H
