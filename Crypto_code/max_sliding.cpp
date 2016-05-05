#include<bits/stdc++.h>
using namespace std;
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
	int n,k;
	cin>>n>>k;
	int A[n];
	for(int i=0;i<n;i++)
	 cin>>A[i];
	int B[n];
	maxWindow(A,k,n,B);
	// for(int i=0;i<=n-k;i++)
	//   cout<<B[i]<<endl;
}