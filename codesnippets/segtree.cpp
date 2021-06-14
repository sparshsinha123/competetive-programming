class node{
public:
    int mx;
    node(){
        mx = INF;
    }
    node(int v){
        mx = v;
    }
};
 
template<typename T>
class segtree{
    public:
    vector<node> tree;
    int sz;

    segtree(){}

    segtree(int n){
        sz = n;
        tree.resize (4 * n, 0);
    }
    segtree(vector<T> &v){
        sz = int(v.size());
        int n = int (v.size());
        tree.resize (4 * n);
        build (0 , 0 , n - 1 , v);
    }
    node unite (node i , node j){
        return max(i.mx, j.mx);
    }
    void f (node &o , T v){
        o = node(v);
    }
    void build (int x , int s , int e , vector<T> &v){
        if (s == e){
            tree[x] = node(v[s]);
            return;
        }
        int m = (s + e) >> 1;
        build (x + x + 1 , s , m , v);
        build (x + x + 2 , m + 1 , e , v);
        tree[x] = unite (tree[x + x + 1] , tree[x + x + 2]);
    }
    void update (int x , int s , int e , int pos , T v){
        if (pos > e || pos < s) return;
        if (s == e){
            assert (s == pos);
            f(tree[x] , v);
            return;
        }
        int m = (s + e) >> 1;
        update (x + x + 1 , s , m , pos , v);
        update (x + x + 2 , m + 1 , e , pos , v);
        tree[x] = unite (tree[x + x + 1] , tree[x + x + 2]);
    }
    node query (int x , int s , int e, int l , int r){
        assert (r >= l);
        assert (!(e < l || s > r));
        if (s >= l && e <= r){
            return tree[x];
        }
        assert (s != e);
        int m = (s + e) >> 1;
        if (m < l || s > r) return query (x + x + 2 , m + 1 , e , l , r);
        else if (m + 1 > r || e < l) return query (x + x + 1, s , m , l , r);
        else{
            node lef = query (x + x + 1 , s , m , l , r);
            node rig = query (x + x + 2 , m + 1, e , l , r);
            return unite (lef , rig);
        }
    }

    // API
    node get(int l , int r){
        return query(0 , 0 , sz - 1, l , r);
    }
    void modify(int pos, T val){
        update(0 , 0 , sz - 1, pos, val);
    }
};