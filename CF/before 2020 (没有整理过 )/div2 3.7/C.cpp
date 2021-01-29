#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int max_n=1e6+5;
char s[max_n];
int main()
{
	int t1,t2;
	int n;
	int i;
	scanf("%d",&n);
	scanf("%s",s);
	t1=t2=0;
	for(i=0;i<n;i++){
		if(s[i]=='(') t1++;
		else t2++;
	}
	if(t1!=t2) printf("-1\n");
	else{
		int flag=0;
		int start;
		int cnt=0;
		t1=0;
		for(i=0;i<n;i++){
			if(s[i]=='('){
				t1++;
				if(t1==0&&flag){
					flag=0;
					cnt+=i-start+1;
				}
			}else{
				t1--;
				if(t1<0){
					if(flag==0){
						flag=1;
						start=i;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}