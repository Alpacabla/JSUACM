#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define IO std::ios::sync_with_stdio(false); cin.tie(0)
#define int long long
#define ull unsigned long long
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define INF 0x3f3f3f3f

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int maxn = 1e7 + 10;
int prime[maxn], mu[maxn], pcnt;
bool vis[maxn];
void init() {
  mu[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      prime[++pcnt] = i;
      mu[i] = -1;
    }
    for (int j = 1; i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else mu[i * prime[j]] = -mu[i];
    }
  }
  for(int i=2;i<=100;i++){
  	cout<<mu[i]<<endl;
  }
}
int n,k;
signed main() {
  IO;
  int t;
  init();
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> v;
    map<int, int> memo;
    int now = n;
    while (!memo[now]) {
      v.pb(now);
      memo[now] = 1;
      now = now + mu[now];
    }
    int j;
    for (int i = 0; i < SZ(v); i++) if (v[i] == now) { j = i; break; }
    vector<int> v1;
    for (int i = j; i < SZ(v); i++) v1.push_back(v[i]);
    if (k < v.size()) cout << v[k] << '\n';
    else cout << v1[(k - v.size()) % v1.size()] << '\n';
  }
  return 0;
}