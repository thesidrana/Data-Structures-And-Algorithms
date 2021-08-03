void printAsRoot(Node* root, int k, vector<int>&res){
        if(k < 0 || !root) return;
        if(k==0){
            res.push_back(root->data);
            return;
        }
        printAsRoot(root->left, k - 1, res);
        printAsRoot(root->right, k - 1, res);
    }
    int printkdist(Node* root, int target, int k, vector<int> &res){
        if(root==NULL) return -1;
        if(root->data == target){
            printAsRoot(root,k,res);
            return 0;
        }
        int dl = printkdist(root->left, target, k, res);
        if(dl!=-1){
            if(dl+1 == k){
                res.push_back(root->data);
            }
            else{
                printAsRoot(root->right, k - dl - 2, res);
            }
            return 1+dl;
        }
        int dr = printkdist(root->right, target, k, res);
        if(dr!=-1){
            if(dr+1 == k){
                res.push_back(root->data);
            }
            else{
                printAsRoot(root->left, k - dr - 2, res);
            }
            return 1+dr;
        }
        return -1;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> res;
        printkdist(root, target, k, res);
        sort(res.begin(), res.end());
        return res;
    }
