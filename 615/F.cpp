#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

const int N = 2e5 + 7;
const int inf = 1e9 + 7;
vi g[N];
int n;
int parent[N];
ll h[N] , d[N] , y[N];
bool mark[N];
void dfs(int a, int par){
    // cerr << "dfs " << a << '\n';
    for(auto x : g[a]){
        if(x != par){
            h[x] = 1 + h[a];
            dfs(x , a);
        }
    }
}
void dfS(int a, int par){
    // cerr << "dfs2 " << a << '\n';
    for(auto x : g[a]){
        if(x != par){
            d[x] = 1 + d[a];
            parent[x] = a;
            dfS(x , a);
        }
    }
}
void dfs3(int a, int par){
    // cerr << "dfs3 " << a << '\n';
    for(auto x : g[a]){
        if(x != par && !mark[x]){
            y[x] = 1 + y[a];
            dfs3(x , a);
        }
    }
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a , b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int a = -1;
    dfs(1 , -1);
    ll mx = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(h[i] > mx) {
            a = i;
            mx = h[i];
        }
    }
    parent[a] = -1;
    dfS(a, -1);
    int b = -1;
    mx = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] > mx) {
            b = i;
            mx = d[i];
        }
    }
    debug(mx);
    ans += (mx);
    int p = parent[b];
    mark[b] = true;
    while(p != -1){
        mark[p] = true;
        p = parent[p];
    }
    for(int i = 1; i <= n; i++){
        if(mark[i]){
            dfs3(i , parent[i]);
        }
    }
    int c = -1;
    mx = 0;
    for(int i = 1; i <= n; i++){
        if(!mark[i] && y[i] > mx) {
            c = i;
            mx = y[i];
        }
    }
    debug(mx);
    if(c == -1) c = parent[b];
    ans += mx;
    cout << ans << '\n';
    cout << a << " " << b << " " << c << '\n';
}