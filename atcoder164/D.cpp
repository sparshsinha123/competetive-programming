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
int main(){
    IOS;
    string str;
    cin >> str;
    int  n = (int) str.length();
    vector<ll> rem1(n , 0);
    vector<ll> rem2(n , 0);
    for(int i = 0; i < n; i++){
       int num = str[i] - '0';
       if(i == 0){
           rem1[i] = num % 3;
           rem2[i] = num % 673;
       } else{
           rem1[i] = (10*rem1[i - 1] + num) % 3;
           rem2[i] = (10*rem2[i - 1] + num) % 673;
       }
    }
    ll ans = 0;
    vector<ll> p3(n + 5 , 0);
    vector<ll> p6(n + 5 , 0);
    p3[0] = 1;
    p6[0]=1;
    for(int i = 1; i <= n + 4; i++){
        p3[i] = (p3[i - 1] * 10) % 3;
        p6[i] = (p6[i - 1] * 10) % 673; 
    } 
    map<pair<ll , ll>, ll> cnt;
    for(int i = n - 1; i >= 0; i--){
        ll t1=(rem1[i]*modexp(p3[i],3-2,3))%3;
        ll t2=(rem2[i]*modexp(p6[i],673-2,673))%673;
        cnt[MP(t1,t2)]++;
        ll r3=0,r6=0;
        if(i!=0){
            r3=(((modexp(p3[i],3-2,3)*10)%3)*rem1[i-1])%3;
            r6=(((modexp(p6[i],673-2,673)*10)%673)*rem2[i-1])%673;
        }
        ans+=1ll*cnt[MP(r3,r6)];
    }
    // for(int i = 0; i < n; i++){
    //     cout << i <<" = " << "(" << rem1[i] <<"," <<rem2[i]<<")\n";
    // }
    cout << ans << '\n';
    #ifdef LOCAL
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
    #endif
    // g++ -DLOCAL -std=c++17 f.cpp
}
