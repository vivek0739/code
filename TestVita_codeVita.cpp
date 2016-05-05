#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;    
    void DFSUtil(int v, bool visited[],int &sum);  
public:
	int *hour;
	list<int> *adj;
	int *dp;
	int *indegree;
    Graph(int V);   
    void addEdge(int v, int w);  
    void DFS(int &sum);  
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    hour= new int[V];
    dp= new int[V];
    indegree= new int[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFSUtil(int v, bool visited[],int &sum)
{
	if(visited[v]) 
	{
		sum =dp[v];
		return;
	}
    visited[v] = true;
    int sum2=0;
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
    	if(!visited[*i])
    	{
    		int sum1=0;
    		DFSUtil(*i, visited,sum1);
    		
    		if(sum1>sum2) sum2=sum1;
    	}
    	else
    	{
    		if(dp[*i]>sum2) sum2=dp[*i];
    	}
            
    }
    sum2+=hour[v];
    //cout<<v<<sum2<<endl;
    dp[v]=sum2;
    sum+=sum2;
        
}
 
void Graph::DFS(int &sum)
{
    
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
   
    for(int i=0;i<V;i++)
    {
    	int sum2=0;
    	if(!visited[i])
    	{
    		//cout<<i<<endl;
    		DFSUtil(i, visited,sum2);
    		if(sum2>sum) sum=sum2;
    		//cout<<sum<<endl;
    	}
    }
}
 

// Driver program to test above functions

int main()
{
	int t;
	scanf("%d",&t);
	int ans=0;
	while(t--)
	{	ans=0;
		int n;
		scanf("%d",&n);
		Graph g(n);
		
		for(int i=0;i<n;i++)
		{
			int x,b;
			scanf("%d%d",&x,&b);
			g.hour[x-1]=b;
			std::string line;
			   std::vector<int> all_integers;
			   getline( std::cin, line );
			      std::istringstream is( line );
			      
			           all_integers=std::vector<int>( std::istream_iterator<int>(is),
			                              std::istream_iterator<int>()  );
			 
			 int p=all_integers.size();

			for (int i=0;i<p;i++ )
			{
			    g.addEdge(all_integers[i]-1,x-1);
			    // g.indegree[x-1]++;
			}
		}
		int sum=0;
		g.DFS(sum);
		
		
		if(t!=0)
		{
			printf("%d\n",sum);

		}
		else
		{
			printf("%d",sum);

		}

		
	}	
	return 0;	
}