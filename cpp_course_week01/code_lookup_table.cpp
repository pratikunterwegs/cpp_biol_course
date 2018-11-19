// bool Has30Days(int &month) {
//   static const bool T[] = { 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
//
//   if(T[month-1] == 1)
//       cout << "Yes"
//            << endl;
//
//   else
//       cout << "No"
//            << endl;
//
//   return T[month];
// }
//
// int main()
// {
//     int month;
//     //test a lookup table; from the Wikipedia article on lookup tables
//     cout << "enter a month number 1 -- 12"
//          << endl;
//
//     cin >> month;
//     cout << "month " << month << " has 30 days = " << Has30Days(month)
//              << endl;
//
//
//     return 0;
// }
