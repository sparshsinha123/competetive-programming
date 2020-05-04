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
bool gr[3][N];
int n , q;
set<pair<pi,pi>> s;
bool present(int r,int c, int nr, int nc){
    pi p1=make_pair(r,c);
    pi p2=make_pair(nr,nc);
    if(r==1) return s.find(make_pair(p1,p2))!=s.end();
    else return s.find(make_pair(p2,p1))!=s.end();
}
void tag(int r, int c, int nr, int nc){
    pi p1=make_pair(r,c);
    pi p2=make_pair(nr,nc);
    if(r==1) s.insert(make_pair(p1,p2));
    else s.insert(make_pair(p2,p1));
}
void takeout(int r, int c, int nr, int nc){
     pi p1=make_pair(r,c);
     pi p2=make_pair(nr,nc);
    if(r==1) s.erase(make_pair(p1,p2));
    else  s.erase(make_pair(p2,p1));
}
bool iswithin(int r,int c){
    if(r<=0||r>=3)return false;
    if(c>=1 && c<=n)return true;
    return false;
}
void handle(int r, int c){
   int nx=(r==1 ? 2:1);
   if(gr[r][c]==0){
        gr[r][c]=1;
        if(iswithin(nx,c+1) && gr[nx][c+1]) tag(r,c,nx,c+1);
        if(iswithin(nx,c) && gr[nx][c]) tag(r,c,nx,c);
        if(iswithin(nx,c-1) && gr[nx][c-1]) {
            tag(r,c,nx,c-1);
        }
   } else{
        gr[r][c]=0;
        if(iswithin(nx,c+1) && present(r,c,nx,c+1)) takeout(r,c,nx,c+1);
        if(iswithin(nx,c) && present(r,c,nx,c)) takeout(r,c,nx,c);
        if(iswithin(nx,c-1) && present(r,c,nx,c-1)) takeout(r,c,nx,c-1);
   }
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    while(q--){
        int r , c;
        cin >> r >> c;
        handle(r,c);
        cout << (s.size() == 0 ? "Yes\n" : "No\n");
    }
}
