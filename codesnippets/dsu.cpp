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