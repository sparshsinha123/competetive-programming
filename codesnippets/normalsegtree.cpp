const int MAXN = 5e5;
pi segtree[MAXN];
int arr[141221];
void unite(pi &output , pi val1 , pi val2){
	assert(val1.second == val2.second);
	int v1 = val1.first , v2 = val2.first;
	int type = val1.second;
	output = {(type == 0 ? (v1 | v2) : (v1 ^ v2)) , 1 - type};
}
void build(int x , int start , int end){
	if(start == end){
		segtree[x] = {arr[start] , 0};
		return;
	}
	int mid = (start + end) >> 1;
	build(x + x + 1 , start , mid);
	build(x + x + 2, mid + 1, end);
	unite(segtree[x] , segtree[x * 2 + 1] , segtree[x * 2 + 2]);
}

void update(int x , int start , int end, int idx , int val){
	if(idx > end || idx < start) return;
	if(start == end){
		arr[start] = val;
		segtree[x] = {arr[start] , 0};
		return;
	}
	int mid = (start + end) >> 1;
	update(2 * x + 1, start , mid , idx , val);
	update(2 * x + 2, mid + 1, end, idx , val);
	unite(segtree[x] , segtree[2 * x + 1] , segtree[2 * x + 2]);
}