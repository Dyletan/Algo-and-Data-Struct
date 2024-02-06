bool bin_search(int a[], int n, int x){
    int min = 0;
    int max = n-1;
    while(min<=max){
        int mid = (min+max)/2;
        if(x == a[mid]) return true;
        else if(x < a[mid]){
            max = mid - 1;
        } else{
            min = mid+1;
        }
    }
    return false;
}