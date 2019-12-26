#include <iostream>
#include "Zadanie.h"

int main(int argc, const char * argv[]) {
    // Stack 2
    std::cout << "\nSTACK2<INT> ST2:\n";
    Stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push_emplace(3, 4, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << st2.head() << std::endl;
        st2.pop();
    }
}

