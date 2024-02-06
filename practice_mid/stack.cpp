struct stack{
    int a[500];
    int size = 0;
    void push(int x){
        size++;
        a[size] = x;
    }
    void pop(){
        size--;
    }
    int top(){
        return a[size];
    }
};

