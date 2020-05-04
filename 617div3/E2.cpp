#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
            common mistakes
           1) long long vs int overflow
           2) read question carefully please!!!! it can cost you a lot
           3) unorderedmap is O(1) look up but worst case can be bad
           4) maps have higher constant so many lookups can cause TLE
           5) leaving debugs or cerrs in the program at times can cause TLE

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
#define MP(a,b) make_pair(a,b);
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
const int N = 28;

template <typename T>
class segTree{
    public:
     vector <T> tree;
     vector <T> v;
     vector <T> lazy;
     void build(vector <T> &vec){ // O(N)
            v = vec;
            tree.resize(4 * v.size());
            lazy.resize(4 * v.size());
            fill(lazy.begin() , lazy.end() , 0);
            buildUtil(0 , 0 , v.size() - 1);
     }
     void update(int x , int start , int end, int idx , T val){ // O(logN)
            if(idx > end || idx < start) return;
            if(start == end){
                v[idx] = min(v[idx],val);
                tree[x] = min(tree[x],val); // update elements in interval
                return;
            }
            int mid = ((end + start) >> 1);
            update(x + x + 1,   start, mid, idx, val);
            update(x + x + 2, mid + 1, end, idx, val);
            tree[x] = min(tree[x + x + 1] , tree[x + x + 2]); // combine intervals
     }
     T query(int x, int start , int end, int qs , int qe){ // O(logN)
            if(qs > end || qe < start) return inf; // interval will not contribute
            if(start >= qs && end <= qe) return tree[x];
            int mid = ((start + end) >> 1);
            T lef = query(x + x + 1, start, mid , qs , qe);
            T rig = query(x + x + 2, mid + 1 , end , qs , qe);
            return min(lef , rig); // combine intervals
     }
     void buildUtil(int x , int start , int end){ // O(N)
         if(start == end){
             tree[x] = v[start];
             return;
         }
         int mid = ((start + end) >> 1);
         buildUtil(x + x + 1, start , mid); 
         buildUtil(x + x + 2, mid + 1, end);
         tree[x] = min(tree[x + x + 1] , tree[x + x + 2]); // combine intervals
     } 
     void naiveUpdate(int x , int start , int end , int l , int r , T val){ // O(N)
            if(l > end || r < start) return;
            if(start == end){
                tree[x] += val; // update node by val
                return;
            }
            int mid = ((start + end) >> 1);
            naiveUpdate(x + x + 1 ,   start, mid, l, r, val);
            naiveUpdate(x + x + 2 , mid + 1, end, l, r, val);
            tree[x] = min(tree[x + x + 1] , tree[x + x + 2]); // combine intervals
      }
      void lazyUpdate(int x , int start , int end , int l , int r, T val){ // O(logN)
      // time complexity analysis is similar to function query.
            if(lazy[x] != 0){
                tree[x] += lazy[x]; // update current node by lazy value and push
                if(start != end){
                lazy[x + x + 1] += lazy[x]; 
                lazy[x + x + 2] += lazy[x]; 
                }
                lazy[x] = 0;
            }
            if(start > end || l > end || r < start) return;

            if(start >= l && end <= r){ // node completely within
                lazy[x] = val;
                return; 
            }
            int mid = ((start + end) >> 1);
            lazyUpdate(x + x + 1,   start, mid , l , r , val);
            lazyUpdate(x + x + 2, mid + 1, end , l , r , val);
            T left  = tree[x + x + 1] + lazy[x + x + 1];
            T right = tree[x + x + 2] + lazy[x + x + 2];
            tree[x] = min(left , right);
      }
      T lazyQuery(int x , int start , int end , int qs , int qe){
            if(start > end || qe < start || qs > end) return inf;
            if(lazy[x] != 0){
                tree[x] += lazy[x];
                if(start != end){
                    lazy[x + x + 1] += lazy[x];
                    lazy[x + x + 2] += lazy[x];
                }
                lazy[x] = 0;
            }
            if(start >= qs && end <= qe) return tree[x];
            int mid = ((start + end) >> 1);
            T lef = lazyQuery(x + x + 1 , start  , mid , qs , qe);
            T rt  = lazyQuery(x + x + 2 , mid + 1, end , qs , qe);
            return min(lef , rt); // combine nodes
      }
};
ll fenw[N];
void modify(int x , ll val){
    while(x < N){
        fenw[x] += val;
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
void show(){
    for(int i = 0; i < 26;i++){
        cout<<get(i)-get(i-1);
    }
    cout<<'\n';
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s; cin >> s;
    vi c(n,-1);
    vi dp(n,0);
    vi arr(26,inf);
    vi before(n,-1);
    modify(s[0]-'a'+1,1);
    for(int i=1;i<n;i++){
        int v=s[i]-'a'+1;
        dp[i]=get(N-1)-get(v);
        modify(s[i]-'a'+1,1);
    }
    
    before[0]=inf;
    segTree<int> sg;
    sg.build(arr);
    sg.update(0,0,25,s[0]-'a',0);
    for(int i=1;i<n;i++){
        if(dp[i]!=0){
            int which=(s[i]-'a');
            before[i]=sg.query(0,0,25,which+1,25);
        } else before[i]=inf;
        sg.update(0,0,25,s[i]-'a',i);    
    }
    // for(int i=0;i<n;i++)cout<<before[i]<< ' ';
    // cout<<'\n';
    map<int,int> mp;
    for(int i=0;i<n;i++){
        // if(c[i]==-1)c[i]=1;
        // for(int j=i+1;j<n;j++){
        //     if(s[j]<s[i]){
        //         if(c[j]==-1) c[j]=c[i]+1;
        //         else if(c[j]==c[i]){
        //             c[j]++;
        //         }
        //     }
        // }
        if(dp[i]==0) c[i]=1;
        else{
            c[i]=c[before[i]]+1;
            c[i] += mp[]
        }
    }
    vi b=c;
    sort(all(b));
    b.resize(unique(b.begin(),b.end())-b.begin());
    int res=b.size();
    for(int i=0;i<n;i++){
        c[i]=lower_bound(b.begin(),b.end(),c[i])-b.begin();
        c[i]++;
    }
    cout<<res<<'\n';
    for(int i=0;i<n;i++){
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}