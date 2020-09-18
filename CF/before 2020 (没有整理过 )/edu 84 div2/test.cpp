#include"stdio.h"
#include"string.h"
#include"stack"
#include"map"
#include"math.h"
#include"vector"
#include"queue"
#include"algorithm"
using namespace std;
#define OK printf("\n");
#define Debug printf("this_ok\n");
typedef long long ll;
#define scanll(a,b) scanf("%lld%lld",&a,&b);
#define scanl(a) scanf("%lld",&a);
#define printl(a,b) if(b == 0) printf("%lld ",a); else printf("%lld\n",a);
#define print_int(a,b) if(b == 0) printf("%d ",a); else printf("%d\n",a);
typedef pair<int,int> PII;
inline int read(){
    int s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9')   { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { s = (s << 3) + (s << 1) + (ch ^ 48); ch = getchar(); }
    return s * w;
}
const ll mod = 998244353;
const int N = 200100;
int n,m;
int a[N];
int str[N];int top;
int id[100];
ll dp[N];
int s[101]; int tot = 0;
ll dp1[N],dp2[N];
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % mod;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % mod;
    }
    return result;
}
void check(){
    int l = 1,r = tot;
    for(int i = l; i <= r; i ++){
        int cnt = 1;
        while(i + 1 <= r && s[i] == s[i + 1]) {
            cnt ++; i ++;
        }
        id[cnt] ++;
    }
}
int main()
{
    n = read(); ll limit = fastPower(10,n) - 1;
    for(int i = 0; i <= limit; i ++){
        int x = i;
        tot = 0;
        while(x) {
           s[++ tot] = x % 10;
           x /= 10;
        }
        while(tot < n) {
            s[++ tot] = 0;
        }
        int l = 1,r = tot;
        while(l < r){
            int t = s[l];s[l]  =s[r]; s[r] = t;
            l ++ ;r --;
        }
        check();
    }
    for(int i = 1; i <= top; i ++)
        printf("%d",str[i]);OK
    for(int i = 1; i <= n; i ++)
        printf("%d ",id[i]);OK
}
