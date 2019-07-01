//
// Created by kelleyf on 6/21/2019.
//

#ifndef CURSE_COURSES_H
#define CURSE_COURSES_H

class course{
public:
    std::string name;
    int level = 0;
    int crn =0;
    course() = default;
    ~course() = default;

    void setName(std::string n){
        name = n;
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
    void print(){
        std::cout << "Course name: " + name + "\nCrn: ";
        std::cout << getCrn();
        std::cout << "\nCourse Level: ";
        std::cout << getLevel();
    }
};

#endif //CURSE_COURSES_H
