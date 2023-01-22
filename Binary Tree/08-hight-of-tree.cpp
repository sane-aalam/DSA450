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


//Method 1 : use DFS Algo

int maxDepth(Node* root) {
    
        if(root == nullptr)
            return 0;
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left,right) + 1;
}

// Method 2 use BFS Algo
int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        queue<Node *> q;
        int count = 0;

        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            Node *front = q.front();
            q.pop();

            if(front == NULL) {
                count++;
                if(!q.empty())
                    q.push(NULL);
            } else {
                if(front->left) 
                    q.push(front->left); 
                if(front->right) 
                    q.push(front->right); 
            }
        }
        return count;
}

int main(){ 
    Node * root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    
    cout << "Maximum Depth of binary tree is :" << maxDepth(root);
    cout << endl;

    cout << endl;
    return 0;
}