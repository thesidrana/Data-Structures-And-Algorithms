/*
Given a linked list of strings having n nodes check to see whether the combined string formed is palindrome or not. 
*/

bool compute(Node* root)
{
   Node* temp = root;
   string res = "";
   while(temp){
       string x = temp->data;
       for(int i = 0; i < x.length(); i++){
           res += x[i];
       }
       temp = temp->next;
   }
   int i = 0, j = res.length()-1;
   while(j > i){
       if(res[i] != res[j]){
           return false;
       }
       j--;
       i++;
   }
   return true;
}
