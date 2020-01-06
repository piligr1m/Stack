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
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push_emplace(3);
    st.push_emplace(4);
    st.push_emplace(5);
    Stack<Student> group;
    group.push_emplace("Martynov", 19, 1111111);
    
    
    for (int i = 0; i < 5; i++) {
        std::cout << st.head() << std::endl;
        st.pop();
    }


}

