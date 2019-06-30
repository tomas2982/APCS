//
// Created by kelleyf on 6/21/2019.
//

#ifndef CURSE_COURSES_H
#define CURSE_COURSES_H

class course{
public:
    std::string name, level;
    int crn =0;
    course() = default;
    ~course() = default;

    void setName(std::string n){
        name = n;
    }
    void setCrn(int crnNum){
        crn = crnNum;
    }
    int getCrn(){
        return crn;
    }
    void print(){
        std::cout << "Course name:" + name + "\nCrn:";
        std::cout << getCrn();
    }
};

#endif //CURSE_COURSES_H
