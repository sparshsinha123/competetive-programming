#define SIEVE
const int maxn = 2e6; /* check this.. */
int spf[maxn];
void construct(){
	spf[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(spf[i] > 0) continue;
		for(int j = i; j < maxn; j += i) if(spf[j] == 0) spf[j] = i;
	}
}

bool isprime(int N){
	return spf[N] == N;
}