#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<iostream>
#include<cstdlib>
#define For(i,N) for(int i=1;i<=N;i++)
#define Rep(i,N) for(int i=0;i<N;i++)
#define INF 0x3f3f3f3f
using namespace std;

int N,M,T;

int V[100011];
struct Edge{
	int v,w,next;
}edge[100001];
int m=0;

void adde(int v,int u,int w)
{
	Edge &e=edge[m];
	e.v=v;
	e.w=w;
	e.next=V[u];
	V[u]=m++;
}

int L[10001],R[10001],sum[10001];

void pushup(int x)
{
	int xx=x<<1;
	sum[x]=sum[xx]+sum[xx|1];
} 

void Build(int l,int r,int x)
{
	if(l==r)
	{
		scanf("%d",&sum[x]);
		return ;
	}
	
	int xx=x<<1,mid=(l+r)>>1;
	Build(l,mid,xx);
	Build(mid+1,r,xx|1);
	pushup(x);
}

int sum=0;
void Ask(int L,int R,int l,int r,int x)
{
	if(r<L||l>R)return ;
	if(l<=L&&r>=R)
	{
		ans+=sum[x];
		return ;
	}
	//pushdown(x);
	int xx=x<<1,mid=(l+r)>>1;	
	Ask(L,R,l,mid,xx);
	Ask(L,R,mid+1,r,xx|1);
	//pushup(x);	
}


int prim(int st)
{
	bool vis[100001];
	int low[10001];
	memset(low,127,sizeof(int)*(N+2));
	int u=st;
	for(int i=V[st];~i;i=edge[i].next){
		int v=edge[i].v;
		low[v]=edge[i].w;
	}
	
	low[st]=0;
	vis[st]=1;
	int ans=0;
	
	For(k,N-1)
	{
		int j;
		int MAX=INF;
		for(int i=1;i<=N;i++)
		{
			if(!vis[i] && MAX>low[i])
			{
				MAX=low[i];
				j=i;
			}
		}
		
		ans+=MAX;
		vis[j]=1;
		
		int v,w;
		for(int i=V[j];~i;i=edge[i].next)
		{
			v=edge[i].v;
			w=edge[i].w;
			if(vis[v]==0 && low[v]>w)
			{
				low[v]=w;
			}		
		}
	}
	 cout<<ans<<endl;
	return 0; 
}

queue<int>QQ;
int SPFA(int st)
{
	
	bool ed[10001];
	ed[st]=1;
	int dis[10001];
	For(i,N)dis[i]=INF;
	dis[st]=0;
	
	int v,u,w;
	while(!QQ.empty())
	{
		u=QQ.front();
		QQ.pop();
		for(int i=V[u];~i;i=edge[i].next){
			v=edge[i].v;
			w=edge[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!ed[v]){
					QQ.push(v);
					ed[v]=1;
				} 
			}
			
		}
		
	}
	
	return dis[N];
} 

int P[10001];
int Find(int x)
{
	if(P[x]==x)return x;
	int f=Find(P[x]);
	P[x]=f;
	return P[x];
}
void Uniun(int a,int b)
{
	int x=Find(a);
	int y=Find(b);
	if(x==y);
	else P[x]=y;	
}

int S[12001]={0,1,3,4,54,554,656,746,756,767,867,834,1443};
int Search(int x)
{
	int p=1,q=12;
	int mid=(p+q)>>1;
	while(p<=q)
	{
		mid=(p+q)>>1;
		if(S[mid]==x)return mid;
		if(S[mid]<x)p=mid+1;
		else q=mid-1; 
	}
	return -1;
}



int main()
{
	memset(V,-1,sizeof(V));
	
	cout<<Search(756);
	
/*
	cin>>N>>M;
	int a,b,c;
	For(i,M)
	{
		scanf("%d%d%d",&a,&b,&c);
		adde(a,b,c);
		adde(b,a,c);	
	}
	prim(1); 
	*/
	
	return 0;
}

/*

3 3
1 2 3
2 3 4
3 2 1




int prim()
{
    int i,j,pos,min,result=0;
    memset(visited,0,sizeof(visited));
//从某点开始，分别标记和记录该点
    visited[1]=1;pos=1;
//第一次给low数组赋值
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];
//再运行n-1次
    for(i=1;i<n;i++)
    {
//找出最小权值并记录位置
     min=MaxInt;
     for(j=1;j<=n;j++)
         if(visited[j]==0&&min>low[j])
         {
             min=low[j];pos=j;
         }
//最小权值累加
    result+=min;
//标记该点
    visited[pos]=1;
//更新权值
    for(j=1;j<=n;j++)
        if(visited[j]==0&&low[j]>map[pos][j])
            low[j]=map[pos][j];
    }
    return result;
}



*/