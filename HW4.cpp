#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef int element_type;
typedef element_type& reference;
typedef const element_type& const_reference;

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    explicit LinkedList(size_t n);

    // methods
    bool isEmpty() const;
    void clear();
    reference back();
    const_reference back() const;
    reference front();
    const_reference front() const;
    LinkedList& operator=(const LinkedList& ll);
    void pop_back();
    void pop_front();
    void push_back(const element_type& x);
    void push_front(const element_type& x);
    void sort();

    void check() const;
    void rcheck() const;

private:
    struct Node {
        element_type elem;
        Node* next;
        Node* prev;
        };
    Node* head;
    Node* tail;
    Node* current;
    size_t numElements;
};

LinkedList::LinkedList() {
    numElements = 0;
    head = new Node;
    tail = new Node;

    tail->next = nullptr;
    tail->prev = head;

    head->next = tail;
    head->prev = nullptr;
}

LinkedList::~LinkedList() {
    numElements = 0;
    tail->next = nullptr;
    tail->prev = head;
    head->next = tail;
    head->prev = nullptr;
}

LinkedList::LinkedList(size_t n) {
    numElements = 0;
    head = new Node;
    tail = new Node;

    tail->next = nullptr;
    tail->prev = head;

    head->next = tail;
    head->prev = nullptr;
    for(int i = 0; i < n; ++i) {
        push_back(i);
    }
}

bool LinkedList::isEmpty() const {
    if(head->next == tail)
        return true;
    return false;
}

void LinkedList::clear() {
    current = head->next;
    Node* nodeToDelete = nullptr;
    while(current != nullptr) {
            nodeToDelete = current;
            current->elem = -1;
            current->prev = nullptr;
            current = current->next;
            nodeToDelete->next = nullptr;
            delete nodeToDelete;
    }
    head = nullptr;
    numElements = 0;
}

reference LinkedList::back() {
    return tail->prev->elem;
}

const_reference LinkedList::back() const {
    return tail->prev->elem;
}

reference LinkedList::front() {
    return head->next->elem;
}

const_reference LinkedList::front() const {
    return head->next->elem;
}

LinkedList& LinkedList::operator=(const LinkedList& ll) {
    current = ll.head;
    if(this != &ll) {
        clear();
        while(current != nullptr) {
        push_back(current->elem);
        current = current->next;
        }
    }
}

void LinkedList::pop_back() {
    current = tail;
    tail = tail->prev;
    delete current;
}

void LinkedList::pop_front() {
    current = head;
    head = head->next;
    delete current;
}

void LinkedList::push_back(const element_type& x) {
    Node* newNode = new Node();
    newNode->elem = x;
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
}

void LinkedList::push_front(const element_type& x) {
    Node* newNode = new Node();
    newNode->elem = x;
    newNode->prev = head;
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
}

void LinkedList::sort() {
    if(head->next == tail)
        return;

    Node* i = nullptr;
    element_type swapValue;
    while(current != nullptr) {
        for(i = current->next; i != nullptr; i = i->next) {
            if(current->elem > i->elem) {
                swapValue = current->elem;
                current->elem = i->elem;
                i->elem = swapValue;
            }
        }
        current = current->next;
    }
}

void LinkedList::check() const {
    Node* t = head;
    while(t != nullptr) {
        cout << t->elem << endl;
        t = t->next;
    }
    cout << endl;
}

void LinkedList::rcheck() const {
    Node* t = tail;
    while(t != nullptr) {
        cout << t->elem << endl;
        t = t->prev;
    }
    cout << endl;
}


int main() {

    return 0;
}
