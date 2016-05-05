#include<bits/stdc++.h>
using namespace std;
bool isValid(float N,float SV,float CSV,float R,float CR)
{
	if(N>=20000.00 && N<=10000000.00 && SV>=20.00 && SV<=10000.00
		&& CSV>=-2000.00 && CSV<=2000.00 && R>=0.01 && R<=99.99
		&& CR>=-10.00 && CR<=10.00 )
	{
		if(CSV<0 && CR<=0)
			return true;
		else if(CSV>=0)
			return true;
	}
		
	return false;
}
bool isValidOp(float SVd,float Rd)
{
	if(Rd>=0.01 && Rd<=99.99 && SVd>=20.00 && SVd<=10000.00)
		return true;
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	double N,SV,CSV,R,CR;
	double SVd,Rd,CV,CE,CA;
	int ans=0;
	while(t--)
	{	ans=0;
		scanf("%lf%lf%lf%lf%lf",&N,&SV,&CSV,&R,&CR);
		if(!isValid(N,SV,CSV,R,CR))
		{
			if(t!=0)
			printf("Invalid Input\n" );
			else
			printf("Invalid Input" );
		   continue;
		}
		SVd=SV-CSV;
		Rd=R-CR;
		CV=N*min(SVd,SV);
		CE=CV*0.5;
		CA=CE*min(Rd,R)/100;
		if(!isValidOp(SVd,Rd))
		{
			if(t!=0)
			printf("Invalid Input\n" );
			else
			printf("Invalid Input" );
		   continue;
		}
		if(t!=0)
		{
			cout <<  SVd << '\n';
			cout << Rd<< '\n';
			cout << setprecision(2) << fixed <<  CV << '\n';
			cout << setprecision(2) << fixed <<  CE << '\n';
			cout << setprecision(2) << fixed <<  CA << '\n';

		}
			//printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf\n",SVd,Rd,CV,CE,CA );
		else
		{
			cout <<  SVd << '\n';
			cout <<  Rd<< '\n';
			cout << setprecision(2) << fixed <<  CV << '\n';
			cout << setprecision(2) << fixed <<  CE << '\n';
			cout << setprecision(2) << fixed <<  CA ;

		}
			//printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n%.2lf",SVd,Rd,CV,CE,CA );
	}	
	return 0;	
}