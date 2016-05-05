#include<bits/stdc++.h>
using namespace std;
int prime[10000];
void seive()
{
	prime[0]=1;
	prime[1]=1;
	for(int i=2;i*i<10000;i++)
	{
		for(int j=i*2;j<10000;j+=i)
		{
			prime[j]=1;
		}
	}
}
int bfs(int a,int b)
{
	bool visited[10000];
	memset(visited,false,sizeof(visited));
	int dist[10000];
	memset(dist,1000000,sizeof(dist));
	queue<int> q;
	q.push(a);
	dist[a]=0;
	while(!q.empty())
	{
		int top=q.front();
		if(top==b)
		{
			return dist[top];
		}
		q.pop();
		if(visited[top]==false)
		{
			visited[top]=true;
			int d=top;
			int c;
			int pow2=1;
			for(int j=1;j<=4;j++)
			{
				pow2*=10;
				int r=d%10;

					d/=10;
				for(int i=0;i<=9;i++)
				{
				
					c=top+(i-r)*pow2/10;
					//cout<<c<<" "<<dist[c]<<endl;
					if(visited[c]==false && c>=1000 && c<10000 && prime[c]==0 && dist[c]>dist[top]+1)
					{

						q.push(c);
						dist[c]=dist[top]+1;
					}

				}
			}
		}
		
		
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	seive();
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int c=bfs(a,b);
		if(c==-1)
		 printf("Impossible\n");
		else
		printf("%d\n",c);
	}
}