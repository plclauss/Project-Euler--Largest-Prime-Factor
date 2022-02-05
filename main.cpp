#include <iostream>

int isPrime(long long p) {
    for (int i = 2; i <= 10; i++) { //See if number is divisible by any number [2,10]
        if ((p % i) == 0) //if yes, not prime
            return -1;
    }
    return 1;
}

int noRemainder(long long n) {
    long long a = n - 1;
    while (a > 1)
    {
        if ((n % a) == 0) { //see if (originalNumber)/(someNumberLessThanOriginalNumber) has a remainder
            int b = isPrime(a); //if yes, see if someNumberLess... is prime
            if (b == 1)
                return a; //if yes, return someNumberLess... it'll be the largest, since decrementing from originalNum
        }
        a--;
    }
    return n;
}

int main() {
    std::cout << noRemainder(13195 ) << std::endl;

    return 0;
}
