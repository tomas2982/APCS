//
// Created by kelleyf on 6/21/2019.
//

#ifndef CURSE_COURSES_H
#define CURSE_COURSES_H

class course{
public:
    std::string name;
    course() = default;
    ~course() = default;

    void setName(std::string n){
        name = n;
    }
    void print(){
        std::cout << "Course name is :" + name + "\n";
    }
};

#endif //CURSE_COURSES_H
