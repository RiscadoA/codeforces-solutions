#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, p[1000][5], s[5];
    cin >> t;
    for (; t > 0; --t)
    {
        memset(s, 0, sizeof(s));

        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 5; ++j)
            {
                cin >> p[i][j];
                s[j] += p[i][j];
            }

        vector<pair<int, int>> pairs;
        for (int i = 0; i < 5; ++i)
            for (int j = i + 1; j < 5; ++j)
                if (s[i] >= n / 2 && s[j] >= n / 2)
                    pairs.push_back({i, j});

        bool success = false;

        for (auto& pair : pairs)
        {
            success = true;

            for (int i = 0; i < n; ++i)
                if (!p[i][pair.first] && !p[i][pair.second])
                {
                    success = false;
                    break;
                }
            
            if (success)
                break;
        }

        cout << (success ? "YES" : "NO") << endl;
    }

    return 0;
}