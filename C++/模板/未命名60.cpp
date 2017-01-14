#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <list>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;
const int NN=100100;
//int l[NN<<2],r[NN<<2],w[NN<<2]; 
int N,M,T;
long long TT[100100];
int V[100001];
struct TTT{
	int v,w,next;
}edge[200200];
int le[100001],ri[100001],vi[100001];
int m;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0' && ch<='9')){ch=getchar();if(ch=='-') f=-1;}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void adde(int a,int b)
{
	TTT &e=edge[m];
	e.v=b;
	e.next=V[a];
	V[a]=m++;
}

bool ed[100010];
int tot;
void DFS(int x){
	if(ed[x])return ;
	ed[x]=1;
	le[x]=tot;
	int u,v,y=x;
	for(int i=V[x];~i;i=edge[i].next){
		v=edge[i].v;
		tot++;
		DFS(v);
	}
	ri[x]=tot;
}

int sum(int x)
{
    int ret = 0;
    while(x>0){
        ret+=TT[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d){
    while(x<=N){
        TT[x]+=d;
        x+=lowbit(x);
    }
}

int main()
{
	while(~scanf("%d",&N)){
		memset(V,-1,sizeof(V));
		m=0;tot=1;
		memset(ed,0,sizeof(ed));
		memset(TT,0,sizeof(TT));
		memset(vi,0,sizeof(vi));
		
		int a,b;	
		for(int i=1;i<N;i++){
			scanf("%d%d",&a,&b);
			adde(a,b);
		}
		
		DFS(1);
		
		for(int i = 1; i<=N; i++){
            vi[i] = 1;
            add(i,1);
        }
		
		cin>>M;
		char P;
		for(int i=1;i<=M;i++){
			scanf("%s%d",&P,&a);
			if(P=='Q'){
                printf("%d\n",sum(ri[a])-sum(le[a]-1));
            }
            else{
                if(vi[a])
                    add(le[a],-1);
                else
                    add(le[a],1);
                vi[a]=!vi[a];
            }	
		}		
	}
		
	return 0;
}

/*

3
1 2
1 3
3
Q 1
C 2
Q 1

*/