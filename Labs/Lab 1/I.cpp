#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    int cnt_k = 0;
    int cnt_s = 0;
    int kick_k = 0;
    int kick_s = 0;

    cin >> n;

    queue<char> q;

    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        q.push(ch);
        if(ch == 'K')
            cnt_k++;
        else
            cnt_s++;
    }

    while(true){
        if(q.size() == 1){
            break;
        }
        if(q.front() == 'K'){
            if(kick_k > 0){
                kick_k--;
                q.pop();
                cnt_k--;
            }
            else{
                if(cnt_s > 0){
                    kick_s++;
                }
                else{
                    kick_k++;
                }
                q.pop();
                q.push('K');
            }
        }
        else{
            if(kick_s > 0){
                kick_s--;
                q.pop();
                cnt_s--;
            }
            else{
                if(cnt_k > 0){
                    kick_k++;
                }
                else{
                    kick_s++;
                }
                q.pop();
                q.push('S');
            }
        }
    }

    q.front() == 'K' ? cout << "KATSURAGI" : cout << "SAKAYANAGI"; 

}