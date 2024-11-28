#include "BST.h"

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */

    root = nullptr;
    numElements = 0;
}

void delete_recurrence(BST::Node* n){
    if(n != nullptr){
        delete_recurrence(n->leftChild);
        delete_recurrence(n->rightChild);
        delete n;
    }
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    delete_recurrence(root);
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    delete_recurrence(root);
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    Node* new_node = new Node(element);
    if(numElements == 0){
        root = new_node;
        numElements += 1;
        return true;
    }
    else {
        Node* current = root;
        while(current->data != element){
            if (current->data > element){
                if (current->leftChild == nullptr){
                    current->leftChild = new_node;
                    numElements += 1;
                    new_node->parent = current;
                    return true;
                }
                else{
                    current = current->leftChild;
                }
            }
            else if(current->data < element){
                if (current->rightChild == nullptr){
                    current->rightChild = new_node;
                    numElements += 1;
                    new_node->parent = current;
                    return true;
                }
                else{
                    current = current->rightChild;
                }
            }
        }
        delete new_node;
        return false;
    }
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */

    Node* current = root;

    while(current != nullptr){
        if(current->data == query){
            return true;
        }
        else if (current->data < query){
            current = current->rightChild;
        }
        else {
            current = current->leftChild;
        }
    }

    return false;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */

    Node* left = root;

    if (left == nullptr){
        return nullptr;
    }
    else {
        while(left->leftChild != nullptr){
            left = left->leftChild;
        }
        return left;
    }
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */

    if(this->rightChild != nullptr){
        Node* left = this->rightChild;
        while(left->leftChild != nullptr){
            left = left->leftChild;
        }
        return left;
    }
    else {
        Node* current = this;

        while(current->parent != nullptr){
            if (current->parent->leftChild == current){
                return current->parent;
            }
            else {
                current = current->parent;
            }
        }

        return nullptr;
    }
}
