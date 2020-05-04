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
class SegTree{
    public:
     vector<T> tree;
     vector<T> v;
     vector<T> Lazy;
     void build(vector <T> &vec){ // O(N)
            v = vec;
            tree.resize(4 * v.size());
            Lazy.resize(4 * v.size());
            fill(Lazy.begin() , Lazy.end() , 0);
            buildUtil(0 , 0 , v.size() - 1);
     }
     void buildUtil(int x , int start , int end){ // O(N)
         if(start == end){
             tree[x] = v[start];
             return;
         }
         int mid = ((start + end) >> 1);
         buildUtil(x + x + 1, start , mid); 
         buildUtil(x + x + 2, mid + 1, end);
         tree[x] = tree[x + x + 1] + tree[x + x + 2]; // combine intervals
     } 
      void LazyUpdate(int x , int start , int end , int l , int r, T val){ // O(logN)
      // time complexity analysis is similar to function query.
            if(Lazy[x] != 0){
                tree[x] += ((end - start + 1) * Lazy[x]); // Update current node by Lazy value and push
                if(start != end){
                Lazy[x + x + 1] += Lazy[x]; 
                Lazy[x + x + 2] += Lazy[x]; 
                }
                Lazy[x] = 0;
            }
            if(start > end || l > end || r < start) return;

            if(start >= l && end <= r){ // node completely within
                Lazy[x] = val;
                return; 
            }
            ll mid = ((start + end) >> 1);
            LazyUpdate(x + x + 1,   start, mid , l , r , val);
            LazyUpdate(x + x + 2, mid + 1, end , l , r , val);
            T left  = tree[x + x + 1] + (mid - start + 1) * Lazy[x + x + 1];
            T right = tree[x + x + 2] + (end - mid) * Lazy[x + x + 2];
            tree[x] = left + right;
      }
      T LazyQuery(int x , int start , int end , int qs , int qe){
            if(start > end || qe < start || qs > end) return 0;
            if(Lazy[x] != 0){
                tree[x] += ((end - start + 1) * Lazy[x]);
                if(start != end){
                    Lazy[x + x + 1] += Lazy[x];
                    Lazy[x + x + 2] += Lazy[x];
                }
                Lazy[x] = 0;
            }
            if(start >= qs && end <= qe) return tree[x];
            ll mid = ((start + end) >> 1);
            T lef = LazyQuery(x + x + 1 , start  , mid , qs , qe);
            T rt  = LazyQuery(x + x + 2 , mid + 1, end , qs , qe);
            return lef + rt; // combine nodes
      }
};
int n;

int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = (int)s.length();
    int q;
    cin >> q;
    SegTree<ll> sg[26];
    vector<vector<ll>> c(26 , vector<ll>(n , 0));
    for(int i = 0; i < (int)s.length(); ++i){
        for(int ii = 0; ii < 26; ++ii){
          c[ii][i] += (i - 1 >= 0 ? c[ii][i - 1] : 0); 
        }
        c[s[i] - 'a'][i] += 1;
    }
    for(int j = 0; j < 26; j++) sg[j].build(c[j]);
    while(q--){
       int x;
       cin >> x;
       if(x == 1){
           int pos; cin >> pos; --pos;
           char c; cin >> c;
           sg[s[pos] - 'a'].LazyUpdate(0 , 0 , n - 1, pos , n - 1, -1ll);
           sg[c - 'a'].LazyUpdate(0 , 0 , n - 1, pos , n - 1, 1ll);          
           s[pos] = c;    

       } else{
           int L , R;
           cin >> L >> R;
           --L; --R;
           int d = 0;
           for(int i = 0; i < 26; i++){
              ll Qr = sg[i].LazyQuery(0 , 0 , n - 1, R , R);
              ll Ql = 0;
              if(L - 1 >= 0) Ql = sg[i].LazyQuery(0 , 0 , n - 1, L - 1 , L - 1);
              if(Qr > Ql) ++d;
           }
           cout << d << '\n';
       }
    }
}