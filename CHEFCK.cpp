#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll A[10000005];
ll st[100000005];
ll min(ll a,ll b)
{
    if(a<b)
    return a;
    else
    return b;
}
ll   minVal(ll   x, ll   y) { return (x < y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
ll   getMid(ll   s, ll   e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.
 
    st    --> Poll  er to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
ll   RMQ( ll   ss, ll   se, ll   qs, ll   qe, ll   index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return  INT_MAX;
 
    // If a part of this segment overlaps with the given range
    ll   mid = getMid(ss, se);
    return minVal(RMQ( ss, mid, qs, qe, 2*index+1),
                  RMQ( mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()

 


 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
ll   constructSTUtil(ll   arr[], ll   ss, ll   se, ll   si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    ll   mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid,si*2+1),
                     constructSTUtil(arr, mid+1, se, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
void  constructST(ll   arr[], ll   n)
{
   
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, 0);
 
   
}
int main()
{
    ll N,K,Q,a, b, c, d, e, f, r, s, t, m,l1, la, lc, lm, d1, da, dc,dm,i,j;
    scanf("%lld %lld %lld",&N,&K,&Q);
 
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&A[0]);
     scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&l1,&la,&lc,&lm,&d1,&da,&dc,&dm);
      ll p=t;
     for(i=1;i<N;i++)
     {
        p=(p*t)%s;
        if(p<=r)
        {
            A[i]=((a*A[i-1]*A[i-1])+(b*A[i-1])+c)%m;
        }
        else
            A[i]=((d*A[i-1]*A[i-1])+(e*A[i-1])+f)%m;
     }   
     constructST(A,N);  
     ll L,R,sum=0,product=1;
     for(i=1;i<=Q;i++)
     {
        l1=(la*l1+lc)%lm;
        d1=(da*d1+dc)%dm;
        L=l1+1;
        R=min(L+K-1+d1,N);
        ll ans1;
        //cout<<L<<" "<<R<<endl;
        ans1=RMQ(0,N-1,L-1,R-1,0);
        //cout<<ans1;
        sum=(sum+ans1);
        product=(product*ans1)%mod;
     }
     printf("%lld %lld",sum,product);
 
}