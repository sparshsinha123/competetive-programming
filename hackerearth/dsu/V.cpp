#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define ll long long
#define umapii unordered_map<int,int>
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<int,int>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define vs vector<string>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define MP(a,b) make_pair(a,b)
#define debug(x)       cerr<< #x << " : " << x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[i].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
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

const int inf = 1e9 + 7;

const int maxn = 1e5 + 8;

vector<tuple<ll,int,int>> edges;
tuple<ll , ll , int> a[maxn];
tuple<ll , ll , int> b[maxn];

int par[maxn];

int findset(int x){
    return par[x] == x ? x : (par[x] = findset(par[x]));
}

void merge( int x , int y){
    int px = findset(x);
    int py = findset(y);

    if (px == py) return;
    par[px] = py;
}
void solve(){
   int n;
   cin >> n;

   for (int i = 0; i < n; i++){
    ll x , y;
    cin >> x >> y;
    a[i] = make_tuple(x , y , i);
    b[i] = make_tuple(y , x , i);
    par[i] = i;
   }
   sort(a , a + n);
   sort(b , b + n);
   for (int i = 1; i < n; i++){
    int cur = get<2>(a[i]);
    int pre = get<2>(a[i - 1]);
    ll xc = get<0>(a[i]);
    ll yc = get<1>(a[i]);
    ll xp = get<0>(a[i - 1]);
    ll yp = get<1>(a[i - 1]);
    ll cost = min (abs (xc - xp) , abs(yc - yp)); 
    edges.push_back(make_tuple(cost , cur , pre));
   }
   for (int i = 1; i < n; i++){
    int cur = get<2>(b[i]);
    int pre = get<2>(b[i - 1]);
    ll xc = get<1>(b[i]);
    ll yc = get<0>(b[i]);
    ll xp = get<1>(b[i - 1]);
    ll yp = get<0>(b[i - 1]);
    ll cost = min (abs (xc - xp) , abs(yc - yp)); 
    edges.push_back(make_tuple(cost , cur , pre));
   }

   sort (edges.begin() , edges.end());
   int taken = 0;
   ll mincost = 0;
   for (auto x: edges){
    ll c = get<0>(x);
    int i1 = get<1> (x);
    int i2 = get<2> (x);
    if (findset(i1) == findset(i2)){
        continue;
    }
    merge(i1 , i2);
    mincost += c;
    taken++;
    if (taken == n){
        break;
    }
   }

   cout << mincost << endl;
}   
int main(){
    IOS;
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}
