class maxflow{
public:
    int N;
    vector<vector<int>> adj;
    vector<vector<int>> capacity;
    maxflow(int _N){
        N = _N;
        adj.resize(N + 1);
        capacity = vector<vector<int>> (N + 1 , vector<int>(N + 1 , 0));
    }

    void addEdge(int u , int v , int cap){
        adj[u].push_back(v);
        capacity[u][v] = cap;
    }

    int breadth_first_search(int source , int sink , vector<int> &parents){
        fill(parents.begin(), parents.end() , -1);
        parents[source] = -2;
        queue<pair<int , int>> que;
        que.push({source , INF});

        while(!que.empty()){
            int current = que.front().first;
            int flow = que.front().second;
            que.pop();
            for(auto child : adj[current]){
                if(parents[child] != -1) continue;
                if(capacity[current][child] == 0) continue;
                int flowhere = min(flow , capacity[current][child]);
                parents[child] = current;
                if(child == sink) {
                    return flowhere;
                }
                que.push({child , flowhere});
            }
        }
        return 0;
    }

    int edmond_karp(int source,  int sink){
        int flow = 0;

        vector<int> parents(N + 1);

        int augmentingflow = 0;
        while((augmentingflow = breadth_first_search(source, sink, parents))){
            flow += augmentingflow;
            int current = sink;
            while(current != source){
                int previous = parents[current];
                capacity[previous][current] -= augmentingflow;
                capacity[current][previous] += augmentingflow;
                current = previous;
            }
        }
        return flow;
    }
};