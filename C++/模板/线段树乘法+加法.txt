#include<cstdio>
#include<cstring>
#include<iostream> 
#include<cstdlib>
#include<queue>
#include<stack>
#define For(i,N) for(int i=1;i<=N;i++)
#define Rep(i,N) for(int i=0;i<N;i++)
#define LL long long
using namespace std;

LL N,M;
const int MAXN=100001+20;

struct TT{
	int l,r,d;
	LL m,a,sum;
	TT(){
		sum=a=0;
		m=1;
	}
}Tree[MAXN*4];

void pushup(int x)
{
	int xx=x<<1;
	Tree[x].sum=(Tree[xx].sum+Tree[xx|1].sum)%M;
} 

void build (int l,int r,int x)
{
	Tree[x].l=l;
	Tree[x].r=r;
	
	if(l==r){
		scanf("%lld",&Tree[x].d);
		Tree[x].sum=Tree[x].d; 
		return ;
	}
	int xx=x<<1;
	int mid=(l+r)>>1;
	build(l,mid,xx);
	build(mid+1,r,xx+1);
	pushup(x);
} 

void pushdown(int x,int Len)
{
	int l=x<<1;
	int r=l|1;
	Tree[l].sum = (Tree[l].sum * Tree[x].m +Tree[x].a*(Len - (Len >> 1)))%M;
	Tree[l].m = Tree[l].m * Tree[x].m % M;
    Tree[l].a = (Tree[l].a * Tree[x].m + Tree[x].a) % M;
    
	Tree[r].sum = (Tree[r].sum * Tree[x].m + (Len >> 1) * Tree[x].a) % M;
    Tree[r].m = Tree[r].m * Tree[x].m % M;
    Tree[r].a = (Tree[r].a * Tree[x].m + Tree[x].a) % M;
 
    Tree[x].m = 1, Tree[x].a = 0;
}

void update(int L,int R,int mul,int add,int x)
{
	if(L>Tree[x].r||Tree[x].l>R)return ;
	if(L<=Tree[x].l && R>=Tree[x].r){
		Tree[x].sum = (Tree[x].sum * mul + (Tree[x].r-Tree[x].l+1)*add) % M;
		Tree[x].m= Tree[x].m * mul % M;
		Tree[x].a = (Tree[x].a *mul+ add)%M;
		return ;	
	}
	//cout<<Tree[x].sum<<endl;
	//cout<<"*"<<l<<" "<<r<<endl;
	//cout<<"*&"<<Tree[x].l<<" "<<Tree[x].r<<endl;
    int mid = (Tree[x].r + Tree[x].l)>>1;
	int xx=x<<1;
	pushdown(x,Tree[x].r-Tree[x].l+1);
	update(L,R,mul,add,xx);
	update(L,R,mul,add,xx+1);
	pushup(x);	 
}


LL Question(int l,int r,int x)	
{
	if (r < Tree[x].l || Tree[x].r< l) return 0;
	//cout<<Tree[x].l<<" "<<Tree[x].r<<endl;
	if(l<=Tree[x].l && Tree[x].r<=r)
	{
		//cout<<Tree[x].sum<<endl;
		return Tree[x].sum;
	}
	int mid = (Tree[x].l+Tree[x].r)>>1;
 	pushdown(x,Tree[x].r-Tree[x].l+1);
 	LL ans = (Question(l,r,x<<1) + Question(l,r,x<<1|1))%M; 
	pushup(x);
	return ans;
}			


int main()
{
	int a,b,c,d,X;
	cin>>N>>M;
	build(1,N,1);
	cin>>X;
	
	For(i,X){
		scanf("%d",&a);
		if(a==1){
			scanf("%d%d%d",&b,&c,&d);
			update(b,c,d,0,1);			
		}
		else if(a==2){
	    	scanf("%d%d%d",&b,&c,&d);
			update(b,c,1,d,1);		
		}
		else if(a==3){
		    scanf("%d%d",&b,&c);
			cout<<Question(b,c,1)<<endl;;	
		}
		//For(k,N*3)cout<<Tree[k].sum<<" ";cout<<endl;		
	}
	
	return 0;
} 

