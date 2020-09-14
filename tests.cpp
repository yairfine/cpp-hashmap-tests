//
// Created by Yuser on 14/09/2020.
//
#include <iostream>
#include "HashMap.hpp"
#include <cassert>
#include <vector>
#include <cmath>

#define KeyT1 std::string
#define ValueT1 int

#define KeyT2 int
#define ValueT2 int

#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define ITERATIONS 10

void testDefaultConstruct()
{
    HashMap<KeyT1, ValueT1> map;

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY);
    assert(map.empty() == true);

    map.insert("a", 1);

    assert(map.getSize() == 1);
    assert(map.getCapacity() == INITIAL_CAPACITY);
    assert(map.empty() == false);


    std::cout << "PASS - testDefaultConstruct" << std::endl;
}

void testAt()
{

}

void testConstruct1()
{
    std::vector<KeyT1> keys = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    std::vector<ValueT1> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    HashMap<KeyT1, ValueT1> map(keys.begin(), keys.end(), values.begin(), values.end());

    assert(map.getSize() == 9);
    assert(map.at("a") == 1);
    assert(map.at("b") == 2);
    assert(map.at("c") == 3);
    assert(map.at("d") == 4);
    assert(map.at("e") == 5);
    assert(map.at("f") == 6);
    assert(map.at("g") == 7);
    assert(map.at("h") == 8);
    assert(map.at("i") == 9);


    std::vector<KeyT1> keys2 = {"a", "b", "c", "d", "e", "f", "g", "a", "b", "h", "i"};
    std::vector<ValueT1> values2 = {1, 2, 3, 4, 5, 6, 7, 100, 200, 8, 9};

    HashMap<KeyT1, ValueT1> map2(keys2.begin(), keys2.end(), values2.begin(), values2.end());

    assert(map.getSize() == 9);
    assert(map2.at("a") == 100);
    assert(map2.at("b") == 200);
    assert(map2.at("c") == 3);
    assert(map2.at("d") == 4);
    assert(map2.at("e") == 5);
    assert(map2.at("f") == 6);
    assert(map2.at("g") == 7);
    assert(map2.at("h") == 8);
    assert(map2.at("i") == 9);

    try
    {
        auto it = keys.begin();
        it++;
        HashMap<KeyT1, ValueT1> map(it, keys.end(), values.begin(), values.end());
        assert(!"Constructor1 should throw an exception if iterators are not at the same length");
    }
    catch (std::exception &e) {}

    try
    {
        auto it = keys.end();
        it--;
        HashMap<KeyT1, ValueT1> map(keys.begin(), it, values.begin(), values.end());
        assert(!"Constructor1 should throw an exception if iterators are not at the same length");
    }
    catch (std::exception &e) {}

    try
    {
        auto it = values.begin();
        it++;
        HashMap<KeyT1, ValueT1> map(keys.begin(), keys.end(), it, values.end());
        assert(!"Constructor1 should throw an exception if iterators are not at the same length");
    }
    catch (std::exception &e) {}

    try
    {
        auto it = values.end();
        it--;
        HashMap<KeyT1, ValueT1> map(keys.begin(), keys.end(), values.begin(), it);
        assert(!"Constructor1 should throw an exception if iterators are not at the same length");
    }
    catch (std::exception &e) {}

    std::cout << "PASS - testConstruct1" << std::endl;
}

void testInsert()
{

}

void testErase()
{

}

void testCapacityAndSizeResizeMap()
{
    HashMap<KeyT2, ValueT2> map;

    int i = 1;

    for (int n = 0; n <= ITERATIONS; n++)
    {
        while (i <= INITIAL_CAPACITY * pow(2, n) * 0.75)
        {
            map.insert(i, i);

            assert(map.getSize() == i);
            assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, n));

            i++;
        }
    }

    i--;

    for (int n = ITERATIONS; n >= 0; n--)
    {
        while (i >= INITIAL_CAPACITY * pow(2, n) * 0.25)
        {
            assert(map.getSize() == i);
            assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, n));

            map.erase(i);
            i--;
        }
    }

    std::cout << "PASS - testCapacityAndSizeResize" << std::endl;
}

void testClear()
{
    HashMap<KeyT2, ValueT2> map;

    // Insert elements to the Hash map

    int i = 1;

    for (int n = 0; n <= ITERATIONS; n++)
    {
        while (i <= INITIAL_CAPACITY * pow(2, n) * 0.75)
        {
            map.insert(i, i);
            i++;
        }
    }
    i--;

    // checking 'clear' methods

    assert(map.getSize() == i);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.clear();

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.insert(1,1);

    // todo make sure this is the appropriate behavior:

    assert(map.getSize() == 1);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.erase(1);

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY);


    std::cout << "PASS - testClear" << std::endl;
}

int main()
{
    std::cout << "~~~~~ Starting tests ~~~~~" << std::endl;

    testDefaultConstruct();
    testConstruct1();
    testCapacityAndSizeResizeMap();
    testClear();


    std::cout << "~~~~~ All tests are PASSED ~~~~~" << std::endl;

    return 0;
}
