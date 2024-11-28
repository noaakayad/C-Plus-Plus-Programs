#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */
int height(BinaryTree::Node* root){
    if(root == nullptr){
        return 0;
    }
    
    else {
        return max(1 + height(root->leftChild), 1 + height(root->rightChild));
    }
}

int bf(BinaryTree::Node* node){
    if(node == nullptr){
        return 0;
    }
    
    else {
        return height(node->rightChild) - height(node->leftChild);
    }
}

void recursiveBF(unordered_map<int, int> &map, BinaryTree::Node* node){
    if(node != nullptr){
        map[node->label] = bf(node);
        recursiveBF(map, node->leftChild);
        recursiveBF(map, node->rightChild);
    }
}

unordered_map<int,int> BinaryTree::balanceFactors() {
    unordered_map<int, int> map;

    recursiveBF(map, root);
    return map;
}
