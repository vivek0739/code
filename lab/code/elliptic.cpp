#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int a = 2;
const int b = 3;
const int mod = 67;
pair<int, int> e1;
const int d = 4;
int cffs, cffb;
void calcInverse(int a, int b) {
        int newa = b;
        int newb = a % b;
        if(newa % newb == 0) {
                cffs = (a / b) * (-1);
                cffb = 1;
                //cout << cffb << " " << cffs << endl;
                return;
        }
        calcInverse(b, a % b);
        int store = cffs;
        cffs = cffb - (a / b) * (cffs);
        cffb = store;
        //cout << cffb << " " << cffs << endl;

}
int getModVal(int a) {
        a = a % mod;
        if(a < 0) {
                a += mod;
        }
        return a;
}
pair<int, int> add(pair<int, int> x, pair<int, int> y) {
        pair<int, int> c;
        if(x == y) {
                int slope = getModVal(3 * x.first * x.first + a);
                int divisor = getModVal(2 * x.second);
                calcInverse(mod, divisor);
                divisor = cffs;
                slope = getModVal(divisor * slope);
                c.first = getModVal(getModVal(slope * slope) + getModVal(-2 * x.first));
                c.second = getModVal(getModVal(x.second) + getModVal(slope * getModVal(c.first + getModVal(-x.first))));
                c.second = getModVal(-c.second);
        } else {
                int slope = getModVal(y.second - x.second);
                int divisor = getModVal(y.first - x.first);
                calcInverse(mod, divisor);
                divisor = cffs;
                slope = getModVal(divisor * slope);
                c.first = getModVal(getModVal(slope * slope) + getModVal(-x.first) + getModVal(-y.first));
                c.second = getModVal(getModVal(x.second) + getModVal(slope * getModVal(c.first + getModVal(-x.first))));
                c.second = getModVal(-c.second);
        }
        return c;
}
pair<int, int> mul(pair<int, int> a, int d) {
        int i;
        pair<int, int> ans = a;
        for(i = 0; i < d - 1; i++) {
                ans = add(ans, a);
        }
        return ans;
}
int main() {
        pair<int, int> P;
        cout << "Enter the plaintext to be encrypted ";
        cin >> P.first >> P.second;
        e1.first = 2;
        e1.second = 22;
        pair<int, int> e2 = mul(e1, d);
        int r = 4;
        pair<int, int> C1 = mul(e1, r);
        pair<int, int> C2 = add(P, mul(e2, r));
        cout << "Cipher Text1: " << C1.first << " " << C1.second << endl;
        cout << "Cipher Text2: " << C2.first << " " << C2.second << endl;
        pair<int, int> temp = mul(C1, d);
        temp.second = getModVal(-temp.second);
        pair<int, int> P2 = add(C2, temp);
        cout << "After decryption " << P2.first << " " << P2.second << endl;

        return 0;
}
