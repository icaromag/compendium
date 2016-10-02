# compendium-lib

## Requirements

- Recommended OS: [Linux Ubuntu 14.04.4 LTS 64-bit](http://releases.ubuntu.com/14.04/)
- You need some packages installed: `g++`, `git`, `doxygen`, `make`
- To generate documentation: `doxygen`, `texlive`, `abntex`, `texlive-latex-extra`, `texlive-lang-portuguese`, `texlive-math-extra`

```sh
    $ sudo apt-get install build-essential git make
    $ sudo apt-get install doxygen texlive abntex texlive-latex-extra texlive-lang-portuguese texlive-math-extra
```

## Environment

- Set some environment variables in your system
- Note: The path `$HOME/Workspace` can be replaced according to your preference

```sh
    $ export COMPENDIUM_PROJECT_PATH=$HOME/Workspace/compendium/
    $ sudo sed "/COMPENDIUM_PROJECT_PATH/ d" -i /etc/profile
    $ sudo sed "\$aCOMPENDIUM_PROJECT_PATH=$COMPENDIUM_PROJECT_PATH" -i /etc/profile
    $ mkdir -p $COMPENDIUM_PROJECT_PATH
```

## Sources

- To get source code, use these commands

```sh
    $ cd $COMPENDIUM_PROJECT_PATH
    $ git clone https://github.com/icaromag/compendium-lib
```

## Installation

- To install

```sh
    $ cd $COMPENDIUM_PROJECT_PATH/compendium-lib/
    $ make
    $ sudo make install
```

## Documentation

- To generate documentation

```sh
    $ cd $COMPENDIUM_PROJECT_PATH/compendium-lib/
    $ make doc
    # open documentation in html format
    $ firefox ./doc/html/index.html
    # open documentation in pdf format
    $ gnome-open ./doc/latex/refman.pdf
```

## Code Example

- To use the shared library, add the following flags to the compiler

```sh
    -I /usr/local/include/compendium/core/ -L /usr/local/lib/compendium/core/ -lcompendium main.cpp -o a.out
```

- Add this header in your `c++` program

```cpp
    #include <compendium.h>
```

## Tests

- To compile and run tests

```sh
    $ cd $COMPENDIUM_PROJECT_PATH/compendium-lib/
    $ make build
    $ make run
```

## Contributors

* Ícaro Lima Magalhães <icaro.lmag@gmail.com>
* Mateus Pires Lustosa <mateusplpl@gmail.com>