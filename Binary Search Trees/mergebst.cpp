/*
Given two BSTs, return elements of both BSTs in sorted form.
*/
void inorder(Node* root){
        if(root==NULL) return;
        inorder(root->left);
        cout << root->data <<" ";
        inorder(root->right);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        //Create 2 stacks and 2 iterating nodes
        vector<int> res;
       stack<Node*> s1;
       Node* current1 = root1;
       stack<Node*> s2;
       Node* current2 = root2;
       
       //Base conditions
       if(!root1){
           inorder(root2);
           return res;
       }
       if(!root2){
           inorder(root1);
           return res;
       }
       //Iterative Inorder Traversal of both trees
       while(current1 || !s1.empty() || current2 || !s2.empty()){
           //Reaching the left most nodes in both trees.
           if(current1 || current2){
               if(current1){
                   s1.push(current1);
                   current1 = current1->left;
               }
               if(current2){
                   s2.push(current2);
                   current2 = current2->left;
               }
           }
           //After we have reached the leftmost nodes, both 
           //current 1 and current 2 will be NULL.
           else{
             //If one stack is empty, 
               if(s1.empty()){
                   while(!s2.empty()){
                       current2 = s2.top();
                       s2.pop();
                       current2->left = NULL;
                       inorder(current2);
                   }
                   return res;
               }
               if(s2.empty()){
                   while(!s1.empty()){
                       current1 = s1.top();
                       s1.pop();
                       current1->left = NULL;
                       inorder(current1);
                   }
                   return res;
               }
               
               //Pop from both stacks and compare
               current1 = s1.top();
               s1.pop(); 
               current2 = s2.top();
               s2.pop();
               
               //If element of first is smaller, print it and push right sub-tree
               //Else, push it back to the corresponding stack.
               
               if(current1->data < current2->data){
                   cout << current1->data <<" ";
                   current1 = current1->right;
                   s2.push(current2);
                   current2 = NULL;
               }
               else{
                   cout << current2->data <<" ";
                   current2 = current2->right;
                   s1.push(current1);
                   current1 = NULL;
               }
           }
       }
       return res;
       
    }
