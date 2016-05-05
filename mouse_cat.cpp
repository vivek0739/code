#include<bits/stdc++.h>
using namespace std;
int n,c;
vector<vector<int> > mouse;
vector<vector<int> > cat;

int value[20005];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool m_isValid(int a,int b, int d,int e)
{
	if(a<n&&a>=0&&b<c&&b>=0&&mouse[a][b]>mouse[d][e]+1)
	{
		return true;
	}
	return false;
}
bool c_isValid(int a,int b, int d,int e)
{
	if(a<n&&a>=0&&b<c&&b>=0&&cat[a][b]>cat[d][e]+1)
	{
		return true;
	}
	return false;
}
void cat_bfs(int c1,int c2)
{
	queue<pair<int,int> > q;
	vector<vector<bool> > visited (n,vector<bool> (c,0));
	//cout<<cat[c1][c2]<<endl;
	q.push(make_pair(c1,c2));
	cat[c1][c2]=0;
	while(!q.empty())
	 {
		pair<int,int> top=q.front();
		q.pop();
		//cout<<(visited[top.first][top.second]==false)<<endl;
		if(!visited[top.first][top.second])
		{
			visited[top.first][top.second]=true;
			for(int k=0;k<4;k++)
			{

				int new_x=top.first+dir[k][0];
				int new_y=top.second+dir[k][1];
				//cout<<new_x<<new_y<<endl;
				if(c_isValid(new_x,new_y,top.first,top.second))
				{
					q.push(make_pair(new_x,new_y));
					cat[new_x][new_y]=cat[top.first][top.second]+1;
				}
			}
		}
	}

}
void mouse_bfs(int m1,int m2)
{
	queue<pair<int,int> > q;
	vector<vector<bool> > visited (n,vector<bool> (c,0));
	q.push(make_pair(m1,m2));
	mouse[m1][m2]=0;
	while(!q.empty())
	 {
		pair<int,int> top=q.front();
		q.pop();
		if(!visited[top.first][top.second])
		{
			visited[top.first][top.second]=true;
			for(int k=0;k<4;k++)
			{
				int new_x=top.first+dir[k][0];
				int new_y=top.second+dir[k][1];
				if(m_isValid(new_x,new_y,top.first,top.second))
				{
					q.push(make_pair(new_x,new_y));
					mouse[new_x][new_y]=mouse[top.first][top.second]+1;
				}
			}
		}
	}

}
void solve(int m1,int m2,int c11,int c12,int c21,int c22)
{
	mouse.resize(n,vector<int>(c,1000000));
	cat.resize(n,vector<int>(c,1000000));
	mouse_bfs(m1-1,m2-1);
	cat_bfs(c11-1,c12-1);
	cat_bfs(c21-1,c22-1);

	bool found=false;
	for(int i=0;i<n;i++)
	{
		if(mouse[i][0]<cat[i][0] ||mouse[i][c-1]<cat[i][c-1])
		{
			found=true;
			printf("YES\n");
			//printf("i");
			return;
		}
	}
	for(int j=0;j<c;j++)
	{
		if(mouse[0][j]<cat[0][j] || mouse[n-1][j]<cat[n-1][j])
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
	return;

}
int main()
{
	int t;
	
	scanf("%d%d",&n,&c);
	scanf("%d",&t);
	while(t--)
	{
			int m1,m2,c11,c12,c21,c22;
			scanf("%d%d%d%d%d%d",&m1,&m2,&c11,&c12,&c21,&c22);
			solve(m1,m2,c11,c12,c21,c22);
	}
	 return 0;
}