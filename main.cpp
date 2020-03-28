/*Physics calculator 
Author: Jesus Cardenas, 
Teacher: Dr_T
*/

#include "calculations.h"

int main() 
{
  string option = ""; //the option local to int main()
  string color = "\x1b[" + to_string(31) + ";1m"; //Red color
  string reset = "\x1b[0m";
  //loop until the user provides "e" or (&&) "E" as exit condition
  
  do
  {
    showMenu(); //call a menu void function here
    cout << "\nPlease enter an option: ";
    //cin >> option; //getline(cin,option); //get the entire line
    cout << color; //change color, reference "string color" 
    option = validateString(option); 
    cout <<endl<< reset; //reset back to standard
    handleOption(option); //call handleOption and pass the user option as an argument
    
  
  }while(option != "g" && option != "G"); //DeMorgan's Law!!! 
  
  
 
  return 0; 
}