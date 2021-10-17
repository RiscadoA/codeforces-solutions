#include <bits/stdc++.h>

using namespace std;

bool isComposite(int n)
{
    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0)
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, a[100];

    cin >> t;
    for (; t > 0; --t)
    {
        int evenCount = 0;
        int sum = 0;

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                evenCount += 1;
            sum += a[i];
        }

        if ((n - evenCount) % 2 == 0 || isComposite(sum))
        {
            cout << n << endl;
            for (int i = 0; i < n; ++i)
                cout << (i + 1) << ' ';
            cout << endl;
        }
        else
        {
            for (int i = 0; i < n; ++i)
                if (isComposite(sum - a[i]))
                {
                    cout << (n - 1) << endl;
                    for (int j = 0; j < i; ++j)
                        cout << (j + 1) << ' ';
                    for (int j = i + 1; j < n; ++j)
                        cout << (j + 1) << ' ';
                    cout << endl;
                    break;
                }
        }
        
    }

    return 0;
}