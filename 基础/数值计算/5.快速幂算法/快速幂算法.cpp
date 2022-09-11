#include <iostream>
using namespace std;

typedef long long LL;
int a, b, p;

int quickpow(LL a, int n, int p){
  int res = 1;
  while(n){
    if(n & 1) res = res*a %p;
    a = a*a %p;
    n >>= 1; 
  }
  return res;
}
int main(){
  cin >> a >> b >> p;
  int s = quickpow(a, b, p);
  printf("%d^%d mod %d=%d\n",a,b,p,s);
  return 0;
}