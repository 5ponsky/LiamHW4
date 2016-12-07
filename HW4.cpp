#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
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
    Node* t = head->next;
    Node* nodeToDelete;
    while(t->next != nullptr) {
            nodeToDelete = t;
            t->elem = -1;
            t->prev = nullptr;
            t = t->next;
            nodeToDelete->next = nullptr;
            delete nodeToDelete;
    }
    head->next = tail;
    tail->prev = head;
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

LinkedList& LinkedList::operator=(const LinkedList& listToCopy) {
    Node* t = listToCopy.head->next;
    if(this != &listToCopy) {
        clear();
        while(t->next != nullptr) {
            push_back(t->elem);
            t = t->next;
        }
    }
}

void LinkedList::pop_back() {
    Node* t = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = tail;
    delete t;
    --numElements;
}

void LinkedList::pop_front() {
    Node* t = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    delete t;
    --numElements;
}

void LinkedList::push_back(const element_type& x) {
    Node* newNode = new Node();
    newNode->elem = x;
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
    ++numElements;
}

void LinkedList::push_front(const element_type& x) {
    Node* newNode = new Node();
    newNode->elem = x;
    newNode->prev = head;
    newNode->next = head->next;
    head->next->prev = newNode;
    head->next = newNode;
    ++numElements;
}

void LinkedList::sort() {
    if(head->next == tail)
        return;

    Node* i;
    Node* t = head->next;
    element_type swapValue;
    while(t != nullptr) {
        for(i = t->next; i != nullptr; i = i->next) {
            if(t->elem > i->elem) {
                swapValue = t->elem;
                t->elem = i->elem;
                i->elem = swapValue;
            }
        }
        t = t->next;
    }
}

void LinkedList::check() const {
    Node* t = head->next;
    if(head->next == tail)
        return;
    while(t->next != nullptr) {
        cout << t->elem << endl;
        t = t->next;
    }
    cout << endl;
}

void LinkedList::rcheck() const {
    Node* t = tail->prev;
    if(tail->prev == head)
        return;
    while(t->prev != nullptr) {
        cout << t->elem << endl;
        t = t->prev;
    }
    cout << endl;
}


int main() {

    // Demonstrating default constructor
    list<int> list1;
    LinkedList list1a;

    // Explicit "constructor"
    list<int> list2(3);
    LinkedList list2a(3);


    //Checking Empty/Non-empty status
    if(list1.empty())
        cout << "Classic List Empty\n";
    if(list1a.isEmpty())
        cout << "Re-implementation list empty\n";

    if(list2.empty())
        cout << "Classic List Empty\n";
    if(list2a.isEmpty())
        cout << "Re-implementation list empty\n";

    //Checking push_front, push_back
    list1.push_back(3);
    list1.push_back(10);
    list1.push_back(5);
    list1.push_front(7);

    list1a.push_back(3);
    list1a.push_back(10);
    list1a.push_back(5);
    list1a.push_front(7);

    //Checking Print functions
    list1a.check(); // Did everything append and prepend properly?
    list1a.rcheck();

    cout << "Front of list: " << list1a.front() << endl;
    cout << "Back of list: " << list1a.back() << endl;

    //Check clear
    if(!list1.empty())
        cout << "Classic List NOT Empty\n";
    if(!list1a.isEmpty())
        cout << "Re-implementation list NOT empty\n";

    list1.clear();
    list1a.clear();

    if(list1.empty())
        cout << "Classic List Empty\n";
    if(list1a.isEmpty())
        cout << "Re-implementation list empty\n";

    LinkedList list3a;
    list3a.push_back(10);
    list3a.push_back(6);
    list3a.push_back(7);
    list3a.push_back(34);

    //Operator Overloading
    list1a = list3a;

    list1a.check();
    list1a.rcheck();



    //Pop methods
    list1a.pop_front();
    list1a.check();
    list1a.rcheck();

    list1a.pop_back();
    list1a.check();
    list1a.rcheck();

    //Sort
    list1a.push_back(12);
    list1a.push_back(4);
    list1a.push_back(1);
    list1a.push_back(23);

    list1a.sort();
    list1a.check();
    list1a.rcheck();

    return 0;

}





