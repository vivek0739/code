#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
	int t;
	scanf("%d",&t);
	
	long long int ans=0;
	while(t--)
	{	
		int n;
		scanf("%d",&n);
		n++;
		if(n==2)
		{
			printf("2\n");
		}
		else if(!(n&(n-1)))
		{
			printf("%d\n",n/2-1);
		}
		
		else
		printf("-1\n");
		
	}
	return 0;	
}