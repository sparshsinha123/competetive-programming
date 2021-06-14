struct rational_number {
	ll num, den;
	rational_number() {}
	rational_number(ll a, ll b) : num(a), den(b) {}
	void print(){
	   cout << "(" << num << " " << den << ")\n";
	}
};
inline bool operator < (rational_number a, rational_number b) { return a.num * b.den < b.num * a.den; }
 
inline bool operator > (rational_number a, rational_number b) { return b < a; }
