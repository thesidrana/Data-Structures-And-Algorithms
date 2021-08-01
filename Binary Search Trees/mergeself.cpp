/*
Given two BSTs, return elements of both BSTs in sorted form.
This method takes O(n^2) in worst case and time complexity is O(m+n).
Therefore it is not optimal. merge.cpp contains optimal solution.
*/

void inorder(Node *root, vector<int> &res, map<Node*, bool> &mp){
        if(root==NULL) return;
        if(!mp[root->left])inorder(root->left, res, mp);
        if(!mp[root]){
            res.push_back(root->data);
            mp[root] = true;
        }
        if(!mp[root->right])inorder(root->right, res, mp);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> res;
       vector<int> inorder1, inorder2;
       map<Node*, bool> visited1, visited2;
       inorder(root1, inorder1, visited1);
       inorder(root2, inorder2, visited2);
       int num1 = inorder1.size(), num2 = inorder2.size();
       int i =0, j =0;
       while(i < num1 && j < num2){
           if(inorder1[i] <= inorder2[j]){
               res.push_back(inorder1[i]);
               i++;
           }
           else{
               res.push_back(inorder2[j]);
               j++;
           }
       }
       if(i==num1){
           for(int x = j; x < num2; x++){
               res.push_back(inorder2[x]);
           }
       }
       else{
           for(int x = i; x < num1; x++){
               res.push_back(inorder1[x]);
           }
       }
       
       return res;
    }
