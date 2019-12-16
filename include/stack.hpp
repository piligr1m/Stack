//
//  stack.hpp
//  LW5
//
//  Created by Stanislav Martynov on 03/11/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <initializer_list>
#include <stdarg.h>
template <class T>
class stack
{
    struct Node
    {
        T value;
        Node *next;
    };
    Node *top;
public:
    stack(); // Default constructor.
    stack(const stack&) = delete;
    stack& operator=(const stack&) = delete;
    template <class... Args>
    void push_emplace(Args&&... value);
    template<class T1,class... Args>
    void push_emplace1(T1&& value, Args&&... value1); //constructs element in-place at the top
    void push(T&& value); // inserts element at the top
    void push(const T& value);
    const T& head() const;
    T pop(); // removes the top element
    ~stack(); //destructor
};
template <class T>
stack<T>::stack()
{
    top = nullptr;
}
template <class T>
template <class... Args>
void stack<T>::push_emplace(Args&&... value)
{
    for (auto p : std::initializer_list<T>{value...})
    {
        Node *node = new Node;
        node->value = p;
        node->next = top;
        top = node;
    }
}
template <class T>
void stack<T>::push(T&& value)
{
    Node *node = new Node;
    node->value = value;
    node->next = top;
    top = node;
}
template <typename T>
void stack<T>::push(const T& value)
{
    Node *node = new Node;
    node->value = value;
    node->next = top;
    top = node;
}
template <class T>
const T& stack<T>::head() const
{
    return top->value;
}
template <class T>
T stack<T>::pop() 
{
    T value = top->value;
    Node *tmp = top;
    top = top->next;
    delete tmp;
    return value;
}

template <class T>
stack<T>::~stack()
{
    while (top)
    {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
}
#endif /* Stack_hpp */
