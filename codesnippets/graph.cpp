	<content><![CDATA[
class Graph{
public:
	// template for 1 indexed graph
	int N;
	bool cycle;
	vector<vector<int>> g;
	vector<bool> visited;
	vector<bool> in_stack;
	vector<int> indegree;

	Graph(int N){
		cycle = false;
		(*this).N = N;
		g.resize(N + 1);
		indegree.resize(N + 1);
	}
	void printGraph(){
		cout << "the graph is " << endl;
		for(int i = 1; i <= N; i++){
			cout << i << " --> " ;
			for(auto child : g[i]){
				cout << child << " ";
			}
			cout << endl;
		}
	}
	void addEdge(int src , int dest){
		g[src].push_back(dest);
		indegree[dest]++;
	}
	void dfs(int src){
		visited.resize(N + 1 , false);
		in_stack.resize(N + 1, false);
		dfsUtil(src);
	}
	void dfsUtil(int src){
		visited[src] = 1;
		in_stack[src] = 1;
		for(auto child : g[src]){
			if(visited[child] == 1){
				if(in_stack[child]) cycle = true;
			}
			dfsUtil(child);
		}
		in_stack[src] = false;
	}
	void toposort(vector<int> &topo){
		visited.resize(N + 1 , false);
		for(int i = 1; i <= N; i++){
			if(visited[i] == 1 || (indegree[i] > 0)) continue;
			topological_sort(i , topo);
		}
		reverse(topo.begin(), topo.end());
	}
	void topological_sort(int src , vector<int> &topo){
		visited[src] = 1;
		for(auto child : g[src]){
			if(visited[child] == 1) continue;
			topological_sort(child, topo);
		}
		topo.push_back(src);
	}

	void bfs(int src){
		queue<int> que;
		vector<int> dist(N + 1 , INF);
		visited.resize(N + 1);
		fill(visited.begin(), visited.end(), 0);
		que.push(src);
		visited[src] = 1;
		dist[src] = 0;
		while(!que.empty()){
			auto tp = que.front();
			que.pop();
			for(auto child : g[tp]){
				if(visited[child] == 1) continue;
				visited[child] = 1;
				dist[child] = 1 + dist[tp];
				que.push(child);
			}
		}
	}
	
};