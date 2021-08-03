/* LEETCODE : 116
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.


       10                          10 ------> NULL
      / \                       /      \
     3   5       =>           3 ------> 5 --------> NULL
    / \    \                /  \          \
   4   1   2               4 --> 1 -----> 2 -------> NULL

*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* prev = NULL;
            while(size--){
                Node* front = q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                if(prev){
                    prev->next = front;
                }
                prev = front;
            }
            prev->next = NULL;
        }
        return root;
    }
};
