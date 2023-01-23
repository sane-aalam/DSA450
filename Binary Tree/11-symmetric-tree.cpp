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


// Algo
/*
 101. Symmetric Tree [ Leetcode ]
For two trees to be mirror images, the following three conditions must be true
 1.) Their root node's key must be same
2.) left subtree of left tree and right subtree of right tree have to be mirror images
3.) right subtree of left tree and left subtree of right tree have to be mirror images 

*/

// we are using breath first search so complexity )):
// TC - 0(N)
// SC - 0(N)
bool isSymmetric(Node* root) {

        queue<Node*>q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            int size = q.size();
            Node* temp1 = q.front(); q.pop();
            Node* temp2 = q.front(); q.pop();
            size = size - 2;

            if(temp1 == nullptr && temp2 == nullptr) 
                continue;

            // if temp1 is null or temp2 is null 
            // or both data are not equal (anyone is false then return false)
            if(temp1 == nullptr || temp2 == nullptr || temp1->data != temp2->data)
                return false;

            q.push(temp1->left);
            q.push(temp2->right);
            q.push(temp1->right);
            q.push(temp2->left);

        }
        return true;
}


int main(){ 
    Node *root = CreateNode(1);
    
    // second level creation
    root->left = CreateNode(2);
    root->right = CreateNode(2);

    // third level creation
    // left side creation
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(4);
    // right side creation
    root->right->left = CreateNode(4);
    root->right->right = CreateNode(3);

    if(isSymmetric(root) == true){
        cout << "Yes ! - Tu bhai hai )): ";
    }else{
        cout << "No ! - Tu bhai nahi hai )):";
    }
 
    cout << endl;
    return 0;
}













   