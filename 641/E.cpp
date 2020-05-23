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

const int MAXN = 1010;
string arr[MAXN];


int N , M , T;
int V[MAXN][MAXN];
int DX[] = {-1 , 0 , 0 , 1};
int DY[] = {0  ,-1 , 1 , 0};

bool bad (int x , int y){
    for (int i = 0; i < 4; i++){
        int newx = x + DX[i];
        int newy = y + DY[i];
        if (newx >= N || newx < 0 || newy >= M || newy < 0) continue;
        if (arr[newx][newy] == arr[x][y]) return true;
    }
    return false;
}
void solve(){

    cin >> N >> M >> T;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }	

    memset (V , -1 , sizeof(V));

    queue<pair<int , int>> Q;

    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (bad(x , y)){
                Q.push(make_pair(x , y));
                V[x][y] = 0;
            }
        }
    }

    while (!Q.empty()){
        pair<int, int> P = Q.front();
        Q.pop();
        int x = P.first;
        int y = P.second;

        assert (V[x][y] != -1);

        for (int i = 0; i < 4; i++){
            int newx = (x + DX[i]);
            int newy = (y + DY[i]);
            if (newx >= N || newx < 0 || newy >= M || newy < 0 || V[newx][newy] != -1) continue;
            V[newx][newy] = V[x][y] + 1;
            Q.push(make_pair(newx , newy));
        }
    }

    while (T--){
        int R , C ;
        ll P;
        cin >> R >> C >> P;
        --R; 
        --C;

        if (V[R][C] == -1){
            cout << arr[R][C] << endl;
            continue;
        }
        if (P <= V[R][C]){
            cout << arr[R][C] << '\n';
        } else{
            ll more = P - V[R][C];
            if (more & 1) cout << (arr[R][C] == '1' ? 0 : 1) << endl;
            else cout << arr[R][C] << endl;
        }
    }
}
int main(){
    IOS;
    int TT = 1;
    // cin >> T;
    for(int i = 1; i <= TT; i++){
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
}
