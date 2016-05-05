#include<bits/stdc++.h>
using namespace std;
int parent[20005];
int value[20005];
void printvalue(int current)
{
	if(parent[current])
	{
		printvalue(parent[current]);
		printf("%d",value[current]);
	}
	else
	{
		printf("1");
		return;
	}
}
void solve(int n)
{
	
	memset(parent,-1,sizeof(parent));
	
	int current;
	queue<int> q;
	q.push(1);
	parent[1]=0;
	while(!q.empty())
	{
		current=q.front();
		q.pop();
		if(current==0)
		{
			//printf("check");
			printvalue(current);
			printf("\n");
			break;
		}
		int temp=(current*10)%n;
		if(parent[temp]==-1)
		{
			q.push(temp);
			parent[temp]=current;
			value[temp]=0;
		}
		temp=(current*10+1)%n;
		if(parent[temp]==-1)
		{
			q.push(temp);
			parent[temp]=current;
			value[temp]=1;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
			int n;
			scanf("%d",&n);
			solve(n);
	}
	 return 0;
}