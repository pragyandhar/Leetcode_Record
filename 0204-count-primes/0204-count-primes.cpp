class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        // Create a Sieve
        vector<bool> sieve(n, true);
        sieve[0] = sieve[1] = false;

        // Counting the primes
        int count = n/2;

        // Sieving loop to remove composite
        for (int i = 3; i*i < n; i += 2) {
            if (sieve[i]) {
                for (int j = i*i; j < n; j += 2*i) {
                    if (sieve[j]) {
                        sieve[j] = false;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};