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
int par[maxn];

int findset (int x){
    return par[x] == x ? x : (par[x] = findset(par[x]));
}

void merge (int x , int y){
    int px = findset(x);
    int py = findset(y);
    if (px == py) return;
    par[px] = py;
}
void promote (int a){
    int px = findset(a);

    par[a] = a;
    par[px] = a;
    return;
}

void solve(){
   int n  , q;
   cin >> n >> q;
   for (int i = 1; i <= n; i++){
    par[i] = i;
   }

   while(q--){
    int num;
    cin >> num;
    if (num == 1){
        int a , b;
        cin >> a >> b;
        merge(a , b);
    } else if (num == 2){
        int a;
        cin >> a;
        promote(a);
    } else{
        int a;
        cin >> a;
        cout << findset(a) << endl;
    }   
   }
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
