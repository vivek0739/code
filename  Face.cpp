#include<bits/stdc++.h>
using namespace std;
char b[55][55];
int dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
bool visited[55][55];
int ans=0;
int n,m;
int bfs(int i,int j,int count)
{
	int newcount=0;
	if(!visited[i][j])
	{
		visited[i][j]=false;
		if(b[i][j]=='f')
		newcount=1;
		else if(b[i][j]=='a' and count ==1)
		newcount=2;
		else if(b[i][j]=='c' and count ==2)
		newcount=3;
		else if(b[i][j]=='3' and count ==3)
		newcount=4;
		if(newcount == 4)
		ans++;
		for(int k=0;k<4;k++)
		{
		 int temp_i=i+dir[k][0];
		 int temp_j=j+dir[k][1]
			if(temp_i<n && temp_i >=0)
			{
				if(temp_j<m && temp_j >=0)
				{
					bfs(temp_i,temp_j,newcount);
				}
			}
		}

	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%s",b[i]);
	printf("%d\n",ans)l;
	return 0;
}