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
		string A,B;
		cin>>A>>B;
		int n=A.size();
		int m=B.size();
		if(n!=m)
		{
			printf("No\n");
			continue;
		}
		int i;
		for(i=0;i<n;i++)
		{
			if(A[i]=='?'||B[i]=='?')
				continue;
			else if(A[i]!=B[i])
				 {
				 	printf("No\n");
				 	break;
				 }
		}
		if(i==n)
			printf("Yes\n");
		
	}
	return 0;	
}