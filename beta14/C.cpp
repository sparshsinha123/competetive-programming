/*author : Sparsh Sinha */
#include "bits/stdc++.h"
using namespace std;
#define ll long long
bool isright(ll x , ll y , ll x1 , ll y1 , ll x2 , ll y2){
    return (y1 - y) * (y2 - y) == (x2 - x) * (x - x1);
}
bool isparalleltooneofaxes(int x1 , int y1 , int x2 , int y2){
    if(x1 == x2 || y1 == y2) return true;
    else return false;
}
int main(){
    map<pair<long long, long long> , set<pair<long long, long long>>> mp;
    long long x1 , y1, x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool bad = false;
    mp[{x1 , y1}].insert(make_pair(x2 , y2));
    mp[{x2 , y2}].insert(make_pair(x1 , y1));
    if(!isparalleltooneofaxes(x1 , y1, x2 , y2)) bad = true;
    cin >> x1 >> y1 >> x2 >> y2;
    mp[{x1 , y1}].insert(make_pair(x2 , y2));
    mp[{x2 , y2}].insert(make_pair(x1 , y1));  
    if(!isparalleltooneofaxes(x1 , y1, x2 , y2)) bad = true;
    cin >> x1 >> y1 >> x2 >> y2;
    mp[{x1 , y1}].insert(make_pair(x2 , y2));
    mp[{x2 , y2}].insert(make_pair(x1 , y1));
    if(!isparalleltooneofaxes(x1 , y1, x2 , y2)) bad = true;
    cin >> x1 >> y1 >> x2 >> y2;
    mp[{x1 , y1}].insert(make_pair(x2 , y2));
    mp[{x2 , y2}].insert(make_pair(x1 , y1));
    if(!isparalleltooneofaxes(x1 , y1, x2 , y2)) bad = true;
    if(bad){
        cout << "NO\n";
        return 0;
    }
    if((int) mp.size() != 4){
        cout << "NO\n";
    }else{
        for(auto pt : mp){
            if((int) pt.second.size() != 2){
                cout << "NO\n";
                return 0;
            }
            auto beg = (pt.second.begin());
            auto en = (pt.second.end());
            --en;
            if(!isright(pt.first.first , pt.first.second , (*beg).first , (*beg).second , (*en).first, (*en).second)){
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }
}