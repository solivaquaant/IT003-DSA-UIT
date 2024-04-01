#include <bits/stdc++.h>
using namespace std;
string s;
int sum = 0;
int cnt[10];
int main()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        sum += s[i] - '0';
        cnt[s[i] - '0']++;
    }

    if (sum % 3 == 1)
    {
        if (cnt[1] || cnt[4] || cnt[7])
        {
            if (cnt[1])
                cnt[1]--, sum--;
            else if (cnt[4])
                cnt[4]--, sum -= 4;
            else
                cnt[7]--, sum -= 7;
        }
        else if (cnt[2] >= 2)
            cnt[2] -= 2, sum -= 4;
        else if (cnt[5] >= 2)
            cnt[5] -= 2, sum -= 10;
        else if (cnt[8] >= 2)
            cnt[8] -= 2, sum -= 16;

        else if ((cnt[2] && cnt[5]) || (cnt[8] && cnt[5]) || (cnt[8] && cnt[2]))
        {

            if ((cnt[2] && cnt[5]))
                cnt[2]--, cnt[5]--, sum -= 7;
            else if ((cnt[2] && cnt[8]))
                cnt[2]--, cnt[8]--, sum -= 10;
            else if ((cnt[5] && cnt[8]))
                cnt[5]--, cnt[8]--, sum -= 13;
        }
    }

    else if (sum % 3 == 2)
    {
        if (cnt[2] || cnt[5] || cnt[8])
        {
            if (cnt[2])
                cnt[2]--, sum -= 2;
            else if (cnt[5])
                cnt[5]--, sum -= 5;
            else
                cnt[8]--, sum -= 8;
        }
        else if (cnt[1] >= 2)
            cnt[1] -= 2, sum -= 2;
        else if (cnt[4] >= 2)
            cnt[4] -= 2, sum -= 8;
        else if (cnt[7] >= 2)
            cnt[7] -= 2, sum -= 14;

        else if ((cnt[1] && cnt[4]) || (cnt[1] && cnt[7]) || (cnt[7] && cnt[4]))
        {
            if ((cnt[1] && cnt[4]))
                cnt[1]--, cnt[4]--, sum -= 5;
            else if ((cnt[1] && cnt[7]))
                cnt[1]--, cnt[7]--, sum -= 8;
            else if ((cnt[4] && cnt[7]))
                cnt[4]--, cnt[7]--, sum -= 11;
        }
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = cnt[i]; j > 0; j--)
            cout << i;
    }
    return 0;
}