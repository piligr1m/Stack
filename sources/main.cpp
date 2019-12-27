#include <iostream>
#include "Zadanie.h"

int main(int argc, const char * argv[]) {
    std::cout << "\nSTACK<INT> ST:\n";
    Stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push_emplace(3, 4, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << st2.head() << std::endl;
        st2.pop();
    }
}

