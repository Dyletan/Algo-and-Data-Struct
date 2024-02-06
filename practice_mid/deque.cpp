struct deque{
    int a[600];
    int end = 300 , st = 300;
    int push_front(int x){
        st--;
        a[st] = x;
    }
    int push_front(int x){
        a[end] = x;
        end++;
    }
    int pop_front(){
        st++;
    }
    int pop_back(){
        end--;
    }
    int front(){
        return a[st];
    }
    int back(){
        return a[end-1];
    }
};