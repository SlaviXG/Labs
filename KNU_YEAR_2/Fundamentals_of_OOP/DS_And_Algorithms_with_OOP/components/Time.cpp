#include "Time.h"

namespace datetime
{
    //Constructor
    Time::Time()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;

        //Negative flag
        isNegative = false;
    }


    bool isTimeValid(Time time)
    {

        //std::cout << std::endl << "Checking out!" << std::endl;
        if(time.year < 1) return false;
        if(time.month < 1 or time.month > 12) return false;
        if(time.day < 1) return false;

        // February
        if(time.month == 2)
        {
            if((!time.year%100 and !time.year%400) or (time.year%100 and !time.year%4))
            {
                if(time.day < 1 or time.day > 29) return false;
            }
            else
            {
                if(time.day < 1 or time.day > 28) return false;
            }
        }
            // other months
        else
        {
            if(time.month < 8) // January - July
            {
                if(time.month % 2) // 31
                {
                    if(time.day > 31) return false;
                }
                else // 30
                {
                    if(time.day > 30) return false;
                }
            }
            else // August - December
            {
                if(time.month % 2)
                {
                    if(time.day > 30) return false;
                }
                else
                {
                    if(time.day > 31) return false;
                }
            }
        }

        if(time.hour > 23 or time.hour < 0) return false;
        if(time.minute > 59 or time.minute < 0) return false;
        if(time.second > 59 or time.second < 0) return false;

        return true;
    }

    Time inputTime()
    {
        Time time;

        std::string input;

        bool validness = true;
        do
        {
            //std::cout << validness << std::endl;
            if(!validness)
            {
                std::cerr << "Error. Incorrect input." << std::endl;
                validness = true;
            }
            try
            {

                std::cout << "Enter a date (dd.mm.yyyy) : " << std::endl;

                std::getline(std::cin, input, '.');

                time.day = (short) std::stoi(input);

                std::getline(std::cin, input, '.');

                time.month = (short) std::stoi(input);

                std::getline(std::cin, input,'\n');

                time.year = std::stoll(input);

                std::cout << "Time (hh:mm:ss) : " << std::endl;

                std::getline(std::cin, input, ':');

                time.hour = (short) std::stoi(input);

                std::getline(std::cin, input, ':');

                time.minute = (short) std::stoi(input);

                std::getline(std::cin, input,'\n');

                time.second = (short) std::stoi(input);

            }
            catch (std::exception)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                validness = false;
            }

            if(validness) validness = isTimeValid(time);
        }
        while(!validness);

        std::cout << std::endl;

        return time;

    }

//"Date (dd.mm.yyyy) :"
//"Time (hh:mm:ss) :"
    void printTime(Time time)
    {
        std::cout.flush();
        std::cout << "Exact time : " << ((time.isNegative) ? "- " : "");
        std::cout << time.day << '.' << time.month << '.' << time.year << ' ';
        std::cout << time.hour << '.' << time.minute << '.' << time.second << ' ';
        std::cout << std::endl;
    }

    void normalizeTime(Time &time)
    {

        time.minute += time.second/60;
        time.second %= 60;

        time.hour += time.minute/60;
        time.minute %= 60;

        time.day += time.hour/24;
        time.hour %= 24;

        short dayCnt = getDayAmountInMonth(time.month, time.year);

        while(time.day > dayCnt)
        {
            time.month++;
            time.day -= dayCnt;
            dayCnt = getDayAmountInMonth(time.month, time.year);
        }

        time.year += (time.month - 1) / 12;
        time.month = (time.month - 1) % 12 + 1;
    }

    bool isYearLeap(long long year)
    {
        return ((!year%100 and !year%400) or (year%100 and !year%4));
    }

    short getDayAmountInMonth(short monthNum, long long year)
    {
        switch (monthNum) {
            case 1: return 31;
            case 2: return ((isYearLeap(year)) ? 29 : 28);
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: std::cerr << "Incorrect month" << std::endl, throw std::exception();
        }
    }

//Comparison operators
    bool operator >= (Time A, Time B)
    {
        if(!A.isNegative and B.isNegative) return true;
        if(A.isNegative and !B.isNegative) return false;

        bool res = false;

        if(A.year > B.year) res = true;
        else if(A.year == B.year)
        {
            if(A.month > B.month) res = true;
            else if(A.month == B.month)
            {
                if(A.day > B.day) res = true;
                else if(A.day == B.day)
                {
                    if(A.hour > B.hour) res = true;
                    else if(A.hour == B.hour)
                    {
                        if(A.minute > B.minute) res = true;
                        else if(A.minute == B.minute)
                        {
                            if(A.second >= B.second) res = true;
                        }
                    }
                }
            }
        }

        if(!A.isNegative and !B.isNegative) return res;
        if(A.isNegative and B.isNegative) return !res;
    }

    bool operator > (Time A, Time B)
    {
        if(!A.isNegative and B.isNegative) return true;
        if(A.isNegative and !B.isNegative) return false;

        bool res = false;

        if(A.year > B.year) res = true;
        else if (A.year == B.year)
        {
            if(A.month > B.month) res = true;
            else if (A.month == B.month)
            {
                if(A.day > B.day) res = true;
                else if (A.day == B.day)
                {
                    if(A.hour > B.hour) res = true;
                    else if (A.hour == B.hour)
                    {
                        if(A.minute > B.minute) res = true;
                        else if (A.minute == B.minute)
                        {
                            if(A.second > B.second) res = true;
                        }
                    }
                }
            }
        }

        if(!A.isNegative and !B.isNegative) return res;
        if(A.isNegative and B.isNegative) return !res;
    }

    bool operator == (Time A, Time B)
    {
        return
                (A.day == B.day and
                 A.month == B.month and
                 A.year == B.year and
                 A.hour == B.hour and
                 A.minute == B.minute and
                 A.second == B.second and
                 A.isNegative == B.isNegative);
    }

    bool operator < (Time A, Time B)
    {
        return (!(A>B) and !(A==B));
    }

    bool operator <= (Time A, Time B)
    {
        return (!(A>B));
    }

    bool operator != (Time A, Time B)
    {
        return (!(A==B));
    }

//Arithmetical operators
    Time operator + (Time A, Time B)
    {
        if(!A.isNegative and !B.isNegative)
        {
            Time res;

            //Adding
            res.day = A.day + B.day;
            res.month = A.month + B.month;
            res.year = A.year + B.year;
            res.hour = A.hour + B.hour;
            res.minute = A.minute + B.minute;
            res.second = A.second + B.second;

            //Normalizing
            if(!isTimeValid(res)) normalizeTime(res);

            return res;
        }
        else if(A.isNegative and B.isNegative)
        {
            A.isNegative = false;
            B.isNegative = false;

            Time C = A + B;

            C.isNegative = true;

            return C;
        }
        else // A - B
        {
            Time C;

            if(A.isNegative and !B.isNegative)
            {
                A.isNegative = false;
                if(A > B)
                {
                    C = A - B;
                    C.isNegative = true;
                }
                else
                {
                    C = B - A;
                    C.isNegative = false;
                }
            }
            else //A is positive, B is negative
            {
                B.isNegative = false;
                if(A > B)
                {
                    C = A - B;
                    C.isNegative = false;
                }
                else
                {
                    C = B - A;
                    C.isNegative = true;
                }
            }

            return C;
        }
    }

    Time operator - (Time A, Time B)
    {
        if(A.isNegative and B.isNegative) //A < 0, B < 0
        {
            B.isNegative = false;

            Time C = A + B;

            return C;
        }
        else if(!A.isNegative and !B.isNegative) //A > 0, B > 0
        {
            Time C;

            if(A < B)
            {
                std::swap(A, B);
                C.isNegative = true;
            }

            //Now A >= B

            if(B.second > A.second)
            {
                A.minute--;
                A.second += 60;
            }
            C.second = A.second - B.second;

            if(A.minute < 0)
            {
               A.hour--;
               A.minute+=60;
            }
            if(B.minute > A.minute)
            {
                A.hour--;
                A.minute += 60;
            }
            C.minute = A.minute - B.minute;

            if(A.hour < 0)
            {
                A.day--;
                A.hour += 24;
            }
            if(B.hour > A.hour)
            {
                A.day--;
                A.hour += 60;
            }
            C.hour = A.hour - B.hour;

            if(A.day < 1)
            {
                A.day += getDayAmountInMonth(A.month, A.year);
                A.month--;
            }
            if(B.day > A.day)
            {
                A.day += getDayAmountInMonth(A.month, A.year);
                A.month--;
            }
            C.day = A.day - B.day;

            if(A.month < 1)
            {
                A.month += 12;
                A.year--;
            }
            if(B.month > A.month)
            {
                A.month += 12;
                A.year--;
            }
            C.month = A.month - B.month;

            if(A.year < 0)
            {
                std::cerr << "Incorrect time data." << std::endl;
                throw std::exception();
            }
            C.year = A.year - B.year;

            return C;
        }
        else
        {
            Time C;

            if(A.isNegative) //A < 0, B > 0
            {
                A.isNegative = false;
                C = A + B;
                C.isNegative = true;
                return C;
            }
            else //A > 0, B < 0
            {
                B.isNegative = false;
                C = A + B;
                return C;
            }
        }
    }
}