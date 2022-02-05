class DSU
{
  public:
    vector<int> par;
    vector<int> sz;

  public:
    DSU(int N)
    {
      N += 5;
      par.resize(N);
      sz.assign(N, 1);

      for(int i = 0; i < N; i++) 
        par[i] = i;
    }

    int root(int x)
    {
      while(par[x] ^ x)
        x = par[x];

      return x;
    }

    bool unite(int a, int b)
    {
      a = root(a);
      b = root(b);

      if(a == b) 
        return 0;
      
      if(sz[a] < sz[b]) 
        a ^= b ^= a ^= b;

      sz[a] += sz[b]; // Small to Large Merging
      par[b] = a;
      
      return 1;
    }
};