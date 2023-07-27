#include <cstdlib>
#include <cstring>
#include <string_view>
#include <functional>
#include <cassert>

int test_1()
{
    return EXIT_SUCCESS;
}

int test_2()
{
    return EXIT_SUCCESS;
}

using TestFunction = std::function<int()>;

struct TestMapping
{
    std::string_view name;
    TestFunction func;
};

namespace
{
    const TestMapping tests[] = {
        {"test_1", &test_1},
        {"test_2", &test_2},
    };

    TestFunction getTest(std::string_view testName)
    {
        for (auto &test : tests)
        {
            if (testName == test.name)
            {
                return test.func;
            }
        }

        assert(!"cant find test");
        return []() -> int
        { return EXIT_FAILURE; };
    }
} // namespace

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        auto func = getTest(argv[1]);
        return func();
    }

    return EXIT_FAILURE;
}