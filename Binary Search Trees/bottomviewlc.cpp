/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int> mp;
        int hd=0;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,hd));
        while(!q.empty()) {
            pair<Node*,int> p = q.front();
            q.pop();
            Node* node = p.first;
            hd = p.second;
            mp[hd] = node->data;
            if(node->left) q.push(make_pair(node->left,hd-1));
            if(node->right) q.push(make_pair(node->right, hd+1));
        }
        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            res.push_back((*it).second);
        }
        return res;
    }
};
