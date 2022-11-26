#include <string>
#include <string.h>

namespace Rabin_Karp
{
    //q - prime number for hash

    std::vector <long long> findPattern(std::string pattern, std::string text, int q)
    {
        std::vector <long long> entries;

        long long patternLength = pattern.length();
        long long textLength = text.length();
        long long i, j;
        int p = 0;
        int t = 0;
        int h = 1;

        for (i = 0; i < patternLength - 1; i++)
            h = (h * 256) % q;

        for (i = 0; i < patternLength; i++)
        {
            p = (256 * p + pattern[i]) % q;
            t = (256 * t + text[i]) % q;
        }

        for (i = 0; i <= textLength - patternLength; i++)
        {
            if (p == t)
            {

                for (j = 0; j < patternLength; j++)
                {
                    if (text[i + j] != pattern[j])
                        break;
                }
                if (j == patternLength)
                    entries.push_back(i);
            }
            if (i < textLength - patternLength)
            {
                t = (256 * (t - text[i] * h) + text[i + patternLength]) % q;

                if (t < 0)
                    t = (t + q);
            }
        }

        return entries;
    }

    std::vector <long long> findPattern(char* pattern, char* text, int q)
    {
        std::vector <long long> entries;

        long long patternLength = strlen(pattern);
        long long textLength = strlen(text);
        long long i, j;
        int p = 0;
        int t = 0;
        int h = 1;

        for (i = 0; i < patternLength - 1; i++)
            h = (h * 256) % q;

        for (i = 0; i < patternLength; i++)
        {
            p = (256 * p + pattern[i]) % q;
            t = (256 * t + text[i]) % q;
        }

        for (i = 0; i <= textLength - patternLength; i++)
        {
            if (p == t)
            {

                for (j = 0; j < patternLength; j++)
                {
                    if (text[i + j] != pattern[j])
                        break;
                }
                if (j == patternLength)
                    entries.push_back(i);
            }
            if (i < textLength - patternLength)
            {
                t = (256 * (t - text[i] * h) + text[i + patternLength]) % q;

                if (t < 0)
                    t = (t + q);
            }
        }

        return entries;
    }
}
