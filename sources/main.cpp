#include "stack.h"
#include <iostream>

struct Student
{
    std::string name;
    int age;
    int stipendia;
    friend std::ostream& operator <<(std::ostream& out, Student group)
    {
       out<<group.name<<group.age<<group.stipendia;
        return out;
    }
};
int main(int argc, const char * argv[]) {
    std::cout << "Stack:" << std::endl;
    Stack<Student> group;
    group.push_emplace("aaa", 19, 1111111);
    std::cout<<group.head();
}

