/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires Lustosa
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file mathematics.h
 *   \author Ícaro Magalhães <icaro.lmag@gmail.com>
 *   \author Mateus Pires <mateusplpl@gmail.com>
 *   \date 11/05/2016
 *
 ***************************************************************************/

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <string.h>

namespace compendium
{

    #define cls(arr) memset(arr, 0, sizeof *arr);
    /**
     * \brief This class helps other classes offering mathematics algorithms
     */
    class Mathematics
    {

    public:

        /**
         * \brief return base powered to expoent
         * \param const_int base
         * \param const_int exponent
         * \return integer
         */
        static long power(const int b, const int e);

        /**
         * \brief return base powered to expoent dynamically
         * \param const_int base
         * \param const_int exponent
         * \return integer
         */
        static long *dynamic_power(const int b, const int e);

        template<typename T>
        static void swap(T *f, T *s)
        {
            *f = *f ^ *s;
            *s = *f ^ *s;
            *f = *f ^ *s;
        }

        /**
         * \brief Calculate factorial of a number
         * \param const_uint number to get factorial
         * \return const_ulong number factorial
         */
        static ulong factorial(const uint n);

        /**
         * \brief Calculate factorial of a number dynamically
         * \param const_uint number to get factorial
         * \return const_ulong number factorial
         */
        static unsigned long long *dynamic_factorial(const int n);

        /**
         * \brief Calculate arithmetic progression sum
         * \param first
         * \param ratio
         * \param quantity
         * \return long with AP sum
         */
        static long arithmetic_progression_sum(int initial, int ratio, int quantity);

        /**
         * \brief Calculate geometric progression sum
         * \param first
         * \param ratio
         * \param quantity
         * \return long with GP sum
         */
        static long geometric_progression_sum(int initial, int ratio, int quantity);

        /**
         * \brief Returns array with fibonacci numbers calculated dynamically
         * \param quantity of fibonacci numbers
         * \return unsigned int array with fibonacci numbers
         */
        static uint *dynamic_fibonacci(const uint n);

        /**
         * \brief In combinatorial mathematics, the Catalan numbers form a sequence
         *      of natural numbers that occur in various counting problems,
         *      often involving recursively-defined objects
         * \param quantity of catalan numbers
         * \return unsigned int array with catalan numbers
         */
        static uint *dynamic_catalan_numbers(const uint n);

        /**
         * \brief converts number from base 10 to another base
         * \param integer number
         * \param integer base
         * \return char* with number in requested base
         */
        static char *convert_num_to_base(int n, const uint b);

        /**
         * \brief Create a sierve of eratosthenes to fast prime retrieval
         * \param const_int n
         * \param vector<int> vector to store sierve
         * \return int* with the primes
         */
        static int *eratosthenes_sieve(const int n, std::vector<int> &v);

        /**
         * \brief decompose number in it's prime factors
         *      and fill the map with it
         * \param int_n = number to decompose
         * \return int number of prime factors
         */
        static int prime_factors(int n, std::map<int, int> &prime_factors);

        /**
         * \brief Calculate multiplicative_inverse from a number mod another
         * \param int_num number to calculate the multiplicative inverse
         * \param int_mod modulus
         * \return integer quantity of prime factors
         */
        static int inverse_multiplication(int num, int mod);

        /**
         * \brief Calculate number of divisors using the prime factors
         * \param map prime_factors
         * \return integer quantity of divisors
         */
        static int quantity_of_divisors(std::map<int, int> &prime_factors);

        /**
         * \brief Supeeds up exponentiation
         * \param int base
         * \param int exponent
         * \param int modulus
         * \return integer base to exponent modulus mod
         */
        static int fast_exponentiation(int b, int e, int mod);

        /**
         * \brief This number is prime?
         * \param int number
         * \return bool is it prime?
         */
        static bool is_prime(int n);

        /**
         * \brief Calculate the greatest common divisor between two numbers
         * \param int first_number
         * \param int second_number
         * \return the greatest common divisor between these two numbers
         */
        static int greatest_common_divisor(int a, int b);

        /**
         * \brief Calculate the lowest common divisor between two numbers
         * \param int first_number
         * \param int second_number
         * \return int lowest common divisor between these two numbers
         */
        static int lowest_common_divisor(int a, int b);

    };

}

#endif // MATHEMATICS_H
