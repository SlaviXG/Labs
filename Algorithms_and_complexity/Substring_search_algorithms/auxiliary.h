#include <string>
#include <random>

int random_int(const int max_value, const int min_value)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_value, max_value);
    return dist(gen);
}

char random_char()
{
    return (char) random_int(126, 32);
}

std::string random_string(const long long int length)
{
    std::string str = "";

    for(int i = 0; i < length; i++)
        str += random_char();

    return str;
}

std::string random_binary_string(const long long int length)
{
    std::string str = "";

    for(int i = 0; i < length; i++)
        str += random_int(1, 0) + '0';

    return str;
}