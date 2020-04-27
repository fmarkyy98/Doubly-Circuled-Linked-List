#include <iostream>
#include "C2L.h"

using namespace std;

#define NORMAL_MODE
#ifdef  NORMAL_MODE

int main()
{
    C2L list1;
    list1.add(2);
    list1.add(4);
    list1.add(3);
    list1.add(5);

    C2L list2("./Test/01.txt");

    cout << list1 << endl;
    cout << list2 << endl;
    list1.symdiff(list2);
    cout << list1 << endl;
    cout << list2 << endl;

    return 0;
}

#else
#define CATCH_CONFIG_MAIN

TEST_CASE("t01_empty")
{
    Competitor c;
    CHECK_FALSE(first_search("./Test/t01_empty.txt", c));

    CHECK("" == second_search("./Test/BlackBox/t01_empty.txt").str());
}

#endif
