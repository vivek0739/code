#include <iostream>
using namespace std;
char encryptionMatrix[5][5] = {{'L', 'G', 'D', 'B', 'A'}, {'Q', 'M', 'H', 'E', 'C'}, {'U', 'R', 'N', 'I', 'F'}, {'X', 'V', 'S', 'O', 'K'}, {'Z', 'Y', 'W', 'T', 'P'}};
pair<int, int> findPos(char ch) {
        int i, j;
        pair<int, int> pos;
        for(i = 0; i < 5; i++) {
                for(j = 0; j < 5; j++) {
                        if(ch == encryptionMatrix[i][j]) {
                                pos.first = i;
                                pos.second = j;
                                return pos;
                        }
                }
        }
}
int main() {
        string str, output = "";
        cin >> str;
        for(int i = 0; i < str.size(); i += 2) {
                char first, second;
                first = str[i];
                second = str[i + 1];
                if(first == 'J') {
                        first = 'I';
                }
                if(second == 'J') {
                        second = 'I';
                }
                if(i + 1 == str.size() || first == second) {
                        second = 'X';
                        i--;
                }
                pair<int, int> firstPos = findPos(first), secondPos = findPos(second);
                char encrFirst, encrSecond;
                if(firstPos.first == secondPos.first) {
                        encrFirst = encryptionMatrix[firstPos.first][(firstPos.second + 1) % 5];
                        encrSecond = encryptionMatrix[secondPos.first][(secondPos.second + 1) % 5];
                } else if(firstPos.second == secondPos.second) {
                        encrFirst = encryptionMatrix[(firstPos.first + 1) % 5][firstPos.second];
                        encrSecond = encryptionMatrix[(secondPos.first + 1) % 5][secondPos.second];
                } else {
                        encrFirst = encryptionMatrix[firstPos.first][secondPos.second];
                        encrSecond = encryptionMatrix[secondPos.first][firstPos.second];
                }
                output.push_back(encrFirst);
                output.push_back(encrSecond);
        }
        cout << output<<endl;
        return 0;
}
