/*
 *
 * First ../sudo make install
 *
 * This sample file shows how to use the shared library compendium.so
 *
 * To compile use:
 *
 * g++ -std=c++11 -Wall -Wextra -I /usr/local/include/compendium/core/ -L /usr/local/lib/compendium/core/ -lcompendium sample_hello.cpp -o a.out && ./a.out
 *
 * OR JUST RUN     $ bash run.sh     INSIDE THIS FOLDER
 *
 */

#include <compendium.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tree.h> /* just module binary-tree.h */

/* optional namespace compendium */
using namespace compendium;
using std::cout;
using std::endl;
using std::vector;
using std::for_each;

int main()
{

    // Init and sort vector sample
    std::vector<int> v = Util::vector_with_random_ints(10,100);

    Util::print_vector(v, '-');
    Sorting::mergesort(v);

    // use util alongside with std libs
    cout << "after sorting:" << endl;
    for_each(std::begin(v), std::end(v), [](int n)
    {
        cout << n << '-';
    });

    cout << endl;

    // Binary search tree sample
    cout << "creating this vector binary-tree:" << endl;
    BTree<int> *integer_btree = new BTree<int>(v);

    std::cout << "Integer BTree contains " << 10 << "? :"
        << (((*integer_btree).search(10)) ? " True\n" : " False\n");

    integer_btree->insert(10);

    std::cout << "Integer BTree contains " << 10 << "? :"
        << (((*integer_btree).search(10)) ? " True\n" : " False\n");

    return 0;

}
