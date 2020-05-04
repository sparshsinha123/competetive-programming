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
const int N = 1e5 + 7;
int a[N];
const int inf = 1e9 + 7;
void show(int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int sg[4 * N];
int lazy[4 * N];
int identity(){
    return 1;
}
int unite(int x , int y){
    return(__gcd(x , y));
}
void push(int x, int s, int e){ 
    if(lazy[x] == 1) return;
    sg[x] *= lazy[x]; 
    if(s != e){
      lazy[x + x + 1] *= lazy[x]; 
      lazy[x + x + 2] *= lazy[x];
    }
    lazy[x] = 1; 
    return;
}
void pull(int x , int s , int e){
    assert(s != e);
    int mid = (s + e) >> 1;
    push(x + x + 1 , s , mid); 
    push(x + x + 2 , mid + 1 , e); 
    sg[x] = unite(sg[x + x + 2] , sg[x + x + 1]); 
}

void build(int x , int s , int e){
    if(s == e){
        sg[x] = a[s];
        lazy[x] = identity();
        return;
    }
    int mid = (s + e) >> 1;
    build(x + x + 1 , s , mid);
    build(x + x + 2 , mid + 1, e);
    pull(x , s , e);
}
void modify(int x, int s ,int e , int l , int r , int v){
    if(l > r) return; 
    if(r < s || l > e) return;
    push(x , s , e);
    if(s >= l && e <= r){
        lazy[x] = v;  
        return;
    }    
    int mid = (s + e) >> 1;
    modify(x + x + 1, s , mid , l , r , v);
    modify(x + x + 2, mid + 1, e, l , r,v);
    pull(x , s , e);
}
int query(int x, int s, int e, int l , int r){
    if(l > r) return identity(); 
    if(l > e || r < s) return identity(); 
    push(x ,s ,e); 
    if(s == e) return sg[x];
    if(s >= l && e <= r) return sg[x];
    int mid = (s + e) >> 1;
    return unite(query(x + x + 1 , s , mid, l , r), query(x + x + 2, mid + 1 ,e ,l , r));    
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 100000;
    for(int i = 0; i < n; i++){
        a[i] = (rand() % n);
    }
    // show(n);
    build(0 ,0 , n - 1);
    for(int i = 0; i < 100001; ++i){
        int l , r;
        l = (rand() % n); r = (rand() % n);
        if(r < l) swap(l , r);
        int v = rand() % n;
        cout << "updated range l = " << l << " and r = " << r << " by " << v << '\n';
        for(int j = l; j <= r; j++){
            a[j] *= v;
        }
        modify(0 , 0 , n - 1, l , r , v);
        // show(n);
        int qs = rand() % n;
        int qe = rand() % n;
        if(qs > qe) swap(qs , qe);
        int sum = 1;
        for(int j = qs; j <= qe; ++j){
            sum = __gcd(sum , a[j]);
        }
        int sgsum = query(0 , 0 , n - 1, qs, qe);
        cout << "sum = " << sum << " and sgsum = "  << sgsum << '\n';
        assert(sum == sgsum);
        // assert(sum == sgsum);
    }
}