#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	char A[105],B[105];
	scanf("%d",&t);
	
	while(t--)
	{
		
		scanf("%s%s",A,B);

		int x,y;
		x=strlen(A);
		int minq=0,maxq=0;
		for(int i=0;i<x;i++)
		{
			if(A[i]=='?'||B[i]=='?')
			{
				maxq+=1;
			}
			else if(A[i]!=B[i])
			{
				maxq++;
				minq++;
			}


		}
		
		printf("%d %d\n",minq,maxq);
	}
	return 0;
} 