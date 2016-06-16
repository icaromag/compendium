#include <mathematics.h>

namespace compendium
{

    long Mathematics::power(const int b, const int e)
    {
        return e == 0 ? 1 : b * power(b, e-1);
    }

    ulong Mathematics::factorial(const uint n)
    {
        return n == 0 ? 1 : n * factorial(n-1);
    }

    //first, ratio, quantity
    long Mathematics::arithmetic_progression_sum(int initial, int ratio, int quantity)
    {
        return ((initial + (initial + ratio*(quantity-1)))*quantity) / 2;
    }

    //first, ratio, quantity
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
            num[cont--] = (n%b >= 10 ? 'A' + (n-10)%b : '0' + n%b);
            n /= b;

        }while(n != 0);

        for(cont = cont + 1, contt = 0; cont < 64; cont++, contt++)
            Mathematics::swap(&num[cont], &num[contt]);

        num[contt] = '\0';

        return num;
    }

}
