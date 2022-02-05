#include <iostream>

int isPrime (int m) {
    int a = m - 1;
    while (a > 1) { //see if number is prime by checking if it's divisible by any number smaller than it that's not 1
        if ((m % a) == 0)
            return -1;
        a--;
    }
    return 1;
}

int findDivisor (long long n) {
    int i = 2, res = 0, ans = 0;
    while (i < n) {
        if ((n % i) == 0) { //finds divisor (with no remainder)
            int res = isPrime(i); //check to see if that divisor is prime
            if (res == 1) //if yes, set new highest prime factor
                ans = i;
            else
                return ans; //otherwise, just return the latest prime number
        }
        i++;
    }
    return ans;
}

int main() {
    std::cout << findDivisor(600851475143) << std::endl;
//    std::cout << findDivisor(13195) << std::endl;

    return 0;
}
