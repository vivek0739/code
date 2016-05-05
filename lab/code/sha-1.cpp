#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned int uint;
vector<uint> plaintext;
vector<uint> words;
uint H0 = 0x67452301, H1 = 0xefcdab89, H2 = 0x98badcfe, H3 = 10325476, H4 = 0xc3d2e1f0;
uint k;
uint leftShift(uint x, int n) {
        if(n > 32) {
                n %= 32;
        }
        uint y = (x << n) | (x >> (32 - n));
        return y;
}
void createWords() {
        int i;
        for(i = 0; i < plaintext.size(); i++) {
                words.push_back(plaintext[i]);
        }
        for(i = 16; i < 80; i++) {
                uint wordT = leftShift(words[i - 3] ^ words[i - 8] ^ words[i - 14] ^ words[i - 16], 1);
                words.push_back(wordT);
        }
}
uint functionT(uint B, uint C, uint D, int t) {
        if(t < 20) {
                k = 0x5a827999;
                return (B & C) | (~(B) & D);
        } else if(t < 40) {
                k = 0x6ed9eba1;
                return B ^ C ^ D;
        } else if(t < 60) {
                k = 0x8f1bbcdc;
                return (B & C) | (B & D) | (C & D);
        } else {
                k = 0xca6261d6;
                return B ^ C ^ D;
        }
}
void performHash() {
 uint A = H0, B = H1, C = H2, D = H3, E = H4;
        int i;
        for(i = 0; i < 80; i++) {
                uint t = leftShift(A, 5) + functionT(B, C, D, i) + E + words[i] + k;
                E = D;
                D = C;
                C = leftShift(B, 30);
                B = A;
                A = t;
        }
        H0 = H0 + A;
        H1 = H1 + B;
        H2 = H2 + C;
        H3 = H3 + D;
        H4 = H4 + E;
}
uint convertToHex(char ch) {
        if(ch >= '0' && ch <= '9')
                return 0x0 + ch - '0';
        else
                return 0xa + ch - 'a';
}
int main() {
        string str = "aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbcccccccccc";
        int i;
        int length = 0;
        uint t;
        for(i = 0; i < str.size(); i += 8) {
                t = convertToHex(str[i]);
                length += 4;
                int flag = 0;
                if(i + 1 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 1]);
                        length += 4;
                }
                if(i + 2 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 2]);
                        length += 4;
                }
                if(i + 3 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 3]);
                        length += 4;
                }
                if(i + 1 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 1]);
                        length += 4;
                }
                if(i + 2 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 2]);
                        length += 4;
                }
                if(i + 3 < str.size()) {
                        t <<= 4;
                        t |= convertToHex(str[i + 3]);
                        length += 4;
                }
                if(flag)
                        plaintext.push_back(t);
        }
        int size = length;
        if(length < 448) {
                if(length % 32 == 8) {
                        t <<= 24;
                        t |= (1 << 24);
                        length += 24;
                        plaintext.push_back(t);
                } else if(length % 32 == 16) {
                        t <<= 16;
                        t |= (1 << 16);
                        length += 16;
                        plaintext.push_back(t);
                } else if(length % 32 == 24) {
                        t <<= 8;
                        t |= (1 << 8);
                        length += 8;
                        plaintext.push_back(t);
                }
        }
        for(; length < 448; length += 4) {
                plaintext.push_back(0);
        }
        plaintext.push_back(0);
        plaintext.push_back(size);
        // for(i = 0; i < plaintext.size(); i++) {
        //         cout << hex << plaintext[i] << endl;
        // }
        createWords();
        performHash();
        cout << "The hashed value is ";
        cout << hex << H0 << H1 << H2 << H3 << H4 << endl;
        return 0;
}
