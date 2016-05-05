#include<bits/stdc++.h>
using namespace std;

int modPower(int a, int p, int mod)
{
        long long ans = 1;
        while(p)
        {
                if(p&1)
                        ans = (ans*a)%mod;
                a = (a*a)%mod;
                p = p/2;
        }
        return (int)ans;
}




int main()
{
        int p, q, e;
        cin>>p>>q>>e;
        int msg;
        cin>>msg;
        int phi = (p-1)*(q-1);
        int n = p*q;
        int d = 1;
        while(1)
        {
                if(((d*e)-1)%phi==0)
                        break;
                d++;
        }
        //cout<<d<<endl;
        int y = modPower(msg, d, n);
        int z = modPower(y, e, n);
        if(msg == z)
                cout<<"Verified";
        else
                cout<<"Not Verified";
        cout<<endl;
        cout<<endl;
        return 0;
}
