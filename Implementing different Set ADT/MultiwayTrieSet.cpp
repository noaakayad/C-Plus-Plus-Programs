#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    root = nullptr;
    numElements = 0;
}


/**
 * Implement the MultiwayTrieSet destructor
 */
void delete_(MultiwayTrieSet::Node* node){
    if(node != nullptr){
        for(auto &child : node->children){
            delete_(child.second);
        }
        delete(node);
    }
}

MultiwayTrieSet::~MultiwayTrieSet() {
    /* YOUR CODE HERE */
    delete_(root);
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    /* YOUR CODE HERE */
    return numElements;
}

bool MultiwayTrieSet::find(const string & s) {
    /* YOUR CODE HERE */
    Node* curr = root;
    for(auto &c : s){
        if (curr == nullptr ||curr->children.find(c) == curr->children.end()){
            return false;
        }
        else {
            curr = curr->children[c];
        } 
    }

    if(curr->isWord){
        return true;
    }
    else {
        return false;
    }
}

void MultiwayTrieSet::insert(string s) {
    /* YOUR CODE HERE */
    if(root == nullptr){
        root = new Node();
    }

    Node* curr = root;

    for (auto &c : s){
        if(curr->children.find(c) == curr->children.end()){
            curr->children[c] = new Node;
        }
        curr = curr->children[c];
    }

    if(!curr->isWord){
        curr->isWord = true;
        numElements++;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if(root == nullptr){
        return;
    }

    Node* curr = root;

    for(auto &c : s){
        if (curr->children.find(c) == curr->children.end()){
            return;
        }
        else {
            curr = curr->children[c];
        }
    }

    if(curr->isWord){
        curr->isWord = false;
        numElements --;
    }
}


