#include <mathematics.h>

namespace compendium
{

    long Mathematics::power(const int b, const int e)
    {
        return e == 0 ? 1 : b * power(b, e-1);
    }

    long *Mathematics::dynamic_power(const int b, const int e)
    {
        long *n = new long[e+1];

        n[0] = 1;

        for(int i = 1; i <= e; i++)
            n[i] = b * n[i-1];

        return n;
    }

    ulong Mathematics::factorial(const uint n)
    {
        return n == 0 ? 1 : n * factorial(n-1);
    }

    unsigned long long *Mathematics::dynamic_factorial(const int n)
    {
        unsigned long long *f = new unsigned long long[n+1];

        f[0] = 1;

        for(int i = 1; i <= n; i++)
            f[i] = i * f[i-1];

        return f;
    }

    long Mathematics::arithmetic_progression_sum(int initial, int ratio, int quantity)
    {
        return ((initial + (initial + ratio*(quantity-1)))*quantity) / 2;
    }

    long Mathematics::geometric_progression_sum(int initial, int ratio, int quantity)
    {
        return ratio == 1 ? initial * quantity : initial *  ((1 - power(ratio, quantity) - 1) / (1 - ratio));
    }

    uint *Mathematics::dynamic_fibonacci(const uint n)
    {
        uint *f = new uint[n];

            f[0] = f[1] = 1;

            for(uint i = 2; i < n; i++)
                f[i] = f[i-1] + f[i-2];

            return f;
    }

    uint *Mathematics::dynamic_catalan_numbers(const uint n)
    {
        uint *catalan = new uint[n];
        for(uint i = 0; i < n; i++)
            catalan[i] = Mathematics::factorial(2*i) / (Mathematics::factorial(i+1) * Mathematics::factorial(i));

        return catalan;
    }

    char *Mathematics::convert_num_to_base(int n, const uint b)
    {
        char *num = new char[64];
        uint cont = 64-1, contt;

        do
        {
            num[cont--] = (n % b >= 10 ? 'A' + (n - 10) % b : '0' + n % b);
            n /= b;
        }while(n != 0);

        for(cont = cont + 1, contt = 0; cont < 64; cont++, contt++)
            Mathematics::swap(&num[cont], &num[contt]);

        num[contt] = '\0';

        return num;
    }

    int *Mathematics::eratosthenes_sieve(const int n, std::vector<int> &v)
    {
        int *sieve = new int[n+1];
        memset(sieve, 0, sizeof(int)*(n+1));

        sieve[0] = sieve[1] = 1;
        for(int i = 2; i <= n; i++)
            if(!sieve[i]) {
                for(int j = i * i; j <= n; j += i)
                    sieve[j] = 1;
                v.push_back(i);
            }

        return sieve;
    }

    int Mathematics::inverse_multiplication(int num, int mod)
    {
        int b0 = mod, t, q;
        int x0 = 0, x1 = 1;
        if (mod == 1) return 1;
        while (num > 1) {
            q = num / mod;
            t = mod; mod = num % mod; num = t;
            t = x0; x0 = x1 - q * x0; x1 = t;
        }
        if (x1 < 0) x1 += b0;

        int inv_num = x1;
        return inv_num;
    }

    int Mathematics::prime_factors(int n, std::map<int, int> &prime_factors)
    {
        int q = 0;
        for(int i = 2, sqrt_n = sqrt(n) && n > 1; i <= sqrt_n; i++)
            while(n%i == 0)
            {
                prime_factors[i]++;
                n/=i;
                q++;
            }

        if(n > 1)
        {
            prime_factors[n]++;
            q++;
        }

        return q;
    }

    int Mathematics::quantity_of_divisors(std::map<int, int> &prime_factors)
    {
        int r = 1;
        for(std::map<int, int>::iterator it = prime_factors.begin();
            it != prime_factors.end(); it++) r *= (it->second + 1);
        return r;
    }

    int Mathematics::fast_exponentiation(int b, int e, int mod)
    {
        int ans = 1;

        while(b)
        {
            if(b % 2 == 1) ans = (ans * e) % mod;
            e = (e*e) % mod;
            b = (b/2);
        }

        return ans;
    }

    bool Mathematics::is_prime(int n)
    {
        for(int i = 1, sqrt_n = sqrt(n); i <= sqrt_n; i++)
            if(n%i == 0) return false;
        return true;
    }

    int Mathematics::greatest_common_divisor(int a, int b)
    {
        return b == 0 ? a : greatest_common_divisor(b, a % b);
    }

    int Mathematics::lowest_common_divisor(int a, int b)
    {
        return a * (b / Mathematics::greatest_common_divisor(a, b));
    }


}
