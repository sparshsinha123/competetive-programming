#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
           1) long long vs int overflow
           2) read question carefully
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
struct point{
    ll x;
    ll y;
};
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    ll sx,sy;
    cin >> n >> sx>> sy;
    vector<point> v;
    for(int i=0;i<n;i++){
        point p;
        cin>>p.x >> p.y;
        v.pb(p);
    }
    ll lx = LLONG_MIN, rx = LLONG_MAX , uy = LLONG_MAX , by = LLONG_MIN;
    for(auto pt : v){
        if(pt.x < sx) lx = max(lx , pt.x);
        if(pt.x > sx) rx = min(rx , pt.x);
        if(pt.y > sy) uy = min(uy, pt.y);
        if(pt.y < sy) by = max(by, pt.y);
    }
    ll c1 = 0, c2 = 0, c3= 0 , c4 = 0;
    if(lx != LLONG_MIN){
        for(auto pt : v){
            if(pt.x <= lx) ++c1;
        }
    }
     if(rx != LLONG_MAX){
        for(auto pt : v){
            if(pt.x >= rx) ++c2;
        }
    }
     if(uy != LLONG_MAX){
        for(auto pt : v){
            if(pt.y >= uy) ++c3;
        }
    }
     if(by != LLONG_MIN){
        for(auto pt : v){
            if(pt.y <= by) ++c4;
        }
    }
    ll take = max({c1 , c2 , c3 , c4});
    if(take == c1){
        cout << c1 << '\n';
        cout<< lx << ' ' << sy << '\n';
    } else if(take == c2){
        cout << c2 << '\n';
        cout << rx << ' ' << sy << '\n';
    } else if(take == c3){
        cout << c3 << '\n';
        cout << sx << ' ' << uy << '\n';
    } else{
        assert(take == c4);
        cout << c4 << '\n';
        cout << sx << ' ' << by << '\n';
    }
}