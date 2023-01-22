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

// postorder Algo
// Arroach --
/*  1. go the left 
    2. go the right 
   3. push the node into the array and vector
*/
void postorder(Node* root, vector<int>&solution){
        if(root == nullptr)
                 return;
         postorder(root->left, solution);
        postorder(root->right, solution);
        solution.push_back(root->data);
      
}

int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->right->right = CreateNode(5);
    
    // for storing the answer
    vector<int> solution;
    cout << "postorder traversal" << endl;
    postorder(root, solution);

    // print the vector 
    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}