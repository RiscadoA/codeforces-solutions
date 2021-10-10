#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int64_t, int> val_to_id;

    int64_t t, n, a[200000];
    int64_t occurrences[200000];
    cin >> t;
    
    for (; t > 0; --t)
    {
        cin >> n;
        
        int64_t sum = 0;
        memset(occurrences, 0, sizeof(occurrences));
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
            if (val_to_id.find(a[i]) == val_to_id.end()) // At most 200000 times, O(N)
                val_to_id.insert({ a[i], val_to_id.size() });
            occurrences[val_to_id[a[i]]] += 1;
        }

        int64_t count = 0;

        for (int i = 0; i < n; ++i)
        {
            occurrences[val_to_id[a[i]]] -= 1;
            int64_t x = 2 * sum - n * a[i];
            if (x % n == 0)
            {
                int64_t y = x / n;
                auto itr = val_to_id.find(y);
                if (itr != val_to_id.end())
                    count += occurrences[itr->second];
            }
        }

        cout << count << endl;
    }

    return 0;
}