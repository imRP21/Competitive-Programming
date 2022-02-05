// PRIM'S ALGORITHM //
///////////////////////////////////////////
const int N = 1e5 + 5; // # Nodes + 5

// Adjacency List
vector<pii> g[N];
bool vis[N];

int PRIM_MST(int init)
{
  priority_queue<pii> pq;

  int res = 0;
  int cost, node;

  pq.push({-0, init});
  while(!pq.empty())
  {
    node = pq.top().ss;
    cost = -pq.top().ff;
    pq.pop();

    if(vis[node]) 
        continue;

    vis[node] = 1;
    res += cost;
    for(const pii& t: g[node])
      if(!vis[t.ff])
        pq.push({-t.ss, t.ff});
  }
  return res; 
}
///////////////////////////////////////////


// KRUSKALS'S ALGORITHM //
///////////////////////////////////////////
const int N = 1e5 + 5; // # Nodes + 5
const int M = 1e5 + 5; // # Edges + 5

// Edge List
pair<int, pii> g[M];

class DSU
{
  public:
    vector<int> par;
    vector<int> sz;

  public:
    DSU(int N)
    {
      par.assign(N);
      sz.assign(N, 1);

      for(int i = 1; i < N; i++) 
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

int KRUSKAL_MST(int m)
{
  DSU T(N);   

  int m; 
  int res = 0;
  int u, v;
  for(int i = 0; i < m; i++)
  {
    u = g[i].ss.ff;
    v = g[i].ss.ss;

    if(T.root(u) ^ T.root(v))
    {
      res += g[i].ff;
      T.unite(u, v);
    }
  }
  return res;
}
///////////////////////////////////////////