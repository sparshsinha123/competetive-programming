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

const ll inf = 2e18 + 7;

const int MAXN = 105;
ll arr[MAXN][MAXN];

void solve(){
   int N , M;
   cin >> N >> M;
   for (int i = 0; i < N; i++){
   	for (int j = 0; j < M; j++){
   		cin >> arr[i][j];
   	}
   }

   ll ans = inf;
   for (int i = 0; i < N; i++){
   	for (int j = 0; j < M; j++){
   		ll b = arr[i][j] - i - j;
   		vector<vector<ll>> dp (N, vector<ll> (M , inf));
   		for (int ii = 0; ii < N; ii++){
   			for (int jj = 0; jj < M; jj++){
   			  ll dx = arr[ii][jj] - (b + ii + jj);
   			  if (dx < 0) continue;
   			  if (ii != 0 && jj != 0){
   			  	dp[ii][jj] = min (dp[ii - 1][jj] , dp[ii][jj - 1]) + dx;
   			  } else if (ii != 0){
   			  	dp[ii][jj] = dp[ii - 1][jj] + dx;
   			  } else if (jj != 0){
   			  	dp[ii][jj] = dp[ii][jj - 1] + dx;
   			  } else dp[ii][jj] = dx;
   			}
   		}
   		ans = min (ans , dp[N - 1][M - 1]);
   	}
   }

   cout << ans << '\n';
}
int main(){
    IOS;
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}
