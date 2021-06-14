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

const int INF = 1e9 + 7;
const long long MOD = 1e9 + 7;

long long get(long long start , long long end){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    long long ret = uniform_int_distribution<int> (start , end)(rng);   
    return ret;
}

class dsu{
public:
    vector<int> par;
    dsu(int N){
        par.resize(N + 1);
        iota(par.begin(), par.end() , 0);
    }
    int find_set(int x){
        return par[x] == x ? x : (par[x] = find_set(par[x]));
    }
    bool merge(int x , int y){
        int px = find_set(x) , py = find_set(y);
        if(px == py) return false;
        par[px] = py;
        return true;
    }
};

void solve(){
	/*no multi tests*/
    int n = get(1 , 100);
    int k = get(1 , n);
    cout << n << " " << k << endl;
    
    dsu dsu(n);

    for(int i = 0; i < n - 1; i++){
        int x = get(1 , n);
        int y = get(1 , n);
        while(x == y || dsu.find_set(x) == dsu.find_set(y)){
            x = get(1 , n);
            y = get(1 , n);
        }
        dsu.merge(x , y);
        cout << x << " " << y << endl;
    }
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