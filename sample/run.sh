cd ..
sudo make
sudo make install
cd sample/
g++ -std=c++11 -Wall -Wextra -I /usr/local/include/compendium/core/ -L /usr/local/lib/compendium/core/ -lcompendium sample_hello.cpp -o a.out && ./a.out