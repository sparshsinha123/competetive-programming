#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define ll long long
#define umapii unordered_map<int,int>
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<int,int>
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
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define MP(a,b) make_pair(a,b)
#define debug(x)       cerr<< #x << " : " << x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[i].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";

/* ordered set: 
tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
member functions :
1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/

inline ll gcd (ll x , ll y){
    if (x < y) swap (x , y);
    while (y){
        ll temp = y;
        y = x % y;
        x = temp; 
    }
    return x;
}

inline ll modexp(ll x, ll ex , ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}

const int inf = 1e9 + 7;

class segTree{
    public:
     vector<pll> tree;
     vector<ll> v;
     void build(vector <ll> &vec){ // O(N)
            v = vec;
            tree.resize(4 * v.size());
            buildUtil(0 , 0 , v.size() - 1);
     }
     void update(int x , int start , int end, int idx , ll val){ // O(logN)
            if(idx > end || idx < start) return;
            if(start == end){
                v[idx] = val;
                if (start % 2 == 0){
                    tree[x].first = val * 1ll * (start + 1);
                    tree[x].second = val;
                } else{
                    tree[x].first = -val * 1ll * (start + 1);
                    tree[x].second = -val;
                }
                return;
            }
            int mid = ((end + start) >> 1);
            update(x + x + 1,   start, mid, idx, val);
            update(x + x + 2, mid + 1, end, idx, val);
            tree[x].first = (tree[x + x + 1].first + tree[x + x + 2].first);
            tree[x].second = (tree[x + x + 1].second + tree[x + x + 2].second);
     }
     pll query(int x, int start , int end, int qs , int qe){ // O(logN)
            if(qs > end || qe < start) return {0 , 0}; // interval will not contribute
            if(start >= qs && end <= qe) return tree[x];
            int mid = ((start + end) >> 1);
            pll lef = query(x + x + 1, start, mid , qs , qe);
            pll rig = query(x + x + 2, mid + 1 , end , qs , qe);
            return make_pair(lef.first + rig.first , lef.second + rig.second);
     }
     void buildUtil(int x , int start , int end){ // O(N)
         if(start == end){
                if (start % 2 == 0){
                    tree[x].first = v[start] * 1ll *(start + 1);
                    tree[x].second = v[start];
                } else{
                    tree[x].first = -v[start] * 1ll * (start + 1);
                    tree[x].second = -v[start];
                }
                return;
         }
         int mid = ((start + end) >> 1);
         buildUtil(x + x + 1, start , mid); 
         buildUtil(x + x + 2, mid + 1, end);
            tree[x].first = (tree[x + x + 1].first + tree[x + x + 2].first);
            tree[x].second = (tree[x + x + 1].second + tree[x + x + 2].second);
     } 

   
};


void solve(){
   int N , Q;

   cin >> N >> Q;

   vector<ll> A(N);

   for (int i = 0; i < N; i++){
    cin >> A[i];
   }

   segTree sg;

   sg.build(A);
   ll sum = 0;


   for (int q = 0; q < Q; ++q){
     char ch;
     cin >> ch;
        int L , R;
     if (ch == 'U'){
        int idx , Value;

        cin >> idx >> Value;
        --idx;

        sg.update(0 , 0 , N - 1, idx , Value);

     } else{
        cin >> L >> R;
        L--;
        R--;
        pll p = sg.query(0 , 0 , N - 1, L, R);
        ll helperval = p.second;
        ll prefval = p.first;
        if (L & 1){
            sum -= (prefval - helperval * L);
        }
        else{
            sum += (prefval - helperval * L);
        }
     }
   }

   cout << sum << endl;
}
int main(){
    IOS;
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}
