#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    string r1, r2;

    cin >> t;

    while (t > 0)
    {
        cin >> n;
        cin.ignore();
        getline(cin, r1);
        getline(cin, r2);

        bool possible = true;
        for (int c = 0; c < n; ++c)
            if (r1[c] == '1' && r2[c] == '1')
            {
                possible = false;
                break;
            }

        cout << (possible ? "YES" : "NO") << endl;
        --t;
    }

    return 0;
}