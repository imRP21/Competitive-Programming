ll pow_(ll x, ll n) 
{ 
  ll res = 1; 
  while(n)
  { 
    if(n & 1) res = (res * x); 
    x = (x * x); 
    n >>= 1; 
  } 
  return res; 
}