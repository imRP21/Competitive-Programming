////////////////////////
// ALMOST LINEAR SIEVE(N * loglogN)

const int M = 1e6 + 5;
bool sieve[M];

int limit = sqrt(M) + 5;
sieve[1] = 1;
for(int i = 2; i < limit; i++)
  if(!sieve[i])
    for(int j = i * i; j < N; j += i)
      sieve[j] = 1;

////////////////////////

////////////////////////
// LINEAR SIEVE 
// N is (MAX + 5), as always.
// Make sure to use correct n (mostly N) in the function parameter.

int lp[N];
vi primes;

void RunLinearSieve(int n) 
{
  for(int i = 2; i < n; i++) 
  {
    if(!lp[i]) 
      primes.pb(lp[i] = i);
    for(int &x: primes) 
    {
      if(x > lp[i] || i * x >= n) break;
      lp[i * x] = x;
    }
  }
}
////////////////////////