/**********************************************\
*
*  Mikhail Shaimukhamedov
*  mixail.any@gmail.com
*
\**********************************************/

#include "simple_test.hpp"

#include <cstdlib>

int test_1([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    return EXIT_SUCCESS;
}

int test_2([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
    return EXIT_FAILURE;
}

void initializeTests()
{
    auto& tests = TestStorage::instance();

    tests.addTest("test_1", &test_1);
    tests.addTest("test_2", &test_2);
}