#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <random>
#include <functional>
#include <fstream>
#include <sstream>
#include <regex>
#include <future>
#include <array>
#include <optional>


void test_cpp_stdlib() {
    std::cout << "Testing C++ Standard Library..." << std::endl;

    std::vector<int> v = {1, 2, 3};
    std::map<std::string, int> m = {{"one", 1}, {"two", 2}};
    std::set<int> s(v.begin(), v.end());
    std::sort(v.begin(), v.end());

    std::thread t([] { std::this_thread::sleep_for(std::chrono::milliseconds(10)); });
    t.join();

    std::mutex mu;
    std::lock_guard<std::mutex> lock(mu);

    std::atomic<int> ai{0};
    ai++;

    std::function<int(int)> f = [](int x) { return x * x; };
    int y = f(5);

    std::cout << "Square of 5 is " << y << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::cout << "Random number: " << dis(gen) << std::endl;

    std::optional<int> opt = 42;
    if (opt) std::cout << "Optional value: " << *opt << std::endl;
}

