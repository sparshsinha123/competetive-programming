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
const int N = 100;
int n , m;
vector<pair < int , int > > g[N];
bool vis[N];
const int inf = 1e9 + 7;
char code(int x){
    if(x == 1) return 'x';
    if(x == 2) return 'z' ;
    if(x == 3) return 'y';
    if(x == 4) return 'v';
    if(x == 5) return 'w';
    if(x == 6) return 't';
    if(x == 7) return 'u';
    return '?';
}
void dfs(int a){
    vis[a] = 1;
    cout << code(a) << ' ';
    for(auto x : g[a]){
        int v = x.first;
        int wt = x.second;
        if(!vis[v]){
            dfs(v);
        }
    }
}
int dis[N];
void bfs(){
    memset(dis , -1 , sizeof(dis));
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    while(!Q.empty()){
        int tp = Q.front();
        Q.pop();
        cout << "("<<code(tp) << "," << dis[tp] <<") ";
        for(auto x : g[tp]){
            int v = x.first;
            int w = x.second;
            if(dis[v] == -1){
                dis[v] = 1 + dis[tp];
                Q.push(v);
            }
        }
    }
}

int dist[N];
int par[N];
void djikstra(){
    memset(dist , inf , sizeof(dist));
    memset(par, -1, sizeof(par));
    dist[1] = 0;
    par[1]=-1;
    multiset<pair<int,int>> ms; // min heap
    for(int i = 1; i <= n; i++){
        ms.insert(MP(dist[i],i));
    }
    int step=0;
    string s;
    while(!ms.empty()){
        cout<<"step " << step<<": ";
        // find the minimum vertex from the multiset
        pair<int,int> f= *(ms.begin());
        ms.erase( ms.begin() );
        int d=f.first;
        int v=f.second;
        // cerr<<"picked up " << code(v) << " with distance = " << dist[v] << ' ';
        s.pb(code(v));
        cout<<s<<" ";
        // relax all the edges
        for(auto x : g[v]){
            int c  = x.first;
            int wt = x.second;
            // cerr<<"edge to " << code(c) << " with " << dist[c]<<' ';
            if(dist[v] + wt < dist[c]){
                ms.erase(ms.find(MP(dist[c],c)));
                ms.insert(MP(dist[v]+wt,c));
                par[c]=v;
                dist[c]=dist[v]+wt;
                cout<<"(" << code(c)<<","<<dist[c] <<","<<code(par[c])<<") ";
            } else{
                cout<<"(" << code(c)<<","<<dist[c] <<","<<code(par[c])<<") ";
            }
        }
        cout<<'\n';
        vector<int> l={6,7,4,5,3,2};
        for(int ii=0;ii<=(int)l.size()-1;ii++){
            int i=l[ii];
             cout<<"("<<code(i)<<","<<dist[i]<<","<<code(par[i])<<") ";

        }
        cout<<'\n';
        ++step;
    }
}
int main(){
    IOS;
    cin >> n >> m;
    for(int  i = 0; i < m; i++){
        int u , v , wt;
        cin >> u >> v >> wt;
        g[u].pb(MP(v , wt));
        g[v].pb(MP(u , wt));
    }
    cout << "dfs from vertex  = " << code(1) << '\n';
    dfs(1);
    cout << '\n';
    cout << "bfs from vertex = " << code(1) << '\n';
    bfs();
    cout << '\n';
    cout<<"running djikstra on the graph\n";
    djikstra();
}
