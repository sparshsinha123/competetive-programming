typedef struct Edge{
	ll weight;
	int from;
	int to;
	Edge(ll weight , int from , int to){
		(*this).weight = weight;
		(*this).from = from;
		(*this).to = to;
	}
} Edge;
vector<Edge> kruskal(vector<Edge> &edges , int numvertices){
	dsu dsu(numvertices);
	int numedges = (int) edges.size();
	sort(edges.begin(), edges.end() , [&](Edge e1 , Edge e2){ return e1.weight < e2.weight; });
	int taken = 0;
	vector<Edge> minimum_spanning_tree;
	for(int i = 0; i < numedges; i++){
		ll weight = edges[i].weight;
		int x = edges[i].from;
		int y = edges[i].to;
		if(dsu.merge(x , y)){
			taken++;
			minimum_spanning_tree.push_back(Edge(weight , x , y));
			if(taken == numvertices - 1) break;
		}
	}
	return minimum_spanning_tree;
}
