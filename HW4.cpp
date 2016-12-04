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

    //typedef element_type& reference;
    //explicit linkedlist(size_t n);
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
    Node* previous;
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

bool LinkedList::isEmpty() const {
    if(head->next == tail)
        return true;
    return false;
}

void LinkedList::clear() {
    current = head->next;
    while(current != nullptr) {
            current->elem = 0;
    }
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

LinkedList& LinkedList::operator=(const LinkedList& ll) { ///NEED
    //this->elem = ll.
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

void LinkedList::push_back(const element_type& tailNode) { ///NEED
    Node* newNode = new Node();
    newNode->elem = tailNode.elem;

}

void LinkedList::push_front(const element_type& headNode) { ///NEED

}

void LinkedList::sort() {
    if(head == tail)
        return;

    Node* i = nullptr;
    element_type swapValue;
    while(current != nullptr) {
        for(i = head->next; i != nullptr; i = i->next) {
            if(current->elem > i-> elem) {
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
