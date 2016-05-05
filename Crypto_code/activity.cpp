#include<bits/stdc++.h>
using namespace std;
int compare1(const void *a,const void *b)
{
	int *aa=(int*)a;
	int *bb=(int*)b;
	if(aa[1]>bb[1]) return true;
	else if(aa[1]==bb[1] && aa[0]>bb[0]) return true;
	return false;
}
int Activity1(int A[][3],int n)
{
	int x[n];
	memset(x,0,sizeof(x));
	qsort(A,n,3*sizeof(int),compare1);
	x[A[0][2]]=1;
	int count=0;
	int i;
	for(i=0;i<n;i++)
		cout<<A[i][0]<< " "<<x[i]<<endl;
	int finish=A[0][2];
	for(i=1;i<n;i++)
	{
		if(A[i][0]>=finish)
		{
			x[A[i][2]]=1;
			finish=A[i][1];
			count++;
		}
	}
	for(i=0;i<n;i++)
		if(x[i]==1)
		{
			cout<<i<<endl;
		}
		
	return count+1;
}
int main()
{
	int n,k;
	cin>>n;
	int A[n][3];
	for(int i=0;i<n;i++)
	 cin>>A[i][0];
	
	for(int i=0;i<n;i++)
	{
	 cin>>A[i][1];
	 A[i][2]=i;
	}

	cout<<Activity1(A,n);
	// for(int i=0;i<=n-k;i++)
	//   cout<<B[i]<<endl;
}