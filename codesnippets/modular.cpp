/* template for modular arithmetic */
ll modexp(ll a, ll b, ll md) {
    assert(b >= 0);
    ll x = a, res = 1LL, p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
        res %= md;
        x %= md;
    }
    return res;
}
struct mint{
    ll val;

    mint(ll _val = 0){
        val = _val % MOD;
        if(val < 0) val += MOD;
    }

    mint operator+ (mint other) const {
        return mint(val + other.val);
    }

    mint operator- (mint other) const{
        return mint(val - other.val);
    }
    void operator+= (mint other){
        val += other.val;
        val %= MOD;
    }

    mint operator- () const{
        return mint(-val);
    }

    void operator-= (mint other){
        val += MOD - other.val;
        val %= MOD;
    }

    mint operator* (mint other) const{
        return mint(val * other.val);
    }

    void operator*= (mint other) {
        val *= other.val;
        val %= MOD;
    }

    bool operator== (mint other) const{
        return val == other.val;
    }

    bool operator!= (mint other) const{
        return val != other.val;
    }

    mint operator/ (mint other) const{
        ll p = modexp(other.val, MOD - 2, MOD);
        p *= val;
        p %= MOD;
        return mint(p);
    }

    void operator/= (mint other){
        ll p = modexp(other.val, MOD - 2, MOD);
        p *= val;
        p %= MOD;
        val = p;
    }
};

ostream& operator<< (ostream& out, mint p) {
  out << p.val;
  return out;
}
