#include<bits/stdc++.h>
using namespace std;
const int mod = 26;

void encrypt(string str, int a, int b)
{
        int len = str.size();
        int i;
        for(i=0; i<len; i++)
        {
                char ch = 'A'+((a*(str[i]-'A')+b)%mod);
                cout<<ch;
        }
        cout<<endl;
}

int main()
{
        string str;
        int a, b;
        cout<<"Enter string: ";
        cin>>str;
        cout<<"Enter Keys a and b: ";
        cin>>a>>b;
        encrypt(str, a, b);
        return 0;
}
