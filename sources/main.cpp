#include "stack.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Stack:" << std::endl;
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push_emplace(3, 4, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << st.head() << std::endl;
        st.pop();
    }


}

