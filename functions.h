/* A header file to hold the 
main defintions of the program
Student: You
Teacher: Dr_T 10-17-2019, updated 3-24-2020 (clear screen methods for Ubuntu)
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//put libraries here
#include <iostream>
#include<string>
#include "Input_Validation_Extended.h" 
using namespace std;

//put prototypes here
void handleOption(string); //function prototype 
void showMenu(); 
void printMulti(int,char);
string evenOddChecker(int); 
int numberReverse(int); 
void getMinMax(double,double,double);  

//put definitions here
void handleOption(string userOption)
{
    int rows = 0, num = 0;
    char theChar = '\0'; //null char '\0' 
    double num1 = 0.0, num2 = 0.0, num3 = 0.0; 
    if(userOption == "A" || userOption == "a")
    {
      cout << "\nTime to print some Triangle patterns\n";
      cout << "\nHow Many rows: ";
      rows = validateInt(rows); //cin >> rows; 
      cout << "\nWhat char would you like to print: "; 
      theChar = validateChar(theChar); //cin >> theChar; 
      printMulti(rows,theChar);//call the printMulti function 
    }
    else if(userOption == "B" || userOption == "b")
    {
      cout << "\nIt's Even/Odd time ya'll!" << endl; 
      num = validateInt(num); //cin >> num; 
      cout << "Your number is " << evenOddChecker(num) << endl; 
    }
    else if(userOption == "C" || userOption == "c")
    {
      cout << "\nIt's reverse number time!"; 
      cout << "What number would you like to reverse: "; 
      num = validateInt(num); //cin >> num; 
      cout << "\nYour number Reversed is " << numberReverse(num) << endl; 
    }
    else if(userOption == "D" || userOption == "d")
    { 
      cout << "\nIt's min/max time ya'll" << endl ;
      cout << "Please enter 3 numbers (enter between each): "; 
      //cin >> num1 >> num2 >> num3; 
      num1 = validateDouble(num1);
      num2 = validateDouble(num2); 
      num3 = validateDouble(num3); 
      getMinMax(num1,num2,num3); //function call of a void function

    }
    else if(userOption == "X" || userOption == "x")
    {
      string reset = "\x1b[0m";
      //Linux Umbunu
      cout << reset; 
      cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
      //Windows: system("cls"); 
      system("clear"); //for ubuntu Linux Option 2 of 2
    }
    else if(userOption == "E" || userOption == "e")
    {
      cout << "\nEnd program. Hasta la vista, Baby!!" << endl; 
    }
    else
    {
      cout << "\nInvalid input: try again." << endl; 
    }
}

void showMenu()
{
  cout << "\nMENU" << endl; 
  cout << "A: print triangle patterns" <<endl; 
  cout << "B: even odd checker" << endl; 
  cout << "C: reverse a number" << endl; 
  cout << "D: get min and max" << endl; 
  cout << "E: Exit" << endl; 
  cout << "X: clear the screen" << endl;  
}
//definintion 
void printMulti(int r,char c)
{
   for(int i = 0; i <= r; i++)
   {
     for(int j=i; j>0; j--)
     {
       cout << c; 
     }
     cout << endl; 
   }
   cout << "\nand\n" << endl; 
   //new nested for loop to go other way
   for(int i=r; i >=0; i--)
   {
     for(int j=1; j<=i; j++)
     {
       cout << c; 
     }
     cout << endl; 
   }

}

string evenOddChecker(int number)
{
  string result = ""; 
  //determine if number is even/odd assign "odd" or "even"
  result = ( (number % 2) == 0) ? "even" : "odd"; 
      /*
      if( (number % 2) == 0)
      {
        result = "even"; 
      }
      else if((number % 2) == 1)
      {
        result = "odd"; 
      }
      */
  return result;
}

int numberReverse(int number)
{
  int reversedNumber = 0, rem = 0;
  //reverse process
  while(number != 0)
  {
    rem = number % 10; 
   //   cout << rem << ","; 
    reversedNumber = reversedNumber*10+rem; 
    //  cout << reversedNumber << ","; 
    number /= 10; //int division
   //   cout << number << endl; 
  } //per javaPoint.com 
  
  return reversedNumber; 
}

void getMinMax(double n1,double n2,double n3)
{    
   string color = "";
   string reset = "\x1b[0m";
    //Max test block 
    if(n1 > n2 && n1 > n3)
    { 
      color = "\x1b[" + to_string(36) + ";1m";
      cout << "\nMax is " << color << n1 << reset << endl; 
    }
    else if(n2 > n1 && n2 > n3)
    {
      color = "\x1b[" + to_string(42) + ";1m";
      cout << "\nMax is " << color << n2 << reset << endl; 
    }
    else if(n3 > n2 && n3 > n1)
    {
      cout << "\nMax is " << n3 << endl; 
    }
    else
    {
      cout << "\nThe numbers are the same, or something went wrong.\n"; 
    }
    //Min test block
    if(n1 < n2 && n1 < n3)
    {
      cout << "\nMin is " << n1 << endl; 
    }
    else if(n2 < n1 && n2 < n3)
    {
      cout << "\nMin is " << n2 << endl; 
    }
    else if(n3 < n2 && n3 < n1)
    {
      cout << "\nMin is " << n3 << endl; 
    }
    else
    {
      cout << "\nThe numbers are the same, or something went wrong.\n"; 
    } 


}
#endif