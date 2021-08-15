void push(stack<int>& s, int a){
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	if(s.size() == n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size()==0) return true;
	return false;
}

int pop(stack<int>& s){
	s.pop();
}

int getMin(stack<int>& s){
	stack<int> res;
	int mini = s.top();
	while(!s.empty()){
	    int x = s.top();
	    s.pop();
	    if(x < mini) mini = x;
	    res.push(x);
	}
	while(!res.empty()){
	    int x = res.top();
	    res.pop();
	    s.push(x);
	}
	return mini;
}	
