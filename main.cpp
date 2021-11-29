#include <iostream>
#include <math.h>

typedef double pq_array[2];
typedef double keypair[2][2];

/// util func
int gcd(int _a, int _b);
bool isPrime(int _n);
bool relativelyPrime (int _a, int _b);
int modInverse(int _e, int _phiN);
int pow_modulo(int _a, int _b, int _c);
/// gen p and q
pq_array const& genPrime();
/// gen public key and private key
keypair const& genrsa(double _p,double _q);

/// MAIN
int main()
{
    pq_array const& pq = genPrime();
    keypair const& mykeys = genrsa(pq[0],pq[1]);
    std::cout << std::endl;
    std::cout << std::endl;

    int plaintext;
    std::cout << "  Enter an int to encrypt it : ";
    std::cin >> plaintext;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "  Plaintext  : " << plaintext << std::endl;
    std::cout << std::endl;

    //encrypt
    int encrypt = pow_modulo(plaintext, int(mykeys[0][0]), int(mykeys[0][1]));
    std::cout << "  Cyphertext : " << encrypt << std::endl;
    std::cout << std::endl;

    //decrypt
    int decrypt = pow_modulo(encrypt, int(mykeys[1][0]), int(mykeys[1][1]));
    std::cout << "  Decrypted  : " << decrypt << std::endl;
}

/// FUNCTIONS IMPLEMENTATION ///
/// ======================== ///

/// UTIL FUNC
///BEGIN
int gcd(int _a, int _b)
{
    int tmp;
    while (1)
    {
        tmp = _a%_b;
        if (tmp == 0)
          return _b;
        _a = _b;
        _b = tmp;
    }
}

bool isPrime(int _n)
{
    if (_n <= 1)
        return false;

    for (int i = 2; i < _n; i++)
        if (_n % i == 0)
            return false;

    return true;
}

bool relativelyPrime (int _a, int _b)
{
    if(_a==1)
        return false;
    for ( ; ; )
    {
        if (!(_a %= _b)) return _b == 1 ;
        if (!(_b %= _a)) return _a == 1 ;
    }
}

int modInverse(int _e, int _phiN)
{
    for (int x = 1; x < _phiN; x++)
        if (((_e%_phiN) * (x%_phiN)) % _phiN == 1)
            return x;

    return 0;
}

int pow_modulo(int _a, int _b, int _c)
{
    long long x=1;
    long long y=_a;
    while(_b > 0)
        {
        if((_b % 2) == 1){
            x=(x*y)%_c;
        }
        y = (y*y)%_c;
        _b = _b / 2;
    }
    return (int) x%_c;
}
///END

///=== GENERATE P AND Q ===///
///=== BEGIN ===///
pq_array const& genPrime()
{
    static double return_table[2];
    double p, q;
    while(!isPrime(p))
    {
        system("cls");
        std::cout << std::endl;
        std::cout << "  PRIME NUMBER" << std::endl;
        std::cout << "  ENTER P : ";
        std::cin >> p;
    }
    return_table[0] = p;
    while(!isPrime(q) || p==q)
    {
        system("cls");
        std::cout << std::endl;
        std::cout << "  PRIME NUMBER" << std::endl;
        std::cout << "  ENTER Q : ";
        std::cin >> q;
    }

    return_table[1] = q;
    system("cls");
    return return_table;
}
///=== END ===///

///=== GENERATE PRIVATE AND PUBLIC KEY PR(d,n) PU(e,n) ===///
///=== BEGIN ===///
keypair const& genrsa(double _p, double _q)
{
    static double return_matrix[2][2];
    double p(_p), q(_q), n, phiN, e, d;
    // generate n and phi(n)
    n = p*q;
    phiN = (p - 1)*(q - 1);

    while(!relativelyPrime(e,phiN))
    {
        system("cls");
        std::cout << std::endl;
        std::cout << "  RELATIVELY PRIME" << std::endl;
        std::cout << "  ENTER e : ";
        std::cin >> e;
    }

    // d = e^-1 mod phi(n) // je n'y arrive pas :|
    d = modInverse(int(e), int(phiN));

    // pu(e,n) pr(d,n)
    system("cls");
    std::cout << std::endl;
    std::cout << "  PU(" << e << "," << n << ") , PR(" << d << "," << n << ")" << std::endl;
    return_matrix[0][0]=e;
    return_matrix[0][1]=n;
    return_matrix[1][0]=d;
    return_matrix[1][1]=n;

    return return_matrix;
}
///=== END ===///
