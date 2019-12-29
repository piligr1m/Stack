#ifndef Zadanie_h
#define Zadanie_h
#include <iostream>
#include <memory>

template <typename T>
class Stack
{
private:
    static const unsigned int st_capacity = 32; 
    unsigned int capacity;
    unsigned int size; 
    std::unique_ptr<T> st_ptr;

public:
    Stack();
    Stack(const Stack<T>& stack) = delete;
    Stack(Stack<T>&& stack);
    ~Stack() = default;

    Stack<T>& operator=(const Stack<T>& stack) = delete;
    Stack<T>& operator=(Stack<T>&& stack);

    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(const T& value);
    void push(T&& value);
    T pop();

    bool isEmpty() const;
    bool isFull() const;

    const T& head() const;
};

template <typename T>
Stack<T>::Stack() {
    this->capacity = this->st_capacity;
    this->size = 0;
    this->st_ptr.reset(new T [this->st_capacity]);
}

template <typename T>
Stack<T>::Stack(Stack<T>&& stack) {
    std::swap(this->capacity, stack.capacity);
    std::swap(this->size, stack.size);
    std::swap(this->st_ptr, stack.st_ptr);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& stack) {
    if(std::move(stack) != this) {
        std::swap(this->capacity, stack.capacity);
        std::swap(this->size, stack.size);
        std::swap(this->st_ptr, stack.st_ptr);
    }

    return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
    this->size++;
    if (this->size > this->capacity && !this->isFull()) {
        this->capacity *= 2;

        std::unique_ptr<T> new_st(new T [this->capacity]);

        for(int i = 0; i < this->size - 1; i++) {
            new_st.get()[i] = this->st_ptr.get()[i];
        }
        new_st.get()[this->size - 1] = value;

        this->st_ptr.swap(new_st);
    }
    else if (this->isFull()) {
        throw std::logic_error("Stack is full");
        this->size--;
    }
    else
        this->st_ptr.get()[this->size - 1] = value;
}

template <typename T>
void Stack<T>::push(T&& value) {
    this->size++;
    if (this->size > this->capacity && !this->isFull()) {
        this->capacity *= 2;

        std::unique_ptr<T> new_st(new T [this->capacity]);

        for(int i = 0; i < this->size - 1; i++) {
            new_st.get()[i] = this->st_ptr.get()[i];
        }
        new_st.get()[this->size - 1] = std::move(value);

        this->st_ptr.swap(new_st);
    }
    else if (this->isFull()) {
        throw std::logic_error("Stack is full");
        this->size--;
    }
    else this->st_ptr.get()[this->size - 1] = std::move(value);
}

template <typename T>
template <typename ... Args>
void Stack<T>::push_emplace(Args&&... value) {
    T args [] = {value...};

    for(const auto& e: args) {
        this->push(e);
    }
}

template <typename T>
T Stack<T>::pop() {
    if(!this->isEmpty()) {
        this->size--;
    }
    else
        throw std::logic_error("Stack is empty");


}

template <typename T>
bool Stack<T>::isEmpty() const {
     return this->size == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
     return this->size > 65536;
}

template <typename T>
const T& Stack<T>::head() const {
    if (!this->isEmpty())
        return this->st_ptr.get()[this->size - 1];
    else
        throw std::logic_error("Stack IS EMPTY");
}

#endif /* Zadanie_h */
