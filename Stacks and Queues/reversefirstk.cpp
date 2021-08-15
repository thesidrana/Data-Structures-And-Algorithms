// Given an integer K and a queue of integers, we need to reverse the order of the first 
// K elements of the queue, leaving the other elements in the same relative order.

queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int> s;
    queue<int> res;
    
    stack<int> aux;
    for(int i = 0; i < k; i++){
        int x = q.front();
        q.pop();
        aux.push(x);
    }
    while(!aux.empty()){
        int x = aux.top();
        aux.pop();
        s.push(x);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        s.push(x);
    }
    return s;
}
