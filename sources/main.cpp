#include "stack.h"
#include <iostream>

struct Student
{
    std::string Name;
    int age;
    int stipendia;
};
int main(int argc, const char * argv[]) {
    std::cout << "Stack:" << std::endl;
    Stack<Student> group;
    group.push_emplace("aa", 19, 1111111);
    std::cout<<group.head();
    group.pop();
}

