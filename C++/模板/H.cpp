
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;


int main()
{
	int   T,m,k,a,b,c,l;
	int n;
	long long K,G=0;

    cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int ans=0;
	    cin>>n>>l>>a>>b>>c;
	   
       a*=100;
	   b*=100;
	   c*=100;
	   l*=100;
	   
	   
	   
	   
	    
	    /*
for(int i=1;;i++)
	    {
    		if((a*i%l)==(b*i%l) && (b*i%l)==(c*i%l))
    		{
		    	ans++;
		    	if(ans==n)
		    	{
		    		double ANS=i;
		    	    printf("%.2lf",ANS/100);
		    	    break;
				}
		    }
    	}
	    */
  
	}
	
	return 0;
}

/*


3
1 1000000 1 0
1 1000000 2 0
1 1000000 3 1


*/
