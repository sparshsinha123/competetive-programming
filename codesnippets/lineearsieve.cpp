#define SIEVE
const int MAXN = 1e6 + 7;
int lp[MAXN + 1];
vector<int> pr;

void construct(){
	for(int i = 2; i <= MAXN; i++){
		if(lp[i] == 0){
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAXN; ++j){
			lp[i * pr[j]] = pr[j];
		}
	}
}
