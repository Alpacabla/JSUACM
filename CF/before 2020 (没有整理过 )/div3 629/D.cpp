#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=2e5+5;
int num[max_n];
int ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	int n,i;
	cin>>q;
	while(q--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		num[n]=num[0];
		ans[0]=0;
		i=0;
		while(i<n&&num[i+1]!=num[i]){
			ans[i+1]=!ans[i];
			i++;
		}
		if(i==n&&ans[n]!=ans[0]){
			n-=1;
			cout<<"3"<<endl;
			for(i=0;i<n;i++){
				if(i%2) cout<<"1 ";
				else cout<<"2 ";
			}
			cout<<"3 "<<endl;
		}else{
			i=0;
			while(i<n&&num[i+1]==num[i]){
				i++;
			}
			if(i==n){
				cout<<"1"<<endl;
				for(i=0;i<n;i++){
					cout<<"1 ";
				}
				cout<<endl;
			}else{
				i=0;
				cout<<"2"<<endl;
				ans[0]=1;
				for(i=1;i<n;i++){
					if(num[i]!=num[i-1]){
						ans[i]=!ans[i-1];
					}else{
						ans[i]=ans[i-1];
					}
				}
				if(num[n-1]!=num[0]&&ans[n-1]==ans[0]){
					i=0;
					ans[0]=1;
					while(i<n-1&&num[i+1]!=num[i]){
						ans[i+1]=!ans[i];
						i++;
					}
					while(i<n-1&&num[i+1]==num[i]){
						ans[i+1]=ans[i];
						i++;
					}
					ans[i]=!ans[i-1];
					i++;
					while(i<n){
						if(num[i]!=num[i-1]){
							ans[i]=!ans[i-1];
						}else{
							ans[i]=ans[i-1];
						}
						i++;
					}
				}
				for(i=0;i<n;i++){
					if(ans[i]) cout<<"1 ";
					else cout<<"2 ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}