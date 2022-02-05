bool isPalindrom(string &s)
{
  int n = sz(s);
  for(int i = 0; i < (n >> 1); i++)
    if(s[i] ^ s[n - 1 - i])
      return 0;

  return 1;
}
