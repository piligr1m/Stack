//
//  stack.hpp
//  LW5
//
//  Created by Stanislav Martynov on 03/11/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

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
    stack();
    stack(const stack&) = delete;
    stack& operator=(const stack&) = delete;
    template <class... Args>
    void push_emplace(Args&&... value);
    template<class T1,class... Args>
    void push_emplace1(T1&& value, Args&&... value1);
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    T pop();
    ~stack();
};
template <class T>
stack<T>::stack()
{
    top = nullptr;
}
template <class T>
template <class... Args>
void stack<T>::push_emplace(Args&&... value) //Конструирует элементы "на месте" и вставляет их начиная с заданной позиции pos
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
void stack<T>::push(T&& value) //Вставляет элемент на верх.
{
    Node *node = new Node;
    node->value = value;
    node->next = top;
    top = node;
}
template <typename T>
void stack<T>::push(const T& value) //Вставляет элемент на верх.
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
T stack<T>::pop() //Удаляет верхний элемент.
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
#endif /* stack_hpp */

