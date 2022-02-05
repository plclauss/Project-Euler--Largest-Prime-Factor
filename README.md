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
