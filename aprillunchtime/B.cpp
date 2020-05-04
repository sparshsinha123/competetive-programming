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
#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 

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

template <typename T>
class fenwick{
    public:
     vector<T> BIT;
     int N;
     fenwick(int size){ 
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
const int maxn = 2e6 + 3;
struct querynode{
    int fr;
    int sc;
    int td;
    int ft;
};
struct node{
    int df;
    int x;
    int y;
};
bool compare(node n1, node n2){
    return n1.df < n2.df;
}
bool qcomp(querynode q1 , querynode q2){
    return q1.fr < q2.fr;
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n , q;
        cin >> n >> q;
        vector<node> v(n);
        vector<querynode> queries(q);
        vector<int> ans(q);
        for(int i = 0; i < n; i++){
            int x , y;
            cin >> x >> y;
            node nn;
            nn.df = x - y;
            nn.x = x;
            nn.y = y;
            v[i] = nn;
        }
        sort(v.begin() , v.end() , compare);
        for(int i = 0; i < q; i++){
            int l , r;
            cin >> l >> r;
            querynode qq;
            int low = 0 , high = n - 1;
            int idx = n;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(v[mid].df >= l){
                    idx = mid;
                    high = mid - 1;
                } else low = mid + 1;
            }
            qq.fr = idx;
            qq.sc = l;
            qq.td = r;
            qq.ft = i;
            queries[i] = qq;
        }
        sort(queries.begin() , queries.end() , qcomp);
        // fenwick<int> fenw(fsize + 1);
        ordered_set ms; 
        int j = n - 1;
        int i = 0;
        for(int i = q - 1; i >= 0; i--){
            int l = queries[i].sc;
            int r = queries[i].td;
            while(j >= queries[i].fr){
                ms.insert(MP(v[j].x + v[j].y , j));
                // fenw.modify(v[j].x + v[j].y , 1);
                --j;
            }
            int tt = ms.order_of_key(MP(r , inf)); 
            ans[queries[i].ft] = tt;
        }
        for(int i = 0; i < q; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    #ifdef LOCAL
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
    #endif
    // g++ -DLOCAL -std=c++17 f.cpp
}
