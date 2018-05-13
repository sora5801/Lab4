/*****************************************************************************/
//  Filename:      Lab4.cpp
//
//  Author:        Matthew Fu
//
//  Date:          2018.05.22
//
//  
//
//
//  Description:   This program calculates the number of copies of a book needed
//                 if it is required or suggested, and if it is new or old,
//                 and give the profit of the store.
//
/*****************************************************************************/
#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;

#define COPYPAID 0.8

//Unfortunately, I bruteforced at bit here as
// I could not make (x || toupper(x)) or any of it's variant
//work. I could only exhaust all possibility.
int NumberOfBooks(char x, char y, int z) {
   int x1 = static_cast<int>(0.9 * z + .5);
   int x2 = static_cast<int>(0.65 * z + .5);
   int x3 = static_cast<int>(0.4 * z + .5);
   int x4 = static_cast<int>(0.2 * z + .5);
   bool b1 = x == 'R';
   bool b2 = y == 'N';
   bool b3 = x == 'S';
   bool b4 = y == 'O';
   if ((b1 == 1) && (b2 == 1)) {
      return x1;
   }
   if ((b1 == 1) && (b4 == 1)) {
      return x2;
   }
   if ((b3 == 1) && (b2 == 1)) {
      return x3;
   }
   if ((b3 == 1) && (b4 == 1)) {
      return x4;
   }
   if ((toupper(x) == 'R') && (toupper(y) == 'N'))
      return x1;
   if ((toupper(x) == 'R') && (toupper(y) == 'O'))
      return x2;
   if ((toupper(x) == 'S') && (toupper(y) == 'N'))
      return  x3;
   if ((toupper(x) == 'S') && (toupper(y) == 'O'))
      return x4;
   else
      cout << "Invalid input" << endl;
   exit(0);

}


//Not Exactly clear on what the professor meant by profit,
//So for now, I will keep it like this.
double Profit(int a, double b) {
   return (a * b) - (a * b * COPYPAID);
}
//Curiously, The problem said that I can only have
//one function for all output. I wonder if the 
//current code I have right now is sufficient.
void Output(int d, double f,long long int g) {
   cout << "ISBN: " << setw(10)<< setfill('0') << g << endl;
   cout << "Copies Needed: " << d <<  endl;
   cout << setprecision(2) << fixed;
   cout << "Profit:$ " << f << endl;
}

int main()
{
   long long int BookNumber;
   int ExpectedClassEnrollment;
   double price;
   char Required_or_suggested;
   char New_or_Old;

   cout << "Solution provided by Matthew Fu" << endl;

   //I ask for a bunch of input. The problem on the Lab
   //says that these have to be part of the output function.
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

   //I put the functions as variables.
   int c = NumberOfBooks(Required_or_suggested, New_or_Old, ExpectedClassEnrollment);
   double e = Profit(c, price);

   Output(c, e, BookNumber);

   

    return 0;
}
//All Five Outputs so far.
/*
Solution provided by Matthew Fu
Enter book number:
0755798652
Enter price per copy:
34.98
Enter expected class enrollment:
31
Enter 'R' if required or 'S' if suggested:
R
Enter 'N' if new or 'O' if not a new text:
O
ISBN: 0755798652
Copies Needed: 20
Profit:$ 139.92
Press any key to continue . . .

Solution provided by Matthew Fu
Enter book number:
3453456784
Enter price per copy:
23.95
Enter expected class enrollment:
100
Enter 'R' if required or 'S' if suggested:
r
Enter 'N' if new or 'O' if not a new text:
N
ISBN: 3453456784
Copies Needed: 90
Profit:$ 431.10
Press any key to continue . . .

Solution provided by Matthew Fu
Enter book number:
5677655673
Enter price per copy:
54.50
Enter expected class enrollment:
40
Enter 'R' if required or 'S' if suggested:
R
Enter 'N' if new or 'O' if not a new text:
O
ISBN: 5677655673
Copies Needed: 26
Profit:$ 283.40
Press any key to continue . . .

Solution provided by Matthew Fu
Enter book number:
2462462464
Enter price per copy:
5.95
Enter expected class enrollment:
40
Enter 'R' if required or 'S' if suggested:
s
Enter 'N' if new or 'O' if not a new text:
O
ISBN: 2462462464
Copies Needed: 8
Profit:$ 9.52
Press any key to continue . . .

Solution provided by Matthew Fu
Enter book number:
8953647888
Enter price per copy:
65.99
Enter expected class enrollment:
35
Enter 'R' if required or 'S' if suggested:
N
Enter 'N' if new or 'O' if not a new text:
Y
Invalid input
Press any key to continue . . .
*/

