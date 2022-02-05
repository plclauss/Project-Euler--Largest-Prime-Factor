# Project Euler: Problem 3 - Largest Prime Factor:

---

***Note:*** *Previously, I included my first thoughts, first solution, and analyzed the algorithm that led to the better solution. This time, I will include my first thoughts; any barriers that affected this solution, and how I plan to work around it; my final solution, along with its time complexity; and my analysis of the algorithmic solution, along with its time complexity.*<br>
***Concerning the time complexity, if I've made an error, please notify me.***

---

## First thoughts:

---

As before, I pulled up a list of the first few thousand prime numbers to see if I could extract a pattern. Just by looking at it for a minute our two, I couldn't seem to find a simple one; though, I'm sure one exists. After not finding a pattern, I searched for the definition of a prime number in hopes of finding that one obscure sentence that would help in finding a pattern. That one obscure sentence did not exist. So, I started thinking.<br>
A prime number is a number only divisible by itself and 1, right? So, no even numbers, no multiples of 10, no...Hmm<br>
I wonder if, after finding all the possible factors, *m*, of a given number, *n*, if I check against every *m* if it's divisible by any number between two and 10, inclusive, then I can discard it as a possible prime number.<br>
I'll try this first. As for finding all the possible factors of *n*...<br>
This one I thought about less, and kind of threw together a solution. Since we're looking for the *largest* possible factor, why don't we start at n-1, decrementing from there until we find a number, *a*, such that `n % a == 0`. Then, we can run it through our function that determines if it's divisible by one of the numbers 2 through 10, inclusive, and if it is, discard it. Otherwise, return that number, and we're done.<br><br>
This is, by far, the most thrown together, first thought solution I've ever committed to, so I imagine there will be plenty workaround. I will update this README accordingly.

## Update on First Thoughts:

---

That didn't work. I ran the example they gave and received a different output than what I should've gotten. My program returned 377, as it's not divisible by any number between 2 and 10, inclusive.
<br><br>
I suppose if I refactor the code such that, if I find a number, *a*, where `n % a == 0`, I can recursively call the same function, decrementing *a'*, checking to see if `a % a' == 0`. Once I get to a number, *a<sup>(x)</sup>*, where *x* is some number greater than 1, that is NOT divisible by any smaller number, I return this number.

## Update 2:

---

The solution in my first update worked, but here's the thing. It didn't just work. It worked *beautifully*....for just the example they provided. I'm guessing that the reason it doesn't work for the input given to me is because of how insanely large the input is. The example input is far less than the capacity that an int can hold. The input they're giving me, however, is in the long long int category. Since I'm decrementing my number by 1, it's taking quite a while. I ran the debugger and sat for a minute or so, and even then, it didn't reach into the if statement that essentially controls whether I receive output. It feels like cheating to just sit there and let it do its thing, so I won't be doing that. For one, that's not very good code. Second, I'm not even sure if it crashes before then. So, on to new endeavors:
<br><br>
I employed, really, the same method, just in reverse. I noticed that, though the numbers are extremely large, the largest prime factor was rather small. Additionally, instead of checking for every number smaller than the original number, *n*, I halted the program when a non-prime factor was returned from the `isPrime()` function. More detail on my final solution (pre-algorithm reveal) below.

## Final solution (Pre-Algorithm):

---

From main, I call `findDivisor(long long n)`, which returns an `int`. The purpose of this function is to find the smallest possible divisor of some number, *n*. Then, this function calls `isPrime(int m)`, which takes that number *n*, now *m*, and checks to see if it's divisible by any number smaller than it (not including 1). If it is, then we know it's not prime. Upon return, `findDivisor(long long n)` will either set the new highest prime factor, or return the previously found prime number. (This definitely contains bugs, though). 
<br><br>
Now to test my time complexity knowledge: I suppose, in the worst case scenario, for the `findDivisor(long long n)` function, the while loop will travel all the way from 2 to *n* (*i.e.,* `O(n)`). The same is true for the `isPrime(int m)` function, since, if the number, *m*, ***is*** prime, the loop will have to go *all* the way from *m-1* to 2. Thus, another `O(n)`.
<br>
The total time complexity would then be: `O(n) + O(n) = 2 * O(n)`, but, since we can ignore constants, the total time complexity of this solution is `O(n)`.

## The Algorithm:

---

As far as I can tell, this algorithm makes use of the Fundamental Theorem of Arithmetic and Euclid's Lemmas. Let's tackle those one by one.
<br>
The Fundamental Theorem of Arithmetic is simple. It states that every integer greater than 1 can be represented uniquely as a product of prime numbers, up to the order of the factors. Let's analyze a few examples:

```asm
Examples:

100 = 2^(2) * 5^(2) = 2 * 2 * 5 * 5 = 100

1200 = 2^(4) * 3 * 5^(2) = 2 * 2 * 2 * 2 * 3 * 5 * 5 = 1200

16 = 4 * 4 = 2^(2) * 2^(2) = 2 * 2 * 2 * 2 = 16
```
I included the last one to show that, even if you start out by dividing some number *n* by a non-prime (composite) number, those composite numbers can be broken down further into prime factors. 
<br>
This is actually the contents of one of Euclid's Lemmas: "Any composite number is measured by some prime number" (*Euclid, Elements Book VII, Proposition 31*). *Proposition 32* of the same book is a derivation of the previous statement, which may also be of use here: "Any number either is prime or is measured by some prime number."
<br><br>
There are a number of other lemmas concerning this theorem and prime numbers, in general, which I encourage you to read. The above information was retrieved from the [Wikipedia on the Fundamental Theorem of Arithmetic](https://en.wikipedia.org/wiki/Fundamental_theorem_of_arithmetic) and the [Wikipedia on Euclid's Theorems, Lemmas, and Algorithms](https://en.wikipedia.org/wiki/Euclid%27s_lemma#:~:text=Euclid's%20lemma%20%E2%80%94%20If%20a%20prime,those%20integers%20a%20and%20b.&text=Euclid's%20Lemma%20shows%20that%20in,elements%20are%20also%20prime%20elements.).
<br>
---
The information provided, though, should be enough, for now, to explore the algorithm a bit further:
<br><br>
**Algorithm, Part I:**
<br>
The algorithm suggests that, given a number *n*, and numbers *k = 2, 3, 4, 5, ...*, if *k* is a factor of *n*, we may divide out all possible *k* from *n* before moving on to the next *k*, just as we did in the examples above. This ensures *k* will be prime, as all other smaller factors of *n* have been removed. <br>(*i.e.,* by dividing 100 by 2 repeatedly, we no longer have to worry about the composite factors 50 and 25, as the number we'd be working with from this point forward will be 25, which will then become irrelevant once *k* = 5 .)
<br><br>
**Algorithm, Part II:**
<br>
The PDF then points out the special case of when *k* = 2. Since 2 is the only even prime, if we divide out *n* by 2 in its own loop/function, the factor *k* in the other loop/function may increase its factor by 2, instead of 1, as we were doing before.
<br><br>
**Algorithm, Part III:**
<br>
Here's where the algorithm became a little tricky to understand, but after a short bit of research, I believe this is the message the PDF was trying to convey:
<br><br>
*"...Every composite number has a prime factor less than or equal to its square root."* - Retrived from a [Math Stack Exchange Q&A](https://math.stackexchange.com/questions/63276/is-a-prime-factor-of-a-number-always-less-than-its-square-root).
<br><br>
The PDF does suggest, however, to start by factoring the even prime, 2, first. After, you may calculate the max limit, which would be the square root of the remaining *n*.
<br>
---
**Time Complexity:**
<br>
If I'm correct, the worst case scenario would produce `O(n)`. This assumes that the `evenPrime()` function (in my implementation) does nothing. (*i.e.,* the number was not even, so as it proceeds to the next function, the maximum number of iterations it must execute is equal to the number, *n*, itself, meaning the original number was prime).<br>
***However,*** if *n* is even and `evenPrime()` does its job, the time complexity would be `O(log(n))`, as we'd effectively be cutting the problem in half over and over.
---
***NOTE: If you notice any mistakes in this analysis, please notify me. This is a learning experience for me, so I'd appreciate anyone bringing any mistakes to my attention.***