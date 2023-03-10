#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
 
// to create a new node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode)
        return nullptr;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


int main(){
    // creation of binary tree
    /* Tree like this ->
    
               1
             /   \
            /     \
          2       3
          / \     /  \
         /   \   /    \
        4     5 -6     10
        
    */
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->right->right = CreateNode(5);
 
    return 0;
}
