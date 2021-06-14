
class hld{
public:
    vector<vector<int>> tree;
    vector<vector<int>> chains;
    vector<int> subtree;
    vector<int> parent;
    vector<int> color;
    vector<int> index_in_chain;
    vector<int> depth;
    int ROOT;
    int n;
    bool heavy_light_decomposed;

    hld(){}

    hld(int n, int root = 1){
        this->n = n;
        tree    = vector<vector<int>> (n + 1);
        chains  = vector<vector<int>> (n + 1);
        subtree = vector<int> (n + 1, 0);
        parent  = vector<int> (n + 1, -1);
        color   = vector<int> (n + 1, 0);
        depth   = vector<int> (n + 1, 0);
        index_in_chain = vector<int> (n + 1, -1);

        ROOT = root;
        heavy_light_decomposed = false;
    }

    void add_edge(int a, int b){
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    void dfs_compute_functions(int src, int par = -1){
        subtree[src] = 1;
        parent[src] = par;
        for(auto child : tree[src]){
            if(child == par) continue;
            depth[child] = 1 + depth[src];
            dfs_compute_functions(child , src);
            subtree[src] += subtree[child];
        }
    }

    void dfs_heavy_light_color(int x, int p = -1){
        int best = -1;
        for(auto child : tree[x]){
            if(child == p) continue;

            if(best < 0 || subtree[best] < subtree[child]){
                best = child;
            }
        }

        if(best == -1) return;

        color[best] = color[x];
        index_in_chain[best] = index_in_chain[x] + 1;
        chains[color[x]].push_back(best);

        dfs_heavy_light_color(best , x);

        for(auto child : tree[x]){
            if(child == best || child == p) continue;
            
            color[child] = child;
            index_in_chain[child] = 1;
            chains[child].push_back(child);

            dfs_heavy_light_color(child, x);
        }
    }

    void init(){
        dfs_compute_functions(ROOT);
        color[ROOT] = ROOT;
        index_in_chain[ROOT] = 1;
        chains[color[ROOT]].push_back(ROOT);
        dfs_heavy_light_color(ROOT);
        heavy_light_decomposed = true;
    }


    /* {color, start_index , end_index} or {-1 , jump_vertex_1, jump_vertex_2}*/
    vector<tuple<int, int, int>> hld_segments(int x , int y){
        /*perform decomposition on the path from a to b*/
        assert(heavy_light_decomposed);
        vector<tuple<int, int, int>> paths_segments_x = {};
        vector<tuple<int, int, int>> paths_segments_y = {};

        while(true){
            if(color[x] == color[y]){
                paths_segments_x.emplace_back(color[x], index_in_chain[x], index_in_chain[y]);
                break;
            }
            if(depth[color[x]] < depth[color[y]]){
                paths_segments_y.emplace_back(color[y], 1, index_in_chain[y]);
                paths_segments_y.emplace_back(-1, parent[color[y]], color[y]);
                y = parent[color[y]];
            } else{
                paths_segments_x.emplace_back(color[x], index_in_chain[x], 1);
                paths_segments_x.emplace_back(-1, color[x], parent[color[x]]); 
                x = parent[color[x]];               
            }
        }

        reverse(paths_segments_y.begin(), paths_segments_y.end());
        
        for(auto segments : paths_segments_y)
            paths_segments_x.push_back(segments);

        return paths_segments_x;
    }

};
