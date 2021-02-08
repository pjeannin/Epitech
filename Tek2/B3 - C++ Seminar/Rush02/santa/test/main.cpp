#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

static void test1()
{
    std::cout << "Test1 : Test size [correct]" << std::endl;
    std::string result = exec("./santa_test test_file/correct_size.xml");
    std::cout << "Got:" << std::endl;
    std::cout << result << std::endl;
    std::cout << "Expected:" << std::endl;
    std::cout << "useful to know what's inside, Right ?\n" << std::endl;
}

static void test2()
{
    std::cout << "Test2 : Test size [wrong]" << std::endl;
    std::string result = exec("./santa_test test_file/wrong_size.xml");
    std::cout << "Got:" << std::endl;
    std::cout << result << std::endl;
    std::cout << "Expected:" << std::endl;
    std::cout << "The list 'test_file/wrong_size.xml' has been broken.\n" << std::endl;
}

static void test3()
{
    std::cout << "Test3 : Test size [correct]" << std::endl;
    std::string result = exec("./santa_test test_file/wrong_input.xml");
    std::cout << "Got:" << std::endl;
    std::cout << result << std::endl;
    std::cout << "Expected:" << std::endl;
    std::cout << "The list 'test_file/wrong_size.xml' has been broken.\n" << std::endl;
}

static void test4()
{
    std::cout << "Test4 : Wrong file" << std::endl;
    std::string result = exec("./santa_test false.xml");
    std::cout << "Got:" << std::endl;
    std::cout << result << std::endl;
    std::cout << "Expected:" << std::endl;
    std::cout << "File false.xml, not readable! Please try again\n" << std::endl;
}

static void test5()
{
    std::cout << "Test5 : Test size [correct]" << std::endl;
    std::string result = exec("./santa_test");
    std::cout << "Got:" << std::endl;
    std::cout << result << std::endl;
    std::cout << "Expected:" << std::endl;
    std::cout << "Exemple:\n\t./santa filename.xml filename.xml\n" << std::endl;
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return (0);
}