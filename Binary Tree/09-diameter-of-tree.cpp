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

// Maximum Hieght Code template used here)

int hieght(Node * root){
    if(root == nullptr)
            return 0;
        
    int leftans = hieght(root->left);
    int rightans = hieght(root->right);
        
    int ans =  max(leftans,rightans) + 1;
        return ans;
}


int diameterOfBinaryTree(Node* root) {

        if(root == nullptr){
            return 0;
        }
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = hieght(root->left) + hieght(root->right);
        
        int ans = max(op1,max(op2,op3));
        return ans;
}




int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(45);
    
    cout << "diameter Of BinaryTree is : " << diameterOfBinaryTree(root);
    cout << endl;

    cout << endl;
    return 0;
}