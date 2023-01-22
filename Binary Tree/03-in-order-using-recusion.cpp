#include <bits/stdc++.h>
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

// Inorder Algo
// Approach 
/*    1. go the left 
    2. push the node into the array and vector
    3. go the right 
*/
void inorder(Node* root, vector<int>&solution){
        if(root == nullptr) 
            return;
        inorder(root->left, solution);
        solution.push_back(root->data);
        inorder(root->right, solution);
}

int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->right->right = CreateNode(5);
    
    // for storing the answer
    vector<int> solution;
    cout << "Inorder traversal" << endl;
    inorder(root, solution);

    // print the vector 
    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}