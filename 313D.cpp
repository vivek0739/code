#include<bits/stdc++.h>
using namespace std;
char A[200000],B[200000];
bool equivalence(char *Ar,char *Br)
{
	int n=strlen(Ar);
	int m=strlen(Br);
	if(n!=m) return false;
	if(strcmp(Ar,Br)==0) return true;
	if(n%2==1) return false;
	char *A1,*B1,*A2,*B2;
	A1=(char *)malloc(sizeof(char)*n/2);
	A2=(char *)malloc(sizeof(char)*n/2);
	B1=(char *)malloc(sizeof(char)*m/2);
	B2=(char *)malloc(sizeof(char)*m/2);
	int i=0;
	for(i=0;i<n/2;i++)
	A1[i]=Ar[i];
	A1[i]='\0';
	for(i=0;i<n/2;i++)
	A2[i]=Ar[n/2+i];
	A2[i]='\0';
	for(i=0;i<m/2;i++)
	B1[i]=Br[i];
	B1[i]='\0';
	for(i=0;i<m/2;i++)
	B2[i]=Br[m/2+i];
	B2[i]='\0';
	if((equivalence(A1,B1) && equivalence(A2,B2) ) ||(equivalence(A1,B2) && equivalence(A2,B1) ))
	return true;
	else
	return false;

}
int main()
{
	
	cin>>A>>B;
	

	
	
	if(equivalence(A,B))
		cout<<"YES"<<endl;
    else
    	cout<<"NO"<<endl;
	return 0;
}