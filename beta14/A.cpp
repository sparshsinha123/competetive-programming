/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }       
    int xmin = n, xmax = -1, ymin = m , ymax = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '*'){
                xmin = min(xmin , i);
                xmax = max(xmax , i);
                ymin = min(ymin , j);
                ymax = max(ymax , j);
            }
        }
    }
    for(int ii = xmin; ii <= xmax; ii++){
        for(int jj = ymin; jj <= ymax; jj++){
            cout << s[ii][jj];
        }
        cout << '\n';
    }
}