#ifndef TEMPLATESTACK_H
#define TEMPLATESTACK_H

#include <stdexcept>


template <typename T>
class TemplateStack {
private:

    struct Node {
        T data;
        Node* next;
        explicit Node(T val) : data(val), next(nullptr) {}
    };

    Node* topNode;
    size_t size;

public:

    TemplateStack() : topNode(nullptr), size(0) {}


    ~TemplateStack() {
        while (!empty()) {
            pop();
        }
    }


    TemplateStack(const TemplateStack&) = delete;
    TemplateStack& operator=(const TemplateStack&) = delete;


    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }


    void pop() {
        if (empty()) {
            throw std::runtime_error("Попытка pop() из пустого стека");
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }


    T top() const {
        if (empty()) {
            throw std::runtime_error("Попытка top() из пустого стека");
        }
        return topNode->data;
    }


    bool empty() const {
        return size == 0;
    }


    size_t getSize() const {
        return size;
    }
};

#endif
