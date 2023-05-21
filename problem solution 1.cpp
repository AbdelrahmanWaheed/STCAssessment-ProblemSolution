/**
 * Solution with complexity o(n2)
 */

#include <bits/stdc++.h>

using namespace std;

string s;

void rec(int start, int end, int p)
{
    if (start > end)
    {
        return;
    }

    int i = start, c = 0, first = -1, last = -1;
    while (i <= end)
    {
        if (s[i] == '(' && c++ == 0)
        {
            first = i;
        }
        else if (s[i] == ')' && --c == 0)
        {
            last = i;
            rec(first + 1, last - 1, p + 1);
        }
        i++;
    }

    if (p > 0)
    {
        for (int j = 0; j <= (end - start) / 2; j++)
        {
            swap(s[start + j], s[end - j]);
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> s;
    rec(0, s.size(), 0);
    printf("%s\n", s.c_str());

    return 0;
}