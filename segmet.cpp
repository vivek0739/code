#include<bits/stdc++.h>
using namespace std;



#define MAX 10000007 
#define inf 0x7fffffff
struct Node
{
	int nodes;
	int times;
};
int arr[100005];

Node tree[MAX];

void build_tree(int node, int a, int b) {
    if(a > b) return;
  	
  	if(a == b) {
    		tree[node].nodes = arr[a]; 
    		tree[node].times=1;
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); 
	build_tree(node*2+1, 1+(a+b)/2, b); 
	if(tree[node*2].nodes>tree[node*2+1].nodes)
	{
	 	tree[node].nodes=tree[node*2].nodes;
	 	tree[node].times=tree[node*2].times;

	}
	else if(tree[node*2].nodes<tree[node*2+1].nodes)
	{
	 	tree[node].nodes=tree[node*2+1].nodes;
	 	tree[node].times=tree[node*2+1].times;
	}
	else
	{
		tree[node].nodes=tree[node*2].nodes;
	 	tree[node].times=tree[node*2].times+tree[node*2+1].times;
	 	
	}

	
}



Node query_tree(int node, int a, int b, int i, int j) {
	
	Node result;
	if(a > b || a > j || b < i)
	{
		result.nodes=-inf;
		result.times=0;
		return result;
	} 
	if(a >= i && b <= j) 
		return tree[node];

	Node q1 = query_tree(node*2, a, (a+b)/2, i, j); 
	Node q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 

	
	if(q1.nodes>q2.nodes)
	{
	 	result.nodes=q1.nodes;
	 	result.times=q1.times;

	}
	else if(q1.nodes<q2.nodes)
	{
	 	result.nodes=q2.nodes;
	 	result.times=q2.times;
	}
	else
	{
		result.nodes=q1.nodes;
		result.times=q2.times+q1.times;
	
	} 
	return result;
}

int main() {
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i++) 
		scanf("%d",&arr[i]);
	build_tree(1, 0, N-1);

	while(M--)
	{
		int lf,rt;
		scanf("%d%d",&lf,&rt);
		Node result= query_tree(1, 0, N-1, lf-1, rt-1);
		cout << result.times<< endl; 
	}
	return 0;
}