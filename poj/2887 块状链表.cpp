/*
link: http://poj.org/problem?id=2887
tags: 块状链表模板，块状链表就是块状链表，没啥好说的呜呜呜
      就是太难写了
*/
#include<iostream>
#include<cstring>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
const int sqn=1e3;
struct node{
	node* nxt;
	char s[(sqn<<1)+5];
	int siz;

	void ins(char ch,int pos){
		for(int i=siz;i>pos;i--){
			s[i]=s[i-1];
		}
		s[pos]=ch;
		siz++;
		if(siz==(sqn<<1)){
			split();
		}
		return ;
	}

	void split(){
		node* p=(node *)malloc(sizeof(node));
		p->init();
		p->nxt=nxt;
		nxt=p;
		for(int i=sqn;i<(sqn<<1);i++){
			p->s[(p->siz)++]=s[i];
		}
		siz=sqn;
		return ;
	}

	inline void init(){
		siz=0;
		nxt=NULL;
		return ;
	}
}*head;
char s[max_n];
void init(int n)
{
	head=(node *)malloc(sizeof(node));
	node* p=head;
	p->init();
	int siz=0;
	for(int i=0;i<n;i++){
		(p->s[siz++])=s[i];
		if((siz==sqn)){
			p->siz=siz;
			if(i==n-1) break;
			siz=0;
			node* q=(node *)malloc(sizeof(node));
			q->init();
			p->nxt=q;
			p=q;
		}
	}
	p->siz=siz;
	return ;
}
void insert(char ch,int pos)
{
	node *p=head;
	while(p->nxt!=NULL&&pos>p->siz){
		pos-=p->siz;
		p=p->nxt;
	}
	if(p->nxt==NULL&&pos>p->siz) pos=p->siz+1;
	pos-=1;
	p->ins(ch,pos);
	return ;
}
char find(int pos)
{
	node *p=head;
	while(p->nxt!=NULL&&pos>p->siz){
		pos-=p->siz;
		p=p->nxt;
	}
	if(p->nxt==NULL&&pos>p->siz) pos=p->siz;
	pos-=1;
	return p->s[pos];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>s;
	int n;
	cin>>n;
	init(strlen(s));
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='I'){
			char c;
			int p;
			cin>>c>>p;
			insert(c,p);
		}else{
			int p;
			cin>>p;
			cout<<find(p)<<endl;
		}
	}
	return 0;
}