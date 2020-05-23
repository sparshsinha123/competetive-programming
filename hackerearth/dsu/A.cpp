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

const int MAXN = 1e5 + 7;
vector<int>g [MAXN];
pair<int, int> edges[MAXN];
ll A[MAXN] , Q[MAXN], par[MAXN] , sz[MAXN], ans[MAXN];
map<ll , ll> mp[MAXN];
int N , D;

int find_set (int x){
    if (par[x] == x) return x;
    return par[x] = find_set(par[x]);
}

ll merge(int x , int y){

     int px = find_set(x);
     int py = find_set(y);
     if (sz[px] > sz[py]) {
        swap (x  , y);
        swap (px , py);
     }
     assert (sz[px] <= sz[py]);

     ll ans = 0;
     for (auto it = mp[px].begin() ; it != mp[px].end(); it++){
         for (int d = -D; d <= D; ++d){
            if (mp[py].count (it->first + d)) {
                ans += 1ll * it->second * mp[py][it->first + d];
            }
         }
     }

     for (auto it = mp[px].begin();  it != mp[px].end(); it++){
        mp[py][it->first] += it->second;
     }
     par[px] = py;
     sz[py] += sz[px];
     return ans; 
}

// void showMaps (){
//     for (int i = 1; i <= N; i++){
//         cout << i << ": ";
//         for (auto x : mp[find_set(i)]){
//             cout << "(" << x.first << "," << x.second <<") ";
//         }
//         cout << '\n';
//     }
// }
void solve(){
   cin >> N >> D;
   for (int i = 0; i < N; i++){
    cin >> A[i + 1];
   }

   for (int i = 0; i < N - 1; i++){
     int U , V;
     cin >> U >> V;
     g[U].push_back(V);
     g[V].push_back(U);
     edges[i + 1] = make_pair(U , V);
   }

   for (int i = 0; i < N - 1;i++){
     cin >> Q[i + 1];
    }
 
    for (int i = 1; i <= N; i++){
        par[i] = i;
        sz[i] = 1;
        mp[i][A[i]]++;
    }

    int p = 0;
    ans[p] = 0;
    for (int i = N - 1; i >= 1; i--){
        int U , V;
        U = edges[Q[i]].first;
        V = edges[Q[i]].second;
        p++;
        ans[p] = 1ll *  ans[p - 1] + merge(U , V);
    }

    for (int i = p - 1; i >= 0; i--){
        cout << ans[i] << '\n';
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
