#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool v[30000010];
int pr[30000010],t,x;
int main()
{
    int m=0;v[1]=1;
    for(int i=2; i<=30000000; i++)
    {
        if(v[i]==0)
        {
            pr[++m]=i;
        }
        for(int j=1; j<=m; j++)
        {
            if(i*pr[j]>30000000)
                break;
            v[i*pr[j]]=1;
            if(i%pr[j]==0)
                break;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x==0){
        	cout<<3<<endl;
        	continue;
        }
        if(x<0)
        {
            int tmp=1-x;
            while(v[tmp]){
                tmp++;
            }
           	int k=-x;
           	while(v[2*k+3]&&2*k+3<=2*tmp){
           		k++;
           	}
           	int res=2*tmp;
           	if(!v[2*k+3]){
           		res=min(res,2*k+3);
           	}
            cout<<res<<endl;
        }
        else
        {
            if(!v[x]){
            	cout<<1<<endl;
            }else{
            	if(!v[x+x+1]||!v[x+x-1]){
            		cout<<2<<endl;
            	}else{
            		int tmp=x+1;
		            while(v[tmp]){
		                tmp++;
		            }
		           	int k=x;
		           	while(v[2*k+3]&&2*k+3<=2*tmp){
		           		k++;
		           	}
		           	int res=2*tmp;
		           	if(!v[2*k+3]){
		           		res=min(res,2*k+3);
		           	}
		            cout<<res<<endl;
            	}
            }
        }
    }
    return 0;
}