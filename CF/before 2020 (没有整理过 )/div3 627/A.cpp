#include<cstdio>
#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[5050] = {0};
		
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
			
		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
				if(a[i] == a[j] && j - i > 1)
				{
					flag = 0;
				}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}