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


void Levelorder(Node* root, vector<int>&solution){

        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node * temp = q.front();
                q.pop();

                solution.push_back(temp->data);

                // if temp of left is not null then push into the queue
                if(temp->left != nullptr) 
                    q.push(temp->left);
                // if temp of right is not present then push into the queue
                if(temp->right != nullptr) 
                  q.push(temp->right);
            }
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
    cout << "Level order traversal using BFS" << endl;
    Levelorder(root, solution);

    // print the vector(solution using for loop)
    for(int i = 0; i<solution.size(); i++){
        cout << solution[i] << " ";
    }

    cout << endl;

    return 0;
}