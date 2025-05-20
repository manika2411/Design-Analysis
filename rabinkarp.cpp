#include <iostream>
#include <string>
using namespace std;

#define d 256       
#define q 101      

void RabinKarpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
    bool found = false;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++) 
	{
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (i = 0; i <= n - m; i++) 
	{
        if (p == t) 
		{
            for (j = 0; j < m; j++) 
			{
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m) 
			{
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }
        if (i < n - m) 
		{
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
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
    RabinKarpSearch(text, pattern);
    return 0;
}
