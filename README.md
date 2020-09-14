# Tests for ex6 in c++ summer course
## Usage
On your project directory, clone the tests using:
```$xslt
$ git clone https://github.com/yairfine/cpp-tests-ex6.git
```
Copy your `HashMap.hpp` file to the tests directory, using:
```$xslt
WINDOWS:  $ copy .\HashMap.hpp .\cpp-tests-ex6
LINUX:    $ cp HashMap.hpp ./cpp-tests-ex6
```
Move to the tests directory, using:
```$xslt
$ cd cpp-tests-ex6
```
Compile the tests, using:
```$ xslt
$ g++ tests.cpp -o compiledTests
```
Run the tests, using:
```$ xslt
WINDOWS:  $ .\compiledTests.exe
LINUX:    $ ./compiledTests
```
For running with valgrind, use:
```$ xslt
$ valgrind --leak-check=full --track-origins=yes compiledTests
```

## Good luck!
![coding gif](https://media.giphy.com/media/iAKXyzgLVtKsU/giphy.gif)
