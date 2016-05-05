#include<bits/stdc++.h>
using namespace std;
int IP[] = {58, 50, 42, 34,26, 18, 10, 2,
                60, 52, 44, 36, 28, 20, 12, 4,
                62, 54, 46, 38, 30, 22, 14, 6,
                64, 56, 48, 40, 32, 24, 16, 8,
                57, 49, 41, 33, 25, 17, 9, 1,
                59, 51, 43, 35, 27, 19, 11, 3,
                61, 53, 45, 37, 29, 21, 13, 5,
                63, 55, 47, 39, 31, 23, 15, 7};
int FP[] = {40, 8, 48, 16, 56, 24, 64, 32,
                39, 7, 47, 15, 55, 23, 63, 31,
                38, 6, 46, 14, 54, 22, 62, 30,
                37, 5, 45, 13, 53, 21, 61, 29,
                36, 4, 44, 12, 52, 20, 60, 28,
                35, 3, 43, 11, 51, 19, 59, 27,
                34, 2, 42, 10, 50, 18, 58, 26,
                33, 1, 41, 9, 49, 17, 57, 25};

int expension[] = { 32, 1, 2, 3, 4, 5,
                    4, 5, 6, 7, 8, 9,
                    8, 9, 10, 11, 12, 13,
                    16, 17, 18, 19, 20, 21,
                    24, 25, 26, 27, 28, 29,
                    28, 29, 31, 31, 32, 1};

int parity[] = {57, 49, 41, 33, 25, 17, 9,
                1, 58, 50, 42, 34, 26, 18,
                10, 2, 59, 51, 43, 35, 27,
                19, 11, 3, 60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7, 62, 54, 46, 38, 30, 22,
                14, 6, 61, 53, 45, 37, 29,
                21, 13, 5, 28, 20, 12, 4};

int cmpress[] = {14, 17, 11, 24, 1, 5,
                3, 28, 15, 6, 21, 10,
                23, 19, 12, 4, 26, 8,
                16, 7, 27, 20, 13, 2,
                41, 52, 31, 37, 47, 55,
                30, 40, 51, 45, 33, 48,
                44, 49, 39, 56, 34, 53,
                46, 42, 50, 36, 29, 32};
int strtperm[] = {16, 7, 20, 21,
                29, 12, 28, 17,
                1, 15, 23, 26,
                5, 18, 31, 10,
                2, 8, 24, 14,
                32, 27, 3, 9,
                19, 13, 30, 6,
                22, 11, 4, 25 };
int s1[][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

int s2[][16] = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
                {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
                {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
                {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};

int s3[][16] = {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
                };
int s4[][16] = {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14} };

int s5[][16] = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
                };

int s6[][16] = {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
        };

int s7[][16] = {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
                };

int s8[][16] = {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
                };

void getIp(char *binr, char *ipr)
{
        int i;
        for(i=0; i<64; i++)
                ipr[i] = binr[IP[i]-1];
}

void getParity(char *ipr, char *party)
{
        int i;
        for(i=0; i<56; i++)
                party[i] = ipr[parity[i]-1];
}

void getLeft(char *party, char *left)
{
        int i;
        for(i=0; i<28; i++)
                left[i] = party[i];
}

void getRight(char *party, char *right)
{
        int i;
        for(i=28; i<56; i++)
                right[i-28] = party[i];
}
void leftShift(char *arr)
{
        int i;
        char ch = arr[0];
        for(i=0; i<27; i++)
        {
                arr[i] = arr[i+1];
        }
        arr[i] = ch;
}

void hexToBin(string str, char binr[])
{
        int i = 0;
        int len = str.size();
        while(i<len)
        {
                int t;
                if(str[i]>='0' && str[i]<='9')
                        t = str[i]-'0';
                if(str[i]=='a' || str[i] == 'A')
                        t = 10;
                if(str[i]=='b' || str[i] == 'B')
                        t = 11;
                if(str[i] == 'c' || str[i] == 'C')
                        t = 12;
                if(str[i]=='d' || str[i] == 'D')
                        t = 13;
                if(str[i] == 'e' || str[i] == 'E')
                        t =14;
                if(str[i] == 'f' || str[i] == 'F')
                        t = 15;
                int k = 3;
                while(k>=0)
                {
                        char ch = '0'+t%2;
                       // cout<<ch;
                        binr[i*4+k] = ch;
                        k--;
                        t = t/2;
                }
                i++;
        }
}
void expensionptr(char str[], char expnr[])
{
        int i;
        for(i=0; i<48; i++)
                expnr[i] = str[expension[i]-1];
}

void xorr(char str[], char ptr[])
{
        int i;
        for(i=0; i<48; i++)
        {
                if(str[i]==ptr[i])
                        str[i] = '0';
                else
                        str[i] = '1';
        }
}
void placeBit(char str[], int num, int t)
{
        int k =3;
        while(k>=0)
        {
                char ch = '0'+num%2;
                str[4*t+k] = ch;
                num = num/2;
                k--;
        }
}

void getRC(char expnr[], int i, int &r, int &c)
{
        r = (expnr[i]-'0')*2+(expnr[i+5]-'0');
        c = (expnr[i+1]-'0')*8+(expnr[i+2]-'0')*4+(expnr[i+3]-'0')*2+(expnr[i+4]-'0');
}

void getStrS(char expnr[], char str[])
{
        int i, j;
        int r, c;
        getRC(expnr, 0, r, c);
        int num, t = 0;
        num = s1[r][c];
        placeBit(str, num, t);

        getRC(expnr, 6, r, c);
        num = s2[r][c];
        t++;
        placeBit(str, num, t);

        t++;
        getRC(expnr, 12, r, c);
        num = s3[r][c];
        placeBit(str, num, t);

        t++;
        getRC(expnr, 18, r, c);
        num = s4[r][c];
        placeBit(str, num, t);
        t++;
        getRC(expnr, 24, r, c);
        num = s5[r][c];
        placeBit(str, num, t);

        t++;
        getRC(expnr, 30, r, c);
        num = s6[r][c];
        placeBit(str, num, t);

        t++;
        getRC(expnr, 36, r, c);
        num = s5[r][c];
        placeBit(str, num, t);

        t++;
        getRC(expnr, 42, r, c);
        num = s6[r][c];
        placeBit(str, num, t);
        t++;

}
void straightD(char str[], char right[])
{
        int i;
        for(i=0; i<32; i++)
                right[i] = str[strtperm[i]-1];
}

void getFP(char str[], char fp[])
{
        int i;
        for(i=0; i<64; i++)
        {
                fp[i] = str[FP[i]-1];
                cout<<fp[i];
        }
}
int main()
{
        char binr[64];
        string str = "123456abcd132536";
        string key = "AABB09182736CCDD";
        int len = str.size();
        int i = 0, k;

        hexToBin(key, binr);

        char ipr[64], party[56];
        getIp(binr, ipr);
        getParity(ipr, party);
//      cout<<party<<endl;
        char left[30], right[30];

        getLeft(party, left);
        getRight(party, right);

        char keyr[17][49];
        i=1;
        while(i<=16)
        {
//              cout<<"Key for "<<i<<endl;
                if(i==1 || i==2 || i==9 || i==16)
                {
                        leftShift(left);
                        leftShift(right);
                }
                else
                {
                        leftShift(left);
                        leftShift(left);
                        leftShift(right);
                        leftShift(right);
                }
                for(k=0; k<48; k++)
                {
                        if(cmpress[k]>27)
                                keyr[i][k] = right[cmpress[k]-28];
                        else
                                keyr[i][k] = left[cmpress[k]];
                }
                i++;
        }
        char bstr[65];
        hexToBin(str, bstr);
        char leftp[33], rightp[33];
        for(i=0; i<32; i++)
                leftp[i] = bstr[i];
        leftp[32] = '\0';
        for(i=0; i<32; i++)
                rightp[i] = bstr[i+32];
        rightp[64] = '\0';
        i = 1;
        while(i<=16)
        {
                char expnr[49], strs[33];
                expensionptr(rightp, expnr);
                xorr(expnr, keyr[i]);
                getStrS(expnr, strs);
                straightD(strs, rightp);
                char temp[33];
                strcpy(temp, rightp);
                temp[32] = '\0';
               strcpy(rightp, leftp);
                rightp[32] = '\0';
                strcpy(leftp, temp);
                leftp[32] = '\0';
                //cout<<leftp<<endl;
                //cout<<rightp<<endl;
                i++;
        }
        char finp[66];
        leftp[32] = '\0';
        rightp[64] = '\0';
        strcpy(finp, left);
        strcat(finp, rightp);
        cout<<finp<<endl;
        char fp[65];
        cout<<"Final Result: ";
        getFP(finp, fp);
        cout<<endl;
        return 0;
}
