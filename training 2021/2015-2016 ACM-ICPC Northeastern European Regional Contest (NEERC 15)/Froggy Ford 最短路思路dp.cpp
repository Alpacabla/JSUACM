#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+10;
typedef long long int ll;
#define int ll
#define esp 1e-8
struct node{
    int x,y;
    bool operator < (const node a) const {
        return x<a.x;
    }
}a[max_n];
double dp[max_n][2];
double dis(int u,int v)
{
    return sqrt((a[u].x-a[v].x)*(a[u].x-a[v].x)+(a[u].y-a[v].y)*(a[u].y-a[v].y));
}
double xx[max_n],yy[max_n];
#define mid(x,y) ((x+y)/2.0)
signed main()
{
	// freopen("froggy.in", "r", stdin);
 	// freopen("froggy.out", "w", stdout);
    int n;
    double m;
    scanf("%lf%lld",&m,&n);
    if(n==0){
        printf("%.8lf %.8lf\n",m/2.0,1.0);
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    double ans=1e17;
    for(int i=1;i<=n;i++){
    	dp[i][0]=a[i].x;
    	dp[i][1]=a[i].x/2.0;
    	xx[i]=mid(0,a[i].x);
        yy[i]=a[i].y;
    }
    struct edge{
    	int v,u;
    	double dis;
    	bool operator < (const node a) const {
    		return dis<a.dis;
    	}
    };
    for(int i=1;i<=n;i++){
    	for(int j=;j<=n;j++){

    	}
    }
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=a[i].x;
        dp[i][1]=a[i].x/2.0;
        xx[i]=mid(0,a[i].x);
        yy[i]=a[i].y;
        for(int j=1;j<i;j++){
            double res=0.0;
            res=max(dp[j][0],dis(i,j));
            dp[i][0]=min(dp[i][0],res);
            res=max(dp[j][1],dis(i,j));
            dp[i][1]=min(dp[i][1],res);
            if(dp[i][1]==res){
                xx[i]=xx[j];
                yy[i]=yy[j];
            }
            res=max(dp[j][0],dis(i,j)/2.0);
            dp[i][1]=min(dp[i][1],res);
            if(dp[i][1]==res){
                xx[i]=mid(a[i].x,a[j].x);
                yy[i]=mid(a[i].y,a[j].y);
            }
        }
    }
    double ans=1e17;
    double x1,y1;
    for(int i=1;i<=n;i++){
        ans=min(ans,max(dp[i][0],(m-a[i].x)/2.0));
        if(ans==max(dp[i][0],(m-a[i].x)/2.0)){
            x1=mid(m,a[i].x);
            y1=a[i].y;
        }
        ans=min(ans,max(dp[i][1],(m-a[i].x)));
        if(ans==max(dp[i][1],(m-a[i].x))){
            x1=xx[i];
            y1=yy[i];
        }
    }
    printf("%.8lf %.8lf\n",x1,y1);
    return 0;
}