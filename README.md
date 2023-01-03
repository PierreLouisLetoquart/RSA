---
Author : Pierre-Louis Létoquart (ECE Paris - France)
Title : RSA cipher for integers
---

# RSA Algorithm

This program uses the RSA encryption method to encrypt whole numbers. 
There are no encrypt and decrypter functions as these steps are performed in the main().
The code is not optimized, you are free to improve it or use it by citing the links.


## ALGORITHM:

1. Select two prime numbers p and q
2. Calculate n = p*q  and  phi(n) = (p-1)(q-1)
3. Pick e where 1 < e < phi(n)  and  gcd(e,phi(n)) = 1
4. Compute d = e^-1(mod n) (using extended Euclid's algo)
5. Destroying p and q for security (not implemente)

__Public key PU(e,n)  Private key PR(d,n)__

6. Select int to be encrypted named A
7. Encrypt with public key :  B = A^e (mod n)
8. Decrypt with private key :  C = B^d (mod n)









