// 
//  binary-search-tree.cpp
//  binary-search-tree
//
//  Created by Nulyaka on 2/2/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector> // used in creation of BST
#include <stack>  // used in inOrder, postOrder creation of BST

struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;
};

Node* binarySearchTree (Node* root_copy, int key) {
    
    Node* curr = root_copy;
    
    while (curr != nullptr) {
        
        if (curr->data == key) {
            return curr;
        }
        else if(curr->data > key) {
            curr = curr->leftChild;
        }
        else if(curr->data < key) {
            curr = curr->rightChild;
        }
    }
    return nullptr;
}

Node* recursiveBST (Node* root_copy, int key) {
    
    Node* curr = root_copy;
    
    if (curr == nullptr) {
        return nullptr;
    }
    else if (curr->data == key) {
        return curr;
    }
    else if (curr->data > key) {
        curr = recursiveBST(curr->leftChild, key);
    }
    else if (curr->data < key) {
        curr = recursiveBST(curr->rightChild, key);
    }
    return curr;
}

void insertBST (Node* root_copy, int key) {
    
    Node* curr = root_copy;
    Node* currParent = curr;
    
    while (curr != nullptr) {
        
        currParent = curr;
        
        if (curr->data == key) {
            return;
        }
        else if (curr->data > key) {\
            curr = curr->leftChild;
        }
        else if (curr->data < key) {
            curr = curr->rightChild;
        }
    }
    
    Node* temp = new Node;
    temp->data = key;
    temp->leftChild = temp->rightChild = nullptr;
    
    if (curr->data < currParent->data) {
        currParent->leftChild = curr;
    }
    else {
        currParent->rightChild = curr;
    }
}

Node* insertRecursiveBST (Node* root_copy, int data) {
    
    Node* curr = root_copy;
    Node* temp;
    
    if (curr == nullptr) {
        temp = new Node;
        temp->data = data;
        temp->leftChild = temp->rightChild = nullptr;
        return temp;
    }
    else if (curr->data > data) {
        return curr->leftChild = insertRecursiveBST(curr->leftChild, data);
    }
    else if (curr->data < data) {
        return curr->rightChild = insertRecursiveBST(curr->rightChild, data);
    }
    
    return curr;
}

Node* createBST (const std::vector<int>& data) {
    
    Node* root;
    
    root = new Node;
    root->data = data.at(0);
    root->leftChild = root->rightChild = nullptr;
    
    for (int i(1); i < data.size(); ++i) {
        
        insertBST(root, data.at(i));
    }
    
    return root;
}

// using stack
Node* inOrderCreateBST (std::vector<int>& data) {
    
    std::stack<Node*> stackBST;
    
    Node* root = new Node;
    int it(0);
    root->data = data.at(it++);
    root->leftChild = root->rightChild = nullptr;
    
    Node* curr = root;
    
    while(it < data.size()) {
        
        if (data.at(it) < curr->data) {
            
            Node* temp = new Node;
            temp->data = data.at(it++);
            temp->leftChild = temp->rightChild = nullptr;
            curr->leftChild = temp;
            stackBST.push(curr);
            curr = temp;
        }
        else {
            
            if (data.at(it) > curr->data &&
                data.at(it) < stackBST.top()->data) {
                
                Node *temp = new Node;
                temp->data = data.at(it++);
                temp->leftChild = temp->rightChild = nullptr;
                curr->leftChild = temp;
                curr = temp;
            }
            else {
                curr = stackBST.top();
                stackBST.pop();
            }
        }
    }
    
    return root;
}

void inOrderDisplayBST (Node* root_copy) {
    
    Node* curr = root_copy;
    
    if (curr != nullptr) {
        
        inOrderDisplayBST(curr->leftChild);
        std::cout << curr->data;
        inOrderDisplayBST(curr->rightChild);
    }
}

int heightBST (Node* currNode) {
    
    int heightLeft(0), heightRight(0);
    
    if (currNode == nullptr) {
        return 0;
    }
    
    heightLeft = heightBST(currNode->leftChild);
    heightRight = heightBST(currNode->rightChild);
    
    return heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
}

// both getRightMostNode and getLeftMostNode used in deleteFromBST
// to replace deleted node with one of them
Node* getRightMostNode (Node *currNode) {
    
    while (currNode && currNode->rightChild != nullptr) {
        currNode = currNode->rightChild;
    }
    return currNode;
}
Node* getLeftMostNode (Node *currNode) {
    
    while (currNode && currNode->leftChild != nullptr) {
        currNode = currNode->leftChild;
    }
    return currNode;
}

Node* deleteFromBST (Node* currNode, int key) {
    
    if (currNode == nullptr) {
        return nullptr;
    }
    else if (currNode->leftChild == nullptr && currNode->rightChild == nullptr) {
        delete currNode;
    }
    
    // searching for node with value key
    if (currNode->data > key) {
        currNode->leftChild = deleteFromBST(currNode->leftChild, key);
    }
    else if (currNode->data < key) {
        currNode->rightChild = deleteFromBST(currNode->rightChild, key);
    }
    else { // found key
        
        Node* temp;
        
        // depending on heights of childs
        // replacing deleted node with node before or after inOrder
        if (heightBST(currNode->leftChild) > heightBST(currNode->rightChild)) {
            
            temp = getRightMostNode(currNode->leftChild);
            currNode->data = temp->data;
            currNode->leftChild = deleteFromBST(currNode->leftChild, temp->data);
        }
        else {
            
            temp = getLeftMostNode(currNode->rightChild);
            currNode->data = temp->data;
            currNode->rightChild = deleteFromBST(currNode->rightChild, temp->data);
        }
    }
    
    return currNode;
}


