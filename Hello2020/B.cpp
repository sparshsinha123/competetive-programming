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
template <typename T>
class fenwick{
    public:
     vector<T> BIT;
     int N;
     void init(int size){ 
         BIT.resize(size + 1);
         fill(BIT.begin() , BIT.end() , 0);
         N = size + 1;
     }
     void modify(int x , T val){ 
           while(x < N){
               BIT[x] += val;
               x += (x & (-x));
           }
     }
     T get(T x){
          T sum = 0;
          while(x > 0){
              sum += BIT[x];
              x -= (x & (-x));
          }
          return sum;
     }
};

const int inf = 1e9 + 7;
const int N = 1e6 + 1;
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n + 1);
    fenwick <int> fenw;
    fenw.init(N + 1);
    vector<bool> is(n + 1, false);
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        int mx = INT_MIN; int mn = INT_MAX;
        bool fat = false;
        int prev = -1;
        for(int j = 0; j < l;j++){
            int b;
            cin >> b;
            if(prev != -1){
                if(b > prev) fat = true;
            }
            mx = max(mx , b);
            mn = min(mn , b);
            prev = b;
        }
        mx++;
        mn++;
        if(fat) {
            is[i] = true;
            ++cnt;
        } else{
           a[i] = make_pair(mx , mn);
           fenw.modify(mx , 1);
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(is[i]){
            ans += 1ll * n;
        } else{
            ans += 1ll * cnt;
            ll tt  = (1ll * fenw.get(N) - fenw.get(a[i].second));
            ans += tt;
        }
    }
    cout << ans << '\n';
}