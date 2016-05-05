#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
unsigned long long plaintext = 0x123456abcd132536;
unsigned long long key = 0xaabb091cca90ccdd;
int parityBitDrop[] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

int keyCompression[] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
unsigned long long s[8][4][16] {{{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8}, {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0}, {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }}, {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5}, {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15}, {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}}, {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8}, {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1}, {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7}, {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}}, {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15}, {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9}, {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4}, {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}}, {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9}, {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6}, {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14}, {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}}, {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11}, {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8}, {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6}, {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}}, {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1}, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6}, {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2}, {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}}, {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7}, {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2}, {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8}, {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};
int straight[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

int initial[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

int final[] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};


vector<unsigned long long> keys;

void initialPerm() {
        unsigned long long tempText = 0;
        for(int i = 0; i < 64; i++) {
                tempText = tempText << 1;
                int tempInd = 64 - initial[i];
                if(((1ULL << (tempInd - 1)) & plaintext) > 0) {
                        tempText |= 1;
                }
 }
        plaintext = tempText;
}
void finalPerm(unsigned long long &encryptedText) {
        unsigned long long tempText = 0;
        for(int i = 0; i < 64; i++) {
                tempText = tempText << 1;
                int tempInd = 64 - final[i];
                if(((1ULL << (tempInd - 1)) & encryptedText) > 0) {
                        tempText |= 1;
                }
        }
        encryptedText = tempText;
}
void dropParity() {
        unsigned long long tempKey = 0;
        for(int i = 0; i < 56; i++) {
                tempKey = tempKey << 1;
                int tempInd = 64 - parityBitDrop[i];
                if(((1ULL << (tempInd- 1)) & key) != 0) {
                        tempKey |= 1;
                }
        }
        key = tempKey;
}
unsigned long long keyCompress(unsigned long long key) {
        unsigned long long tempKey = 0;
        for(int i = 0; i < 48; i++) {
                tempKey = tempKey << 1;
                int tempInd = 56 - keyCompression[i];
                if(((1ULL << (tempInd - 1)) & key) != 0) {
                        tempKey |= 1;
                }
        }
        return tempKey;
}
void calcKeys(unsigned long long key, int round) {
        if(round > 16) {
                return;
        }
        unsigned long long bitmask = (1ULL << 28) - 1;
        //cout << hex << bitmask << endl;
        unsigned long long bitmask2 = (1ULL << 28) | (1ULL << 29);
        unsigned long long lower = key & bitmask;
        unsigned long long upper = key >> 28;
        //printf("%x\n%x\n", lower, upper);
        //cout << hex << lower << endl << hex << upper << endl;
        if(round == 1 || round == 2 || round == 9 || round == 16) {

                lower = lower << 1;
                upper = upper << 1;
        } else {
                lower = lower << 2;
                upper = upper << 2;
        }
        if((lower & bitmask2) != 0) {
                lower |= ((lower & bitmask2) >> 28);
                lower &= bitmask;
        }
        if((upper & bitmask2) != 0) {
                upper |= ((upper & bitmask2) >> 28);
                upper &= bitmask;
        }
        //cout <<"hello" <<  hex << lower <<endl << hex << upper << endl;
        unsigned long long newKey = upper << 28 | lower;
        unsigned long long compKey = keyCompress(newKey);
        keys.push_back(compKey);
        //printf("%x\n%x\n", newKey, compKey);
        cout << "For Round "<< dec << round;
        cout << " " << hex << newKey << endl;
        calcKeys(newKey, round + 1);

}
unsigned long long expand(unsigned long long input) {
        int i;
        unsigned long long ans = 0;
        for(i = 0; i < 8; i++) {
                int pos = i * 4;
                int temp = pos - 1;
                int temp2 = pos + 1;
                if(temp < 0) {
                        temp += 32;
                }
                temp = 32 - temp;
                temp2 = 32 - temp2;
                ans = ans << 1;
                if(input & (1ULL << (temp - 1)) > 0) {
                        ans = ans|1;
                }
                for(int j =0; j < 4; j++) {
                        int tempInd = 32 - pos - j;
                        ans = ans << 1;
                        if((1ULL << (tempInd - 1)) & input > 0) {
                                 ans |= 1;
                        }
                }
                ans = ans << 1;
                if(((1ULL << (temp2 - 1)) & input) > 0) {
                        ans |= 1;
                }

        }
        return ans;
}
unsigned long long encrypt(unsigned long long input, int round) {
        unsigned long long bitmask1 = (1ULL << 32) - 1;
        unsigned long long bitmask2 = bitmask1 << 32;
        unsigned long long left = input & bitmask2;
        left = left >> 32;
        unsigned long long right = input & bitmask1;
        unsigned long long expandedRight = expand(right);
        unsigned long long key = keys[round - 1];
        unsigned long long output = expandedRight ^ key;
        unsigned long long bitmask = (1ULL << 6) - 1;
        int i;
        unsigned long long fOutput = 0;
        for(i = 0; i < 8; i++) {
                unsigned long long temp = (input & bitmask);
                int x = ((temp & (1ULL << 5)) >> 4) | (temp & 1);
                int y = (temp & 30);
                fOutput = fOutput << 4;
                fOutput = fOutput | s[i][x][y];
        }
        unsigned long long temp = 0;
        for(i = 0; i < 32; i++) {
                temp = temp << 1;
                int tempInd = 32 - straight[i];
                if((fOutput & (1ULL << (tempInd - 1))) > 0) {
                        temp = temp | 1;
                }
        }
        fOutput = temp;
        if(round == 15) {
                return ((left << 32) | fOutput);
        } else {
        //      cout << "Encryption after round " << round << " ";
                cout <<  hex << ((fOutput << 32) | left);
                cout << endl;
                return encrypt((fOutput << 32) | left, round + 1);
        }
}
int main() {
        string output = "";
        //cout << "Enter the plaintext: ";
        //cin >> plaintext;
        //cout << "Enter the key: ";
        //cin >> key;
        cout << hex << key << endl;
        dropParity();
        cout << hex << key << endl;
        unsigned long long text;
        calcKeys(key, 1);
        initialPerm();
        //cout << "After initial permutation ";
        cout << hex << plaintext << endl;
        unsigned long long cipherText = encrypt(plaintext, 1);
        //cout << "After encryption ";
        cout << hex << cipherText << endl;
        finalPerm(cipherText);
        //cout << "After final permutation ";
        cout << hex << cipherText;
        return 0;
}
