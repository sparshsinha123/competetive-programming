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

int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s , t;
    cin >> s >> t;
    int n = s.length(); int m = t.length();

    // dp[i][j] is the longest common subsequence of prefix[i] of s and prefix[j] of t
    vector<vector<int>> dp(n , vector<int>(m , 0));
    vector<vector<char>> where(n , vector<char>(m , 'L'));
    dp[0][0] = (s[0] == t[0] ? 1 : 0);
    where[0][0] = (s[0] == t[0] ? 'D' : 'L');
    for(int i = 1; i < n; i++){
        if(s[i] == t[0]) {
            dp[i][0] = 1;
            where[i][0] = 'D'; 
        } else {
            dp[i][0] = dp[i - 1][0];
            where[i][0] = 'T';
        }
    }
    for(int j = 1; j < m; j++){
        if(s[0] == t[j]) {
            dp[0][j] = 1;
            where[0][j] = 'D';
        }
        else dp[0][j] = dp[0][j - 1] , where[0][j] = 'L';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == t[j]){
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
                where[i][j] = 'D';
            } else{
                dp[i][j] = -inf;
                if(dp[i][j - 1] > dp[i][j]){
                    dp[i][j] = dp[i][j - 1];
                    where[i][j] = 'L';
                }
                if(dp[i - 1][j] > dp[i][j]){
                    dp[i][j] = dp[i - 1][j];
                    where[i][j] = 'T';
                 }
            }
        }
    }
    bool done = false;
    int x = n - 1 , y = m - 1;
    string ans = "";
    while(!done){
        assert(x >= 0 && y >= 0);
        if(where[x][y] == 'D') {
            ans.pb(s[x]);
            assert(s[x] == t[y]);
            x = x - 1; y = y - 1;
        } else if(where[x][y] == 'L'){
            y = y - 1;
        } else x = x - 1;
        if(x < 0 || y < 0){
            done = true;
        }
    }
    reverse(all(ans));
    cout << ans << '\n';
}