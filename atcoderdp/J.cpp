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
const int nax = 305;
long double dp[nax][nax][nax];
// bool vis[10][10][10];
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int on = 0, tw = 0 , th = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        on += a[i] == 1;
        tw += a[i] == 2;
        th += a[i] == 3;
    }
   
    // dp[i][j][k] is expected number of moves to finish i , j , k
    // debug(dp[0][0][0]);
     for(int k = 0; k <= n; ++k){
        for(int j = 0; j <= n; ++j){
           for(int i = 0; i <= n; i++){
                int z = n - i - j - k;
                double den = 1.00*i + j + k;
                if(i == 0 && j == 0 && k == 0) {
                    dp[i][j][k] = 0;
                    continue;
                }
                dp[i][j][k] = ((1.00 * n) / den);
                // taking one
               
               if(i != 0) dp[i][j][k] += (1.00 * i / den) * (dp[i - 1][j][k]); 
            
                // taking two
                if(i + 1 <= n && j - 1 >= 0) dp[i][j][k] += (1.00 * j / den) * (dp[i + 1][j - 1][k]);

                //taking three
                if(j + 1 <= n && k > 0)
                dp[i][j][k] += (1.00 * k / den) * (dp[i][j + 1][k - 1]);
            }
        }
    }
    // for(int i = 0; i <= on; i++){
    //     cerr << i << "-->";
    //     for(int j = 0; j <= tw; ++j){
    //         cerr << "   " << j <<"-->";
    //         for(int k = 0; k <= th; ++k){
    //             cerr << dp[i][j][k] << ' ';
    //         }
    //         cerr << '\n';
    //     }
    //     cerr << '\n';
    // }

    // cerr << "checking order of states\n";
    // for(int j = 0; j < 10; j++){
    //    for(int k = 0; k < 10; k++){
    //         for(int i = 0; i < 10; i++){
    //             vis[i][j][k] = true;
    //             if(i != 0) assert(vis[i - 1][j][k]);
    //             if(j != 0 && i + 1 != 10) assert(vis[i + 1][j - 1][k]);
    //             if(k != 0 && j + 1 != 10) assert(vis[i][j + 1][k - 1]);
    //         }
    //     }
    // }
    assert(dp[0][0][0] == 0.00);
    cout << setprecision(13) << dp[on][tw][th] << '\n';
}