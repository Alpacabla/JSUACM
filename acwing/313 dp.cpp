/*
link: https://www.acwing.com/problem/content/description/315/
tags: 简单dp，用个last记录路径
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int sta[105][105];
int dp[105][105],last[105][105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        sta[i][0]=-int_inf;
        for(int j=1;j<=m;j++){
            cin>>sta[i][j];
        }
    }
    memset(dp,-0x3f3f,sizeof(dp));
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            for(int k=0;k<j;k++){
                if(dp[i-1][k]+sta[i][j]>dp[i][j]){
                    dp[i][j]=dp[i-1][k]+sta[i][j];
                    last[i][j]=k;
                }
            }
        }
    }
    int ans=-int_inf,now;
    for(int i=1;i<=m;i++){
        if(dp[n][i]>ans){
            ans=dp[n][i];
            now=i;
        }
    }
    vector<int> path(n+1);
    for(int i=n;i>=1;i--){
        path[i]=now;
        now=last[i][now];
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<((i==1)?"":" ")<<path[i];
    }
    cout<<endl;
    return 0;
}