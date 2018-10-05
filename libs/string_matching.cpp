#include "string_matching.h"

#include <cassert>

std::vector<int> kmp_preprocess(const std::string& pattern)
{
    int matchlength = 0;
    std::vector<int> lppm(pattern.size() + 1);

    lppm[0] = -1; // no proper prefix match when at the beginning
    size_t i;
    for (i = 1; i < pattern.size(); i++) {
        while (matchlength != -1 && pattern[i] != pattern[matchlength]) {
            matchlength = lppm[matchlength];
        }
        matchlength++;
        lppm[i + 1] = matchlength;
    }
    //lppm[i + 1] = matchlength;

    return lppm;
}

void kmp_match(const std::vector<int>& lppm, const std::string& pattern, std::istream& is, std::ostream& os)
{
    assert(pattern.size() + 1 == lppm.size());
    
    const size_t BUFSIZE = 4096;
    char buffer[BUFSIZE];
    int matchlength = 0;
    int total_count = 0;

    while (1) {
        is.read(buffer, BUFSIZE);
        size_t n = is.gcount();
        if (n == 0) {
            break;
        }

        for (size_t i = 0; i < n; i++, total_count++) {
            while (matchlength != -1 && buffer[i] != pattern[matchlength]) {
                matchlength = lppm[matchlength];
            }
            matchlength++;
            if (matchlength == (int) pattern.size()) {
                os << (total_count - pattern.size() + 1) << std::endl; // we print the index where this match began
                matchlength = lppm[matchlength];
            }
        }
    }
}

