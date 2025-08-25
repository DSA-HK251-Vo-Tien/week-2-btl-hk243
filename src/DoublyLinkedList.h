#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "main.h"

template <typename T>
class DoublyLinkedList
{
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node() : data(T()), prev(nullptr), next(nullptr) {}
        Node(const T& val, Node* prev = nullptr, Node* next = nullptr)
            : data(val), prev(prev), next(next) {}
    };

    Node* head; // dummy head
    Node* tail; // dummy tail
    int length;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // rule of 3
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    void insertAtHead(T data);
    void insertAtTail(T data);
    void insertAt(int index, T data);
    void deleteAt(int index);
    T& get(int index) const;
    int indexOf(T item) const;
    bool contains(T item) const;
    int size() const;
    void reverse();
    void clear();
    std::string toString(std::string (*convert2str)(T&) = nullptr) const;

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() const { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        Iterator operator++(int) { Iterator tmp=*this; current=current->next; return tmp; }
        Iterator& operator--() { current = current->prev; return *this; }
        Iterator operator--(int) { Iterator tmp=*this; current=current->prev; return tmp; }
        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() const { return Iterator(head->next); }
    Iterator end() const { return Iterator(tail); }
};

#endif // __DOUBLY_LINKED_LIST_H__
