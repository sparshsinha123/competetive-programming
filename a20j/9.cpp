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
const ll MOD = 1e9 + 7;

void solve(){
   int r , g;
   cin >> r >> g;

   ll h = 0;
   ll lo = 0 , hi = r + g;
   while(lo < hi){
    ll mid = (lo + hi + 1) / 2;
    if ( (mid * (mid + 1)) / 2 <= r + g){
        lo = mid;
    } else hi = mid - 1;
   }

   h = lo;
   debug(h);

   vector<ll> dp(r+1,0);

   // dp[t][r] is the number of ways to form t upper colum

   dp[1]=1;
   if(g>=1)dp[0]=1;
   for (int t = 2; t <= h; t++){
    vector<ll> new_dp(r+1,0);
    for (int red = 0; red <= r; ++red){
        ll gv=(t-1)*t/2-red+t;
        if(gv<=g) new_dp[red]=(new_dp[red]+dp[red])%MOD;
        gv=(t-1)*t/2-(red-t);
        if(gv<=g &&red>=t) new_dp[red]=(new_dp[red]+dp[red-t])%MOD;
    }
    dp=new_dp;
   }
   ll ans=0;
   for (int red=0;red<=r;red++){
    ans+=(dp[red]);
    ans%=MOD;
   }
   cout<<ans<<endl;

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
