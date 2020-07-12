/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2020-07-12
File: B.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

const int maxn = 1000005;
int dp[maxn][4], a[maxn], n, T;

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scd(n);
        for(int i = 1; i <= n; ++ i) scd(a[i]);
        for(int i = 1; i <= n; ++ i)
            for(int j = 0; j < 4; ++ j)
                dp[i][j] = 1e9 + 7;
        for(int i = 0; i < 4; ++ i) dp[1][i] = 0;
        for(int i = 2; i <= n; ++ i)
            for(int j = 0; j < 4; ++ j)
                for(int k = 0; k < 4; ++ k)
                {
                    if(a[i] == a[i - 1])
                    {
                        if(j == k) dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                    }
                    if(a[i] > a[i - 1])
                    {
                        if(j > k) dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                    }
                    if(a[i] < a[i - 1])
                    {
                        if(j < k) dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                    }
                }
        int ans = 1e9 + 7;
        for(int i = 0; i < 4; ++ i)
            ans = min(ans, dp[n][i]);
        prcas; printf("%d\n", ans);
    }
    return 0;
}
