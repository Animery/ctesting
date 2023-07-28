/**********************************************\
*
*  Mikhail Shaimukhamedov
*  mixail.any@gmail.com
*
\**********************************************/

#include "simple_test.hpp"

#include <cassert>
#include <cstdlib>

TestStorage& TestStorage::instance()
{
    static TestStorage storage;
    return storage;
}

void TestStorage::addTest(const std::string& name, TestFunction func)
{
    if (auto result = m_tests.try_emplace(name, func); result.second == false)
    {
        assert(!"m_tests already contain this test");
    }
}

int TestStorage::runTest(const std::string& name, int argc, char* argv[]) const
{
    if (auto it = m_tests.find(name); it != m_tests.end())
    {
        return it->second(argc, argv);
    }

    assert(!"cant find test");
    return EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
    assert((argc > 1 && "fail arg count"));

    initializeTests();

    auto& tests = TestStorage::instance();
    return tests.runTest(argv[1], argc - 2, argv + 2);
}