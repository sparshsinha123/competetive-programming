/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
#define ll long long
int main(){
        int t;
        cin >> t;
        while(t--){
            ll n , m , c1 , r1 , c2 , r2; 
            cin >> n  >> m >> c1 >> r1 >> c2 >> r2;
            ll l = abs(c2-c1);
            ll b = abs(r2-r1);
            ll Ct = abs(n-l);
            ll Rt = abs(m-b);
            if(Ct>=l || Rt>=b){
                cout<<2*l*b<<'\n';
            }else{
                cout<<(2*l*b)-(abs(l-Ct)*abs(b-Rt))<<'\n';
            }
        }
}