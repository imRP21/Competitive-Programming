////////////////////////////////////
// Point update
// Range query
class SegTree
{
  // rename correctly your [input arr]
  // seg arr is 1 - based
  // {l, r}: be the 0 - based transition range of [input arr]
  // {L, R}: be the 0 - based fixed query range of [input arr]
  // idx: 0 - based index of [input arr]
  // node: 1 - based index of segment tree node in [seg arr]
  public:
    int N;
    vector<int> seg;

  public:
    SegTree(int N)
    {
      this->N = N;
      seg.resize((N << 2) + 5);
    }

    void build(int node, int l, int r)
    {
      if(l == r)
      {
        seg[node] = arr[l];   
        return;
      }

      int mid = (l + r) >> 1;
      build(node << 1, l, mid);
      build((node << 1) + 1, mid + 1, r);

      seg[node] = min(seg[node << 1], seg[(node << 1) + 1]);
    }

    void update(int node, int idx, int val, int l, int r) 
    {
      if(l == r)
      {
        seg[node] = arr[idx] = val;
        return;
      }

      int mid = (l + r) >> 1;
      if(idx <= mid)
        update(node << 1, idx, val, l, mid);
      else
        update((node << 1) + 1, idx, val, mid + 1, r);

      seg[node] = min(seg[node << 1], seg[(node << 1) + 1]);
    }

    int query(int node, int L, int R, int l, int r)
    {
      if(R < l || r < L) return INT_MAX;
      if(L <= l && r <= R) return seg[node];

      int mid = (l + r) >> 1;
      return min(query(node << 1, L, R, l, mid), 
                 query((node << 1) + 1, L, R, mid + 1, r));
    }
};
////////////////////////////////////

////////////////////////////////////
// Lazy updates
// Point update + Range update
// Point query + Range query
struct dt
{
  // Use required attributes
  int mn;

  // Paramatric Values
  dt(int x = -INF) : mn(x) {};
};

template<typename T>
class SegTree
{
  // rename correctly your [input arr]
  // seg arr is 1 - based
  // {l, r}: be the 0 - based transition range of [input arr]
  // {L, R}: be the 0 - based fixed query range of [input arr]
  // idx: 0 - based index of [input arr]
  // node: 1 - based index of segment tree node in [seg arr]
  public:
    int N;
    vector<dt> seg;
    vector<T> Lazy;
    vector<bool> isLazy;
    bool beingLazy;

  public:
    SegTree(int N, bool beingLazy = 0)
    {
      this->N = N;
      this->beingLazy = beingLazy;

      seg.resize((N << 2) + 5);
      if(beingLazy) 
      {
        Lazy.assign((N << 2) + 5, 0);
        isLazy.assign((N << 2) + 5, 0);
      }
    }

    // Write reqd merge functions
    dt merge(dt &l, dt &r)
    {
      return dt(min(l.mn, r.mn));
    }

    // Handle lazy propagation appriopriately
    void propagate(int node)
    {
      seg[node << 1] = seg[(node << 1) + 1] = Lazy[node];
      Lazy[node << 1] = Lazy[(node << 1) + 1] = Lazy[node]; 
      isLazy[node << 1] = isLazy[(node << 1) + 1] = 1;
      isLazy[node] = 0;
    }

    void build(int node, int l, int r)
    {
      if(l == r)
      {
        seg[node] = dt(arr[l]);   
        return;
      }

      int mid = (l + r) >> 1;
      build(node << 1, l, mid);
      build((node << 1) + 1, mid + 1, r);

      seg[node] = merge(seg[node << 1], seg[(node << 1) + 1]);
    }

    dt Pquery(int node, int idx, int l, int r)
    {
      if(l == r) 
        return seg[node];

      if(beingLazy && isLazy[node]) 
        propagate(node);

      int mid = (l + r) >> 1;
      if(idx <= mid) 
        return Pquery(node << 1, idx, l, mid);
      else 
        return Pquery((node << 1) + 1, idx, mid + 1, r);
    }

    dt Rquery(int node, int L, int R, int l, int r)
    {
      if(R < l || r < L) 
        return dt();

      if(L <= l && r <= R) 
        return seg[node];

      if(beingLazy && isLazy[node]) 
        propagate(node);

      int mid = (l + r) >> 1;
      dt left = Rquery(node << 1, L, R, l, mid);
      dt right = Rquery((node << 1) + 1, L, R, mid + 1, r);
      return merge(left, right);
    }

    void Pupdate(int node, int idx, T val, int l, int r) 
    {
      if(l == r)
      {
        seg[node] = dt(arr[idx] = val);
        return;
      }

      if(beingLazy && isLazy[node]) 
        propagate(node);

      int mid = (l + r) >> 1;
      if(idx <= mid)
        Pupdate(node << 1, idx, val, l, mid);
      else
        Pupdate((node << 1) + 1, idx, val, mid + 1, r);

      seg[node] = merge(seg[node << 1], seg[(node << 1) + 1]);
    }

    void Rupdate(int node, int L, int R, T val, int l, int r)
    {
      if(R < l || r < L) 
        return;

      if(L <= l && r <= R) 
      {
        seg[node] = dt(Lazy[node] = val);
        isLazy[node] = 1;
        return;
      }

      if(beingLazy && isLazy[node]) 
        propagate(node);

      int mid = (l + r) >> 1;
      Rupdate(node << 1, L, R, val, l, mid);
      Rupdate((node << 1) + 1, L, R, val, mid + 1, r);
    }
};
////////////////////////////////////