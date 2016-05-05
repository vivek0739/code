#include<bits/stdc++.h>
using namespace std;
double d;
double c[25];
double determinant(double a[25][25],double k)
{
  double s=1,det=0,b[25][25];
  int i,j,m,n,c;
  if (k==1)
    {
     return (a[0][0]);
    }
  else
    {
     det=0;
     for (c=0;c<k;c++)
       {
        m=0;
        n=0;
        for (i=0;i<k;i++)
          {
            for (j=0;j<k;j++)
              {
                b[i][j]=0;
                if (i != 0 && j != c)
                 {
                   b[m][n]=a[i][j];
                   if (n<(k-2))
                    n++;
                   else
                    {
                     n=0;
                     m++;
                     }
                   }
               }
             }
          det=det + s * (a[0][c] * determinant(b,k-1));
          s=-1 * s;
          }
    }
 
    return (det);
}

void transpose(double num[25][25],double fac[25][25],double r)
{
  int i,j;
  double b[25][25],inverse[25][25],d;
 
  for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
         b[i][j]=fac[j][i];
        }
    }
  d=determinant(num,r);
  for (i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
       {
        inverse[i][j]=b[i][j]/ d;
        }
    }
   //printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i=0;i<r;i++)
    {
      double val=0;
     for (j=0;j<r;j++)
       {
         val+=inverse[i][j]*c[j];
        }
        if(i==r-1)
        printf("%.2lf",val);
        else
        printf("%.2lf\n",val);

     }
}

void cofactor(double num[25][25],double f)
{
 double b[25][25],fac[25][25];
 int p,q,m,n,i,j;
 for (q=0;q<f;q++)
 {
   for (p=0;p<f;p++)
    {
     m=0;
     n=0;
     for (i=0;i<f;i++)
     {
       for (j=0;j<f;j++)
        {
          if (i != q && j != p)
          {
            b[m][n]=num[i][j];
            if (n<(f-2))
             n++;
            else
             {
               n=0;
               m++;
               }
            }
        }
      }
      fac[q][p]=pow(-1,q + p) * determinant(b,f-1);
    }
  }
  transpose(num,fac,f);
}

int main()
{
  
   
    int n;
    scanf("%d",&n);
    double a[25][25];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          scanf("%lf",&a[i][j]);
        }
        scanf("%lf",&c[i]);
    }
    d=determinant(a,n);
    if(d==0)
       printf("Unsolvable\n");
    else
    {
       cofactor(a,n);

    }
    // double val[25];
    // for(int i=0;i<n;i++)
    // {
    //   val[i][j]=0.0;
    //   for(int j=0;j<n;j++)
    //   {
    //     val[i]+=a[i][j]*c[j];
    //   }
    // }
    
      return 0; 
}