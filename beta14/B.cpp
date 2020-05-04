/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
int main(){
        int n , x0;
        cin >> n >> x0;
        vector<int> v(1001, 0);
        for(int i = 0; i < n; i++){
            int a , b;
            cin >> a >> b;
            if(a > b) swap(a , b);
            for(int j = a; j <= b; j++){
                v[j]++;
            }
        }
        int dis = -1;
        for(int i = 0; i <= 1000; i++){
            if(v[i] == n){
                if(dis == -1) dis = abs(x0 - i);
                else dis = min(dis , abs(x0 - i));
            }
        }
        cout << dis << '\n';
}