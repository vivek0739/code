#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		bool table[n][n];
		memset(table,false,sizeof(table));
		int x,y;
		int col;

		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&x,&y);
			x--;
			y--;
			for(int j=0;j<n;j++)
			{
				col=x+y-j;
				if(col<n && col>=0)
					table[j][col]=true;
				col=y-x+j;
				if(col<n && col>=0)
					table[j][col]=true;

			}
		}
		
			
		int count=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(table[i][j]==false)
					count++;
		printf("%d\n",count);
			
	}
	return 0;
}