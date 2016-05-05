#include<bits/stdc++.h>
using namespace std;
int power1(int a,int b,int mod)
{
  long long int x=a;
  //cout<<a<<b<<mod<<endl;
  long long int y=1;
  while(b)
  {
    if(b&1)
    {
     y=(y*x)%mod;
    }
    x=(x*x)%mod;
    b>>=1;
    //cout<<x<<endl;
  }
  return (int)y;
}
int modInverse(int a, int m) {
    a %= m;
    for(int x = 1; x < m; x++) {
        if((a*x) % m == 1) return x;
    }
}
void keyGenerationAlgorithm(int &e,int &d,int &n)
{
  int p,q;
  cout<<"enter two prime number\n";
  cin>>p>>q;
  n=p*q;
        int phi_n;
  phi_n=(p-1)*(q-1);
  cout<<phi_n<<endl;
  cout<<"ënter any e such that 1<e<phi_n and e is coprime to phi_n"<<endl;

  cin>>e;
  d=modInverse(e,phi_n);
  return;
}
int RsaEncryption(int p,int e,int n)
{
    cout<<p<<e<<n<<endl;
    return power1(p,e,n);
}

string inttostring(int number)
{
  string A="";
  while(number)
  {
   int temp=number%100;
   A=(char)(temp+'a')+A;
   number/=100;
  }
  return A;
}
int RsaDecryption(int c,int d,int n)
{
  return (power1(c,d,n));
}
int stringtoint(string A)
{
  int n=A.size();
  int number=0;
  for(int i=0;i<n;i++)
  {
    int temp=(A[i]-'a');
    number=number*100+temp; 
  
  }
 return number;
}

int main()
{
  int e,d,n;
  e=0,d=0,n=1;
  keyGenerationAlgorithm(e,d,n);
 // cout<<e<<d<<n;
  string plaintext;
  cout<<"enter the plaintext a integer\n";
  cin>>plaintext;
  int C=RsaEncryption(stringtoint(plaintext),e,n);
  cout<<C<<endl;
  int t=RsaDecryption(C,d,n);
  cout<<inttostring(t)<<endl;

}
