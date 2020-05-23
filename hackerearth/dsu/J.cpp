#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define ll long long
#define umapii unordered_map<ll,ll>
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<ll,ll>
#define pi pair<ll,ll>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define vs vector<string>
#define vi vector<ll>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(ll i = a; i <= b; i++)
#define MP(a,b) make_pair(a,b)
#define debug(x)       cerr<< #x << " : " << x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(ll i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(ll i=0;i<N;i++){cerr<<"[";for(ll j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(ll i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(ll i=0;i<v.size();i++){cerr<<"[";for(ll j=0;j<(v[i].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

/* ordered set: 
tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
member functions :
1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/

inline ll gcd (ll x , ll y){
    if (x < y) swap (x , y);
    while (y){
        ll temp = y;
        y = x % y;
        x = temp; 
    }
    return x;
}

inline ll modexp(ll x, ll ex , ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}

const ll inf = 1e9 + 7;
const ll maxn = 1e4 + 5;

vector<pi> g[maxn];
bool vis[maxn];

ll par[maxn] , dis[maxn];

ll find_set (ll x){
    return par[x] == x ? x : (par[x] = find_set(par[x]));
}

void merge (ll x , ll y){
    ll px = find_set (x);
    ll py = find_set (y);

    if (px == py) return;
    par[px] = py;
}
bool compare (ll x , ll y){
    return dis[x] < dis[y];
}

void solve(){
   ll n,  k;
   cin >> n>> k;

   for (ll i = 0; i <= n; i++){
    par[i] = i;
   }
   for (ll i = 0; i < n; i++){
    ll a , b , wt;
    cin >> a >> b >> wt;
    g[a].push_back(make_pair(b , wt));
   }
   queue<ll> q;
   q.push(0);
   dis[0] = 0;
   while(!q.empty()){
    vis[0] = 1;
    ll v = q.front();
    q.pop();
    // cout << v << " ";
    for(auto x : g[v]){
        ll child = x.first;
        ll wt = x.second;
        if (!vis[child]){
            dis[child] = dis[v] + wt;
            vis[child] = 1;
            q.push(child);
        }
    }
   }
   // cout << endl;

   // for (ll i = 0; i <= n; i++){
   //  cout << "source = " << i << ": ";
   //  for (auto x : g[i]){
   //      cout << x.first  << ", " << x.second << "|" ;
   //  }
   //  cout << endl;
   // }
   // cout << "distances\n";
   // for (ll i = 1; i <= n; i++){
   //  cout << dis[i] << " ";
   // }
   // cout << endl;
   vector <ll> v;
   for (ll i = 1; i <= n; i++) v.push_back(i);
    sort(all(v) , compare);
    for(ll i = 0; i < (ll) v.size(); i++){
        if (i == 0) continue;
        if (abs (dis[v[i]] - dis[v[i-1]])  <= k) merge(v[i-1],v[i]);
    }
    ll queries;


   // for (auto x : mp){
   //  cout << x.first << ": ";
   //  for (auto y : x.second){
   //      cout << y << " ";
   //  }
   //  cout << endl;
   // }
    cin >> queries;

    while(queries--){
        ll m;
        cin >> m;
        vector<ll> vv;
        map<ll , ll> ct;
        for (ll i = 0; i < m; i++){
            ll t;
            cin >> t;
            vv.push_back(t);
            ct[find_set(t)]++;
        }
        // debugm(ct);
        if ((ll) ct.size() == 1){
            cout << "YES\n";
        } else{
            bool isone = false;
            for (auto x : ct){
                if (x.second == 1) isone = true;
            }
            if (isone ) cout << "NO\n";
            else cout << (ll) ct.size() << endl;
        }
    }
}
int main(){
    IOS;
    ll T = 1;
    cin >> T;
    for(ll i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}
