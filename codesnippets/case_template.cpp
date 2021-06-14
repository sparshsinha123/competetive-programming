#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ld  long double
#define vi vector<int> 
#define vll vector<ll> 
#define vvll vector<vector<ll>> 
#define vvi vector<vector<int>> 
#define vs vector<string>
#define vpll vector<pll>
#define vpi vector<pi>
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define all(c)  (c).begin(),(c).end()
#define sz(c) int((c).size())
#define MP make_pair

#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORI(i, a, b) for(int i = (a); i >= (b); i--)

const int INF = 1e9 + 7;
const long long MOD = 1e9 + 7;

// credits : tourist 
string to_string(string s) {return '"' + s + '"';}string to_string(const char* s) {return to_string((string) s);}string to_string(bool b) {return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void debug_out() { cerr << "\n"; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H) << "\n";debug_out(T...);} 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
void solve(){
 /*no multi tests*/
}

int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    #ifdef SIEVE
    construct();
    #endif

    #ifdef NCR
    compute_combinations_table(MOD);
    #endif

    #ifdef FACTORIALS
    compute_factorials(MOD);
    #endif

    for(int tc = 1; tc <= tt; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}