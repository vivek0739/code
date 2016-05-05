#include<bits/stdc++.h>
using namespace std;
struct Node1
{
	int node;
	int indegree;
};
void maxWindow(int A[],int k,int n,int B[])
{
	deque<int> Q;
	for(int i=0;i<k;i++)
	{
		while(!Q.empty()&& A[i]>=A[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	
	for(int i=k;i<n;i++)
	{
		cout<<A[Q.front()]<<endl;
		while(!Q.empty()&&A[i]>=A[Q.back()])
			Q.pop_back();
		while(!Q.empty()&& (i-k>=Q.front()))
			Q.pop_front();
		Q.push_back(i);
	}
	cout<<A[Q.front()]<<endl;
}

int main()
{
	int n;
	list<int> adj[n];
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	priority_queue<Node1* ,vector<Node1>,compare> pq;
	for(int i=0;i<n;i++)
	{
		pq.push((Node1){i,adj[i].size()});

	}
	while()
	// for(int i=0;i<=n-k;i++)
	//   cout<<B[i]<<endl;
}