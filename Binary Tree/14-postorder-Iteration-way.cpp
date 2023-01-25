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
/*  using 2 stack we can traversal complete tree
*/
void postorder(Node* root, vector<int>&solution){
       
        if(root == NULL) {
            return; 
        }
        
        stack<Node*> st1,st2;
        st1.push(root);

        while(!st1.empty()) {
            Node* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);

            if(node->right) st1.push(node->right);
        }

        while(!st2.empty()) {
            solution.push_back(st2.top()->data);
            st2.pop();
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
    cout << "postorder traversal" << endl;
    postorder(root, solution);

    // print the vector 
    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}