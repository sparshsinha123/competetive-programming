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
int mx=0;
const int NAX =21;
const int MNAX = 401;
vector<string>v(NAX);
int dp[NAX][NAX][NAX][NAX][MNAX];
int h , w;
 
void min_self(int &a, int b){
    a = min(a, b);
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> w;
    for(int i = 0;i < h; i++){
        cin >> v[i];
    }   
    for(int x = 0; x < h; x++){
        for(int y = 0; y < w; ++y){
            for(int xx = 0; xx < h; xx++){
                for(int yy = 0; yy < w; ++yy){
                    for(int k = 0; k <= h * w; ++k){
                        dp[x][y][xx][yy][k] = inf;
                    }
                }
            }
        }
    }
    for(int x = 0; x < h; ++x){
        for(int y = 0; y < w; ++y){
           if(v[x][y] == '.') dp[x][y][x][y][0] = 0;
        }
    }
    // for(int x = 0; x < h; ++x){
    //     for(int y = 0; y < w; ++y){
    //        if(v[x][y] == '.') cout << dp[x][y][x][y][0] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int n = h * w;
    for(int k = 0; k < n; ++k){
        for(int x = 0; x < h; ++x){
            for(int y = 0; y < w; ++y){
                for(int xx = 0; xx < h; ++xx){
                    for(int yy = 0; yy < w; ++yy){
                        if(v[x][y] == '#' || v[xx][yy] == '#') continue;
                        else{
                            if(xx + 1 < h && v[xx + 1][yy] == '.')  min_self(dp[x][y][xx + 1][yy][k + 1] , dp[x][y][xx][yy][k] + 1);
                            if(xx - 1 >= 0 && v[xx - 1][yy] == '.') min_self(dp[x][y][xx - 1][yy][k + 1] , dp[x][y][xx][yy][k] + 1);
                            if(yy + 1 < w && v[xx][yy + 1] == '.')  min_self(dp[x][y][xx][yy + 1][k + 1] , dp[x][y][xx][yy][k] + 1);
                            if(yy - 1 >= 0 && v[xx][yy - 1] == '.') min_self(dp[x][y][xx][yy - 1][k + 1] , dp[x][y][xx][yy][k] + 1);
                            min_self(dp[x][y][xx][yy][k + 1] , dp[x][y][xx][yy][k]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int x = 0; x < h; x++){
        for(int y = 0; y < w; ++y){
            for(int xx = 0; xx < h; ++xx){
                for(int yy = 0; yy < w; ++yy){
                    if(v[x][y] == '.' && v[xx][yy] == '.'){
                        ans = max(ans, dp[x][y][xx][yy][n]);
                    }
 
                }
            }
        }
    }
    cout << ans << '\n';
}