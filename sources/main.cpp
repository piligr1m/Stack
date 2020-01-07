#include "stack.h"
#include <iostream>

struct Student
{
    int course;
    int age;
    int stipendia;
};
int main(int argc, const char * argv[]) {
    std::cout << "Stack:" << std::endl;
    Stack<Student> group;
    group.push_emplace(2, 19, 1111111);
    group.head();
    group.pop();
}

