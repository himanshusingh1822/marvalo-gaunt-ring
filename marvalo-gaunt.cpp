#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p, q, r;
    cin >> p >> q >> r;

    int suffix_max[n];
    suffix_max[n - 1] = r * arr[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        suffix_max[j] = max(r * arr[j], suffix_max[j + 1]);
    }

    int ans = INT_MIN;
    int maxm = p * arr[0];
    for (int i = 1; i < n - 1; i++) {
        maxm = max(maxm, p * arr[i]);
        ans = max(ans, maxm + q * arr[i] + suffix_max[i + 1]);
    }

    cout << "Maximum sum is: " << ans << endl;

    return 0;
}
