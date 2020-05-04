#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
           1) long long vs int overflow
           2) read question carefully please!!!! it can cost you a lot
*/

#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define umapii unordered_map < int , int >
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<int,int>
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define vs vector<string>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(int i = a;i <= b; i++)

#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

const ll mod = 1000000007;
/*STL:
       (1) PRIORITY_QUEUE pq:
       -> priority_queue < int > pq; // max_heap
       -> priority_queue < int , vector < int > , greater < int > > pq; // min_heap 
       -> pq.top()   --> returns the maximum or minimum element
       -> pq.push()  --> push element into the queue
       -> pq.pop()   --> remove top most element
       -> pq.empty() --> checks whether queue is empty or not



*/
ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int inf = 1e9 + 7;
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int xa , ya, xb , yb, xc , yc;
    vector<pair<int,int>> v(3);
    for(int i = 0; i < 3; i++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(all(v));
    vector<pair<int,int>> ans;
    map < pair<int,int> , bool > mp;
    for(int x = v[0].fi ; x <= v[1].fi; ++x){
       if(!mp.count(make_pair(x , v[0].se))) {
           ans.pb(make_pair(x , v[0].se));
       }
       mp[make_pair(x , v[0].se)] = 1;
    }
    for(int y = min(v[1].se , v[0].se) ; y <= max(v[0].se , v[1].se); ++y){
        if(!mp.count(make_pair(v[1].fi , y))) {
            ans.pb(make_pair(v[1].fi , y));
        }
        mp[make_pair(v[1].fi , y)] = 1;
    }
    int wherey;
    if(abs(v[2].se - v[1].se) <= abs(v[2].se - v[0].se)){
        wherey = v[1].se;
    } else wherey = v[0].se;
    for(int x = v[1].fi; x <= v[2].fi; ++x){
       if(!mp.count(make_pair(x , wherey))) {
           ans.pb(make_pair(x , wherey));
       }
       mp[make_pair(x , wherey)] = 1;
    } 
    for(int y = min(wherey , v[2].se) ; y <= max(wherey, v[2].se); ++y){
        if(!mp.count(make_pair(v[2].fi , y))) {
            // cout << v[2].fi << ' ' << y << '\n';
            ans.pb(make_pair(v[2].fi , y));
        }
        mp[make_pair(v[2].fi , y)] = 1;
    }
    cout << ans.size() << '\n';
    for(auto x : ans){
        cout << x.fi << ' ' << x.se << '\n';
    }
}  