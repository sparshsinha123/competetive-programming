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
#define MP(a,b) make_pair(a,b)
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

       (2) set / multiset  ss; 
       --> ss.insert(key); (insertion)
       --> ss.erase(ss.find(key)) .. (deletion)
       --> ss.find(key) != ss.end() ..existence check
       --> ss.lower_bound(x) -> smallest value which is greater than or equals to x
       --> ss.upper_bound(x) --> first value strictly greater than x
     
       (3) common functions
       lower_bound(v.begin(),v.end(),x) - v.begin() --> smallest value greater than or equals to x
       upper_bound(v.begin(), v.end(),x)- v.begin() --> smallest value greater than x
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
struct Point{
    ll x,y;
};
set<pll>s;
vector<Point> v;
vector<Point> outer;

void add(Point P){
    cerr<<"called\n";
    for(auto pt:v){
        if(pt.x==P.x && pt.y==P.y) continue;
        Point Q; Q.x=pt.x-P.x; Q.y=pt.y-P.y;
        if(s.find(MP(Q.x,Q.y))!=s.end()) continue;
        else{
            outer.pb(Q);
            s.insert(MP(Q.x,Q.y));
        }
    }
}


ll orientation(Point p, Point q, Point r) 
{ 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// Prints convex hull of a set of n points. 
vector<Point> hull;
void convexHull(vector<Point> points) 
{ 
     int n=points.size();
    // There must be at least 3 points 
    if (n < 3) return; 
  
    // Initialize Result 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
    // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output. 
    int p = l, q; 
    do{
        // Add current point to result 
        hull.push_back(points[p]); 
  
        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           // If i is more counterclockwise than current q, then 
           // update q 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 
  
        // Now q is the most counterclockwise with respect to p 
        // Set p as q for next iteration, so that q is added to 
        // result 'hull' 
        p = q; 
  
    } while (p != l);  // While we don't come to first point 
  
}

bool similar(vector<Point> &P, vector<Point> &Q){
    
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    v.resize(n);
    ll xmin=LLONG_MAX; ll xmax=LLONG_MIN; ll ymax=LLONG_MIN;
    ll ymin=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y;
        xmin=min(xmin,v[i].x); xmax=max(xmax,v[i].x);
        ymin=min(ymin,v[i].y); ymax=max(ymax,v[i].y);
    }
    for(auto pt: v){
        if(pt.x==xmin) add(pt);
        if(pt.y==ymin) add(pt);
        if(pt.x==xmax) add(pt);
        if(pt.y==ymax) add(pt);
    }

    cerr<<"outer\n";
    for(auto x: outer){
        cout<<"("<<x.x<<","<<x.y<<")";
    }
    cout<<'\n';
    convexHull(outer);
    if(hull.size()!=n) cout<<"NO\n";
    else{
        cout<<"YES\n";
    }
}