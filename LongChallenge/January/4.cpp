#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
           1) long long vs int overflow
           2) read question carefully
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
const int inf = 1e9 + 7;
int n , q;
int a[N];
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> prefI(n , 0);
    vector<int> prefD(n , 0);
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            bool c = false;
            if(i - 2 >= 0 && a[i - 1] > a[i - 2]) c = true;
            if(c) prefI[i] = prefI[i - 1];
            else prefI[i] = prefI[i - 1] + 1;
            prefD[i] = prefD[i - 1];  
        } else{
            bool c = false;
            prefI[i] = prefI[i - 1];
            if(i - 2 >= 0 && a[i - 1] < a[i - 2]) c = true;
            if(c) prefD[i] = prefD[i - 1];
            else prefD[i] = prefD[i - 1] + 1;
        }
    }
        // cout << "prefi--->\n";
        // for(int i = 0; i < n; i++){
        //     cout << prefI[i] << ' ';
        // }
        // cout << '\n';

        // cout << "prefD--->\n";
        // for(int i = 0; i < n; i++){
        //     cout << prefD[i] << ' ';
        // }
        // cout << '\n';
    while(q--){
        int L , R;
        cin >> L >> R;
        L--; R--;
        if(L == 0){
            cout << (prefI[R] == prefD[R] ? "YES\n" : "NO\n");
        } else{
            int inc , dec;
            if(a[L] > a[L - 1]){
                bool c = false;
                if(L - 2 >= 0 && a[L - 1] > a[L - 2]) c = true;
                if(c){
                    if(a[L + 1] > a[L]) inc = prefI[R] - prefI[L - 1] + 1;
                    else inc = prefI[R] - prefI[L - 1];
                } else{
                    if(a[L + 1] > a[L]) inc = prefI[R] - prefI[L - 1];
                    else inc = prefI[R] - prefI[L - 1] - 1;
                }
                dec = prefD[R] - prefD[L - 1];
                cout << (inc == dec ? "YES\n" : "NO\n");
            } else{
                inc = prefI[R] - prefI[L - 1];
                bool c = false;
                if(L - 2 >= 0 && a[L - 1] < a[L - 2]) c = true;
                if(c){
                    if(a[L + 1] < a[L]) dec = prefD[R] - prefD[L - 1] + 1;
                     else dec = prefD[R] - prefD[L - 1];
                } else{
                    if(a[L + 1] < a[L]) dec = prefD[R] - prefD[L - 1];
                    else dec = prefD[R] - prefD[L - 1] - 1;
                }
                cout << (inc == dec ? "YES\n" : "NO\n");
            }
        }
    }
}