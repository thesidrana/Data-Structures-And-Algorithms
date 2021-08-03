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
