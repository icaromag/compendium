#include <util.h>
#include <iostream>

using namespace compendium;
using std::cout;
using std::endl;
int main()
{

    cout << "Util module test unit is running" << endl;
    cout << Util::hello() << endl;

    cout << "Getting a vector with size 15 and numbers between 0 and 1000" << endl;
    std::vector<int> v = Util::vector_with_random_ints(15, 1000);

    for_each(v.begin(), v.end(),
        [&](int number)
        {
            cout << number << ' ';
        }
    );

    cout << endl;

    return 0;

}
