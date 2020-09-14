//
// Created by Yuser on 14/09/2020.
//
#include <iostream>
#include "HashMap.hpp"
#include <cassert>
#include <vector>
#include <cmath>
#include <unordered_map>

#define KeyString std::string
#define KeyInt int
#define ValueInt int


#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define ITERATIONS 12

void testDefaultConstruct()
{
    HashMap<KeyString, ValueInt> map;

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
    std::vector<KeyString> keys = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    std::vector<ValueInt> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    HashMap<KeyString, ValueInt> map(keys.begin(), keys.end(), values.begin(), values.end());

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


    std::vector<KeyString> keys2 = {"a", "b", "c", "d", "e", "f", "g", "a", "b", "h", "i"};
    std::vector<ValueInt> values2 = {1, 2, 3, 4, 5, 6, 7, 100, 200, 8, 9};

    HashMap<KeyString, ValueInt> map2(keys2.begin(), keys2.end(), values2.begin(), values2.end());

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
        HashMap<KeyString, ValueInt> map(it, keys.end(), values.begin(), values.end());
        assert(!" ~~~ Constructor1 should throw an exception if iterators are not at the same "
                "length ~~~ ");
    }
    catch (std::exception &e)
    {
    }

    try
    {
        auto it = keys.end();
        it--;
        HashMap<KeyString, ValueInt> map(keys.begin(), it, values.begin(), values.end());
        assert(!" ~~~ Constructor1 should throw an exception if iterators are not at the same "
                "length ~~~ ");
    }
    catch (std::exception &e)
    {
    }

    try
    {
        auto it = values.begin();
        it++;
        HashMap<KeyString, ValueInt> map(keys.begin(), keys.end(), it, values.end());
        assert(!" ~~~ Constructor1 should throw an exception if iterators are not at the same "
                "length ~~~ ");
    }
    catch (std::exception &e)
    {
    }

    try
    {
        auto it = values.end();
        it--;
        HashMap<KeyString, ValueInt> map(keys.begin(), keys.end(), values.begin(), it);
        assert(!" ~~~ Constructor1 should throw an exception if iterators are not at the same "
                "length ~~~ ");
    }
    catch (std::exception &e)
    {
    }

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
    HashMap<KeyInt, ValueInt> map;

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
    HashMap<KeyInt, ValueInt> map;

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

    map.insert(1, 1);

    // todo make sure this is the appropriate behavior:

    assert(map.getSize() == 1);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.erase(1);

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY);


    std::cout << "PASS - testClear" << std::endl;
}

void testOperatorSubscript()
{
    std::vector<KeyString> keys = {"a", "b", "c"};
    std::vector<ValueInt> values = {1, 2, 3};

    HashMap<KeyString, ValueInt> map(keys.cbegin(), keys.cend(), values.cbegin(), values.cend());

    assert(map.getSize() == 3);

    try
    {

        int a = map["a"];
        assert(a == 1);
        a = 10;
        assert(map["a"] == 1);

        int b = map["b"];
        assert(b == 2);
        b = 20;
        assert(map["b"] == 2);

        int c = map["c"];
        assert(c == 3);
        c = 30;
        assert(map["c"] == 3);

        assert(map.getSize() == 3);

        map["a"] = 111;
        assert(map["a"] == 111);

        map["b"] = 222;
        assert(map["b"] == 222);

        map["c"] = 333;
        assert(map["c"] == 333);

        assert(map.getSize() == 3);

        map["d"] = 444;
        assert(map["d"] == 444);

        assert(map.getSize() == 4);

        map["e"];

        assert(map.getSize() == 5);
    }
    catch (std::exception &e)
    {
        assert(!" ~~~ Operator [] should NOT throw any exception ~~~ ");
    }

    // check operator[] of const version

    const HashMap<KeyString, ValueInt> constMap(keys.cbegin(), keys.cend(),
                                                values.cbegin(), values.cend());

    assert(constMap.getSize() == 3);

    try
    {
        int aa = constMap["a"];
        assert(aa == 1);
        aa = 10;
        assert(constMap["a"] == 1);

        int bb = constMap["b"];
        assert(bb == 2);

        int cc = constMap["c"];
        assert(cc == 3);

        assert(constMap.getSize() == 3);

        int dd = constMap["d"]; // should be an undefined behavior
    }
    catch (std::exception &e)
    {
        assert(!" ~~~ Operator [] should NOT throw any exception ~~~ ");
    }


    std::cout << "PASS - testOperatorSubscript" << std::endl;
}

void testOperatorEqualsAndNotEquals()
{
    HashMap<KeyInt, ValueInt> mapEmpty1;
    HashMap<KeyInt, ValueInt> mapEmpty2;

    std::vector<KeyString> keysString = {"1", "2", "3"};
    std::vector<ValueInt> values = {1, 2, 3};

    HashMap<KeyString, ValueInt> mapString1(keysString.cbegin(), keysString.cend(),
                                      values.cbegin(), values.cend());
    HashMap<KeyString, ValueInt> mapString2(keysString.cbegin(), keysString.cend(),
                                      values.cbegin(), values.cend());

    assert(mapEmpty1 == mapEmpty2);
    assert(!(mapEmpty1 != mapEmpty2));

    assert(mapString1 == mapString2);
    assert(!(mapString1 != mapString2));

    mapString1["4"];

    assert(mapString1 != mapString2);
    assert(!(mapString1 == mapString2));

    mapString1["4"] = 4;
    mapString2.insert("4", 4);

    assert(mapString1 == mapString2);
    assert(!(mapString1 != mapString2));

    mapString1.clear();
    mapString2.clear();

    assert(mapString1 == mapString2);
    assert(!(mapString1 != mapString2));

    HashMap<KeyInt, ValueInt> map;

    int i = 1;
    for (int n = 0; n <= ITERATIONS; n++)
    {
        while (i <= INITIAL_CAPACITY * pow(2, n) * 0.75)
        {
            map.insert(i, i);
            i++;
        }
    }

    map.clear();

    assert(map != mapEmpty1);
    assert(!(map == mapEmpty1));


    std::cout << "PASS - testOperatorEqualsAndNotEquals" << std::endl;
}

int main()
{
    std::cout << "~~~~~ Starting tests ~~~~~" << std::endl;

    testDefaultConstruct();
    testConstruct1();
    testCapacityAndSizeResizeMap();
    testClear();
    testOperatorSubscript();
    testOperatorEqualsAndNotEquals();

    std::cout << "~~~~~ All tests are PASSED ~~~~~" << std::endl;

    return 0;
}
