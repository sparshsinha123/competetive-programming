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
    #define MP(a,b) make_pair(a,b);
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
    #define ld long double
    ld dist(pll a, pll b){
        ld x=(a.fi-b.fi);
        ld y=(a.se-b.se);
        return sqrt(x*x+y*y);
    }
    int main(){
        ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            ll n,m,w,h;
            cin >> n>>m>>w>>h;
            string s;
            cin>>s;
            vpll v(m),u(m);
            for(int i=0;i<m;++i){
                ll x,y;
                cin>>x>>y;
                v[i]=MP(y,x);
                u[i]=MP(x,y);
            }
            sort(all(v));
            sort(all(u));
            ld top=(h-v[m-1].fi);
            ld dwn=(v[0].fi);
            ld bet=sqrt(h*h+w*w);
            ld rig=(w-u[m-1].fi);
            ld lef=(u[0].fi);
            for(int i=0;i<m;i++){
                for(int j=i+1;j<m;j++){
                    bet=min(bet,dist(v[i],v[j]));
                }
            }
            ld ans=bet;
            int cntl=0,cntr=0,cntu=0,cntd=0;
            for(auto x : s){
                cntd += (x=='D');
                cntu += (x=='U');
                cntr += (x=='R');
                cntl += (x=='L');
            }
            int cntv=cntu+cntd;
            int cnth=cntl+cntr;
            if(s.length()==0) ans=bet;
            else{
                if(cntv >= 2 && cnth >= 2){
                    ans=min({bet,2*top,2*dwn,2*lef,2*rig});
                } else if(cntv>=2){
                    if(cnth==0){
                         ans=min({bet,2*top,2*dwn});                        
                    } else{
                        if(cntl==1){
                           ans=min({bet,2*top,2*dwn,2*lef});
                        } else{ // cntr==1
                           ans=min({bet,2*top,2*dwn,2*rig});
                        }
                    }
                } else if(cnth >= 2){
                       if(cntv==0){
                            ans=min({bet,2*lef,2*rig});
                       } else{
                           if(cntu==1){
                             ans=min({bet,2*lef,2*rig,2*top});                           
                           } else{
                             ans=min({bet,2*lef,2*rig,2*dwn});
                           }
                       }
                } else{
                    if(cntv==1 && cnth==1){
                         if(cntl==1){
                             if(cntu==1){
                                 ans=min({bet,2*lef,2*top});
                             } else{
                                 ans=min({bet,2*lef,2*dwn});
                             }
                         } else{ // cntr==1
                             if(cntu==1){
                                 ans=min({bet,2*rig,2*top});
                             } else{
                                 ans=min({bet,2*rig,2*dwn});
                             }
                         }
                    } else if(cntv==1){
                         if(cntu==1){
                             ans=min(bet,2*top);
                         } else ans=min(bet,2*dwn);
                    } else if(cnth==1){
                         if(cntl==1){
                             ans=min(bet,2*lef);
                         } else ans=min(bet,2*rig);
                    } else{
                        ans=bet;
                    }
                }
            }
            cout<<setprecision(10)<<ans<<'\n';
        }
    }