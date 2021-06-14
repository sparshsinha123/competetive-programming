class lca{
    public:
    const static bool do_tour = false;
    int max_depth;
    int dfs_timer;
    vector<vector<int>> g;
    vector<vector<int>> ancestor;
    vector<bool> visited;
    vector<int> depth;
    vector<int> en;
    vector<int> ex;
    vector<int> par;
    vector<int> tour;

    bool BUILT_LCA_TABLE = false;

    lca(){}

    lca(long long n){
        g.resize(n + 1);
        visited.resize(n + 1 , 0);
        depth.resize(n + 1 , 0);
        en.resize(n + 1, 0);
        ex.resize(n + 1, 0);
        par.resize(n + 1, -1);
        dfs_timer = 0;
        max_depth = ceil(log2(n));
        ancestor = vector<vector<int>>(max_depth + 1, vector<int>(n + 1 , -1));
    }
    void add_edge(int l, int r){
        g[l].push_back(r);
        g[r].push_back(l);
    }
    void do_dfs(int sr){
        visited[sr] = true;
        dfs_timer++;
        en[sr] = dfs_timer;
        if(do_tour)
            tour.push_back(sr);
        for(auto child : g[sr]){
            if(!visited[child]){
                ancestor[0][child] = sr;
                depth[child] = depth[sr] + 1;
                par[child] = sr; 
                do_dfs(child);
            }
        }
        dfs_timer++;
        ex[sr] = dfs_timer;
        if(do_tour)
            tour.push_back(sr);
    }

    void build(){
        int n = (int) g.size() - 1;
        this->do_dfs(1);
        for(int d = 1; d <= max_depth; d++){
            for(int i = 1; i <= n; i++){
                if(ancestor[d - 1][i] != -1){
                    ancestor[d][i] = ancestor[d - 1][ancestor[d - 1][i]];
                }
            }
        }

        BUILT_LCA_TABLE = true;
    }

    /*walk d units starting from l*/
    int climb(int start , int walk_up_by){
        assert(BUILT_LCA_TABLE);
        int i = start;
        for(int dd = 0; (dd <= max_depth && i != -1); dd++){
            if((1 << dd) & walk_up_by) i = ancestor[dd][i];
        }
        return i;
    }
    /*API : find least_common_ancestors of i and j*/
    int get_lca(int i , int j){
        assert(BUILT_LCA_TABLE);
        if(depth[i] > depth[j]) i = climb(i , depth[i] - depth[j]);
        if(depth[j] > depth[i]) j = climb(j , depth[j] - depth[i]);
        assert(depth[j] == depth[i]);
        if(i == j) return i;
        for(int d = max_depth; d >= 0; --d){
            if(ancestor[d][i] != ancestor[d][j]){
                i = ancestor[d][i];
                j = ancestor[d][j];
            }
        }
        return ancestor[0][i];
    }
    /*O(1) check for ancestor*/
    bool isAncestor(int u , int v){
        assert(BUILT_LCA_TABLE);
        return (en[u] <= en[v] && ex[v] <= ex[u]);
    }

    /* get distance between any two vertices */
    int get_distance(int u , int v){
        assert(BUILT_LCA_TABLE);
        return depth[u] + depth[v] - 2 * depth[get_lca(u , v)];
    }
};