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
struct event{
    int s;
    int type;
    int idx;
};
bool compare(event a , event b){
    pll p1 = make_pair(a.s , a.type);
    pll p2 = make_pair(b.s , b.type);
    return p1 < p2;
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pll> a(n) , b(n);
    vector<event> eva , evb;
    for(int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
        event foo , bar , ant , sick;
        foo.s = a[i].fi; foo.type = 0; foo.idx = i;
        bar.s = a[i].se; bar.type = 1; bar.idx = i;
        ant.s = b[i].fi; ant.type = 0; ant.idx = i;
        sick.s = b[i].se; sick.type = 1; sick.idx = i;
        eva.pb(foo);
        eva.pb(bar);
        evb.pb(ant);
        evb.pb(sick);
    } 
    sort(eva.begin() , eva.end() , compare);
    sort(evb.begin() , evb.end() , compare);
    //  for(auto x : eva){
    //     cerr << "("<<x.s <<","<<x.type<<","<<x.idx<<") ";
    // }
    // cerr<<'\n';
    // for(auto x : evb){
    //     cerr << "("<<x.s <<","<<x.type<<","<<x.idx<<") ";
    // }
    // cerr<<'\n';
    vector<bool> bada(n + 1, false);
    vector<bool> badb(n + 1, false);
    int active = 0;
    for(auto x : eva){
        if(x.type == 0){
            ++active;
            if(active > 1){
                bada[x.idx] = true;
            }
        } else{
            --active;
        }
    }
    active = 0;
    for(auto x : evb){
        if(x.type == 0){
            ++active;
            if(active > 1){
                badb[x.idx] = true;
            }
        } else{
            --active;
        }
    }
    bool poor = false;
    for(int i = 0; i < n; i++){
        if((!bada[i] && badb[i]) || (!badb[i] && bada[i])){
            poor = true;
            break;
        }
    }
    cout << (poor ? "NO\n" : "YES\n");
    // int j = -1;
    // for(int i = 0; i < n; i++){
    //     big[++j] = a[i].fi;
    // }
    // for(int i = 0; i < n; i++){
    //     big[++j] = a[i].se;
    // }
    // for(int i = 0; i < n; i++){
    //     big[++j] = b[i].fi;
    // }
    // for(int i = 0; i < n; i++){
    //     big[++j] = b[i].se;
    // }
    // vector<ll> back_up = big;
    // sort(all(back_up));
    // back_up.resize(unique(back_up.begin(), back_up.end()) - back_up.begin());
    // for(int i = 0; i < big.size(); i++){
    //     big[i] = lower_bound(back_up.begin() , back_up.end() , big[i]) - back_up.begin();
    //     assert(big[i] < big.size());
    // }
    // j = -1;
    // for(int i = 0; i < n; i++){
    //     a[i].fi = big[++j] + 1;
    // }
    // for(int i = 0; i < n; i++){
    //     a[i].se = big[++j] + 1;
    // }
    // for(int i = 0; i < n; i++){
    //     b[i].fi = big[++j] + 1;
    // }
    // for(int i = 0; i < n; i++){
    //     b[i].se = big[++j] + 1;
    // }
    // fenwick<int> fenw1;
    // fenwick<int> fenw2;
    // int gg = n + n + n + n + 1;
    // fenw1.init(gg);
    // fenw2.init(gg);
    // for(int i = 0; i < n; i++){
    //     fenw1.modify(a[i].fi , 1);
    //     fenw2.modify(b[i].fi , 1);
    // }
    // bool bad = false;
    // for(int i = 0; i < n ; i++){
    //     int befa = fenw1.get(a[i].se) - fenw1.get(a[i].fi);
    //     int befb = fenw2.get(b[i].se) - fenw2.get(b[i].fi);
    //     if((befa >= 1 && befb == 0) || (befa == 0 && befb >= 1)){
    //         bad = true; 
    //         break;
    //     }
    // }
    // cout << (bad ? "NO\n" : "YES\n");
}