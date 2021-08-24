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
char ops[150];
bool check(string s)
{
	ops['L']='R';
	ops['R']='L';
	ops['U']='D';
	ops['D']='U';
	bool flag=false;
	for(int i=0;i<(int)s.size()-1&&!flag;i++){
		if(s[i]==s[i+1]){
			flag=true;
		}
	}
	if(s.size()>2&&ops[s[s.size()-1]]==s[s.size()-2]&&ops[s[s.size()-2]]==s[s.size()-3]) flag=true;
	return flag;
}
bool flag=false;
vector<int> x,y;
int rd[40];
mt19937 myrand(time(0));
int xx,yy;
void check2(string s)
{
	//x.push_back(0);
	//y.push_back(0);
	int tot=0;
	int lastx,lasty;
	lastx=lasty=0;
	for(int i=0;i<s.size();i++){
		if(i>=2&&s[i]=='D'&&s[i-1]=='U'&&s[i-2]=='D'){
			lastx=x[x.size()-1];
			lasty=y[x.size()-1]+1;
			continue;
		}
		if(i>=2&&s[i]=='U'&&s[i-1]=='D'&&s[i-2]=='U'){
			lastx=x[x.size()-1];
			lasty=y[x.size()-1]-1;
			continue;
		}
		if(i>=2&&s[i]=='L'&&s[i-1]=='R'&&s[i-2]=='L'){
			lastx=x[x.size()-1]+1;
			lasty=y[x.size()-1];
			continue;
		}
		if(i>=2&&s[i]=='R'&&s[i-1]=='L'&&s[i-2]=='R'){
			lastx=x[x.size()-1]-1;
			lasty=y[x.size()-1];
			continue;
		}
		if(s[i]=='D'){
			x.push_back(lastx);
			y.push_back(lasty-rd[i]);
			lasty=lasty-rd[i]+1;
		}
		if(s[i]=='U'){
			x.push_back(lastx);
			y.push_back(lasty+rd[i]);
			lasty=lasty+rd[i]-1;
		}
		if(s[i]=='L'){
			y.push_back(lasty);
			x.push_back(lastx-rd[i]);
			lastx=lastx-rd[i]+1;
		}
		if(s[i]=='R'){
			y.push_back(lasty);
			x.push_back(lastx+rd[i]);
			lastx=lastx+rd[i]-1;
		}
	}
	xx-=lastx;
	yy-=lasty;
	for(int i=0;i<(int)x.size()-1;i++){
		x[i]-=lastx;
		y[i]-=lasty;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	
	cin>>s;
	if(check(s)){
		cout<<"impossible"<<endl;
	}else{
		//for(int i=1;i<=1000;i++){
			int last=0;
			for(int j=0;j<40;j++){
				rd[j]=myrand()%(int)(1e4)+23+last;
				last=rd[j];
			}
			////
			//rd[]
		check2(s);
		//	if(flag){
		//		break;
		//	}
		//}
		cout<<xx<<" "<<yy<<endl;
		cout<<(int)x.size()-1<<endl;
		for(int i=0;i<(int)x.size()-1;i++){
			cout<<x[i]<<" "<<y[i]<<endl;
		}
	}
	
	return 0;
}