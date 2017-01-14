
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
const int  N=10001;
	
struct HPC{
	int num[N];
};

void print(const HPC &A)
{   	
	printf("%d",A.num[A.num[0]]);
	for(int i=A.num[0]-1;i>0;i--) printf("%.4d",A.num[i]);
	printf("\n");
}

HPC operator +(const HPC &a,const HPC &b){//高精 +
	HPC ans;int &len=ans.num[0],L=max(a.num[0],b.num[0]);
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<L;i++){
		ans.num[i]+=a.num[i]+b.num[i];ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=L;ans.num[len]+=a.num[len]+b.num[len];
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator *(const HPC &a,int b){//高精 * 
	HPC ans;
	int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<a.num[0];i++){
		ans.num[i]+=a.num[i]*b;ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
    len=a.num[0];ans.num[len]+=a.num[len]*b;
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator /(const HPC &a,int b){//单 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=a.num[0];i>1;i--){
		ans.num[i-1]+=(ans.num[i]+a.num[i])%b*10000;ans.num[i]=(ans.num[i]+a.num[i])/b;
	}
	ans.num[1]=(ans.num[1]+a.num[1])/b;
	for(len=a.num[0];!ans.num[len];len--);
	return ans;
}

bool operator ==(const HPC &a,const HPC &b){
	int Len=a.num[0];
	if(a.num[0]!=b.num[0])return 0;
	for(int i=1;i<=Len;i++)
	{
		if(a.num[i]!=b.num[i])return 0;
	}
	
   return 1;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int x;
		scanf("%d",&x);
		
		if(x<2)
		{
			cout<<-1<<endl;
			continue;
		} 
		
		HPC a,b,c;
		b.num[1]=1;
		b.num[0]=1;
		
		int y=x%4;
		 
		if(y==3)
		a.num[1+x/4]=100;
		if(y==2)
		a.num[1+x/4]=10;
		if(y==1)
		a.num[1+x/4]=1;
		
		
		a.num[0]=x;
		
		for(;;)
		{
			if((a/47)*47==a)
			{
				print(a);
				break;
			}
			else a=a+b;
		}
		
	}
	
	
	
	
	
	
	return 0;
}