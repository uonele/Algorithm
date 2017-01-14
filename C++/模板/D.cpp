
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

const int N=1080;

int phi[100001];
int pr[100001];

int getphi(int x)
{
	int phi=1;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			x/=i;phi*=i-1;
			while(x%i==0){
				x/=i;phi*=i;
			}
		}
	}
	if(x>1)	phi*=x-1;
	return phi;
}	

/*
void  Prime()
{
	for(long long i=2;i<11111;i++)
	{
		if(pr[i]==0)
		for(long long k=2;k<=(double)sqrt((double)i)+0.5;k++)
		{
			if(i%k==0)
			{
				pr[i]=1;
				for(long long j=1;j*i<11111;j++)
				{
					pr[j*i]=1;
				}
			}
		}
	}

pr[2]=0;

long long G=1;
for(long long  i=2;i<=11111;i++)
{
   if(pr[i]==0)
  	{

       phi[i]=G;
       G++;
    }
    else 
    {
    	phi[i]=G-1;
    }
}


}
*/


int ans [19991];
int ANS[10001];


int prime[10001],tot;
bool mark[10001]; 
int check[10001];
void getphi(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!check[i])  {tot++;prime[tot]=i;phi[i]=i-1;}
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>1000)  break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i * prime[j]]=phi[i]*prime[j];break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
} 

int main()
{
	long long T, M;
	int n;
	long long K,GG=0;

	//Prime();
	cin>>T;
	getphi();


	
	for(long long  i=1;i<=T;i++)
	{
		scanf("%d",&n);
		//if(M>1)M--;
		
		M=ans[n];
		long long AN=0;
		for(int k=2;k<=n;k++)
		{
			AN+=phi[k];
		}
	
		
		printf("%lld\n",AN);
	
	} 
	
	return 0;
}