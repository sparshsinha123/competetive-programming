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
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[i].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
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

const int inf = 1e9 + 7;
ll d[10] = {119,18,93,91,58,107,111,82,127,123};
int main(){
    IOS;
    int n,k;
    cin>>n>>k;
    vll v(n);
    char c;
    FOR(i,0,n-1){
        v[i]=0;
        FOR(j,0,6){
            cin>>c;
            v[i]<<=1ll;
            if(c=='1') v[i]=(v[i]|1ll);
        }
    }
    // ll ** dp=new ll*[2005];
    // FOR(i,0,2004){
    //     dp[i]=new ll[2005];
    // }
    static ll dp[2005][2005];
    FOR(i,0,n+1){
        FOR(j,0,k+1){
            dp[i][j]=-1;
        }
    }
    dp[n][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            FOR(dd,0,9){
               if( (d[dd]&v[i])==v[i] ){
                   if(j>=__builtin_popcountll((d[dd]^v[i]))){
                       if(dp[i+1][j-__builtin_popcountll((d[dd]^v[i]))]==1){
                           dp[i][j]=1;
                       }
                   }
               } 
            }
        }
    }
    if(dp[0][k]==-1)cout<<-1<<'\n';
    else{
        ll rem=k;
       FOR(i,0,n-1){
           for(int dd=9;dd>=0;dd--){
               if( (d[dd]&v[i])==v[i] ){
                   if(rem>=__builtin_popcountll((d[dd]^v[i]))){
                       if(dp[i+1][rem-__builtin_popcountll((d[dd]^v[i]))]==1){
                           cout<<dd;
                           rem-=__builtin_popcountll((d[dd]^v[i]));
                           break;
                       }
                   }
               }
           }
       }
       cout<<'\n'; 
    }
    #ifdef LOCAL
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
    #endif
}
