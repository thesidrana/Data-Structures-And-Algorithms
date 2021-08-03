/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in LEVEL ORDER traversal of the tree.
*/

vector<int> verticalOrder(Node *root)
    {
        
        map<int, vector<int>> mp;
        int hd=0;
        //Queue to store level order traversal.
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,hd));
        while(!q.empty()) {
            pair<Node*,int> p = q.front();
            q.pop();
            Node* node = p.first;
            hd = p.second;
            mp[hd].push_back(node->data);
            if(node->left) q.push(make_pair(node->left,hd-1));
            if(node->right) q.push(make_pair(node->right, hd+1));
        }
        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
          for(int i = 0; i < (*it).second.size(); i++){
              res.push_back((*it).second[i]);
          }
        }
        return res;
    }
