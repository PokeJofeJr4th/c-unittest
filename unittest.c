#include "unittest.h"

#include <stdio.h>

int test_main();

static int UNITTEST_TEST_NUM = 0;
static int UNITTEST_FAILURES = 0;

int unittest_assert(int condition, char *name, char *file, int line)
{
    UNITTEST_TEST_NUM++;
    if (condition)
    {
        return condition;
    }
    UNITTEST_FAILURES++;
    fprintf(stderr, "Test #%i: %s Failed at %s:%i; result=%i", UNITTEST_TEST_NUM, name, file, line, condition);
    return condition;
}

int main()
{
    int test_result = test_main();
    fprintf(stderr, "Total test failures: %i/%i", UNITTEST_FAILURES, UNITTEST_TEST_NUM);
    if (test_result != 0)
    {
        return test_result;
    }
    if (UNITTEST_FAILURES == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
