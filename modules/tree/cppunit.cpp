#include <tree.h>
#include <iostream>

using namespace compendium;

int main()
{

    BTree<int> *integer_btree = new BTree<int>({1,2,3,5,7,4});

    std::cout << "Integer BTree contains " << 10 << "? :"
        << (((*integer_btree).search(10)) ? " True\n" : " False\n");

    integer_btree->insert(10);

    std::cout << "Integer BTree contains " << 10 << "? :"
        << (((*integer_btree).search(10)) ? " True\n" : " False\n");

    // char_btree->btree_transversal(BTreeTransversal::PREFIX, true);
    // char_btree->btree_transversal(BTreeTransversal::INFIX, true);
    // char_btree->btree_transversal(BTreeTransversal::POSTFIX, true);

    return 0;

}
