#include <iostream>

long long noRemainder(long long n) {
    long long a = n - 1;
    while (a > 1)
    {
        if ((n % a) == 0)
            return noRemainder(a);
        a--;
    }
    return n;
}

int main() {
    std::cout << noRemainder(600851475143) << std::endl;

    return 0;
}
