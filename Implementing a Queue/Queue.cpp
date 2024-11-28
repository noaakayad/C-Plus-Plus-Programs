#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    /* YOUR CODE HERE */

    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    /* YOUR CODE HERE */

    Node* copy_head = head;
    while(copy_head != nullptr){
        Node* copy_next = copy_head->next;
        delete copy_head;
        copy_head = copy_next;
    }
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    /* YOUR CODE HERE */

    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    /* YOUR CODE HERE */

    Node* copy_head = head;
    while(copy_head != nullptr){
        Node* copy_next = copy_head->next;
        delete copy_head;
        copy_head = copy_next;
    }

    numElements = 0;
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    /* YOUR CODE HERE */

    Node* new_node = new Node(s);

    if (head == nullptr){
        head = new_node;
        tail = new_node;
        numElements = 1;
    }
    else {
        tail->next = new_node;
        tail = new_node;
        numElements++;
    }
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    /* YOUR CODE HERE */

    if(head == nullptr){
        return "Queue is empty";
    }
    else{
        string data = head->data;
        Node* copy_head = head;
        head = head->next;
        delete copy_head;
        numElements--;

        return data;
    }
}
