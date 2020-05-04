#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
                     Keep trying ..!!!!
                     The journey is more important
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

// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

const ll mod = 1000000007;
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
class segTree{
    public:
     vector < T > tree;
     vector < T > v;
     void build(vector < T > &vec){ // O(N)
            v = vec;
            tree.resize(4 * v.size());
            buildUtil(0 , 0 , v.size() - 1);
     }
     void update(int x , int start , int end, int idx , T val){ // O(logN)
            if(idx > end || idx < start) return;
            if(start == end){
                v[idx] += val;
                tree[x] += val; // update elements in interval
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
};
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
}