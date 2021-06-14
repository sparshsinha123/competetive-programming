class centroid_decomposition_tree{ 
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> parent;
    vector<int> subtree;
    int n;
    static const int ROOT = 1;
    centroid_decomposition_tree(){}

    centroid_decomposition_tree(int sz){
        n = sz;
        graph = vector<vector<int>> (n + 1, vector<int> ());
        visited = vector<bool> (n + 1, false);
        parent = vector<int> (n + 1);
        subtree = vector<int> (n + 1);
    }

    void add_edge(int source, int destination){
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    int find_subtree_sizes(int src, int par = -1){
        if(visited[src]) return 0;
        subtree[src] = 1;
        for(auto child : graph[src]){
            if(child == par) continue;
            subtree[src] += find_subtree_sizes(child , src);
        }
        return subtree[src];
    }

    int find_centroid(int src, int par, int n){
        for(auto child : graph[src]){
            if(child == par) continue;
            if(!visited[child] && subtree[child] > n / 2){
                return find_centroid(child, src, n);
            }
        }
        return src;
    }

    void init_centroid(int src = ROOT, int par = -1){
        find_subtree_sizes(src);

        int centroid = find_centroid(src , -1, subtree[src]);
        visited[centroid] = true;
        
        parent[centroid] = par; 

        for(auto child : graph[centroid]){
            if(!visited[child]){
                init_centroid(child, centroid);
            }
        }
    }

};
