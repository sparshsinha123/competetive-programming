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

const int inf = 1e9 + 7;
const int N=1e5+1;
ll fc[N],pw[N];
ll minv(ll c){
    return modexp(c,mod-2);
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    fc[0]=1;
    pw[0]=1;
    for(int i=1;i<=1e5;i++){
        fc[i]=(1ll*fc[i-1]*i);
        fc[i]%=mod;
        pw[i]=2*pw[i-1];
        pw[i]%=mod;
    }

    while(t--){
        int n;
        cin>>n;
        int m=n+n;
        vll v(m);
        umapll cnt;
        ll s=0;
        FOR(i,0,m-1) {
            cin>>v[i];
            cnt[v[i]]++;
            s+=v[i];
        }
        if(s%(n+1)!=0) cout<<0<<'\n';
        else{
            ll pN=(s/(n+1));
            if(cnt[pN]<2) cout<<0<<'\n';
            else{
                cnt[pN]-=2;
                if(cnt[pN]==0) cnt.erase(cnt.find(pN));
                bool no=false;
                map<pll,ll>mp;
                for(auto it=cnt.begin();it!=cnt.end();it++){
                    ll x=it->fi; ll c=it->se; ll op=pN-x;
                    if(x!=op){
                        if(c!=cnt[op]){
                            no=true;
                            break;
                        } else{
                            if(!mp.count(make_pair(op,x))){
                                mp[make_pair(x,op)]=c;
                            }
                        }
                    } else{
                        if(c%2!=0){
                            no=true;
                            break;
                        } else{
                            if(!mp.count(make_pair(x,x))){
                                mp[make_pair(x,x)]=(c>>1);
                            }
                        }
                    }
                }
                if(no)cout<<0<<'\n';
                else{
                    ll ans=fc[n-1];
                    for(auto pr : mp){
                        ll x=pr.fi.fi; ll y=pr.fi.se; ll c=pr.se;
                        ans*=minv(fc[c]);
                        ans%=mod;
                        if(x!=y){
                            ans*=pw[c];
                            ans%=mod;
                        }
                    }
                    cout<<ans<<'\n';
                }
            }
        }
    }
}