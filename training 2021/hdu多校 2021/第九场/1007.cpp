/*
link: 
tags: 
*/
#include<cstdio>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int max_n=1e7+10;
bool sta[max_n];
int p[max_n];
struct node{
	int last,next,val;
}li[max_n];
int tot=2;
int main()
{
	int n;
	scanf("%d",&n);
	int now=1;

	int head=1;
	int end=2;

	li[head].next=end;
	li[end].last=head;

	int mid;
	int siz=0;
	char opt[2];
	while(n--){
		scanf("%s",opt);
		if(opt[0]=='L'){
			int ind=++tot;
			li[ind].next=li[head].next;
			li[ind].last=head;
			li[ind].val=now;
			li[li[head].next].last=ind;
			li[head].next=ind;
			
			p[now]=ind;

			//li.emplace_front(now);
			//p[now]=li.begin();
			sta[now]=0;
			if(siz==0){
				mid=ind;
				//mid=li.begin();
			}else{
				if(siz%2==0){
					sta[li[mid].val]=1;
					//sta[*mid]=1;
					//mid--;
					mid=li[mid].last;
				}
			}
			siz++;
			now++;
		}
		if(opt[0]=='R'){
			int ind=++tot;
			li[ind].next=end;
			li[ind].last=li[end].last;
			li[ind].val=now;
			li[li[end].last].next=ind;
			li[end].last=ind;
			p[now]=ind;
			//li.emplace_back(now);
			//p[now]=prev(li.end());
			sta[now]=1;
			if(siz==0){
				mid=ind;
				//mid=li.begin();
			}else{
				if(siz%2==1){
					sta[li[mid].val]=0;
					//sta[*mid]=0;
					mid=li[mid].next;
				}
			}
			siz++;
			now++;
		}
		if(opt[0]=='Q'){
			printf("%d\n",li[mid].val);
		}
		if(opt[0]=='G'){
			int k;
			scanf("%d",&k);
			if(li[p[k]].val==li[mid].val){
				if(siz%2==0){
					mid=li[mid].last;
					//mid--;
				}else{
					mid=li[mid].next;
					//mid++;
				}
			}else{
				if(sta[li[p[k]].val]){
					if(siz%2==0){
						// sta[*mid]=1;
						// mid--;
						sta[li[mid].val]=1;
						//sta[*mid]=1;
						//mid--;
						mid=li[mid].last;
					}
				}else{
					if(siz%2==1){
						sta[li[mid].val]=0;
						//sta[*mid]=0;
						mid=li[mid].next;
					}
				}
			}
			li[li[p[k]].last].next=li[p[k]].next;
			li[li[p[k]].next].last=li[p[k]].last;
			//li.erase(p[k]);
			siz--;
		}
	}
	return 0;
}