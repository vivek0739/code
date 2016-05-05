#include<bits/stdc++.h>
using namespace std;
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    cout<<y<<endl;
    return (( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}
int main()
{
	int t;
	scanf("%d",&t);
	int n,m,k;
	while(t--)
	{
		
		scanf("%d%d%d",&m,&k,&n);
		printf("%d\n",dayofweek(m,k,n) );
	}
	return 0;	
}