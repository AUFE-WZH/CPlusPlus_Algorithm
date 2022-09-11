// 数组方式
#include <iostream>
using namespace std;

const int N = 100005;
int A[N],B[N],C[N];
int la,lb,lc;

bool cmp(int A[],int B[]){
  if(la != lb) return la>lb;
  for(int i=la-1; ~i; i--)
    if(A[i]!=B[i]) return A[i]>B[i];
  return true; //避免结果为-0
}
void sub(int A[],int B[],int C[]){
  for(int i=0; i<lc; i++){
    if(A[i] < B[i]) 
      A[i+1]--, A[i]+=10; //借位
    C[i] = A[i]-B[i];     //存差
  }
  while(lc&&C[lc]==0) lc--; //处理前导0
}
int main(){
  string a, b;
  cin >> a >> b;
  la=a.size(),lb=b.size(),lc=max(la,lb);
  for(int i=la-1; ~i; i--) A[la-1-i]=a[i]-'0';
  for(int i=lb-1; ~i; i--) B[lb-1-i]=b[i]-'0';
  if(!cmp(A,B)) swap(A,B), cout<<'-';
  sub(A, B, C);
  for(int i=lc; ~i; i--) printf("%d",C[i]);
  return 0;
}

// 动态数组方式
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi A,B,C;
bool cmp(vi &A, vi &B){
  if(A.size() != B.size()) 
    return A.size()>B.size();
  for(int i = A.size()-1; ~i; i--)
    if(A[i]!=B[i]) return A[i]>B[i];
  return true; //避免结果-0
}
void sub(vi &A, vi &B, vi &C){
  int t = 0;
  for(int i = 0; i<A.size(); i ++){
    t = A[i];
    if(i<B.size()) t -= B[i];
    if(t<0) A[i+1]--, t+=10; //借位
    C.push_back(t);          //存差
  }
  while(C.size()>1&&!C.back())C.pop_back();//处理前导0
}
int main(){
  string a, b;
  cin >> a >> b;
  for(int i=a.size()-1;~i;i--) A.push_back(a[i]-'0');
  for(int i=b.size()-1;~i;i--) B.push_back(b[i]-'0');
  if(!cmp(A, B)) swap(A,B), cout << '-';
  sub(A, B, C);
  for(int i=C.size()-1; ~i; i--) cout << C[i];
}