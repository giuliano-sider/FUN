#include <iostream>
#include <cstdlib>

#include "string_matching.h"

void print_usage_msg(int argc, char *argv[])
{
    std::cerr << "usage: " << argv[0] << " <PATTERN>" << std::endl << std::endl
              << argv[0] << " is a filter program that takes a pattern as a command line argument and takes a text via the standard input" << std::endl
              << "and prints out the (zero-indexed) shifts in the text where the pattern occurs." << std::endl << std::endl
              << "(unix shell) example:" << std::endl
              << "$ echo banana | " << argv[0] << " na" << std::endl
              << "> 2" << std::endl
              << "> 4" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        print_usage_msg(argc, argv);
        exit(1);
    }

    std::string pattern = argv[1];

    auto kmp_memo = kmp_preprocess(pattern);

    kmp_match(kmp_memo, pattern, std::cin, std::cout);
}

