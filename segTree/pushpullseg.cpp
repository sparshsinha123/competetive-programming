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
int unite(int x , int y){
    // return combination of two range values
    return(x + y);
}
void push(int x, int s, int e){ 
    // u have lazy value here and you have to push it down
    if(lazy[x] == 0) return; // if nothing to push then return
    if(s == e){ // if no children then nothing to push 
        sg[x] += lazy[x];//update yourself and return
        lazy[x] = 0;
        return;
    }
    sg[x] += (e - s + 1)*lazy[x]; // update yourself
    lazy[x + x + 1] += lazy[x]; // push changes to left child
    lazy[x + x + 2] += lazy[x];//push changes to right child
    lazy[x] = 0; // no more changes now
    return;
}
void pull(int x , int s , int e){
    assert(s != e);
    int mid = (s + e) >> 1;
    push(x + x + 1 , s , mid); // push changes for left child
    push(x + x + 2 , mid + 1 , e); // push changes for right child
    sg[x] = unite(sg[x + x + 2] , sg[x + x + 1]); // combine values of two intervals
}

void build(int x , int s , int e){
    if(s == e){
        sg[x] = a[s];
        lazy[x] = 0;
        return;
    }
    int mid = (s + e) >> 1;
    build(x + x + 1 , s , mid);
    build(x + x + 2 , mid + 1, e);
    pull(x , s , e);
}
void modify(int x, int s ,int e , int l , int r , int v){
    if(l > r) return; // if malformed interval no need to update
    if(r < s || l > e) return; // if no overlap then no update
    push(x , s , e); // we are at a node which may have a previous lazy value so push it downward
    if(s >= l && e <= r){ // this range is completely within so simply set lazy value and return
        lazy[x] = v;  // any previous lazy value was already pushed down
        return;
    }
    // node is not completely within
    // so call modify procedure on left and right child
    int mid = (s + e) >> 1;
    modify(x + x + 1, s , mid , l , r , v);
    modify(x + x + 2, mid + 1, e, l , r,v);
    // pull the values to update the current node after modification is done
    pull(x , s , e);
}
int query(int x, int s, int e, int l , int r){
    if(l > r) return 0; // malformed interval for guarding against errors
    if(l > e || r < s) return 0; // no overlap so return 0
    push(x , s, e); //to use value of this node push changes down
    if(s == e) return sg[x]; // we can return as changes were pushed down already
    if(s >= l && e <= r) return sg[x]; // same here
    int mid = (s + e) >> 1;
    // in case of partial overlapp return combination of both right and left queries
    return unite(query(x + x + 1 , s , mid, l , r), query(x + x + 2, mid + 1 ,e ,l , r));    
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 100000;
    for(int i = 0; i < n; i++){
        a[i] = (rand() % n);
    }
    show(n);
    build(0 ,0 , n - 1);
    for(int i = 0; i < 11; ++i){
        int l , r;
        l = (rand() % n); r = (rand() % n);
        if(r < l) swap(l , r);
        int v = rand() % n;
        cout << "updated range l = " << l << " and r = " << r << " by " << v << '\n';
        for(int j = l; j <= r; j++){
            a[j] += v;
        }
        modify(0 , 0 , n - 1, l , r , v);
        show(n);
        int qs = rand() % n;
        int qe = rand() % n;
        if(qs > qe) swap(qs , qe);
        int sum = 0;
        for(int j = qs; j <= qe; ++j){
            sum += a[j];
        }
        int sgsum = query(0 , 0 , n - 1, qs, qe);
        cout << "sum = " << sum << " and sgsum = "  << sgsum << '\n';
        assert(sum == sgsum);
        // assert(sum == sgsum);
    }
}