Author : Pierre-Louis Létoquart (ECE Paris - France)
Title : RSA cipher for integers

This program uses the RSA encryption method to encrypt whole numbers. 
There are no encrypt and decrypter functions as these steps are performed in the main().
The code is not optimized, you are free to improve it or use it by citing the links.


ALGORITHM:

Select two prime numbers p and q

Calculate n = p*q  and  phi(n) = (p-1)(q-1)

Pick e where 1 < e < phi(n)  and  gcd(e,phi(n)) = 1

Compute d = e^-1(mod n) (using extended Euclid's algo)

Destroying p and q for security (not implemente)

-> Public key PU(e,n)  Private key PR(d,n)

Select int to be encrypted named A

Encrypt with public key :  B = A^e (mod n)

Decrypt with private key :  C = B^d (mod n)









