#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sbox[256] =
{
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16  //F
};
char RC[10][8] = 
{
    {'0','0','0','0','0','0','0','1'},
    {'0','0','0','0','0','0','1','0'},
    {'0','0','0','0','0','1','0','0'},
    {'0','0','0','0','1','0','0','0'},
    {'0','0','0','1','0','0','0','0'},
    {'0','0','1','0','0','0','0','0'},
    {'0','1','0','0','0','0','0','0'},
    {'1','0','0','0','0','0','0','0'},
    {'0','0','0','1','1','0','1','1'},
    {'0','0','1','1','0','1','1','0'}
};
char getHexDigit(char a,char b,char c,char d)
{
    char ar[4];
    ar[0]=a;
    ar[1]=b;
    ar[2]=c;
    ar[3]=d;   
    if(strcmp(ar,"0000")==0)
        return '0';   
    else if(strcmp(ar,"0001")==0)
        return '1';
    else if(strcmp(ar,"0010")==0)
        return '2';
    else if(strcmp(ar,"0011")==0)
        return '3';
    else if(strcmp(ar,"0100")==0)
        return '4';
    else if(strcmp(ar,"0101")==0)
        return '5';
    else if(strcmp(ar,"0110")==0)
        return '6';
    else if(strcmp(ar,"0111")==0)
        return '7';
    else if(strcmp(ar,"1000")==0)
        return '8';
    else if(strcmp(ar,"1001")==0)
        return '9';
    else if(strcmp(ar,"1010")==0)
        return 'A';
    else if(strcmp(ar,"1011")==0)
        return 'B';
    else if(strcmp(ar,"1100")==0)
        return 'C';
    else if(strcmp(ar,"1101")==0)
        return 'D';
    else if(strcmp(ar,"1110")==0)
        return 'E';
    else
        return 'F';
}
char xor(char x,char y)
{
    if(x==y)
        return '0';
    else
        return '1';
}
void xorArr(char a[],char b[],char c[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
        c[i]=xor(a[i],b[i]);
}
char ** keygeneration(char str[])
{
    char **word;
    word=(char**)malloc(4*sizeof(char*));
    int i,j;
    for(i=0;i<4;i++)
        word[i]=(char*)malloc(32*sizeof(char));
    for(i=0;i<4;i++)
        for(j=0;j<32;j++)
            word[i][j]=str[i*32+j];
    return word;
}
int stringToInt(char V[],int n)
{
        int sum=0;
        int i;
        for(i=n-1;i>=0;i--)
        {
                sum+=(int)(V[i]-'0')*(1<<(n-1-i));
        }
        return sum;
}
void intToString(int n,char V[])
{
        int i;
        for(i=7;i>=0;i--)
        {
                V[i]=(char)(n%2+'0');
                n/=2;
        }
}
void S(char V1[])
{
        int index=stringToInt(V1,8);
        int x=sbox[index];
        intToString(x,V1);
}
void delta(char A[],char B[],int round)
{
    char V[4][8];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
                V[(i-1+4)%4][j]=A[i*8+j];
        }
    }
    S(V[0]);
    S(V[1]);
    S(V[2]);
    S(V[3]);
    xorArr(V[0],RC[round],V[0],8);
    for(i=0;i<4;i++)
        for(j=0;j<8;j++)
            B[8*i+j]=V[i][j];
}
void schedule(char **word,char **temp,int round)
{
    char deltaVal[32];
    delta(word[3],deltaVal,round);
    xorArr(word[0],deltaVal,temp[0],32);
    xorArr(temp[0],word[1] ,temp[1],32);
    xorArr(temp[1],word[2] ,temp[2],32);
    xorArr(temp[2],word[3] ,temp[3],32);
}
int main()
{
    char input[128];
    scanf("%s",input);
    char **word;
    word=keygeneration(input);
    int i;
    for( i=0;i<4;i++)
            printf("%s\n",word[i]);
    char **temp;
    temp=(char**)malloc(4*sizeof(char*));
    int j;
    for(i=0;i<4;i++)
    {
            temp[i]=(char*)malloc(32*sizeof(char));
    }
    int k;
    for(k=0;k<10;k++)
    {
            printf("Round %d\n",k+1);
            schedule(word,temp,k);
            for(i=0;i<4;i++)
            {
                    //printf("%s ",temp[i]);
                    for(j=0;j<8;j++)
                        printf("%c",getHexDigit(temp[i][j*4+0],temp[i][j*4+1],temp[i][j*4+2],temp[i][j*4+3]));
                    printf("\n");
                    strcpy(word[i],temp[i]);
            }

    }
    return 0;
}
