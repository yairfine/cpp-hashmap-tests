//
// Created by Yair on 14/09/2020.
//

#include "HashMap.hpp"
#include "ProgressBar.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <unordered_map>

#define KeyString std::string
#define KeyInt int
#define ValueInt int


#define INITIAL_CAPACITY 16
#define INITIAL_SIZE 0

#define ITERATIONS 16


void testDefaultConstruct();
void testAt();
void testConstruct1();
void testInsert();
void testErase();
void testCapacityAndSizeResizeMap();
void testClear();
void testOperatorSubscript();
void testOperatorSubscriptConst();
void testOperatorEqualsAndNotEquals();
void testIteratorsEmpty();
void testIterators1();
void testIterators2();
void testIterators3();
void testIterators4();

ProgressBar myProgressBar(78);

int main()
{
    std::cout << "~~~~~~ Starting tests ~~~~~~" << std::endl << std::endl;

    
    testDefaultConstruct();
    testAt();
    testConstruct1();
    testInsert();
    testErase();
    testCapacityAndSizeResizeMap();
    testClear();
    testOperatorSubscript();
    testOperatorSubscriptConst();
    testOperatorEqualsAndNotEquals();
    // testIteratorsEmpty();
    // testIterators1();
    // testIterators2();
    // testIterators3();
    // testIterators4();

    myProgressBar.printOutputMsg(std::cout);
    
    
    std::cout << std::endl << "~~~~~~ All tests were PASSED ~~~~~~" << std::endl;

    return 0;
}

void testDefaultConstruct()
{
    HashMap<KeyString, ValueInt> map;

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY);
    assert(map.empty() == true);


    myProgressBar.addToOutputMsg("PASS - testDefaultConstruct\n");
    myProgressBar++;
}

void testAt()
{
    std::vector<KeyString> keys = {"a", "b", "c", "d", "e"};
    std::vector<ValueInt> values = {1, 2, 3, 4, 5};

    HashMap<KeyString, ValueInt> map(keys.begin(), keys.end(), values.begin(), values.end());

    assert(map.at("a") == 1);
    assert(map.at("b") == 2);
    assert(map.at("c") == 3);
    assert(map.at("d") == 4);
    assert(map.at("e") == 5);

    map.at("a") = 100;
    assert(map.at("a") == 100);
    assert (map.getSize() == 5);

    try
    {
        map.at("f") = 6;
        assert(!" ~~~ function '.at' should not allow search for a non-existent key ~~~ ");
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        map.at("f");
        assert(!" ~~~ function '.at' should not allow search for a non-existent key ~~~ ");
    }
    catch (const std::exception &e)
    {
    }

    assert (map.getSize() == 5);


    myProgressBar.addToOutputMsg("PASS - testAt\n");
    myProgressBar++;
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

    
    myProgressBar.addToOutputMsg("PASS - testConstruct1\n");
    myProgressBar++;
}

void testInsert()
{
    HashMap<KeyString, ValueInt> map;
    
    assert(map.empty() == true);  
    assert(map.getCapacity() == INITIAL_CAPACITY);

    bool b = map.insert("a", 10);
    assert(b == true);
    assert(map.getSize() == 1);
    assert(map.empty() == false);

    b = map.insert("a", 100);
    assert(b == false);
    assert(map.getSize() == 1);
    assert(map.empty() == false);

    b = map.insert("a", 10);
    assert(b == false);
    assert(map.getSize() == 1);
    assert(map.empty() == false);

    
    myProgressBar.addToOutputMsg("PASS - testInsert\n");
    myProgressBar++;
}

void testErase()
{
    std::vector<KeyInt> keysInt = {0, 1, 2, 3, 4, 5, 6, 15};
    std::vector<ValueInt> values = {0, 1, 2, 3, 4, 5, 6, 15};

    HashMap<KeyInt, ValueInt> map(keysInt.cbegin(), keysInt.cend(),
                                  values.cbegin(), values.cend());

    bool b = map.erase(0);
    assert(b == true);
    assert(map.getSize() == 7);

    b = map.erase(4);
    assert(b == true);
    assert(map.getSize() == 6);

    b = map.erase(10);
    assert(b == false);
    assert(map.getSize() == 6);


    myProgressBar.addToOutputMsg("PASS - testErase\n");
    myProgressBar++;
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
        
        myProgressBar++;
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

        myProgressBar++;
    }


    myProgressBar.addToOutputMsg("PASS - testCapacityAndSizeResize\n");
    myProgressBar++;
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
        
        myProgressBar ++;
    }
    i--;

    // checking 'clear' methods

    assert(map.getSize() == i);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.clear();

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.insert(1, 1);

    // checking capacity resizing rules

    assert(map.getSize() == 1);
    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));

    map.erase(1);

    assert(map.getSize() == INITIAL_SIZE);
    assert(map.getCapacity() == INITIAL_CAPACITY);

    
    myProgressBar.addToOutputMsg("PASS - testClear\n");
    myProgressBar++;
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


    myProgressBar.addToOutputMsg("PASS - testOperatorSubscript\n");
    myProgressBar++;
}

void testOperatorSubscriptConst()
{
    std::vector<KeyString> keys = {"a", "b", "c"};
    std::vector<ValueInt> values = {1, 2, 3};

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


    myProgressBar.addToOutputMsg("PASS - testOperatorSubscriptConst\n");
    myProgressBar++;
}

void testOperatorEqualsAndNotEquals()
{
    HashMap<KeyInt, ValueInt> emptyMap1;
    HashMap<KeyInt, ValueInt> emptyMap2;

    std::vector<KeyString> keysString = {"1", "2", "3"};
    std::vector<ValueInt> values = {1, 2, 3};

    HashMap<KeyString, ValueInt> mapString1(keysString.cbegin(), keysString.cend(),
                                            values.cbegin(), values.cend());
    HashMap<KeyString, ValueInt> mapString2(keysString.cbegin(), keysString.cend(),
                                            values.cbegin(), values.cend());

    assert(emptyMap1 == emptyMap2);
    assert(!(emptyMap1 != emptyMap2));

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

        myProgressBar++;
    }

    map.clear();

    assert(map != emptyMap1);
    assert(!(map == emptyMap1));


    myProgressBar.addToOutputMsg("PASS - testOperatorEqualsAndNotEquals\n");
    myProgressBar++;
}

void testIteratorsEmpty()
{
    std::unordered_map<KeyString, ValueInt> emptyStdMap;

    auto beginStdMap = emptyStdMap.begin();
    auto endStdMap = emptyStdMap.end();

    assert(beginStdMap == beginStdMap);
    assert(endStdMap == endStdMap);
    assert(beginStdMap == endStdMap);

    for (const auto &j : emptyStdMap)
    {
        assert(!"In empty unordered_map there should not be iterations here");
    }


    HashMap<KeyString, ValueInt> emptyMap;

    auto iterBegin = emptyMap.begin();
    auto iterEnd = emptyMap.end();

    assert(iterBegin == iterBegin);
    assert(iterEnd == iterEnd);
    assert(iterBegin == iterEnd);

    for (const auto &i : emptyMap)
    {
        assert(!" ~~~ In empty HashMap there should not be iterations here ~~~ ");
    }


    myProgressBar.addToOutputMsg("PASS = testIteratorsEmprty\n");
    myProgressBar++;
}

void testIterators1()
{

    std::vector<KeyInt> keysInt = {0, 1, 2, 3, 4, 5, 6, 15};
    std::vector<ValueInt> values = {0, 1, 2, 3, 4, 5, 6, 15};

    HashMap<KeyInt, ValueInt> map(keysInt.cbegin(), keysInt.cend(),
                                  values.cbegin(), values.cend());

    std::vector<int>::const_iterator vecIter = values.begin();

    map.print();

    for (auto it = map.begin(); it != map.end(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }

    vecIter = values.begin();

    for (auto it = map.cbegin(); it != map.cend(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }


    myProgressBar.addToOutputMsg("PASS = testIterators1\n");
    myProgressBar++;
}

void testIterators2()
{

    std::vector<KeyInt> keysInt = {3, 4, 5, 6, 15};
    std::vector<ValueInt> values = {3, 4, 5, 6, 15};

    HashMap<KeyInt, ValueInt> map(keysInt.cbegin(), keysInt.cend(),
                                  values.cbegin(), values.cend());

    std::vector<int>::const_iterator vecIter = values.begin();

    for (auto it = map.begin(); it != map.end(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }

    vecIter = values.begin();

    for (auto it = map.cbegin(); it != map.cend(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }


    myProgressBar.addToOutputMsg("PASS = testIterators2\n");
    myProgressBar++;
}

void testIterators3()
{

    std::vector<KeyInt> keysInt = {1, 4, 5, 6, 9, 14};
    std::vector<ValueInt> values = {1, 4, 5, 6, 9, 14};

    HashMap<KeyInt, ValueInt> map(keysInt.cbegin(), keysInt.cend(),
                                  values.cbegin(), values.cend());

    std::vector<int>::const_iterator vecIter = values.begin();

    for (auto it = map.begin(); it != map.end(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }

    vecIter = values.begin();

    for (auto it = map.cbegin(); it != map.cend(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);
        assert(it->first == (*it).first && it->second == (*it).second);

        vecIter++;
    }


    myProgressBar.addToOutputMsg("PASS = testIterators3\n");
    myProgressBar++;
}

void testIterators4()
{
    HashMap<KeyInt, ValueInt> map;
    std::vector<int> vec;

    // Insert elements to the map

    int i = 1;

    for (int n = 0; n <= ITERATIONS; n++)
    {
        while (i <= INITIAL_CAPACITY * pow(2, n) * 0.75)
        {
            map.insert(i, i);
            vec.push_back(i);
            i++;
        }
        
        myProgressBar++;
    }
    i--;

    assert(map.getCapacity() == INITIAL_CAPACITY * pow(2, ITERATIONS));
    assert(map.getSize() == i);
    assert(vec.size() == i);
    

    auto vecIter = vec.begin();

    for (auto it = map.begin(); it != map.end(); it++)
    {
        assert(it->first == *vecIter && it->second == *vecIter);   
        assert(it->first == (*it).first && it->second == (*it).second);        
        
        vecIter++;
    }

    myProgressBar.addToOutputMsg("PASS = testIterators4\n");
    myProgressBar++;
}
