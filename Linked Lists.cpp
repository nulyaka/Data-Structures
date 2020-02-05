#include <iostream>
#include <vector>

struct Node {
    
    int data;
    Node *next;
};

Node* createLL(const std::vector<int> &array, Node *headCopy) {
    
    headCopy = new Node;
    headCopy->data = array.at(0);
    headCopy->next = NULL;
    
    Node *lastNode, *currentNode;
    lastNode = headCopy;
    
    for (int i(1); i < array.size(); ++i) {
        
        currentNode = new Node;
        currentNode->data = array.at(i);
        currentNode->next = NULL;
        lastNode->next = currentNode;
        lastNode = currentNode;
    }
    
    return headCopy;
}

int getLengthLL(Node *node) {
    
    int length(0);
    
    while (node) {
        ++length;
        node = node->next;
    }
    
    return length;
}

int countSumLL(Node *node) {
    
    int sum(0);
    
    while (node) {
        sum += node->data;
        node = node->next;
    }
    
    return sum;
}

int findMaxLL(Node *node) {
    
    int max = INT32_MIN;
    while (node != NULL) {
        
        if (max < node->data) {
            max = node->data;
        }
        node = node->next;
    }
    
    return max;
}

void displayLL(Node *node) {
    
    while (node != NULL) {
        
        std::cout << node->data << ' ';
        node = node->next;
    }
    std::cout << std::endl;
}

void displayReverseLL(const Node *headCopy) {
    
    if (headCopy != NULL) {
        
        displayReverseLL(headCopy->next);
        std::cout << headCopy->data << ' ';
    }
}

Node* searchLinearLL(Node* node, const int key) {
    
    while (node != NULL) {
        
        if (key == node->data) {
            return node;
        }
        node = node->next;
    }
    
    return NULL;
}

Node* searchRecursiveLL(Node* node, const int key) {
    
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data) {
        return node;
    }
    
    return searchRecursiveLL(node->next, key);
}

void insertNode(Node* *head_ref, const int index, const int value) {
    
    Node *headCopy = *head_ref;
    
    if (index < 0 || index > getLengthLL(headCopy)) {
        return;
    }
    Node *temp = new Node;
    temp->data = value;
    
    if (index == 0) {
        temp->next = *head_ref;
        *head_ref = temp;
    }
    else {
        for (int i(0); i < index - 1 ; ++i) {
            headCopy = headCopy->next;
        }
        temp->next = headCopy->next;
        headCopy->next = temp;
    }
}

bool isSorted(Node *headCopy) {
    
    int currentData = INT_MIN;
    while (headCopy != NULL) {
        
        if (headCopy->data < currentData) {
            return false;
        }
        currentData = headCopy->data;
        headCopy = headCopy->next;
    }
    
    return true;
}

void deleteLL(Node* *head_ref) {
    
    Node *current = *head_ref;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    std::cout << "Linked List is deleted" << std::endl;
}

void mergeLL(Node *headFirstCopy, Node *headSecondCopy) {
    
    Node *last, *third;
    if (headFirstCopy->data < headSecondCopy->data) {
        
        third = last = headFirstCopy;
        headFirstCopy = headFirstCopy->next;
        third->next = NULL;
    }
    else {
        third = last = headSecondCopy;
        headSecondCopy = headSecondCopy->next;
        third->next = NULL;
    }
    while (headFirstCopy && headSecondCopy) {
        
        if (headFirstCopy->data < headSecondCopy->data) {
            last->next = headFirstCopy;
            last = headFirstCopy;
            headFirstCopy = headFirstCopy->next;
            last->next = NULL;
        }
        else {
            last->next = headSecondCopy;
            last = headSecondCopy;
            headSecondCopy = headSecondCopy->next;
            last->next = NULL;
        }
    }
    if (headFirstCopy) { last->next = headFirstCopy; }
    if (headSecondCopy) { last->next = headSecondCopy; }
}

bool isLoop(Node* headCopy) {
    
    Node *slow, *fast;
    slow = fast = headCopy;
    
    do{
        slow = slow->next;
        fast = fast->next;
        fast = (fast != NULL) ? fast->next : NULL;
    }while (slow && fast && slow != fast);
    
    if (slow == fast) {
        return true;
    }
    else {
        return false;
    }
}

