#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


/*
           1) long long vs int overflow
           2) read question carefully please!!!! it can cost you a lot
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
bool solve(ll n , ll d){
    // cerr<<"called with n = " << n << " and d = " << d << ' ';
        bool h = false;
        if(d <= n) h = true;
        else{
            ll D = ((1 - n) * (1 - n) - 4 * (d - n)); 
            if(D < 0){
                h = false;
            } else{
                double r1 = 1.00 * (-(1 - n) - sqrt(D)) / 2.0;
                double r2 = 1.00 * (-(1 - n) + sqrt(D)) / 2.0;
                ll ro1 = floor(r1);
                ll ro2 = ceil(r2);
                if(r1 <= r2) h = true;
                else h = false; 
            }
        
        }
return h;
}
typedef long double ld;

bool kush(ll n , ll d){
    // cerr<<"called with n = " << n << " and d = " << d << ' ';

        ll x = sqrt(d)-1;
        bool k=false;
        if(x>=0 && x+ceil(ld(d)/ld(x+1))<=n){
            k = true;
            return k;
        }
        if(x>0 && x-1+ceil(ld(d)/ld(x))<=n){
            k =true;
            return k;
        }
        if(x+1<=n && x+1+ceil(ld(d)/ld(x+2))<=n){
            k=true;
            return k;
        }
        k=false;
        return k;
}
bool vakul(ll n , ll d){
        int start=0;
        int end=n;
        bool flag=false;
        while(start<=end){
            int mid=(start+end)/2;
            int val1=(mid+(d/(mid+1)));
            if((d%(mid+1))!=0){
                val1++;
            }
            if(val1<=n){
                flag=true;
                break;
            }else{
                end=mid-1;
            }
        }
        // if(flag){
        //     cout<<"YES"<<endl;
        // }else{
        //     cout<<"NO"<<endl;
        // }
    return flag;
}
ll ok(int a,int b)
{
    ll x=a/b;
    if(a%b==0)
        return x;
    else return x+1;
}
bool r(ld n , ld d){

//    ld n,d;
    ll p=n/2;
    if(p+ok(d,p+1)<=n || n>=d)
        return true;
    else return false;
 
    // cout<<endl;
}
bool udbhav(ll n , ll d){
         bool k=false;

        if(n>=d)
        {
            k=true;
            return k;
        }
        bool flag=0;
        for(int i=1;i<=sqrt(d)+1;i++)
        {
            ll val=(d/(i+1));
            if(d%(i+1))
                val++;
            if(i+val<=n)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            k=true;
        }
        else
        {
            k=false;
            // cout<<"NO"<<endl;
        }
    return k;
}
bool r2(ll n, ll d){
    ll count=0;
    	if(n==d)
    	{
    		count=1;
            return true;
    	}
    	else
    	{
    	for(long long int i=1;i<=d;i++)
    	{
    		if((i+ceil(d/(long double)(i+1)))<=n)
    		{
    			count=1;
                return true;
    			break;
    		}
    		else if(i>n)
    		break;
    	}
    	}
    	if(count==0)
        return false;
}
int main(){
    // ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        for(int n = 1; n <= 1000; ++n){
            for(int d = 1; d <= 1000; ++d){
                // ll n = 5; ll d = 9;
                bool h = solve(n,d);
                bool k = kush(n,d);
                bool v = vakul(n,d);
                bool u = udbhav(n , d);
                bool ra = r(n , d);
                bool sec=r2(n,d);
                cout << n << " and " << d << " ";
                cout << h <<" and " << k << "and" << v << "and " << u << "r = " << ra << "and" <<sec<< '\n';
                assert(h==k && k == v && v == u && u == ra && ra == sec);
                if(h)cout<<"yesdfd\n";
                else cout<<"no\n";
            }
        }
}