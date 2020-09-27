#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define eps 1e-8
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
#define MP(a, b) make_pair(a, b)
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
const int maxN = 1e5 + 7;
int N, M, T, head[maxN], cnt, ans, p[maxN];
struct Eddge
{
    int nex, to;
    Eddge(int a=-1, int b=0):nex(a), to(b) {}
}edge[maxN];
inline void addEddge(int u, int v)
{
    edge[cnt] = Eddge(head[u], v);
    head[u] = cnt++;
}
int tim[maxN] = {0};
vector<int> vt[maxN];
queue<pair<int, int>> Q;
pair<int, int> now;
inline void bfs()
{
    for(int i=head[T], v; ~i; i=edge[i].nex)
    {
        v = edge[i].to;
        tim[v]++;
        vt[v].push_back(v);
        Q.push(MP(v, v));
    }
    while(!Q.empty())
    {
        now = Q.front(); Q.pop();
        int u = now.first;
        for(int i=head[u], v; ~i; i=edge[i].nex)
        {
            v = edge[i].to;
            if(v == T) continue;
            if(tim[v] < 2)
            {
                if(!tim[v])
                {
                    tim[v]++;
                    vt[v].push_back(now.second);
                    Q.push(MP(v, now.second));
                }
                else if(tim[v] == 1)
                {
                    if(vt[v][0] == now.second) continue;
                    tim[v]++;
                    vt[v].push_back(now.second);
                    Q.push(MP(v, now.second));
                }
            }
        }
    }
}
inline void init()
{
    cnt = ans = 0;
    for(int i=0; i<=N; i++) head[i] = -1;
}
int main()
{
    scanf("%d%d%d", &N, &M, &T);
    init();
    for(int i=1, u, v; i<=M; i++)
    {
        scanf("%d%d", &u, &v);
        addEddge(v, u);
    }
    tim[T] = 1;
    bfs();
    for(int i=head[T], v; ~i; i=edge[i].nex)
    {
        v = edge[i].to;
        if(tim[v] < 2) p[++ans] = v;
    }
    sort(p + 1, p + ans + 1);
    printf("%d\n", ans);
    for(int i=1; i<=ans; i++) printf("%d\n", p[i]);
    return 0;
}
 