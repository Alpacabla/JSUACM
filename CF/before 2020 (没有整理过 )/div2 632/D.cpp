#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
int ans[3005][1600],cnt1[3005];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	string s;
	int n,k;
	cin>>n>>k;
	cin>>s;
	int sum=0;
	int flag=1;
	int lim=n-1;
	for(i=0;flag;i++){
		flag=0;
		j=0;
		while(j<lim){
			if(s[j]=='R'&&s[j+1]=='L'){
				ans[i][cnt1[i]++]=j+1;
				s[j++]='L';
				s[j++]='R';
				flag=1;
			}else j+=1;
		}
		sum+=cnt1[i];
	}
	i-=1;
	//cout<<sum<<" "<<i<<endl;
	if(k<i||k>sum){
		cout<<-1<<endl;
	}else{
		int max1=i;
		i=0,j=0;
		while(k>max1){
			printf("1 %d\n",ans[i][j]);
			j++;
			if(j>=cnt1[i]){
				i++;
				j=0;
				max1--;
			}
			k--;
		}
		if(j!=0){
			printf("%d",cnt1[i]-j);
			while(j<cnt1[i]){
				printf(" %d",ans[i][j]);
				j++;
			}
			putchar(10);
			i++;
			k--;
		}
		for(int l=1;l<=k;l++){
			printf("%d",cnt1[i]);
			for(j=0;j<cnt1[i];j++){
				printf(" %d",ans[i][j]);
			}
			i++;
			putchar(10);
		}
	}
	return 0;
}