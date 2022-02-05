struct node_t 
{
  int val;                // store more info if required
  
  node_t() { val = 0; }   // identity element
  node_t(ll v) { val = v; }
  void merge(node_t &L, node_t &R) { val = gcd(L.val, R.val); }
};

template<typename T>
class SparseTable 
{
  public:        
    int n;
    int k;      // MaxLog 
    int *log;
    int **st;   

  public:
    SparseTable(int n, vector<int> &v) 
    {
      this -> n = n;
      k = log2(n);
      st = new T*[n];
      log = new int[n + 1];

      log[1] = 0;
      for(int i = 2; i <= n; i++) 
        log[i] = log[i >> 1] + 1;
      for(int i = 0; i < n; i++) 
        st[i] = new T[k + 1]();

      build(v);
    }

    void build(vector<int> &v) 
    {
      for(int i = 0; i < n; i++) 
        st[i][0] = node_t(v[i]);
      for(int j = 1; j <= k; j++) 
        for(int i = 0; (i + (1 << j)) <= n; i++) 
          st[i][j].merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    T queryNormal(int L, int R) 
    {
      T res(); 
      for(int j = log[R - L + 1]; j >= 0; j--) 
        if((1 << j) <= R - L + 1) 
        {
          res.merge(res, st[L][j]);
          L += (1 << j);
        }

      return res;
    }

    T queryIdempotent(int L, int R)  
    {
      T res();
      int j = log[R - L + 1];
      res.merge(st[L][j], st[R - (1 << j) + 1][j]);

      return res;
    }
};