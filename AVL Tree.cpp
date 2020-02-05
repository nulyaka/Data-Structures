#include <iostream>

struct Node {
    int data;
    int height;
    Node* lChild; // left child
    Node* rChild; // right child
}*root = nullptr;

int getNodeHeight(Node* currNode) {

    // stands for Left Child Height(LCH)
    // and Right Child Height (RCH)
    int LCH, RCH;
    
    // if both current node and its' child exist,
    // then return childs' height, else the height is 0
    LCH = (currNode && currNode->lChild) ? currNode->lChild->height : 0;
    RCH = (currNode && currNode->rChild) ? currNode->rChild->height : 0;
    
    // which one has greater height?
    // return it and +1 for current node
    return (LCH > RCH) ? LCH + 1 : RCH + 1;
}

int balanceFactor (Node* currNode) {
    
    // what is LCH, RCH?
    // read comments for getNodeHeight function
    int LCH, RCH;
    
    LCH = (currNode && currNode->lChild) ? currNode->lChild->height : 0;
    RCH = (currNode && currNode->rChild) ? currNode->rChild->height : 0;
    
    return LCH - RCH;
}

// Left Left Rotation

// Because left side of currend node is bigger than right side,
// we have to balance it.
// We get left child of current node, and make it current node
// and moving original current node to its' right side
// and returning updated and balanced current node

// example:
// not balanced, left side of a tree is bigger
//
//                     20  <-currNode
//                   /    \
//   currNode_L->  10      40
//                /  \
//               5   15  <-currNode_LR
//              / \
//             2   6
//
// balanced, after Left Left Rotation:
//
//                     10
//                  /     \
//                 5      20
//                / \    /  \
//               2   6  15  40

Node* LL_Rotation (Node* currNode) {
    
    Node* currNode_L = currNode->lChild;
    Node* currNode_LR = currNode->lChild->rChild;
    
    currNode_L->rChild = currNode;
    currNode->lChild = currNode_LR;
    
    currNode->height = getNodeHeight(currNode);
    currNode_L->height = getNodeHeight(currNode_L);
    
    if (root == currNode) {
        root = currNode_L;
    }
    
    return currNode_L;
}

// Left Right Rotation

// example:
// not balanced, left side of a tree is bigger:
//
//                   10  <-currNode
//                 /    \
//   currNode_L-> 5     20
//               / \
//              3   8  <-currNode_LR
//                 / \
//                6   9
//
// balanced, after Left Right Rotation:
//
//                  8
//                /   \
//              5      10
//             / \    /  \
//            3   6  9   20

Node* LR_Rotation (Node* currNode) {
    
    Node* currNode_L = currNode->lChild;
    Node* currNode_LR = currNode->lChild->rChild;
    
    currNode_L->rChild = currNode_LR->lChild;
    currNode = currNode_LR->rChild;
    
    currNode_LR->lChild = currNode_L;
    currNode_LR->rChild = currNode;
    
    currNode->height = getNodeHeight(currNode);
    currNode_L->height = getNodeHeight(currNode_L);
    currNode_LR->height = getNodeHeight(currNode_LR);
    
    if (root == currNode) {
        root = currNode_LR;
    }
    
    return currNode_LR;
}

// Right Right Rotation

// example:
// not balanced, right side of a tree is bigger
//
//                     20  <-currNode
//                   /    \
//                  10    25  <-currNode_R
//                       /  \
//       currNode_RL->  23  30
//                         /  \
//                        27  35
//
// balanced, after Right Right Rotation:
//
//                      25
//                   /     \
//                  20     30
//                 /  \   /  \
//                10  23 27  35
//
Node* RR_Rotation (Node* currNode) {
    
    Node* currNode_R = currNode->rChild;
    Node* currNode_RL = currNode->rChild->lChild;
    
    currNode_R->lChild = currNode;
    currNode->rChild = currNode_RL;
    
    currNode->height = getNodeHeight(currNode);
    currNode_R->height = getNodeHeight(currNode_R);
    
    if (root == currNode) {
        root = currNode_R;
    }
    
    return currNode_R;
}

// Right Left Rotation

// example:
// not balanced, right side of a tree is bigger
//
//                     20  <-currNode
//                   /    \
//                  10    25  <-currNode_R
//                       /  \
//       currNode_RL->  23  30
//                     /  \
//                    21  24
//
// balanced, after Right Left Rotation:
//
//                      23
//                   /     \
//                  20     25
//                 /  \   /  \
//                10  21 24  30
//
Node* RL_Rotation (Node* currNode) {
    
    Node* currNode_R = currNode->rChild;
    Node* currNode_RL = currNode->rChild->lChild;
    
    currNode_R->lChild = currNode_RL->rChild;
    currNode->rChild = currNode_RL->lChild;
    
    currNode_RL->lChild = currNode;
    currNode_RL->rChild = currNode_R;
    
    currNode->height = getNodeHeight(currNode);
    currNode_R->height = getNodeHeight(currNode_R);
    currNode_RL->height = getNodeHeight(currNode_RL);
    
    if (root == currNode) {
        root = currNode_RL;
    }
    
    return currNode_RL;
}

Node* insertAVL_recursive (Node* currNode, int dataToInsert) {
    
    Node* temp = nullptr;
    
    // if root doesn't exist, create it
    if (currNode == nullptr) {
        
        temp = new Node;
        temp->data = dataToInsert;
        temp->height = 1;
        temp->lChild = temp->rChild = nullptr;
        return temp;
    }
    
    if (dataToInsert < currNode->data) {
        currNode->lChild = insertAVL_recursive(currNode->lChild, dataToInsert);
    }
    else if (dataToInsert > currNode->data) {
        currNode->rChild = insertAVL_recursive(currNode->rChild, dataToInsert);
    }
    
    currNode->height = getNodeHeight(currNode);
    
    if (balanceFactor(currNode) == 2 && balanceFactor(currNode->lChild) == 1) {
        return LL_Rotation(currNode);
    }
    else if (balanceFactor(currNode) == 2 && balanceFactor(currNode->lChild) == -1) {
        return LR_Rotation(currNode);
    }
    else if (balanceFactor(currNode) == -2 && balanceFactor(currNode->lChild) == -1) {
        return RR_Rotation(currNode);
    }
    else if (balanceFactor(currNode) == -2 && balanceFactor(currNode->lChild) == 1) {
        return RL_Rotation(currNode);
    }
    
    return currNode;
}


