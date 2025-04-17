#include <iostream>
#include <string>
using namespace std;

bool isSimilar(string a, string b) {
    if (a == b) return true;

    int n = a.length();
    for (int i = 0; i < n - 1; ++i) {
        swap(a[i], a[i+1]);
        if (a == b) return true;
        swap(a[i], a[i+1]); // Swap back to original
    }
    return false;
}

int countSimilarSubstrings(string key, string text) {
    int keyLen = key.length(), textLen = text.length();
    int count = 0;

    for (int i = 0; i <= textLen - keyLen; ++i) {
        string sub = text.substr(i, keyLen);
        if (isSimilar(sub, key)) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << countSimilarSubstrings("moon", "monomon") << endl;  // Output: 2
    cout << countSimilarSubstrings("aaa", "aaaa") << endl;      // Output: 2
    cout << countSimilarSubstrings("xxy", "zxxyxyx") << endl;   // Output: 3
    return 0;
}
