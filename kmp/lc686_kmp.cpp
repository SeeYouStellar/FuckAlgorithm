#include <bits/stdc++.h>
using namespace std;
int prefix[10010], alpha[10010];
void getPrefixTable(string pattern, int n)
{
    int i = 1, j = 0;
    prefix[0] = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[j])
            prefix[i++] = ++j;
        else
        {
            if (j == 0)
                prefix[i++] = 0;
            else
                j = prefix[j - 1];
        }
    }
    for (int i = n - 1; i >= 1; i--)
        prefix[i] = prefix[i - 1];
    prefix[0] = -1;
}
int kmp(string text, string pattern, int n, int m)
{
    int i = 0, j = 0;
    while (i < m)
    {
        if (j == n)
        {
            return 1;
        }
        if (j == -1)
        {
            j++;
            i++;
        }
        else if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];
        }
    }
    if (i == m && j == n)
        return 1;
    return 0;
}
int repeatedStringMatch(string a, string b)
{
    int n = b.length(), m = a.length();
    string c = a;
    for (char i : a)
        alpha[i] = 1;
    for (char i : b)
        if (!alpha[i])
            return -1;
    int cnt = 1;
    while (m < n)
    {
        a += c;
        m += m;
        cnt++;
    }
    int mostcnt = cnt + 1;
    getPrefixTable(b, n);
    while (!kmp(a, b, n, m) && cnt<=mostcnt)
    {
        a += c;
        cnt++;
        m += m;
    }
    if(cnt>mostcnt) return -1;
    return cnt;
}

int main()
{
    string a = "abc";
    string b = "aabcbabcc";
    cout << repeatedStringMatch(a, b);
    system("pause");
}