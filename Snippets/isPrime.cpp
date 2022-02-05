bool isPrime(int n)
{
  if(n < 2) 
    return 0;
  if(n < 4) 
    return 1;
  if(n % 2 == 0 || n % 3 == 0) 
    return 0;

  int t = sqrt(n);
  for(int i = 5; i <= t; i += 6)
    if(n % i == 0 || n % (i + 2) == 0) 
      return 0;

  return 1;
}