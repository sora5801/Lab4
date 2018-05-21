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
//  Description:   This program takes in the book number, price per book, expected
//                 class enrollment,calculates the number of copies of a book needed
//                 if it is required or suggested, and if it is new or old,
//                 and give the profit of the store, which is calculated by taking the
//                 amount of money earned by the sales and subtracting 80% of it.
//
/*****************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

#define COPYPAID 0.8


/*****************************************************************************/
//
// Function:  int NumberOfBooks(CheckRequired_or_Suggested, char CheckNew_or_Old,
//                              int CheckExpectedClassEnrollment)
//
// Parameters:  char CheckRequired_or_Suggested - a character that is R or S
// (Inputs)     char CheckNew_Or_old - a character that is N or O
//              int CheckExpectedClassEnrollment - the expected number of enrollment
//
// Outputs:   None 
//
// Returns:    
//
// Author:     Matthew Fu
//
// Date:       2018.05.22
//
//
// Description: This function takes the user input and check if it is Required or Suggested, 
// New or Old. It only takes capital letters so if the user input a lowercase letter, then
// the function will convert it to uppercase. Then it will give the number of books required
// based on the expected class enrollment number. If it is a new,required book, then it will
// sell to 90% of the expected enrollment. If it is an old, required book, then it will sell to
// 65% of the expected enrollment. If it is a new, suggested book, then it will sell to 
// 40% of the expected enrollment. If it is an old, suggested book, then it will sell to
// 20% of the eexpected enrollment. If the user gives an invalid input, then the program
// will stop.
//
/*****************************************************************************/

int NumberOfBooks(char CheckRequired_or_Suggested, char CheckNew_or_Old, int CheckExpectedClassEnrollment)
{
   int NewRequiredBook = static_cast<int>(0.9 * CheckExpectedClassEnrollment + .5);
   int OldRequiredBook = static_cast<int>(0.65 * CheckExpectedClassEnrollment + .5);
   int NewSuggestedBook = static_cast<int>(0.4 * CheckExpectedClassEnrollment + .5);
   int OldSuggestedBook = static_cast<int>(0.2 * CheckExpectedClassEnrollment + .5);
   bool UserInputRequired = CheckRequired_or_Suggested == 'R';
   bool UserInputNew = CheckNew_or_Old == 'N';
   bool UserInputSuggested = CheckRequired_or_Suggested == 'S';
   bool UserInputOld = CheckNew_or_Old == 'O';
   if ((UserInputRequired == 1) && (UserInputNew == 1)) {
      return NewRequiredBook;
   }
   if ((UserInputRequired == 1) && (UserInputOld == 1)) {
      return OldRequiredBook;
   }
   if ((UserInputSuggested == 1) && (UserInputNew == 1)) {
      return NewSuggestedBook;
   }
   if ((UserInputSuggested == 1) && (UserInputOld == 1)) {
      return OldSuggestedBook;
   }
   if ((toupper(CheckRequired_or_Suggested) == 'R') && (toupper(CheckNew_or_Old) == 'N'))
      return NewRequiredBook;
   if ((toupper(CheckRequired_or_Suggested) == 'R') && (toupper(CheckNew_or_Old) == 'O'))
      return OldRequiredBook;
   if ((toupper(CheckRequired_or_Suggested) == 'S') && (toupper(CheckNew_or_Old) == 'N'))
      return  NewSuggestedBook;
   if ((toupper(CheckRequired_or_Suggested) == 'S') && (toupper(CheckNew_or_Old) == 'O'))
      return OldSuggestedBook;
   else
      cout << "Invalid input" << endl;
   exit(0);

}


/*****************************************************************************/
//
// Function:   double Profit(int TotalCopiesNeeded, double UnitPriceOfBooks)
//
// Parameters: int TotalCopiesNeeded - The copies needed that was calculated
// (Inputs)    double UnitPriceOfBooks - The price of each book
//             
//
// Outputs:    None
//
// Returns:    double profit, in dollars
//
// Author:     Matthew Fu
//
// Date:       2018.5.22
//
//
// Description:
// This function takes the total copies needed, calculated from the function numberofbooks
// and multiplies it with the Unit Price of Books, which is given, then subtracts that
// with the product of the number of books, unit price of the books, and the percentage that
// the store pays, which was defined globally.
//
//
/*****************************************************************************/

double Profit(int TotalCopiesNeeded, double UnitPriceOfBooks) {
   return (TotalCopiesNeeded * UnitPriceOfBooks) - (TotalCopiesNeeded * UnitPriceOfBooks * COPYPAID);
}


/*****************************************************************************/
//
// Function:   void Output(int CopiesNeeded, double TheProfit,long long int TheBookNumber)
//
// Parameters: int CopiesNeeded - The calculated amount of copies needed
// (Inputs)    double TheProfit - The calculated profit made by the bookstore
//             long long int - The ISBN book number
//
// Outputs:    None
//
// Returns:    none
//
// Author:     Matthew Fu
//
// Date:       2018.05.22
//
//
// Description: This function outputs all the information that was given and
// calculated starting with ISBN number, Copies needed, and profit in dollars.
//
/*****************************************************************************/

void Output(int CopiesNeeded, double TheProfit,long long int TheBookNumber) {
   cout << "ISBN: " << setw(10)<< setfill('0') << TheBookNumber << endl;
   cout << "Copies Needed: " << CopiesNeeded <<  endl;
   cout << setprecision(2) << fixed;
   cout << "Profit: $" << TheProfit << endl;
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
Profit: $139.92
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
Profit: $431.10
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
Profit: $283.40
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
Profit: $9.52
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

