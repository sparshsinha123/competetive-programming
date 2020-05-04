#include<bits/stdc++.h>
/* imp functions
ARRAYS AND STRINGS
	sorting arrays - sort(array,array+n);
	finding size of string - str.length();

VECTORS:
	assign() – It assigns new value to the vector elements by replacing old ones
	push_back() – It push the elements into a vector from the back
	pop_back() – It is used to pop or remove elements from a vector from the back.
	insert() – It inserts new elements before the element at the specified position
	erase(v.begin()+i) – It is used to remove elements from a container from the specified position or range.
	swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
	clear() – It is used to remove all the elements of the vector container
	emplace() – It extends the container by inserting new element at position
	emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
	v.reverse(v.begin(),v.end()) - reversing vector
	v.size() - finding size of vector
	v.sort(v.begin(),v.end()) - sorting vectors
*/

/* Properties of modulo:Fermat's little theorem
	(a/b)%m ,where m is prime  = (a%m) * (b^(m-2))%m
*/
using namespace std;
#define ll long long 
#define pb push_back
#define gcd __gcd
// checking whether a number is prime or not
bool compare(ll x, ll y){
    return x>y;
}
// checking whether a number is prime or not
ll isprime(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else{
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
    return 1;   
    }
}
// returning vector containing all prime numbers less than a given number
vector<ll> get_prime_factors_less_than(ll n){
    vector<ll> factor;
    vector<ll> prime(n,1);
    prime[0]=0,prime[1]=0;
    for(ll i = 2 ; i <= n ; i++){
        if(prime[i]==1){
            for(ll j=i*i;j<=n;j=j+i) prime[j]=0; 
            factor.push_back(i);
        }
    }
    return factor;
}
//returning vector containing index refering to elements of normal array after sorting it
vector<ll> retain_index(ll arr[], ll n){ 
    vector<pair<ll, ll> > vp; 
    for (ll i = 0; i < n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    } 
    sort(vp.begin(), vp.end());
    vector<ll> retain;
    for (ll i = 0; i < vp.size(); i++) { 
        ll a = vp[i].second;
        retain.pb(a);
    }
    return retain;
}
//returns x^y in order logn 
ll power(ll x, ll y) 
{ 
    if (y == 0) return 1; 
    ll a = power(x,y/2);
    if (y % 2 == 0) return a * a; 
    else return x * a * a; 
} 
int main(){
    ll n, m;
    cin>>n>>m;
    string s[n];
    ll t,score ;
    vector<ll> team[m];
    map<ll ,vector<string>> name[m];
    ll ct[m] = {0};
    for(ll i=0 ; i < n;i++){
        cin>>s[i]>>t>>score;
        team[t - 1].push_back(score);
        name[t-1][score].pb(s[i]);
    }
    for(ll i=0;i<m;i++) sort(team[i].begin() , team[i].end(),compare);
    for(ll i = 0;i < m;i++){
            //if(team[i].size() == 2 && team[i][0] == team[i][1]) ct[i]++;
            if(team[i].size() >= 3){
                if((team[i][0] == team[i][1] && team[i][1] == team[i][2]) || (team[i][0]!=team[i][1] && team[i][1]==team[i][2])) ct[i]++;
            }
    }
    for(ll i= 0;i<m;i++){
        if(ct[i] > 0 ) cout<<"?"<<endl;
        else cout<<name[i][team[i][0]]<<" "<<name[i][team[i][1]]<<endl;
    }
}
