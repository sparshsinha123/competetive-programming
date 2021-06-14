#define FACTORIALS

const int UPTO = 1e5 + 8;
mint fact[UPTO + 1];
void compute_factorials(long long MOD){
    fact[0] = 1;
    for(int i = 1; i <= UPTO; i++){
        fact[i] = fact[i - 1] * mint(i);
    }
}
