/*
You got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.

Currently, it’s Monday, and you needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that you can survive the next S days, or determine that it isn’t possible to survive.
*/

class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(M > N) return -1;
        if(S>=7 && 7*M > 6*N) return -1;
        int res = 0;
        int total = S*M;
        while(total > 0){
            total = total - N;
            res++;
        }
        return res;
    }
};
