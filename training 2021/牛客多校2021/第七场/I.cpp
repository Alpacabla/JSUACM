#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const double esp = 1e-7;
signed main()
{
    int x,s;
    cin>>x>>s;
    if(x>s)cout<<0<<endl;
    else
    {
        int cnt=0,f=0;
        for(int i=0;i<=30;i++) {
            if(((x>>i)&1)&&((s>>i)&1))cnt++;
            else if(((x>>i)&1)&&!((s>>i)&1)){
                f=1;
            }
        }
        if(f==1)cout<<0<<endl;
        else
        cout<<(int)pow(2,cnt)-1<<endl;
    }
}
