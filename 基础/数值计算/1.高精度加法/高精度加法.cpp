// 普通数组

#include <iostream>
using namespace std;

const int N = 100005;
int A[N],B[N],C[N];
int la,lb,lc;

void add(int A[],int B[],int C[]){
  for(int i=0;i<lc;i++){
    C[i] += A[i]+B[i]; //累加
    C[i+1] += C[i]/10; //进位
    C[i] %= 10;        //存余
  }
  if(C[lc]) lc++; //处理最高位
}
int main(){
  string a, b;
  cin >> a >> b;
  la=a.size(),lb=b.size(),lc=max(la,lb);
  for(int i=la-1; ~i; i--) A[la-1-i]=a[i]-'0';
  for(int i=lb-1; ~i; i--) B[lb-1-i]=b[i]-'0';
  add(A,B,C);
  for(int i=lc-1; ~i; i--) printf("%d",C[i]);
  return 0;
}

// 动态数组
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
VI A, B, C;

void add(VI &A,VI &B,VI &C){
  int t=0;
  for(int i=0; i<A.size()||i<B.size(); i++){
    if(i<A.size()) t += A[i];
    if(i<B.size()) t += B[i];
    C.push_back(t%10); //存余
    t /= 10;           //进位
  }
  if(t) C.push_back(t);
}
int main(){
  string a, b;
  cin >> a >> b;
  for(int i=a.size()-1; ~i; i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1; ~i; i--) B.push_back(b[i]-'0');
  add(A,B,C);
  for(int i=C.size()-1; ~i; i--) printf("%d", C[i]);
  return 0;
}