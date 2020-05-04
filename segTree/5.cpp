#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
           1) long long vs int overflow
           2) read question carefully please!!!! it can cost you a lot
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
const int N = 2e6 + 7;
int n;
class fenv{
    public: 
    vector<ll> fenw;
    void init(){
        fenw.resize(N);
    }
    void modify(int x , ll v){
        while(x < N){
            fenw[x] += v;
            x += (x & (-x));
        }
    }
    ll get(int x){
        ll sum = 0;
        while(x > 0){
            sum += fenw[x];
            x -= (x & (-x));
        }
        return sum;
    }
};
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vll a(n);
    FOR(i,0,n-1) cin >> a[i];
    vll b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    ll ans = 0;
    FOR(i,0,n-1){
        a[i] = (ll)(lower_bound(all(b),a[i]) - b.begin());
        ++a[i];
    }
    vector<fenv> f(2);
    f[0].init();
    f[1].init();
    FOR(i,0,n-1){
        ll b = f[1].get(n)-f[1].get(a[i]);
        ans += (f[0].get(n) - f[0].get(a[i]));
        f[1].modify(a[i] , 1);
        f[0].modify(a[i] , b); 
    }
    cout << ans << '\n';
}