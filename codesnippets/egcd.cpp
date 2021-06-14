pll ExtendedEuclid(ll x , ll y){
	/* 
		returns {a , b} such that ax + by = g
		we know that gcd(x , y) = gcd(r , x)  where r = y % x
		x q + r = y. 
		Suppose a1 r + a2 x = g
		Then a1 (y - q x) + a2 x = g ==> Hence, {a2 - q a1 , a1} is the required coeff
	*/
	if(y == 0) return {1 , 0};
	if(x == 0) return {0 , 1};
	pll rec = ExtendedEuclid(y % x , x);
	return {rec.second - y / x * rec.first , rec.first};
}
