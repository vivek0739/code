#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int p = 9979;
bool isPrimitive(int e) {
        int i;
        int ans = 1;
        for(i = 1; i < p; i++) {
                ans = (ans * e) % p;
                if(ans == 1) {
                        return 0;
                }
        }
        return 1;
}
int powMod(int e1, int d) {
        int e2 = 1;
        while(d) {
                if(d & 1) {
                        e2 = (e2 * e1) % p;
                }
                e1 = (e1 * e1) % p;
                d >>= 1;
        }
}
int main() {
        int P;
        cout << "Enter the plaintext to be encrypted ";
        cin >> P;
        int d = rand() % (p - 2) + 1;
        int i;
        int e1;
        for(e1 = 1; e1 < p; e1++) {
                if(isPrimitive(e1)) {
                        break;
                }
        }
        int e2 = powMod(e1,d) % p;
        int r = rand() % (p - 1) + 1;
        int c1 = powMod(e1,r) % p;
 int c2 = (P*powMod(e2,r)) % p;
        cout << "Encrypted text: C1: " <<c1 << " C2: " << c2 << endl;
        int plaintext = (c2 - d * c1) % p;
        if(plaintext < 0) {
                plaintext += p;
        }
        cout << "Decrypted plaintext: " << plaintext << endl;
        return 0;
}
