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

class lca{
    public:
    int MAX_D;
    int dfs_timer;
    vector<vector<int>> g;
    vector<vector<int>> ancestor;
    vector<bool> visited;
    vector<int> depth;
    vector<int> en;
    vector<int> ex;
    lca(int n){
        g.resize(n + 1);
        visited.resize(n + 1 , 0);
        depth.resize(n + 1 , 0);
        en.resize(n + 1, 0);
        ex.resize(n + 1, 0);
        dfs_timer = 0;
        MAX_D = ceil(log2(n));
        ancestor = vector<vector<int>>(MAX_D + 1, vector<int>(n + 1 , -1));
    }
    void addEdge(int l, int r){
        g[l].push_back(r);
    }
    void do_dfs(int sr){
        visited[sr] = true;
        dfs_timer++;
        en[sr] = dfs_timer;
        for(auto child : g[sr]){
            if(!visited[child]){
                ancestor[0][child] = sr;
                depth[child] = depth[sr] + 1;
                do_dfs(child);
            }
        }
        dfs_timer++;
        ex[sr] = dfs_timer;
    }
    void build_lca_table(){
        int n = (int) g.size() - 1;
        this->do_dfs(1);
        for(int d = 1; d <= MAX_D; d++){
            for(int i = 1; i <= n; i++){
                if(ancestor[d - 1][i] != -1){
                    ancestor[d][i] = ancestor[d - 1][ancestor[d - 1][i]];
                }
            }
        }
    }
    int climb(int l , int d){
        int i = l;
        for(int dd = 0; (dd <= MAX_D && i != -1) ;dd++){
            if((1 << dd) & d) i = ancestor[dd][i];
        }
        return i;
    }
    int get_lca(int i , int j){
        if(depth[i] > depth[j]) i = climb(i , depth[i] - depth[j]);
        if(depth[j] > depth[i]) j = climb(j , depth[j] - depth[i]);
        assert(depth[j] == depth[i]);
        if(i == j) return i;
        for(int d = MAX_D; d >= 0; --d){
            if(ancestor[d][i] != ancestor[d][j]){
                i = ancestor[d][i];
                j = ancestor[d][j];
            }
        }
        return ancestor[0][i];
    }
    int isAncestor(int u , int v){
        return (en[u] <= en[v] && ex[v] <= ex[u]);
    }
};

int main(){
    IOS;
    int n;
    cin >> n;
    lca l(n);
    for(int i = 0; i < n - 1; i++){
        int  u , v;
        cin >> u >> v;
        l.addEdge(u , v);
        l.addEdge(v , u);
    }    
    l.build_lca_table();
    int q;
    cin >> q;
    while(q--){
        int r , u , v;
        cin >> r >> u >> v;
        if(u == v) {
            cout << u << '\n';
            continue;
        }
        if(l.isAncestor(r , u) && l.isAncestor(r , v)) cout << l.get_lca(u , v) << '\n';
        else if(l.isAncestor(r , u)){
            cout << r << '\n';
        } else if(l.isAncestor(r , v)){
            cout << r << '\n';
        } else{
            int uv = l.get_lca(u , v);
            int ru = l.get_lca(r , u);
            int rv = l.get_lca(r , v);
            if(uv == ru) cout << rv << '\n';
            else if(uv == rv) cout << ru << '\n';
            else {
                assert(ru == rv);
                cout << uv << '\n';
            }
        }
    }
}