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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MP(a,b) make_pair(a,b)
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
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
     
       (3) common functions
       lower_bound(v.begin(),v.end(),x) - v.begin() --> smallest value greater than or equals to x
       upper_bound(v.begin(), v.end(),x)- v.begin() --> smallest value greater than x
       memset(dp , val , sizeof(dp)) -> sets the value of array dp to val
*/

ll modexp(ll x, ll ex, ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}

const int inf = 1e9 + 7;
ll XMAX = 1e9;
ll YMAX = 1e9;
string s;
bool isdir(char ch){
    return (ch == 'N' || ch == 'E' || ch == 'W' || ch == 'S');
}
bool isnum(char ch){
    return (ch >= '2' && ch <= '9');
}
void add(pll &p , char dir){
    if(dir == 'N') p.first -= 1;
    if(dir == 'S') p.first += 1;
    if(dir == 'W') p.second -= 1;
    if(dir == 'E') p.second += 1;
    p.first %= XMAX;
    p.second %= YMAX; 
}
void add(pll &p , int num, pll val){
    // debug(num);
    val.first = (1ll * num * val.first) % XMAX;
    val.second = (1ll * num * val.second) % YMAX;
    p.first += val.first;
    p.second += val.second;
    p.first %= XMAX;
    p.second %= YMAX;
}
pll solve(int &index){
    pll p = {0 , 0};
    // cerr << "index = " << index << '\n';
     while(index < (int) s.length() && s[index] != ')'){
        if(isdir(s[index])){
            add(p , s[index]);
            // cerr << "index = " << index << " and p = (" << p.fi << ", "<<p.se << ")\n";  
            index++;
        } else if(isnum(s[index])){
            int num = (s[index] - '0');
            // cerr << "nindex = " << index << " and p = (" << p.fi << ", "<<p.se << ")\n";  
            index += 2;
            pll prec = solve(index);
            // cerr << "recieved from bracket (" << prec.fi << ","<<prec.se << ") \n";
            add(p , num , prec);
            // cerr << "made index = " << index << " and p = (" << p.fi << ", "<<p.se << ")\n";  
        }
    }
    ++index;
    return p;
}

int main(){
    IOS;
    int NTC;
    cin >> NTC;
    for(int test = 1; test <= NTC; ++test){
        /*solve here*/
        cin >> s;
        cout << "Case #" << test << ": ";
        /*answer here*/
        pll p;
        int index = 0;
        p = solve(index);
        // cout << "("<<p.first << " " << p.second << ")";
        // debugp(p);
        ll x = p.first;
        ll y = p.second;
        if(x < 0) x += XMAX;
        if(y < 0) y += YMAX;
        x++;
        y++;
        cout << y << " " << x ;
        cout << '\n';
    }
}
