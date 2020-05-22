#include <iostream>

#include "cache.h"

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;
    Cache<std::string, int> cache(3);
    std::cout << "Cache capacity is " << cache.capacity() << std::endl;
    std::cout << "Insert {'one', 1}" << std::endl;
    cache.set("one", 1);
    std::cout << "Insert {'two', 2}" << std::endl;
    cache.set("two", 2);
    std::cout << "Insert {'three', 3}" << std::endl;
    cache.set("three", 3);
    std::cout << "{'one', 1} exists? " << cache.has("one") << std::endl;
    std::cout << "Insert {'four', 4}" << std::endl;
    cache.set("four", 4);
    std::cout << "{'one', 1} exists? " << cache.has("one") << std::endl;
    std::cout << "Value of 'two' is " << cache.get("two") << std::endl;
    std::cout << "{'three', 3} exists? " << cache.has("three") << std::endl;
    std::cout << "Insert {'five', 5}" << std::endl;
    cache.set("five", 5);
    std::cout << "{'two', 2} exists? " << cache.has("two") << "; "
                 "{'three', 3} exists? " << cache.has("three") << std::endl;
    return 0;
}
