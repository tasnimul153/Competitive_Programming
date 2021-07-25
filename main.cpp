#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string nonRepeatingChar(string str) {
    int chars[125] = { 0 };
    for(char ch : str)
        ++chars[ch];
    for(char ch : str) {
        if(chars[ch] == 1)
            return string(1, ch);
    }
    return "-1";
}

string nonRepeatingCharIndex(string str) {

}

string nonRepeatingCharHashmap(string str) {
    unordered_map<char, int> umap;
    for(char ch : str) {
        /* unordered_map doesn't support insertion of repeating key's
           so, we are going to check if the key exist or not.  */
        if(umap.count(ch) == 1) {
            ++umap[ch];
        } else {
            umap.insert(make_pair(ch, 1));
        }
    }

    string result = "-1";
    for(unordered_map<char, int>::iterator it = umap.begin(); it != umap.end(); it++)
        if(it->second == 1)
            result = it->first;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    return 0;
}
