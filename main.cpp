#include <iostream>
#include <math.h>

//int isPrime (int m) {
//    int a = m - 1;
//    while (a > 1) { //see if number is prime by checking if it's divisible by any number smaller than it that's not 1
//        if ((m % a) == 0)
//            return -1;
//        a--;
//    }
//    return 1;
//}
//
//int findDivisor (long long n) {
//    int i = 2, res = 0, ans = 0;
//    while (i < n) {
//        if ((n % i) == 0) { //finds divisor (with no remainder)
//            int res = isPrime(i); //check to see if that divisor is prime
//            if (res == 1) //if yes, set new highest prime factor
//                ans = i;
//            else
//                return ans; //otherwise, just return the latest prime number
//        }
//        i++;
//    }
//    return ans;
//}

int largestPrime(long long n, int* lf) {
    int factor = 3, maxFactor = sqrt(n);
    while ((n > 1) && (factor <= maxFactor)) { //dividing against n, within bounds of maxFactor
        if ((n % factor) == 0) { //divide out all factor before moving onto next factor
            n /= factor;
            *lf = factor; //update most recent largest factor
            while ((n % factor) == 0)
                n /= factor;
        }
        maxFactor = sqrt(n);
        factor += 2;
    }
    if (n == 1)
        return *lf; //if able to be reduced, return largest factor
    else
        return n; //else, original number was prime
}

int evenPrime(long long n) {
    int lastFactor = 1;

    if ((n % 2) == 0) { //divide by even prime if possible to reduce problem further
        lastFactor = 2;
        n /= 2;
        while ((n % 2) == 0)
            n /= 2;
    }
    return largestPrime(n, &lastFactor);
}

int main() {
    std::cout << evenPrime(600851475143) << std::endl;
//    std::cout << evenPrime(13195) << std::endl;

    return 0;
}
