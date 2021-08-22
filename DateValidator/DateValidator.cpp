/////////////////////////////////////////////////////////////
// Author: Fredrik Linde
// Year: 2021
//
// DateValidator.cpp
/////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

typedef unsigned int Unsigned_Type;

// The Gregorian calendar consists of the following 12 months:
// 1. January - 31 days
// 2. February - 28 days in a common year and 29 days in leap years
// 3. March - 31 days
// 4. April - 30 days
// 5. May - 31 days
// 6. June - 30 days
// 7. July - 31 days
// 8. August - 31 days
// 9. September - 30 days
// 10. October - 31 days
// 11. November - 30 days
// 12. December - 31 days

// Months with 31 days = [ 1, 3, 5, 7, 8, 10, 12 ]
// Months with 30 days = [ 4, 6, 9, 11 ]

// February is the only month that is 28 days long in common years and 29 days long in leap years.
// A leap year is every 4 years, but not every 100 years, then again every 400 years.

Unsigned_Type LeapYears[24] = {
4u, 8u, 12u, 16u, 20u, 24u, 28u, 32u, 36u, 40u, 44u, 48u, 
52u, 56u, 60u, 64u, 68u, 72u, 76u, 80u, 84u, 88u, 92u, 96u };

bool IsDateValid(const Unsigned_Type Year, const Unsigned_Type Month, const Unsigned_Type Day)
{
    bool Date_Valid = false;

    if (Year >= 0u && Year <= 99u) {

        if (Month == 1u || Month == 3u || Month == 5u || Month == 7u || Month == 8u || Month == 10u || Month == 12u) {

            Date_Valid = (Day > 0u && Day <= 31u);
        }
        else if (Month == 4u || Month == 6u || Month == 9u || Month == 11u) {

            Date_Valid = (Day > 0u && Day <= 30u);
        }
        else if (Month == 2u) { 

            const bool IsLeapYear = (((Year % 4u == 0u) && (Year % 100u != 0u)) || (Year % 400u == 0u));

            if (IsLeapYear) {

                Date_Valid = (Day <= 29u);
            }
            else {

                Date_Valid = (Day <= 28u);
            }
        }
    }

    return Date_Valid;
}

void ClearInput() 
{
    std::cin.clear(); // Clear bad input flag.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input.
}

void PressEnterToContinue()
{
    std::cout << "\nPress Enter to Continue\n";
    std::string temp;
    std::getline(std::cin, temp);
}

void InvalidInput() 
{
    std::cout << "Enter a valid integer value!\n";
    ClearInput();
    PressEnterToContinue();
    std::system("clear");
}

void TestSuite() 
{
    Unsigned_Type Year = 30u;
    Unsigned_Type Month = 12u;
    Unsigned_Type Day = 31u;

    const Unsigned_Type NumLeapYears = sizeof(LeapYears) / sizeof(Unsigned_Type);

    std::cout << "DECEMBER 31th 2030 TEST" << std::endl;
    IsDateValid(Year, Month, Day) ? std::cout << "[VALID DATE] : " : std::cout << "[INVALID DATE] : ";
    std::cout << Year << "-" << Month << "-" << Day << std::endl;

    ClearInput();
    PressEnterToContinue();

    Year = 0u;
    Month = 2u;
    Day = 29u;

    {
        std::cout << "LEAP YEAR FEBRUARY 29th TEST" << std::endl;
        for (Unsigned_Type i = 0u; i < NumLeapYears - 1u; ++i) {
            Year = LeapYears[i];
            IsDateValid(Year, Month, Day) ? std::cout << "[VALID DATE] : " : std::cout << "[INVALID DATE] : ";
            std::cout << Year << "-" << Month << "-" << Day << std::endl;
        }
    }

    PressEnterToContinue();

    Year = 0u;
    Month = 2u;
    Day = 30u;

    {
        std::cout << "LEAP YEAR FEBRUARY 30th TEST" << std::endl;
        for (Unsigned_Type i = 0u; i < NumLeapYears - 1u; ++i) {
            Year = LeapYears[i];
            IsDateValid(Year, Month, Day) ? std::cout << "[VALID DATE] : " : std::cout << "[INVALID DATE] : ";
            std::cout << Year << "-" << Month << "-" << Day << std::endl;
        }
    }

    PressEnterToContinue();

    Year = 20u;
    Month = 0u;
    Day = 31u;

    {
        std::cout << "MONTHS 31 DAYS TEST" << std::endl;
        for (Unsigned_Type i = 1u; i <= 12u; ++i) {
            Month = i;
            IsDateValid(Year, Month, Day) ? std::cout << "[VALID DATE] : " : std::cout << "[INVALID DATE] : ";
            std::cout << Year << "-" << Month << "-" << Day << std::endl;
        }
    }

    PressEnterToContinue();

    Year = 20u;
    Month = 0u;
    Day = 30u;

    {
        std::cout << "MONTHS 30 DAYS TEST" << std::endl;
        for (Unsigned_Type i = 1u; i <= 12u; ++i) {
            Month = i;
            IsDateValid(Year, Month, Day) ? std::cout << "[VALID DATE] : " : std::cout << "[INVALID DATE] : ";
            std::cout << Year << "-" << Month << "-" << Day << std::endl;
        }
    }

    PressEnterToContinue();
}

int main(int argc, char** argv)
{
    int Option = 0;
    bool Running = true;

    while (Running) {
        std::system("clear");
        std::cout << "Welcome to the DateValidator!\n1: Enter Manual Date\n2: Run Test Suite\n3: Instructions\n4: Exit" << std::endl;
        if (std::cin >> Option) {
            switch (Option)
            {
            case 1:
            {
                Unsigned_Type Year = 0u;
                Unsigned_Type Month = 0u;
                Unsigned_Type Day = 0u;

                std::system("clear");

                while (true) 
                {
                    std::cout << "Enter year: ";
                    if (std::cin >> Year) 
                    {
                        break;
                    }
                    else 
                    {
                        InvalidInput();
                    }
                }
                while (true) 
                {
                    std::cout << "Enter month: ";
                    if (std::cin >> Month) 
                    {
                        break;
                    }
                    else 
                    {
                        InvalidInput();
                        std::cout << "Enter year: " << Year << std::endl;
                    }
                }
                while (true)
                {
                    std::cout << "Enter day: ";
                    if (std::cin >> Day)
                    {
                        break;
                    }
                    else
                    {
                        InvalidInput();
                        std::cout << "Enter year: " << Year << std::endl;
                        std::cout << "Enter month: " << Month << std::endl;
                    }
                }
                IsDateValid(Year, Month, Day) ? std::cout << "\n[VALID DATE] : " : std::cout << "\n[INVALID DATE] : ";
                std::cout << Year << "-" << Month << "-" << Day << std::endl;

                ClearInput();
                PressEnterToContinue();
                break;
            }
            case 2:
            {
                std::system("clear");
                TestSuite();
                break;
            }
            case 3:
            {
                std::system("clear");
                std::cout << "The DateValidator works with dates in the following format:\n";
                std::cout << "YY-MM-DD\n\n";
                std::cout << "Note that years are only accepted in the range 0 - 99\n";
                ClearInput();
                PressEnterToContinue();
                break;
            }
            case 4:
            {
                Running = false;
                break;
            }
            default:
                break;
            }
        }
        else {
            std::system("clear");
            std::cout << "Enter a valid integer value!\n";
            ClearInput();
            PressEnterToContinue();
        }
    }
}