/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file sorting.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
     \author Mateus Pires <mateusplpl@gmail.com>
 *   \date 05/06/2016
 *
 ***************************************************************************/

#ifndef SORTING_H
#define SORTING_H

#include <util.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>

namespace compendium
{

    /**
     * \brief Provide generic sorting algorithms
     */
    class Sorting
    {

    public:

        /**
         * \brief aux function that exchage two values based on position
         * \params a vector and two positions from elements that needs
         *      to be exchanged
         */
        template <typename T>
        static void exchange(std::vector<T> &v, const uint i, const uint j)
        {
            T aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }

        /**
         * \brief Insertion Sort, you should know when is a good
         *      choice use it
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void insertionsort(std::vector<T> &v)
        {
            for(uint i = 0; i < v.size(); ++i)
                for(uint j = i; j > 0 && (v[j] < v[j-1]); --j)
                    Sorting::exchange(v, j, j-1);
        }

        /**
         * \brief Selection Sort, you should know when is a good
         *      choice use it
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void selectionsort(std::vector<T> &v)
        {
            uint N = v.size();
            uint min;
            for(uint i = 0; i < N; ++i)
            {
                min = i;
                for(uint j = i+1; j < N; ++j)
                {
                    if(v[j] < v[min])
                        min = j;
                }
                Sorting::exchange(v, i, min);
            }
        }

        /**
         * \brief Shell Sort, you should know when is a good
         *      choice use it. This method uses the sequence
         *      h = 3*h + 1. You should know what it means.
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void shellsort(std::vector<T> &v)
        {
            uint N = v.size();
            uint h = 1;
            while(h < N/3)
            {
                //1, 4, 13, 40, 121, 364, ...
                h = 3 * h + 1;
            }
            while(h >= 1)
            {
                for(uint i = h; i < N; ++i)
                {
                    for(uint j = i; j >= h && (v[j] < v[j-h]); j -= h)
                    {
                        Sorting::exchange(v, j, j-h);
                    }
                }
                h /= 3;
            }
        }

        /**
         * \brief Heap Sort using the std functions from the
         *      algorithm header
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void heapsort(std::vector<T> &v)
        {
            std::make_heap(v.begin(),v.end());
            std::sort_heap(v.begin(),v.end());
        }

        /**
         * \brief Merge Sort, NLogN divide and conquer
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void mergesort(std::vector<T> &v)
        {
            std::vector<T> aux = v;
            Sorting::mergesort(v, 0, v.size()-1, aux);
        }

        template <typename T>
        static void mergesort(std::vector<T> &v, const uint lo, const uint hi,
            std::vector<T> &aux)
        {
            if(hi <= lo) return;
            int mid = lo + (hi - lo)/2;
            Sorting::mergesort(v, lo, mid, aux);
            Sorting::mergesort(v, mid + 1, hi, aux);
            Sorting::merge(v, lo, mid, hi, aux);
        }

        /**
         * \brief performs merge operation for mergesort algorithm
         */
        template <typename T>
        static void merge(std::vector<T> &v, const uint lo, const uint mid,
            const uint hi, std::vector<T> &aux)
        {
            uint i = lo, j = mid+1;
            for(uint  k = lo; k <= hi; ++k)
            {
                aux[k] = v[k];
            }
            for(uint k = lo; k <= hi; ++k)
            {
                if(i > mid)
                {
                    v[k] = aux[j++];
                }
                else if(j > hi)
                {
                    v[k] = aux[i++];
                }
                else if(aux[j] < aux[i])
                {
                    v[k] = aux[j++];
                }
                else
                {
                    v[k] = aux[i++];
                }
            }
        }


        /**
         * \brief Quick Sort, NLogN. Random shuffled vectors
         *      take advantage of this implementation.
         * \params vector<T> with elements to be sorted
         * \return void
         */
        template <typename T>
        static void quicksort(std::vector<T> &v)
        {
            Sorting::quicksort(v, 0, v.size()-1);
        }
        template <typename T>
        static void quicksort(std::vector<T> &v, const uint lo, const uint hi)
        {
            if(hi <= lo) return;
            uint j = partition(v, lo, hi);
            Sorting::quicksort(v, lo, j-1);
            Sorting::quicksort(v, j+1, hi);
        }
        template <typename T>
        static uint partition(std::vector<T> &v, const uint lo, const uint hi)
        {
            uint i = lo, j = hi + 1;
            T pivot = v[lo];
            while(true)
            {
                while(v[++i] < pivot)
                {
                    if(i == hi)
                        break;
                }
                while(pivot < v[--j])
                {
                    if(j == lo)
                        break;
                }
                if(i >= j)
                {
                    break;
                }
                Sorting::exchange(v, i, j);
            }

            Sorting::exchange(v, lo, j);
            return j;

        }


    };

}

#endif // SORTING_H
