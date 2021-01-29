#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
char s[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	int i,j;
	int cnt=0;
	cin>>n>>m>>k;
	//不需要接收底下的数据，只要nm就可以直接出结果了
	for(i=0;i<n-1;i++){
		s[cnt++]='U';
	}
	for(i=0;i<m-1;i++){
		s[cnt++]='L';
	}//堆在角落其实只需要n+m-2步

	for(i=0;i<n;i++){
		for(j=0;j<m-1;j++){
			s[cnt++]=((i%2==0)?'R':'L');
		}
		if(i!=n-1) s[cnt++]='D';
	}//遍历
	s[cnt++]='\0';
	cout<<cnt-1<<endl<<s;
	return 0;
}