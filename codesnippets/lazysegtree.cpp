template<typename segment, typename update>
class segmenttree{
public:
  struct node {
    segment seg;
    update upd;
  };
  
  int sz;
  vector<node> tree;
  
  segmenttree(){}
  segmenttree(int n){
    init(n);
  }
  void init(int n){
    sz = 1;
    while(sz < n){
      sz <<= 1;
    }
    tree.assign(2 * sz, node());
  }
  /* push down changes from a particular node */
  void push_down(int x, int st, int en){
   if(tree[x].upd.is_default()) return;
    tree[x].seg.apply(st, en, tree[x].upd);
    if(st < en){
      tree[2*x+1].upd = tree[2*x+1].upd.combine(tree[x].upd);
      tree[2*x+2].upd = tree[2*x+2].upd.combine(tree[x].upd);
    }
    tree[x].upd.reset();
  }
  
  /* query a certain range [ql..qr]*/
  void query(int x, int st, int en, int ql, int qr, segment &ans){
    if(st > en || en < ql || st > qr) return; 
    push_down(x, st, en);
    if(st >= ql && en <= qr){
      ans.merge(tree[x].seg);
      return;
    }
    int m = (st + en) >> 1;
    query(2*x+1, st, m, ql, qr, ans);
    query(2*x+2, m+1, en, ql, qr, ans);
  }
  
  /* apply range update on [ul..ur] */
  void range_upd(int x, int st, int en, int ul, int ur, const update &U){
    if(st > en || st > ur || en < ul) return;
    push_down(x, st, en);
 
    if(st >= ul && en <= ur){
      tree[x].upd = tree[x].upd.combine(U);
      return;
    }
    int m = (st + en) >> 1;
    range_upd(2*x+1, st, m, ul, ur, U);
    range_upd(2*x+2, m+1, en, ul, ur, U);
    
    segment lf = tree[2*x+1].seg;
    segment rt = tree[2*x+2].seg;
    
    lf.apply(st, m, tree[2*x+1].upd);
    rt.apply(m + 1, en, tree[2*x+2].upd);
    
    lf.merge(rt);
    tree[x].seg = lf;
  }
  /* API : query */
  segment get(int L, int R){
    segment ans;
    if(L > R) return ans;
    query(0, 0, sz - 1, L, R, ans);
    return ans;
  }
  /* API : range update */
  void modify(int L, int R, const update &U){
    range_upd(0, 0, sz - 1, L, R, U);
  }
};
 
 
struct update{
  int bit;   
  
  static const int DEFAULT_UPD = -1;
  
  /* default lazy update value */
  update(int _bit = DEFAULT_UPD){
    bit = _bit;
  }
  
  bool is_default() const{
   return bit == DEFAULT_UPD;
  }
  /* reset the values of update to default */
  void reset(){
    bit = DEFAULT_UPD;
  }
  /* two successive updates applied */
  update combine(const update &other) const{
    return update(other.bit);
  }
};
 
struct segment{
   int left_most_one;
   int right_most_one;
   int left_most_zero;
   int right_most_zero;
   int sum;
   
   static const ll DEFAULT_VAL = 0; /* when segments are created using init */
   
   static const ll NEUTRAL_VAL = 0; /* be careful here */
   
   /* return empty segment -- when the segment tree is created
    then this is the default segment value */
   segment() {
      left_most_one = left_most_zero = INF;
      right_most_one = right_most_zero = -INF;
      sum = 0;
   }
   
   /* apply the update on current range */
   void apply(int start, int end, const update &UPD){
     if(UPD.is_default()) return;
     if(UPD.bit == 0){
        right_most_one = -INF;
        left_most_one = INF;
        left_most_zero = start;
        right_most_zero = end;
        sum = 0;
     } else{
        assert(UPD.bit == 1);
        left_most_zero = INF;
        right_most_zero = -INF;
        left_most_one = start;
        right_most_one = end;
        sum = end - start + 1;
     }
   }
   
   /* merge `other` segment with this segment */
   void merge(const segment &other){
      left_most_one = min(left_most_one , other.left_most_one);
      right_most_one = max(right_most_one , other.right_most_one);
      
      left_most_zero = min(left_most_zero, other.left_most_zero);
      right_most_zero = max(right_most_zero, other.right_most_zero);
   
      sum += other.sum;
   }
   
   /* merge two segments */
   void merge(const segment &a, const segment &b){
     *this = a;
     merge(b);
   }
};