/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        bool bad = false;
        for(int i = 0; i < n; i++){
            if(v[i].first < v[i].second){
                bad = true;
                break;
            }
            int exp = v[i].first - (i != 0 ? v[i - 1].first : 0);
            int exc = v[i].second - (i != 0 ? v[i - 1].second : 0);
            if(exp < 0 || exc < 0 || exp < exc){
                bad = true;
                break;
            }
        }
        if(bad) cout << "NO\n";
        else cout << "YES\n";
    }       
}