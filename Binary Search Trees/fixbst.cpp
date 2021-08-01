/*
You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. 
Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. 
      All changes must be reflected in the original linked list.
*/

//Function to swap the values of both nodes.
void swap(int* x, int* y){
        int temp = *x;
        *x = *y;
        *y = temp;
}

// Follows inorder traversal and stores the previous node in inorder for every node visited.
// To do this, once you are done with the comparasions, make prev pointer point to root.
// Therefore, when we send the prev pointer into the subsequent function call, it will be set as the inorder predecessor.
// Also, compare only when prev exists. That is, do not compare for the first element.
void correctBSTUtil(struct Node* root, struct Node** first, struct Node** middle, struct Node** last,struct Node** prev){
        if(root){
          //The first element that will actually run the comparasions will be the leftmost element or the first element in inorder.
            correctBSTUtil(root->left, first, middle, last, prev);
            
            if((*prev) && root->data < (*prev)->data){
                if(!(*first)){
                    (*first) = (*prev);
                    (*middle) = root;
                }
                else{
                    (*last) = root;
                }
            }
          //Previous is set to root
            (*prev) = root;
            //Root will become the prev for its inorder successor.
            correctBSTUtil(root->right, first, middle, last, prev);
        }
    }
void correctBST(struct Node* root){
        struct Node* first, *middle, *last, *prev;
        first = middle = last = prev = NULL;
  
        correctBSTUtil(root, &first, &middle, &last, &prev);
  // Once we have set the pointers, we can swap.
  // If last is not null, it means the points are not adjacent, and we swap first and last.
        if(first && last){
            swap(&(first->data), &(last->data));
        }
  //Else if first and middle only exist, we swap the middle and first.
        else if(first && middle){
            swap(&(first->data), &(middle->data));
        }
    }
//THE TREE IS NOW FIXED.
