// 数组方式
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int A[N],C[N];
int b, la, lc;

void div(int A[], int b, int C[]){
  long long r = 0;
  for(int i=la-1; ~i; i--){
    r = r*10 + A[i]; //被除数
    C[la-1-i] = r/b; //存商
    r %= b;          //余数
  }
  reverse(C, C+lc);
  while(lc && C[lc]==0) lc--; //处理多余0
}
int main(){        
  string a; 
  cin >> a >> b;
  lc=la=a.size();
  for(int i=la-1; ~i; i--) A[la-1-i]=a[i]-'0';
  div(A, b, C);
  for(int i=lc; ~i; i--) printf("%d",C[i]);  
  return 0;
}

// 动态数组方式
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
VI A, C; int b;

void div(VI &A, int b, VI &C){
  long long r = 0;
  for(int i=A.size()-1; ~i; i--){
    r = r*10 + A[i];  //被除数
    C.push_back(r/b); //存商
    r %= b;           //余数
  }
  reverse(C.begin(), C.end());
  while(C.size()>1&&!C.back()) C.pop_back();//处理多余0
}
int main(){        
  string a; 
  cin >> a >> b;
  for(int i=a.size()-1;~i;i--) A.push_back(a[i]-'0');
  div(A, b, C);
  for(int i=C.size()-1;~i;i--) cout << C[i];
  return 0;
}