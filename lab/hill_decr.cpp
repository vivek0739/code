#include<bits/stdc++.h>
using namespace std;
int keyM[3][3], invM[3][3];

int getVal(int i, int j)
{
        int sum = 0;
        sum = keyM[(i+1)%3][(j+1)%3]*keyM[(i+2)%3][(j+2)%3]-keyM[(i+1)%3][(j+2)%3]*keyM[(i+2)%3][(j+1)%3];
        return sum;
}

void getInverse()
{
        int i, j, k;
        int mod = 0;
        for(i=0; i<3; i++)
        {
                mod += keyM[0][i]*getVal(0,i);
        }
        int x = 0;
         while(1)
        {
               if((mod*x-1)%26==0)
                        break;
                x++;
        }


        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        invM[j][i] = (getVal(i, j));
                //      if((i+j)%2)
                //              invM[j][i] = invM[j][i];
                        invM[j][i] = (invM[j][i]*x)%26;
                        if(invM[j][i]<0)
                                invM[j][i] += 26;
                }
        }

}

void getdecryp(string str)
{
        int i=0, j=0, sum = 0;
        int len = str.size();

        while(i<len)
        {
                int a[3];
                a[0] = str[i]-'A';
                i++;
                if(i<len)
                {
                        a[1] = str[i++]-'A';
                        if(i<len)
                                a[2] = str[i++]-'A';
                        else
                                a[2] = 'P';
                }
                else
                {
                        a[1] = 'P';
                        a[2] = 'P';
                }
                j= 0;
                while(j<3)
                {
                        int c = (invM[j][0]*a[0]+invM[j][1]*a[1]+invM[j][2]*a[2])%26;
                        char ch = 'A'+c;
                        cout<<ch;
                        j++;
                }
        }
}
int main()
{
        string str, key;
        cout<<"Enter the key string of length 9: ";
        cin>>key;
        int i=0, j=0, k=0;
        while(k<9)
        {
                keyM[i][j] = key[k]-'A';
                j++;
                if(j%3==0)
                {
                        i++;
                        j=0;
                }
                k++;
        }
        getInverse();
        cout<<"\nEnter the cipher text: ";
        cin>>str;
        getdecryp(str);
        return 0;
}
