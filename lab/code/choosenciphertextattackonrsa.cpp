#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
        for (int i = 2; i * i <= a; ++i) {
                if (a % i == 0) return false;
        }
        return true;
}

vector<int> getMeTuple(int a) {
        vector<int> primes (2, 0);
        for (int i = 2; i <= a; ++i) {
                if (a % i == 0 && isPrime(i) && isPrime(a / i)) {
                        primes[0] = i;
                        primes[1] = a / i;
                }
        }
        return primes;
}

int fastExpo(int a, int b, int MOD) {
        if (b == 0) return 1;
        int result = fastExpo(a, b >> 1, MOD);
        result = (result * result) % MOD;
        if (b & 1) result = (result * (a % MOD)) % MOD;
        return result;
}

int inverse(int e, int MOD) {
        int result = 0;
        while (true) {
                if ((e * result) % MOD == 1) return result;
                ++result;
        }
        return result;
}

int main() {
        int p, e, n, c;
        cin >> p >> c >> e >> n;
        vector<int> myPQ = getMeTuple(n);
 int d = inverse(e, (myPQ[0] - 1) * (myPQ[1] - 1));
        int decrypted = fastExpo(c, d, n);
        cout << (decrypted == p) << endl;
        cout << decrypted << endl;
        return 0;
}
