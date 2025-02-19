# Prime_Manifold

- shd add details about the solovay-strassen primality test
  
The Solovay-Strassen primality test is a probabilistic test that determines whether a number is probably prime or composite using the following steps:

1. Pick a random integer 𝑎 such that 1<𝑎<𝑛−1
2. Compute the Jacobi Symbol 𝐽(𝑎,𝑛)
3. Compute (𝑎^(𝑛−1)/2) mod 𝑛
4. If these values don’t match (mod 𝑛), then n is composite.
5. Repeat the test multiple times for accuracy.


   
