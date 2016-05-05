#include<bits/stdc++.h>
using namespace std;
map<int,double> AP;
map<int,int> reldocs;
map<int,int> indexs;
map<int,double> dcg;
int main()
{
	ifstream fin("Run1.res",ios::in);
	string inputline;
	while(getline(fin, inputline)){
		istringstream iss(inputline);
		int id, ind, rel;
		double measure;
		string doc,qno;
		iss>>id>>qno>>doc>>ind>>measure>>rel;
		//cout<<id<<qno<<doc<<ind<<measure<<rel<<endl;
		if(rel == 1)
		{
			reldocs[id]++;
			AP[id]+=(double)reldocs[id]/ind;
		}
		
		
	}
	map<int,double>::iterator it;
		double MAP=0.0;
		for(it = AP.begin();it!=AP.end();it++)
		{
			it->second /= reldocs[it->first];
			cout<<"AP IS :"<<it->second<<endl;
			MAP += it->second;
		}
		cout<< "MAP IS :"<< MAP/AP.size()<<endl;
	fin.close();
	
	ifstream fin1("truth_std_fire13.rel",ios::in);
	
	while(getline(fin1, inputline)){
		istringstream iss(inputline);
		int  id, rel;
		
		string doc,qno;
		iss>>id>>qno>>doc>>rel;
		//cout<<id<<qno<<doc<<ind<<measure<<rel<<endl;
		indexs[id]++;
		if(indexs[id]!=1)
		dcg[id]+=(double)(.301*rel)/log10(indexs[id]);
		else
		dcg[id]=rel;
		
		
		
	}
		
		for(it = dcg.begin();it!=dcg.end();it++)
		{
		
			cout<<"DCG for query " << it->second<<endl;
		}
		//cout<< "MAP IS :"<< MAP/AP.size()<<endl;
	fin1.close();
	
}
