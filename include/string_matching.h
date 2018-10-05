#ifndef _STRING_MATCHING_H_
#define _STRING_MATCHING_H_

#include <vector>
#include <string>
#include <iostream>

/**
*   @brief takes a pattern and returns a (one-indexed) KMP 'length of longest proper matching suffix' array,
*          with a value for each character of the pattern (position zero has value -1, which is used as a sentinel by kmp_match).
*/          
std::vector<int> kmp_preprocess(const std::string& pattern);

/**
*   @brief takes a pattern, a KMP 'length of longest proper matching suffix' array, an input stream, and an output stream,
*          and reads characters from the input stream, printing the (zero-indexed) shifts where the pattern occurs in the input.
*          reads until EOF.
*/
void kmp_match(const std::vector<int>& lppm, const std::string& pattern, std::istream& is = std::cin, std::ostream& os = std::cout);


#endif // _STRING_MATCHING_H_