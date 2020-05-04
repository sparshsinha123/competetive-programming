/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
#define  ll long long
int main(){
        int n;
        cin >> n;
        ll ans=0;
        for(ll i = 1; i <= n; i++){
            if( !((i%3==0 && i%5==0) || (i%3==0) || (i%5==0))) {
                ans += i;
            }
        }
        cout<<ans<<'\n';
}