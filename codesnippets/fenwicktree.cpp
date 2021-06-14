
template<typename T>
class fenwick_tree{ /* 1 - indexed fenwick tree */
public:
  vector<T> tree;
  int n;
  fenwick_tree(int sz){
    tree.resize(sz + 1);
    n = sz + 1;
  }
  T get(int x){
    T sum = 0;
    while(x > 0){
      sum += tree[x]; /* union of all tree[x] values */
      x -= (x & -x);
    }
    return sum;
  }
  void modify(int x, T val){
    while(x < n){
      tree[x] += val; /*update at point effects the interval tree[x]*/
      x += (x & -x);
    }
  }
};
