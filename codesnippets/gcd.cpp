ll gcd(ll x , ll y){
    if(y == 0)  return x;
    if(x == 0)  return y;
    if(x < y) swap(x , y);
    return gcd(x % y , y);
}
