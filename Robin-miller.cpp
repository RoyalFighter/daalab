#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

// Function to check whether a number is prime
bool isPrime(long long int n, int k) {
    // Base cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    // Find r such that n - 1 = 2^d * r
    long long int d = n - 1;
    while (d % 2 == 0) d /= 2;

    // Iterate for k times
    for (int i = 0; i < k; i++) {
        long long int a = rand() % (n - 4) + 2; // Random number in [2, n - 2]
        long long int x = (long long int)(pow(a, d)) % n;

        if (x == 1 || x == n - 1) continue;

        // Iterate for r - 1 times
        for (int j = 0; j < d - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) break;
        }

        if (x != n - 1) return false;
    }

    return true;
}

int main() {
    long long int n;
    int k = 4; // Number of iterations

    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n, k))
        cout << n << " is a prime number" << endl;
    else
        cout << n << " is not a prime number" << endl;
}
