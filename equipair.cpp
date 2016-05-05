#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	vector<int> numbers;
	do
    {
        int input ;
        if ( std::cin >> input )
            numbers.push_back(input) ;
    } while ( std::cin && std::cin.peek() != '\n' ) ;

	    
	int n=numbers.size();
	int i=1;
	int j=n-2;
	int suml=numbers[0];
	int sumr=numbers[n-1];
	int sum=0;

	for(int i=0;i<n;i++)
		sum+=numbers[i];
	while(i+1<j)
	{
		//printf("{ %d,%d }\n",i,j);
		if(suml==sumr)
		{
			if(suml==sum-suml-sumr-numbers[i]-numbers[j])
			{
				printf("Indices which form equi pair { %d,%d }\n",i,j);	
				printf("Slices are { 0,%d },{ %d,%d },{ %d,%d }",i-1,i+1,j-1,j+1,n-1);
				break;
			}
			else
			{
				i++;
				j--;
				suml+=numbers[i-1];
				sumr+=numbers[j+1];
			}
		}
		else if(suml>sumr)
		{
			j--;
			sumr+=numbers[j+1];
		}
		else
		{
			i++;
			suml+=numbers[i-1];
		}
		

	}
		if(i+1>=j )
		{
			
			printf("Array does not contain any equi pair");
		
		}
	return 0;	
}