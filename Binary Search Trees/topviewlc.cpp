// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node.

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        int hd=0;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,hd));
        while(!q.empty()) {
            pair<Node*,int> p = q.front();
            q.pop();
            Node* node = p.first;
            hd = p.second;
            if(mp.find(hd)==mp.end()) mp[hd] = node->data;
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
