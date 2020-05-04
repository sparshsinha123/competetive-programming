#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define umapii unordered_map <int,int>
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<int,int>
#define ll long long
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
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MP(a,b) make_pair(a,b)
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

/*STL:
       (1) PRIORITY_QUEUE pq:
       -> priority_queue < int > pq; // max_heap
       -> priority_queue < int , vector < int > , greater < int > > pq; // min_heap 
       -> pq.top()   --> returns the maximum or minimum element
       -> pq.push()  --> push element into the queue
       -> pq.pop()   --> remove top most element
       -> pq.empty() --> checks whether queue is empty or not

       (2) set / multiset  ss; 
       --> ss.insert(key); (insertion)
       --> ss.erase(ss.find(key)) .. (deletion)
       --> ss.find(key) != ss.end() ..existence check
       --> ss.lower_bound(x) -> smallest value which is greater than or equals to x
       --> ss.upper_bound(x) --> first value strictly greater than x
       --> multiset< data_type , greater<data_type> > ms; // for max ordering
 
       (3) common functions
       lower_bound(v.begin(),v.end(),x) - v.begin() --> smallest value greater than or equals to x
       upper_bound(v.begin(), v.end(),x)- v.begin() --> smallest value greater than x
       memset(dp , val , sizeof(dp)) -> sets the value of array dp to val
     
       (4)  common mistakes
           .) long long vs int overflow
           .) read question carefully please!!!! it can cost you a lot
           .) unorderedmap is O(1) look up but worst case can be bad
           .) maps have higher constant so many lookups can cause TLE
           .) leaving debugs or cerrs in the program at times can cause TLE
*/

ll modexp(ll x, ll ex , ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}


// ll primeNum1 = 31;
// ll primeNum2 = 53;
// MOD = 1e9 + 9
// incase of large hash queries use double hashing with two primes
class RollingHash{
   public:
   string s;
   ll PR;
   ll MOD;
   vll ro;
   vll minv;
   vll pw;
   RollingHash(string ss , ll pr , ll mod){
      s = ss; PR = pr; MOD = mod; int N = (int) s.length(); ll p = 1ll, val = 0;
      ro.resize(N); minv.resize(N + 1); pw.resize(N + 1);
      for(int i = 0; i < N ; i++){
          val += (((s[i] - 'a' + 1) * p) % MOD); val %= MOD; p = (p * PR)%MOD; ro[i] = val;
      }
      pw[0] = 1; minv[0] = 1; minv[1] = modexp(PR , MOD - 2, MOD);
      for(int i = 1; i <= N ; i++) pw[i] = (pw[i - 1] * PR) % MOD;
      for(int i = 2; i <= N ; i++) minv[i] = (minv[i - 1] * minv[1]) % MOD; 
   }
   ll getHash(int ii , int jj){
     return ((minv[ii] * (ro[jj] - ((ii - 1 >= 0) ? ro[ii - 1] : 0)))%MOD + MOD)%MOD;
   }
};


const int inf = 1e9 + 7;
int main(){
    IOS;
    int n , m;
    cin >> n >> m;
    vpi pt(n) ;
    for(int i = 0; i < n; i++){
        cin >> pt[i].F >> pt[i].S;
    }       
    sort(all(pt));
    vector<int> dp(m + 2, 0);
    // dp[i] is the minimum extra cost to cover i..m assuming [0..i-1] is already covered
    dp[m+1] = 0;
    for(int i = m; i >= 1; i--){
        dp[i] = m-i+1 ;// we can always pay one of the previous ones
        for(int ii = 0; ii < n; ii++){
            if(pt[ii].F+pt[ii].S < i) continue;
            int ex=max((pt[ii].F-pt[ii].S-i),0);
            dp[i]=min(dp[i], ex+dp[min(pt[ii].F+pt[ii].S+ex+1,m+1)]);
        }
    }
    cout << dp[1] << '\n';
}
