//#include <iostream>

//int main()
//{
//    int day; int month; int year; int day_now; int month_now; int year_now;

//    std::cout << "This will tell you the number of days until your next birthday! Enter the day of birth : "; std::cin >> day;
//    std::cout << "Enter the month of birth : "; std::cin >> month;
//    std::cout << "Enter your year of birth : "; std::cin >> year;

//    std::cout << "Enter the day today : "; std::cin >> day_now;
//    std::cout << "Enter the month today : "; std::cin >> month_now;
//    std::cout << "Enter the year today : "; std::cin >> year_now;

//    int total_01 = (year_now*365) + (month_now*30) + (day_now);
//    int total_02 = (year*365) + (month*30) + (day);

//    int year_diff = (total_01 - total_02) / 365;
//    int month_diff = ((total_01 - total_02) - year_diff*365)/30;
//    int days_diff = abs((total_01 - total_02) - year_diff*365 - month_diff*35);

//    std::cout << "You are approximately " << year_diff << " years " << month_diff << " months " << days_diff << " days old " << std::endl;

//    std::cout << "Days until your next birthday = "
//              << static_cast<int>(30*(12 - (static_cast<double>(month_diff) + static_cast<double>(days_diff/30.0))))
//              << " more or less, okay!" << std::endl;

//    return 0;
//}
