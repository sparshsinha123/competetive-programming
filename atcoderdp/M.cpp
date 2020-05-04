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

/*
(**) setting precision for cout :(print ans with precision upto 10 decimal places) 
            cout << setprecision(10) << ans << '\n';


STL:
       (1) PRIORITY_QUEUE pq:
       -> priority_queue < int > pq; // max_heap
       -> priority_queue < int , vector < int > , greater < int > > pq; // min_heap 
       -> pq.top()   --> returns the maximum or minimum element
       -> pq.push()  --> push element into the queue
       -> pq.pop()   --> remove top most element
       -> pq.empty() --> checks whether queue is empty or not
     
      (2) map:
      -> map <int, int> mp;
      -> mp.count(key) --> check the presence in a map
      -> mp.find(key) == mp.end() --> check presence in a map
      -> mp.erase(iterator) --> deletes iterator from map..don't directly pass in key here

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
void add(ll &x , ll y , ll z){
    x = y + z;
    x %= mod;
}
void sub(ll &x , ll y , ll z){
    x = y - z;
    x %= mod;
    if(x < 0) x += mod;
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<long long>> dp(n , vector<long long>(k + 1, 0));
    vector<vector<long long>> pref(n , vector<long long>(k + 1, 0));
    // dp[i][j] is the number of ways of distributing exactly j candies among i people
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; ++j){
            if(i == 0){
                if(j <= a[i]) dp[i][j] = 1;
                add(pref[i][j] , dp[i][j] , (j == 0 ? 0 : pref[i][j - 1]));
                continue;
            }
            // for(int choice = 0; choice <= a[i]; ++choice){
            //     if(j >= choice) dp[i][j] += dp[i - 1][j - choice];
            // }
            int up = max(j - a[i] , 0);
            sub(dp[i][j] , pref[i - 1][j] , (up == 0 ? 0 : pref[i - 1][up - 1]));
            add(pref[i][j] , dp[i][j] , (j == 0 ? 0 : pref[i][j - 1]));
        }
    }
    cout << dp[n - 1][k] << '\n';
}