
#include <iostream>

using namespace std;




int main()
{
   int BookNumber, ExpectedClassEnrollment;
   double price;
   char Required_or_suggested;
   char New_or_Old;

   cout << "Enter book number: " << endl;
   cin >> BookNumber;
   cout << "Enter price per copy: " << endl;
   cin >> price;
   cout << "Enter expected class enrollment: " << endl;
   cin >> ExpectedClassEnrollment;
   cout << "Enter 'R' if required or 'S' if suggested: " << endl;
   cin >> Required_or_suggested;
   cout << "Enter 'N' if new or 'O' if not a new text: " << endl;
   cin >> New_or_Old;
   cout << "ISBN: " << BookNumber << endl;

   cout << "Copies Needed: " << endl;
   cout << "Profit:$ " << endl;

    return 0;
}

