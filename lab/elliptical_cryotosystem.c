#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> point;
int a = 2, b = 3;
int p = 67;

int inverse(int v) {
	//cout<<"INv "<<v<<endl;
	if(v < 0)
		v += p;
	int i = 1;
	while(i<p) {
		if( (v*i) %p ==1 )
			return i;
		i++;
	}
}

point multiply(point e1, int d) {
	point p1 = e1;
	point p2 = e1;
	
	for(int i=0;i<d-1;i++) {
		int x1 = p1.first;
		int y1 = p1.second;
		int x2 = p2.first;
		int y2 = p2.second;
		
		if(x1 == x2 && y1 == -1*y2)
			cout<<"here\n";
		else if(x1 == x2 && y1 == y2) {
			int lamda =( (3*x1*x1 + a)*inverse( (2*y1)%p ) )%p ;
			p2.first =  ((lamda*lamda - x1 - x2 )%p )%p ;
			p2.second = ((lamda*(x1 - p2.first) - y1)%p  )%p;
		} else {
			int t = x2 - y1;
			if(t < 0)
			 	t+=p;
			int t1 = y2 - y1;
			if(t1 < 0)
				t1 += p;
			int lamda = ( (t1)*inverse(t) )%p;
			p2.first  = (( lamda*lamda - x1 - x2 )%p  )%p ;
			p2.second = (( lamda*(x1-p2.first) -y1 )%p )%p;
		}
		
		cout<<i<<" "<<x1<<" "<<y1<<" "<<p2.first<<" "<<p2.second<<endl;
	}
 
	return p2;
}

int main() {
	
	point e1 = make_pair(2,22);
	int d = 4;
	point e2 = multiply(e1,d);
	cout<<e2.first<<" "<<e2.second;
	
	return 0;
}
