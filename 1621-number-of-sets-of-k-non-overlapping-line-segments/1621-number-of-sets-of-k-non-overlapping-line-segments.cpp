class Solution {
public:
    long long mod = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {

        int N = n + k - 1;
        int R = 2 * k;

        vector<long long> fact(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long long numerator = fact[N];

        long long denominator =
            (fact[R] * fact[N - R]) % mod;

        long long inverse =
            power(denominator, mod - 2);

        return (numerator * inverse) % mod;
    }
};