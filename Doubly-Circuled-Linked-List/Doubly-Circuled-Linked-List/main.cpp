#include <iostream>
#include <sstream>
#include "C2L.h"

using namespace std;

//#define NORMAL_MODE
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

#include "./Test/src/catch.hpp"

TEST_CASE("empty")
{
    C2L la("./Test/BlackBox/empty.txt");
    C2L lb("./Test/BlackBox/empty.txt");

    stringstream sa;
    sa << la;
    CHECK("[]" == sa.str());

    stringstream sb;
    sb << lb;
    CHECK("[]" == sb.str());

    la.symdiff(lb);

    sa.str("");
    sa << la;
    CHECK("[]" == sa.str());

    sb.str("");
    sb << lb;
    CHECK("[]" == sb.str());
}

TEST_CASE("t01")
{
    C2L la("./Test/BlackBox/01a.txt");
    C2L lb("./Test/BlackBox/01b.txt");

    stringstream sa;
    sa << la;
    CHECK("[1,2,3,4]" == sa.str());

    stringstream sb;
    sb << lb;
    CHECK("[2,3,4,5]" == sb.str());

    la.symdiff(lb);

    sa.str("");
    sa << la;
    CHECK("[1,5]" == sa.str());

    sb.str("");
    sb << lb;
    CHECK("[]" == sb.str());
}

TEST_CASE("t02")
{
    C2L la("./Test/BlackBox/02a.txt");
    C2L lb("./Test/BlackBox/02b.txt");

    stringstream sa;
    sa << la;
    CHECK("[3,5,8,9,12,22,35]" == sa.str());

    stringstream sb;
    sb << lb;
    CHECK("[2,5,6,7,12,27,35]" == sb.str());

    la.symdiff(lb);

    sa.str("");
    sa << la;
    CHECK("[2,3,6,7,8,9,22,27]" == sa.str());

    sb.str("");
    sb << lb;
    CHECK("[]" == sb.str());
}

TEST_CASE("t03")
{
    C2L la("./Test/BlackBox/03a.txt");
    C2L lb("./Test/BlackBox/03b.txt");
    C2L lc("./Test/BlackBox/03c.txt");

    stringstream sa;
    sa << la;
    CHECK("[3,5,19,21,45,48,48,59]" == sa.str());

    stringstream sb;
    sb << lb;
    CHECK("[19,21,34,47,48,63,65]" == sb.str());

    stringstream sc;
    sc << lc;
    CHECK("[18,19,26,27,32,84,92]" == sc.str());

    la.symdiff(lb);
    la.symdiff(lc);

    sa.str("");
    sa << la;
    CHECK("[3,5,18,19,26,27,32,34,45,47,48,59,63,65,84,92]" == sa.str());

    sb.str("");
    sb << lb;
    CHECK("[]" == sb.str());

    sc.str("");
    sc << lc;
    CHECK("[]" == sc.str());
}

TEST_CASE("Check if add works.")
{
    C2L l;
    stringstream s;
    s << l;
    CHECK("[]" == s.str());
    l.add(1);
    s.str("");
    s << l;
}

#endif
