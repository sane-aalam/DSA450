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

/*you can use Recursion, but now we are using BFS algoritm*/

// 1. create simple queue data structure
// 2. push root node into the queue 
// 3. then pop the queue of front node and push into the array?vector
// 4. we will go first temp of right why? because is Stack (last is first out)
// 5. we will go secon temp of left 

// for deep understand, dry run 3-4 times,
// thank you 


void preorder(Node* root, vector<int>&solution){
       stack<Node*> s;
       s.push(root);

       while(!s.empty()){
         Node * temp = s.top();
         s.pop();
        solution.push_back(temp->data);

        if(temp->right != nullptr) 
            s.push(temp->right);
        if(temp->left != nullptr) 
            s.push(temp->left);
       }
}

int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->right->right = CreateNode(5);
    
    // for storing the answer
    vector<int> solution;
    cout << "preorder traversal" << endl;
    preorder(root, solution);

    // print the vector 
    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}