/**
 * Solution with complexity o(n)
 */

#include <bits/stdc++.h>

using namespace std;

struct Window
{
    int start = -1;
    int end = -1;
    int count = 0;
};

Window arr[2000];

int reversed_position_within_window(int pos, Window window)
{
    return window.end - (pos - window.start);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    string input, ans;
    cin >> input;
    ans.assign(input.size(), ' ');

    stack<int> stc;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ')')
            stc.pop();

        arr[i].count = stc.size();
        arr[i].start = !stc.empty() ? stc.top() : -1;

        if (input[i] == '(')
            stc.push(i);
    }
    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (input[i] == '(')
            stc.pop();

        arr[i].end = !stc.empty() ? stc.top() : -1;

        if (input[i] == ')')
            stc.push(i);
    }

    // for (int i = 0; i < input.size(); i++)
    // {
    //     printf("%d: %d %d %d\n", i, arr[i].count, arr[i].start, arr[i].end);
    // }

    int shift = 0, pos;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ')' && arr[i].count % 2 == 1 && i - 1 >= 0 && input[i - 1] != '(')
        {
            int last_shift = reversed_position_within_window(i - 1, arr[i]) - (arr[i - 1].start + 1);
            shift -= last_shift;
        }

        if (arr[i].count % 2 == 0)
            pos = shift + i;
        else
            pos = shift + reversed_position_within_window(i, arr[i]);

        ans[pos] = input[i];

        if (input[i] == '(' && arr[i].count % 2 == 1 && i + 1 < input.size() && input[i + 1] != ')')
        {
            int curr_shift = reversed_position_within_window(arr[i + 1].end - 1, arr[i]) - (i + 1);
            shift += curr_shift;
        }

        // printf("%d: %c -> %d - (%d)\n", i, input[i], pos, shift);
    }

    printf("%s\n", ans.c_str());

    return 0;
}