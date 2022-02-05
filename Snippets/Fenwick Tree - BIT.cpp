////////////////////////////////////
// Point update & Range query
template<typename T>
class FenwickTree
{
  // 1 - based indexing
  // n is the idx of the max of element, not the size of vector bit
  int n;
  vector<T> bit;

  public:
    FenwickTree(int n)
    {
      this -> n = n;
      bit.assign(n + 1, 0);
    }

    FenwickTree(vector<T> &a) : FenwickTree(sz(a))
    {
      for(int i = 1; i <= n; i++) 
        update(i, a[i - 1]);
    }

    void update(int idx, int delta) 
    {
      while(idx <= n)
      {
        bit[idx] += delta;
        idx += (idx & -idx);
      }
    }

    T sum(int idx) 
    {
      T res = 0;
      while(idx > 0)
      {
        res += bit[idx];
        idx -= (idx & -idx); // same as idx &= (idx - 1)
      }
      return res;
    }

    T sum(int l, int r)
    {
      return sum(r) - sum(l - 1);
    }
};
////////////////////////////////////


////////////////////////////////////
// Range update & Point query
template<typename T>
class FenwickTree
{
  // 1 - based indexing
  // n is the idx of the max of element, not the size of vector bit
  int n;
  vector<T> bit;

  public:
    FenwickTree(int n)
    {
      this -> n = n;
      bit.assign(n + 1, 0);
    }

    FenwickTree(vector<T> &a) : FenwickTree(sz(a))
    {
      for(int i = 1; i <= n; i++) 
        update(i, a[i - 1]);
    }

    void update(int idx, int delta) 
    {
      while(idx <= n)
      {
        bit[idx] += delta;
        idx += (idx & -idx);
      }
    }

    void range_update(int l, int r, T delta)
    {
      update(l, +delta);
      update(r + 1, -delta);
    }

    // Point Query
    T sum(int idx) 
    {
      T res = 0;
      while(idx > 0)
      {
        res += bit[idx];
        idx -= (idx & -idx); // same as idx &= (idx - 1)
      }
      return res;
    }
};
////////////////////////////////////