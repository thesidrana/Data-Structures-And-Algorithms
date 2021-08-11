/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a , Item b){
        double r1 = ((double)a.value / (double)a.weight);
        double r2 = ((double)b.value / (double)b.weight);
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        int current = 0;
        double final = 0;
        
        for(int i = 0; i < n; i++){
            if(current + arr[i].weight <= W){
                current += arr[i].weight;
                final += arr[i].value;
            }
            else{
                int remain = W-current;
                final += arr[i].value * ((double)remain / (double)arr[i].weight);
                break;
            }
        }
        return final;
    }
        
};
