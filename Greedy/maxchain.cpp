/*
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. 
*/

bool cmp(struct val p1, struct val p2){
    return (p1.second < p2.second) ;
}
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, cmp);
    int count=0;
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(p[i].first > prev){
            count++;
            prev = p[i].second;
        }
    }
    return count;
} 
