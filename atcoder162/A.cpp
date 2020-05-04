/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
int main(){
       string s;
       cin >> s;
       for(int i = 0; i < (int) s.length(); i++){
           if(s[i] == '7'){
               cout << "Yes\n";
               return 0;
           }
       }
       cout << "No\n";
}