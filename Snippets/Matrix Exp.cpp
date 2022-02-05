#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
 
vector<vector<ll>> MatrixMul(const vector<vector<ll>> &A, const vector<vector<ll>> &B){
  vector<vector<ll>> ans = {{0, 0}, {0, 0}};
  ans[0][0] = (A[0][0] * B[0][0] % mod + A[0][1] * B[1][0] % mod) % mod;
  ans[0][1] = (A[0][0] * B[0][1] % mod + A[0][1] * B[1][1] % mod) % mod;
  ans[1][0] = (A[1][0] * B[0][0] % mod + A[1][1] * B[1][0] % mod) % mod;
  ans[1][1] = (A[1][0] * B[0][1] % mod + A[1][1] * B[1][1] % mod) % mod;
  return ans;
}
 
ll func(ll fib0, ll fib1, ll n){
  vector<vector<ll>> ans = {{1, 0}, {0, 1}}, p = {{1, 1}, {1, 0}};
  while (n){
      if (n & 1)
          ans = MatrixMul(ans, p);

      p = MatrixMul(p, p);
      n >>= 1;
  }
  return (fib1 * ans[0][0] % mod + fib0 * ans[0][1] % mod) % mod;
}
 
int main(){
  ll t;cin>>t;
  while(t--){
      ll n;cin>>n;
      ll ans=func(1,2,--n);
      cout<<ans<<endl;
      
  }
}