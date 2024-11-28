#include <queue>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "HCTree.hpp"
#include "Helper.hpp"
using namespace std;

void delete_node(HCNode* node){
    if(!node){
        return;
    }
    delete_node(node->c0);
    delete_node(node->c1);
    delete node;
}

HCTree::~HCTree(){
    delete_node(root);
}

void HCTree::build(const vector<int>& freqs) {
    priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;

    for (int i = 0; i < int(freqs.size()); i++) {
        if (freqs[i] > 0) {
            HCNode* node = new HCNode(freqs[i], char(i));
            pq.push(node);
            leaves[i] = node; 
        }
    }

    while (pq.size() > 1) {
        HCNode* first = pq.top(); pq.pop();
        HCNode* second = pq.top(); pq.pop();

        HCNode* parent = new HCNode(first->count + second->count, first->symbol);
        parent->c0 = first;
        parent->c1 = second;

        first->p = parent;
        second->p = parent;

        pq.push(parent);
    }

    if(!pq.empty()){
        root = pq.top();
    }
    else {
        root = nullptr;
    }
}

void HCTree::encode(unsigned char symbol, FancyOutputStream & out) const {
    if (symbol >= leaves.size() || !leaves[symbol]) {
        error("Symbol not recognized");
    }

    HCNode* curr = leaves[symbol];
    vector<int> seq;

    while (curr && curr->p) {
        seq.push_back((curr == curr->p->c0) ? 0 : 1);
        curr = curr->p;
    }

    for (int i = seq.size() - 1; i >= 0; --i) {
        out.write_bit(seq[i]);
    }
}

unsigned char HCTree::decode(FancyInputStream& in) const {
    HCNode* curr = root;
    if (!curr) {
        error("Huffman tree root is null");
    }

    while (true) {
        int curr_num = in.read_bit();
        if (curr_num == -1){
            error("Reached end of stream without finding a leaf");
        }

        if (curr_num == 0) {
            if (!curr->c0) {
                error("Invalid bit sequence: 0 leads to null");
            }
            curr = curr->c0;
        } 
        else {
            if (!curr->c1) {
                error("Invalid bit sequence: 1 leads to null");
            }
            curr = curr->c1;
        }

        if (!curr->c0 && !curr->c1) {
            return curr->symbol;
        }
    }
}

