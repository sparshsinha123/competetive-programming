/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n , t;
    cin >> n >> t;
    double xpr;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x , a;
        cin >> x >> a;
        if(i == 0) {
            ans += 1;
            xpr = (x + (1.00 * a / 2.00)); 
        } else{
            double m = (x - (1.00 * a / 2.00));
            if( ((int) (10 * (m - xpr))) == (t * 10)) ans += 1;
            else if(((int) (10 * (m - xpr))) > (t * 10)) ans += 2;
            xpr = (x + (1.00 * a / 2.00)); 
        }
        // cout << xpr << '\n';
    }
    cout << ans + 1 << '\n';
}