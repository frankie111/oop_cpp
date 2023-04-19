#ifndef LAB4_UTILS_CPP
#define LAB4_UTILS_CPP

#include <ctime>
#include <chrono>
#include <string>
#include <vector>

#include <iomanip>
#include <sstream>
#include <iostream>

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

/**
 * @returns the number of words in a string
 * @param str input string
 */
static int wordCount(const string &str) {
    std::istringstream iss(str);
    int wordCount = 0;
    std::string word;

    while (iss >> word) {
        wordCount++;
    }

    return wordCount;
}

/**
 * Process a string to use even spacing between words
 */
static string evenSpacing(string str, int lineWidth) {
    if (lineWidth < str.size())
        throw invalid_argument("utils::evenSpacing: the input string cannot be larger than the lineWidth");

    int spaceCount = wordCount(str) - 1;

    //compute the spacing between words
    int spacing = (lineWidth - int(str.size())) / spaceCount;
    size_t pos = 0;
    while ((pos = str.find(' ', pos)) != string::npos) {
        str.replace(pos, 1, string(spacing, ' '));
        pos += spacing;
    }

    return str;
}


/**
 * Split a string into words
 * @param str input string
 * @returns a vector of strings (words)
 */
static vector<string> getWords(const string &str) {
    vector<string> words;
    istringstream iss(str);
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

static string toLower(string str) {
    for (char &c: str)
        c = char(tolower(c));

    return str;
}

#endif //LAB4_UTILS_CPP