#include<bits/stdc++.h>
using namespace std;
int arr[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sx,sy,ex,ey,bx,by;
		
		scanf("%d%d%d%d%d%d%d",&n,&sx,&sy,&ex,&ey,&bx,&by);
		bool visited[20][20];
		int sol[20][20];
		int ans=INT_MAX;
		memset(sol,0,sizeof(sol));
		memset(visited,false,sizeof(visited));
		queue<pair<int,int> > Q;
		Q.push(make_pair(sx,sy));
		sol[sx][sy]=0;
		
		while(!Q.empty())
		{
			
			pair<int,int> box=Q.front();
			Q.pop();
			int i=box.first;
			int j=box.second;
			
			if(visited[i][j]==false)
			{
				
				visited[i][j]=true;
				if(i!=bx || j!=by)
				{
					if(i==ex && j==ey)
					{
						ans=min(ans,sol[i][j]);

					}
					for(int k=0;k<4;k++)
					{
						int temp_i=i+arr[k][0];
						int temp_j=j+arr[k][1];
						sol[temp_i][temp_j]=sol[i][j]+1;
						if(temp_i<=n && temp_i>=1 && temp_j <=n && temp_j>0)
						Q.push(make_pair(temp_i,temp_j));
					}
				}
			}
			
			
		}

		printf("%d\n",ans);

	}
}