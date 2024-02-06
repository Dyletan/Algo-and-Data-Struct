#include <iostream>
#include <vector>
using namespace std;

vector<string> merge(vector<string> l, int n, vector<string> r, int m){
    vector<string> c;
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i==n){
            c.push_back(r[j++]);
        } else if(j==m){
            c.push_back(l[i++]);
        } else if(r[j].size() < l[i].size()){
            c.push_back(r[j++]);
        } else{
            c.push_back(l[i++]);
        }
    }
    return c;
}

vector<string> msort(vector<string> &a, int n){
    if(n == 1) return a;
    vector<string> al, ar;
    for (int i = 0; i < n / 2; i++) {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++) {
        ar.push_back(a[i]);
    }
    al = msort(al, al.size());
    ar = msort(ar, ar.size());
    return merge(al, al.size(), ar, ar.size());
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> s(n);
    for(int i = 0; i < n; i++){
        string str;
        string temp = "";
        getline(cin, str);
        str += ' ';
        for(char ch : str){
            if(ch == ' '){
                s[i].push_back(temp);
                temp = "";
            }else{
                temp+=ch;
            }
        }
    }

     for(int i = 0; i < n; i++){
        s[i] = msort(s[i], s[i].size());
     }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].size(); j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    
}