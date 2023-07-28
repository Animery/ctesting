/**********************************************\
*
*  Mikhail Shaimukhamedov
*  mixail.any@gmail.com
*
\**********************************************/

#pragma once

#include <functional>
#include <string>
#include <unordered_map>

class TestStorage final
{
    using TestFunction = std::function<int(int argc, char* argv[])>;

public:
    static TestStorage& instance();
    ~TestStorage() = default;

public:
    void addTest(const std::string& name, TestFunction func);
    int runTest(const std::string& name, int argc, char* argv[]) const;

private:
    TestStorage() = default;
    TestStorage(const TestStorage&) = delete;
    TestStorage& operator=(const TestStorage&) = delete;

private:
    std::unordered_map<std::string, TestFunction> m_tests;
};

void initializeTests();