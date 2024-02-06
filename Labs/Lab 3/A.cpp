#include <iostream>
using namespace std;

pair<int, int> find_coordinates(int sorted[], int find, int n, int m){
    int max = m*n-1;
    int min = 0;
    int mid, x, y;
    // 5 4 3 2 1
    while(min<=max){
        mid = (min+max)/2;
        if(find < sorted[mid]){
            min = mid + 1;
        } else if(find == sorted[mid]){
            x = mid / m;
            if(x%2 == 0){
                y = mid%m;
            } else{
                y = m - mid%m-1;
            }
            
            return {x, y};
        } else{
            max = mid - 1;
        }
    }
    return {-1, -1};

}

int main(){
    int t;
    cin >> t;
    int find_this[t];
    for(int i = 0; i < t; i++){
        cin >> find_this[i];
    }

    int m, n;
    cin >> n >> m;
    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i % 2 == 0){
                cin >> a[i][j];
            } else{
                cin >> a[i][m-1-j];
            }
        }
    }

    int sorted[n*m];
    for(int i = 0; i < n * m; i++){
        int ind = i / m;
        int j = i % m;
        sorted[i] = a[ind][j];
    }

    int x, y;
    for(int item : find_this){
        pair<int, int> coord = find_coordinates(sorted, item, n, m);
        x = coord.first, y = coord.second;
        if(x == -1){
            cout << x << endl;
        }
        else{
            cout << x << " " << y << endl;
        }
    }
}