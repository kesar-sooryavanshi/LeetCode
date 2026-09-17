#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Edge case: overflow when dividing INT_MIN by -1
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine sign of the result
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    // Convert to positive long long to avoid overflow with abs(INT_MIN)
    long long n = labs((long long)dividend);
    long long d = labs((long long)divisor);

    long long quotient = 0;

    // Bitwise exponential search subtraction
    while (n >= d) {
        long long temp_d = d;
        long long multiple = 1;

        // Double temp_d while it doesn't exceed n
        while (n >= (temp_d << 1)) {
            temp_d <<= 1;
            multiple <<= 1;
        }

        n -= temp_d;
        quotient += multiple;
    }

    return sign == 1 ? (int)quotient : (int)(-quotient);
}