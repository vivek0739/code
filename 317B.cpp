#include<bits/stdc++.h>
using namespace std;
map<int,int> sell;
map<int,int> pur;
int main()
{
	int n,s;
	cin>>n>>s;
	sell.clear();
	pur.clear();
	pair<int,int>pr;
	while(n--)
	{
		string dir;
		int p,q;
		cin>>dir>>p>>q;
		if(dir[0]=='S')
		{
			if(sell.find(p)!= sell.end())
			{
				sell[p]+=q;
			}
			else
			{
				sell[p]=q;
			}
		}
		else
		{
			if(pur.find(p)!= pur.end())
			{
				pur[p]+=q;
			}
			else
			{
				pur[p]=q;
			}
		}
		

	}

	map<int,int>::iterator it;
	int d=s;
	vector<pair<int,int> > v;
	for(it=sell.begin();it!=sell.end();it++)
	{
		if(d==0)
			 break;
			v.push_back(make_pair(it->first,it->second));
			d--;
	}
	int r=v.size();
	for(int i=r-1;i>=0;i--)
	{
		cout<<"S "<<v[i].first<<" "<<v[i].second<<endl;
	}
	v.clear();
	map<int,int>::reverse_iterator rit;
	d=s;
	for(rit=pur.rbegin();rit!=pur.rend();rit++)
	{
		if(d==0)
			break;
		cout<<"B "<<rit->first<<" "<<rit->second<<endl;
		d--;
	}
	return 0;	
}