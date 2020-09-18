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
char s[15][15];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	int t;
	char ch;
	cin>>t;
	while(t--){
		for(i=0;i<9;i++){
			scanf("%s",s+i);
		}
		int l=0;
		for(i=0;i<9;i+=3,l++){
			int k=0;
			for(j=0;j<9;j+=3,k++){
				for(ch='1';ch<='9';ch++){
					if(s[i+k][j+l]!=ch){
						s[i+k][j+l]=ch;
						break;
					}
				}
			}
		}
		for(i=0;i<9;i++){
			printf("%s\n\n",s+i);
		}
	}
	return 0;
}