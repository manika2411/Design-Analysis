#include <iostream>
#include <vector>
#include <string>
using namespace std;
void computeLPSArray(string pattern, vector<int>& lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pattern.length()) 
	{
        if (pattern[i] == pattern[length]) 
		{
            length++;
            lps[i] = length;
            i++;
        }
        else 
		{
            if (length != 0) 
			{
                length = lps[length - 1];
            }
            else 
			{
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);
    computeLPSArray(pattern, lps);
    int i = 0; 
    int j = 0; 
    bool found = false;
    while (i < n) 
	{
        if (pattern[j] == text[i]) 
		{
            i++;
            j++;
        }
        if (j == m) 
		{
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) 
		{
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (!found)
        cout << "Pattern not found in the text." << endl;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    KMPSearch(text, pattern);
    return 0;
}
