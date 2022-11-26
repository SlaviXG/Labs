#include <string>
#include <string.h>
#include <vector>

namespace Naive
{
    std::vector <long long> findPattern(const std::string pattern, const std::string text)
    {
        std::vector <long long> entries;

        long long patternLength = pattern.size();
        long long textLength = text.size();

        for(long long i = 0; i <= textLength - patternLength; i++)
        {
            long long j;

            for(j = 0; j < patternLength; j++)
            {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == patternLength)
                entries.push_back(i);
        }

        return entries;
    }

    std::vector <long long> findPattern(const char* pattern, const char* text)
    {
        std::vector <long long> entries;

        long long patternLength = strlen(pattern);
        long long textLength = strlen(text);

        for(long long i = 0; i <= textLength - patternLength; i++)
        {
            long long j;

            for(j = 0; j < patternLength; j++)
            {
                if(text[i + j] != pattern[j])
                    break;
            }

            if(j == patternLength)
                entries.push_back(i);
        }

        return entries;
    }
}