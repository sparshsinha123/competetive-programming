#include "bits/stdc++.h"
/* Properties of modulo:
	(a/b)%m ,where m is prime  = (a%m) * (b^(m-2))%m
*/
    /*ROLLING HASH
    Rabin-Karp algorithm for pattern matching in a string in O(n) time
    Calculating the number of different substrings of a string in O(n2logn)
    Calculating the number of palindromic substrings in a string.
    */
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define ll long long 
#define pb push_back
#define gcd __gcd
#define nl cout<<"\n"
#define endl "\n"
#define all(c) (c).begin(),(c).end()
#define trav(a,x) for(auto a = x.begin() ; a != x.end() ; a++)
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

// o_set(ll) name ; -- defining ordered set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set - returns iterator
bool compare(pair<ll,ll> p1 , pair<ll,ll> p2){
    return p1.first > p2.first;
}
int main(){
    IOS;
    vector<pair<ll,ll>> v;
    v.pb(make_pair(1,2));
    v.pb(make_pair(0,100));
    v.pb(make_pair(5,5));
    sort(all(v) , compare);
    trav(it , v) cout << it->f <<" " << it->s<<endl;
}