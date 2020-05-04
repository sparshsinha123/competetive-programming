
// ll primeNum1 = 31;
// ll primeNum2 = 53;
// MOD = 1e9 + 9
// incase of large hash queries use double hashing with two primes
class RollingHash{
   public:
   string s;
   ll PR;
   ll MOD;
   vll ro;
   vll minv;
   vll pw;
   RollingHash(string ss , ll pr , ll mod){
      s = ss; PR = pr; MOD = mod; int N = (int) s.length(); ll p = 1ll, val = 0;
      ro.resize(N); minv.resize(N + 1); pw.resize(N + 1);
      for(int i = 0; i < N ; i++){
          val += (((s[i] - 'a' + 1) * p) % MOD); val %= MOD; p = (p * PR)%MOD; ro[i] = val;
      }
      pw[0] = 1; minv[0] = 1; minv[1] = modexp(PR , MOD - 2, MOD);
      for(int i = 1; i <= N ; i++) pw[i] = (pw[i - 1] * PR) % MOD;
      for(int i = 2; i <= N ; i++) minv[i] = (minv[i - 1] * minv[1]) % MOD; 
   }
   ll getHash(int ii , int jj){
     return ((minv[ii] * (ro[jj] - ((ii - 1 >= 0) ? ro[ii - 1] : 0)))%MOD + MOD)%MOD;
   }
};