#include <string>
#include <string.h>

namespace Horspool
{
    //char - 1 byte = 8 bit -> char space = 2^8

    int max (int a, int b)
    {
        return (a > b) ? a : b;
    }

    void badCharMatch(const std::string str, int badchar[256])
    {
        long long i;
        long long size = str.size();

        for (i = 0; i < 256; i++)
            badchar[i] = -1;

        for (i = 0; i < size; i++)
            badchar[(int) str[i]] = i;
    }

    void badCharMatch(const char *str, long long size, int badchar[256])
    {
        long long i;

        for (i = 0; i < 256; i++)
            badchar[i] = -1;

        for (i = 0; i < size; i++)
            badchar[(int) str[i]] = i;
    }

    std::vector <long long> findPattern(std::string pattern, std::string text)
    {
        std::vector <long long> entries;

        long long patternLength = pattern.length();
        long long textLength = text.length();

        int badchar[256];

        badCharMatch(pattern, badchar);

        long long s = 0;

        while(s <= (textLength - patternLength))
        {
            long long j = patternLength - 1;

            while(j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0)
            {
                entries.push_back(s);
                s += (s + patternLength < textLength) ? patternLength - badchar[text[s + patternLength]] : 1;
            }
            else
                s += max(1, j - badchar[text[s + j]]);
        }

        return entries;
    }

    std::vector <long long> findPattern(char *pattern, char *text)
    {
        std::vector <long long> entries;

        long long patternLength = strlen(pattern);
        long long textLength = strlen(text);

        int badchar[256];

        badCharMatch(pattern, patternLength, badchar);

        long long s = 0;

        while(s <= (textLength - patternLength))
        {
            long long j = patternLength - 1;

            while(j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0)
            {
                entries.push_back(s);
                s += (s + patternLength < textLength) ? patternLength - badchar[text[s + patternLength]] : 1;
            }
            else
                s += max(1, j - badchar[text[s + j]]);
        }

        return entries;
    }
}