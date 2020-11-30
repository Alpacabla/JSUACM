#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
typedef long long int ll;
ll pri[max_n];
bool vis[max_n];
int tot;
void init(const int n)
{
    for(int i=2;i<=n;i++){
        if(!vis[i]) pri[tot++]=1ll*i;
        for(int j=0;j<tot&&pri[j]*i<=n;j++){
            vis[pri[j]*i]=true;
            if(i%pri[j]==0) break;
        }
    }
    return ;
}
int main()
{
    init((int)1e5);
    int t;
    cin>>t;
    while(t--){
        ll num;
        cin>>num;
        vector<ll> ans(0);
        int len=-1;
        int k=-1;
        for(int i=0;i<tot&&pri[i]<=num;i++){
            if(num%pri[i]==0){
                ll temp=num;
                int cnt=0;
                while(temp&&(temp%pri[i])==0){
                    cnt++;
                    temp/=pri[i];
                }
                if(len<cnt){
                    k=i;
                    len=cnt;
                }
            }
        }
        if(len<=1){
            ans.push_back(num);
        }else{
            for(int i=0;i<len-1;i++){
                ans.push_back(pri[k]);
                num/=pri[k];
            }
            ans.push_back(num);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
