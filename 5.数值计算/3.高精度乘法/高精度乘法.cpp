// 数组方法
#include <iostream>
using namespace std;

const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;

void mul(int A[],int B[],int C[]){
  for(int i=0; i<la; i++)
    for(int j=0; j<lb; j++){
      C[i+j] += A[i]*B[j];   //累加乘积
      C[i+j+1] += C[i+j]/10; //进位
      C[i+j] %= 10;          //存余
    }
  while(lc && C[lc]==0) lc--; //处理前导0 
}
int main(){
  string a,b;
  cin >> a >> b;
  la=a.size(); lb=b.size(); lc=la+lb;
  for(int i=la-1; ~i; i--) A[la-1-i]=a[i]-'0';
  for(int i=lb-1; ~i; i--) B[lb-1-i]=b[i]-'0';
  mul(A,B,C);
  for(int i=lc; ~i; i--) cout << C[i];
}


// 动态数组
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
VI A,B;

void mul(VI &A, VI &B, VI &C){
  for(int i=0; i<A.size(); i++)
    for(int j=0; j<B.size(); j++){
      C[i+j] += A[i]*B[j];   //累加乘积
      C[i+j+1] += C[i+j]/10; //进位
      C[i+j] %= 10;          //存余      
    }
  while(C.size()>1&&!C.back()) C.pop_back();//处理前导0 
}
int main(){
  string a, b;
  cin >> a >> b;
  for(int i=a.size()-1;~i;i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1;~i;i--) B.push_back(b[i]-'0');
  VI C(A.size()+B.size());
  mul(A, B, C);
  for(int i=C.size()-1; ~i; i --) cout << C[i];
  return 0;
}