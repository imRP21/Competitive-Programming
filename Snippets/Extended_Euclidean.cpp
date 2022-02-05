class Extended_Euclidean 
{
  public:
    int x;
    int y;
    int GCD;

  public:
    // x * a + y * b = GCD;
    // Gcd(a, b) = Gcd(b, a % b);
    void Gcd(int a, int b)
    {
      if(b == 0) 
      {
        x = 1;
        y = 0;
        GCD = a;
        return;
      }
      Gcd(b, a % b);
      int tmp = x;
      x = y;
      y = tmp - y * (a / b);
    }

    int getGcd(int a, int b)
    {
      Gcd(a, b);
      return GCD;
    }

    int getInverse(int x, int m)
    {
      if(getGcd(x, m) ^ 1) return -1;
      return ((this -> x) + m) % m;   // x may be negative
    }
};


////////////// tourist nu.
template<typename T>
T inverse(T a, T MOD) 
{
  T m = MOD;
  T u = 0, v = 1;
  while(a)
  {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return (u + MOD) % MOD;
}