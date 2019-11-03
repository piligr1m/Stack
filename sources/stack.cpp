#include "stack.hpp"
#include <iostream>
#include <complex>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    cout << "head of stack after push: " << st.head() << endl;
    st.push_emplace(1,2,3);
    cout << "head of stack after emplace: " << st.head() << endl;
    st.push_emplace(4);
    cout << "head of stack after emplace: " << st.head() << endl;
    st.push_emplace(5);
    cout << "head of stack after emplace: " << st.head() << endl;
    st.pop();
    cout << "head of stack after pop: " << st.head() << endl;
    st.pop();
    cout << "head of stack after pop: " << st.head() << endl;
    st.pop();
    cout << "head of stack after pop: " << st.head() << endl;
}
