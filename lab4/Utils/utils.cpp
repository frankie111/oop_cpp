#ifndef LAB4_UTILS_CPP
#define LAB4_UTILS_CPP

#include <ctime>
#include <chrono>
#include <string>

#include <iomanip>

using namespace std;

/**
 * Convert a string to a time_t object
 * @param input input string
 */
static time_t strToTime(const string &input) {
    tm time{};
    stringstream ss(input);
    ss >> get_time(&time, "%d-%m-%Y");

    return mktime(&time);
}

/**
 * Convert a time_t object to a string
 * @param input
 * @return
 */
static string timeToStr(const time_t &input) {
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", std::localtime(&input));
    return {buffer};
}

#endif //LAB4_UTILS_CPP