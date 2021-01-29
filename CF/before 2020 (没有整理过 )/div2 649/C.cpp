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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n;
	int flag=1;
	for(i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]>i) flag=0;
	}
	if(flag){
		int cnt=0;
		vector<int>ans;
		queue<int>q;
		for(i=1;i<=n;i++){
			if(cnt+1==num[i]){
				ans.push_back(cnt);
				cnt++;
			}else{
				if(cnt==num[i]){
					ans.push_back(max_n);
					q.push(i-1);
				}else{
					ans.push_back(cnt);
					cnt++;
					while(cnt<num[i]){
						if(q.empty()){
							cout<<-1<<endl;
							exit(1);
						}
						ans[q.front()]=cnt;
						q.pop();
						cnt++;
					}

				}
			}
		}
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}

	return 0;
}