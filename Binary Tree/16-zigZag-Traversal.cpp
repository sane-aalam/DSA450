
// Write a function to print ZigZag order traversal of a binary tree. 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        
        if(root == nullptr) 
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int leftToright = true;
        
        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size);   

           for(int i =0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();  
                /* 
                const age = 26;
                const beverage = age >= 21 ? "Beer" : "Juice";
                console.log(beverage); // "Beer""
                */
                int index = leftToright? i : size-1-i;
                ans[index] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            leftToright = !leftToright;
           v.push_back(ans);
        }
        return v;    
    }
};