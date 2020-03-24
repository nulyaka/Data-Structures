  
//
//  binary-tree-using-linkedlistqueue.cpp
//  binary-tree-using-linkedlistqueue
//
//  Created by Nulyaka on 2/3/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include "linkedlistqueue.h"

class BinTreeNode{
public:
    int data;
    BinTreeNode *lChild;
    BinTreeNode *rChild;
};

class BinTreeList{
private:
    BinTreeNode *root;
public:
    BinTreeList() { root = nullptr; }
    
    void create();
    BinTreeNode* getRootPointer();
    
    void displayPreOrder(BinTreeNode *currentNode);
    void displayInOrder(BinTreeNode *currentNode);
    void displayPostOrder(BinTreeNode *currentNode);
    
};

BinTreeNode* BinTreeList::getRootPointer() {
    
    BinTreeNode *temp = root;
    
    return temp;
}

void BinTreeList::create() {
    
    root = new BinTreeNode;
    root->lChild = root->rChild = nullptr;
    
    std::cout << "Enter a root value: ";
    std::cin >> root->data;
    
    QueueLL<BinTreeNode*> queue;
    queue.enqueue(root);
    
    while ( !queue.isEmpty() ) {
        
        int tempData(0);
        BinTreeNode *currentNode = queue.dequeue(),
                    *tempNode = nullptr;
        
        // creating left child for current node
        std::cout << "Enter left child value of " << currentNode->data << ": ";
        std::cin >> tempData;
        
        if (tempData != -1) {
            
            tempNode = new BinTreeNode;
            tempNode->data = tempData;
            tempNode->lChild = tempNode->rChild = nullptr;
            currentNode->lChild = tempNode;
            queue.enqueue(tempNode);
        }
        
        // creating right child for current node
        std::cout << "Enter right child value of " << currentNode->data << ": ";
        std::cin >> tempData;
        
        if (tempData != -1) {
            
            tempNode = new BinTreeNode;
            tempNode->data = tempData;
            tempNode->lChild = tempNode->rChild = nullptr;
            currentNode->rChild = tempNode;
            queue.enqueue(tempNode);
        }
    }
}

void BinTreeList::displayPreOrder(BinTreeNode *currentNode) {
    
    if (currentNode != nullptr) {
        
        std::cout << currentNode->data << ' ';
        displayPreOrder(currentNode->lChild);
        displayPreOrder(currentNode->rChild);
    }
}

void BinTreeList::displayInOrder(BinTreeNode *currentNode) {
    
    if (currentNode != nullptr) {
        
        displayInOrder(currentNode->lChild);
        std::cout << currentNode->data << ' ';
        displayInOrder(currentNode->rChild);
    }
}

void BinTreeList::displayPostOrder(BinTreeNode *currentNode) {
    
    if (currentNode != nullptr) {
        
        displayPostOrder(currentNode->lChild);
        displayPostOrder(currentNode->rChild);
        std::cout << currentNode->data << ' ';
    }
}

