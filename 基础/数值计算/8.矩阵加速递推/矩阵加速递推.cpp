// 题目：斐波那契数列
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int mod = 1000000007;
struct matrix
{
    LL c[3][3];
    matrix() { memset(c, 0, sizeof c); }
} F, A; // F为斐波那契矩阵，A为构造矩阵

matrix operator*(matrix &a, matrix &b)
{             //矩阵乘法
    matrix t; //临时矩阵
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j)
            for (int k = 1; k <= 2; ++k)
                t.c[i][j] = (t.c[i][j] + a.c[i][k] * b.c[k][j]) % mod;
    return t;
}
void quickpow(LL n)
{ //快速幂
    F.c[1][1] = F.c[1][2] = 1;
    A.c[1][1] = A.c[1][2] = A.c[2][1] = 1;
    while (n)
    {
        if (n & 1)
            F = F * A;
        A = A * A;
        n >>= 1;
    }
}
int main()
{
    LL n;
    cin >> n;
    if (n <= 2)
    {
        puts("1");
        return 0;
    }
    quickpow(n - 2);
    cout << F.c[1][1];
    return 0;
}

// 题目：【模板】矩阵加速（数列）
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int mod = 1000000007;
struct matrix
{
    LL c[4][4];
    matrix() { memset(c, 0, sizeof c); }
} F, A; // F为斐波那契矩阵，A为构造矩阵

matrix operator*(matrix &a, matrix &b)
{             //矩阵乘法
    matrix t; //临时矩阵
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int k = 1; k <= 3; ++k)
            {
                t.c[i][j] += a.c[i][k] * b.c[k][j] % mod;
                t.c[i][j] %= mod;
            }
    return t;
}
void quickpow(LL n)
{ //快速幂
    F.c[1][1] = F.c[1][2] = F.c[1][3] = 1;
    memset(A.c, 0, sizeof(A.c));
    A.c[1][1] = A.c[1][2] = A.c[2][3] = A.c[3][1] = 1;
    while (n)
    {
        if (n & 1)
            F = F * A;
        A = A * A;
        n >>= 1;
    }
}
int main()
{
    LL T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 3)
        {
            puts("1");
            continue;
        }
        quickpow(n - 3);
        cout << F.c[1][1] << endl;
    }
    return 0;
}