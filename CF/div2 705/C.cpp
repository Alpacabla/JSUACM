/*
link: 
tags: 
*/
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
string ss;
void solve(vector<int> &cnt,int m,int mid,string &a)
{
	vector<char> dc;
	vector<int> d;
	int sum=0;
	for(int i='a';i<='z';i++){
		if(cnt[i]%m!=0){
			dc.push_back(char(i));
			d.push_back(m-(cnt[i]%m));
			sum+=m-(cnt[i]%m);
		}
	}
	int res=a.size()-mid-1;
	int count=0;
	for(int i=mid+1;i<a.size()-sum;i++){
		a[i]='a';
	}
	int now=0;
	for(int i=a.size()-sum;i<a.size();i++){
		if(d[now]==0){
			now++;
		}
		d[now]--;
		a[i]=dc[now];
	}
	//cout<<dc.size()<<endl;
	//ss=a;
	return ;
}
// bool judge(int mid,string a,int m)
// {
// 	vector<int> cnt(28);
// 	for(int i=0;i<mid;i++){
// 		cnt[a[i]-'a']++;
// 	}
// 	for(int i=a[mid]+1;i<='z';i++){
// 		cnt[i-'a']++;
// 		if(solve(cnt,m,mid,a)){
// 			a[mid]=i;
// 			ss=a;
// 			return true;
// 		}
// 		cnt[i-'a']--;
// 	}

// 	return false;
// }
bool isok(vector<int> &cnt,int m,int mid,string &a)
{
	//vector<char> dc;
	//vector<int> d;
	int sum=0;
	for(int i='a';i<='z';i++){
		if(cnt[i]%m!=0){
			//dc.push_back(char(i));
			sum+=m-(cnt[i]%m);
			//d.push_back(m-(cnt[i-'a']%m));
		}
	}
	int res=a.size()-mid-1;
	//cout<<sum<<endl;
	//int sum=0;
	// for(int i=0;i<d.size();i++){
	// 	sum+=d[i];
	// }
	if(sum>res||(a.size()-sum-(mid+1))%m!=0) return false;
	else return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;

		bool flag=true;
		if(n%m!=0) flag=false;
		if(flag){
			vector<int> a;
			vector<int> cnt(150);
			for(int i=0;i<s.size();i++){
				cnt[s[i]]++;
			}
			for(int i='a';i<='z'&&flag;i++){
				if(cnt[i]%m!=0) flag=false;
			}
			if(flag){
				//cout<<1<<endl;
				cout<<s<<endl;
				continue;
			}else flag=true;
			cnt.clear();
			cnt.resize(150);
			int last=-1;
			for(int i=0;i<s.size();i++){
				for(int j=s[i]+1;j<='z';j++){
					cnt[j]++;
					if(isok(cnt,m,i,s)){
						cnt[j]--;
						last=i;
						break;
					}
					cnt[j]--;
				}
				cnt[s[i]]++;
			}
			//cout<<last<<endl;
			if(last!=-1){
				cnt.clear();
				cnt.resize(150);
				for(int i=0;i<last;i++) cnt[s[i]]++;
				for(int j=s[last]+1;j<='z';j++){
					cnt[j]++;
					if(isok(cnt,m,last,s)){
						solve(cnt,m,last,s);
						s[last]=j;
						cnt[j]--;
						break;
					}
					cnt[j]--;
				}
				cout<<s<<endl;
			}else{
				flag=false;
			}
			// for(int i=0;i<s.size();i++){
			// 	if(s[i]!='z') a.push_back(i);
			// 	cnt[s[i]]++;
			// }
			// for(int i='a';i<='z'&&flag;i++){
			// 	if(cnt[i]%m!=0) flag=false;
			// }
			// if(flag){
			// 	cout<<s<<endl;
			// 	continue;
			// }else flag=true;
			// if(a.size()==0){
			// 	flag=false;
			// }else{
			// 	int l=0,r=a.size()-1;
			// 	string res;
			// 	while(l<=r){
			// 		int mid=(l+r)>>1;
			// 		if(judge(a[mid],s,m)){
			// 			l=mid+1;
			// 			res=ss;
			// 			//cout<<res<<endl;
			// 		}else{
			// 			r=mid-1;
			// 		}
			// 	}
			// 	if(res!=""){
			// 		flag=true;
			// 		cout<<res<<endl;
			// 	}
			// }
		}
		if(!flag) cout<<-1<<endl;
	}
	return 0;
}