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
const int N = 101;
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> dp(n + 1, vector<int>(2 , inf));
    int ev = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] != 0) ev += (p[i] % 2 == 0);
    }
    // dp[i][j][k] is the minimum complexity upto position i with use of j even cells so far
    // such that last thing that we used was k --> 0 for even and 1 for odd
    if(p[0] == 0){
        dp[1][0] = 0; 
        dp[0][1] = 0; 
    } else dp[0][0] = dp[0][1] = 0; 
    for(int i = 1; i < n; i++){
        vector<vector<int>> new_dp(n + 1, vector<int>(2 , inf));
        for(int j = 0; j <= n; j++){
            new_dp[j][0] = new_dp[j][1] = inf;
            if(p[i] != 0){
                if(p[i - 1] == 0){
                    new_dp[j][0] = min(new_dp[j][0] , dp[j][0] + p[i] % 2);
                    new_dp[j][1] = min(new_dp[j][1] , dp[j][1] + 1 - (p[i] % 2));
                } else{
                    int take = ((p[i] % 2) != (p[i - 1] % 2));
                    new_dp[j][0] = min(new_dp[j][0] , dp[j][0] + take);
                    new_dp[j][1] = min(new_dp[j][1] , dp[j][1] + take);
                }                
            } else{ 
                if(p[i - 1] == 0){
                    if(j != 0) new_dp[j][0] = min({new_dp[j][0] , dp[j - 1][0] , dp[j - 1][1] + 1});
                    new_dp[j][1] = min({new_dp[j][1] , dp[j][0] + 1, dp[j][1]});
                } else{
                    int par = p[i - 1] % 2;
                    if(j != 0){
                      new_dp[j][0] = 
                      min({new_dp[j][0] , dp[j - 1][0] + par, dp[j - 1][1] + par});
                    } 
                    new_dp[j][1] =
                    min({new_dp[j][1] , dp[j][0] + 1 - par , dp[j][1] + 1 - par});
                }
            }
        }
        dp = new_dp;
    }
    int req = (n / 2 - ev);
    // debug(req);
    cout << min(dp[req][0] , dp[req][1]) << '\n';
}   