/* A header file to hold the 
main defintions of the program
Student: Jesus Cardenas
Teacher: Dr_T 10-17-2019
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//put libraries here
#include <iostream>
#include<string>
#include "Input_Validation_Extended.h" 
using namespace std;

//Function Prototypes 
void showMenu();//Menu DON'T TOUCH

void handleOption(string); //function prototype 
void velocityFunction();
void accelerationFunction();
void motionFunction();

//put definitions here
void showMenu() //Menu which user will see
{
  string green = "\x1b[" + to_string(32) + ";1m"; // Green color 
  string red = "\x1b[" + to_string(31) + ";1m" ;//  Red color
  cout<<green;
  cout << "\n\tMENU" << endl; 
  cout << red<< "A:"<<green<< " Velocity" <<endl; 
  cout << red<< "B:"<<green<< " Acceleration" << endl; 
  cout << red<< "C:"<<green<< " Motion" << endl; 
  cout << red<< "D:"<<green<< " Newton's Second Law" << endl; 
  cout << red<< "E:"<<green<< " Weight" <<endl;
  cout << red<< "F:"<<green<< " Momentum" <<endl;
  cout << red<< "G:"<<green<< " Exit" << endl; 
  cout << red<< "X:"<<green<< " Clear the screen" << endl;  
}

void handleOption(string userOption)
{
    //Velocity option A
    if(userOption == "A" || userOption == "a")
    {
      velocityFunction();

    }
   
    //Acceleration, option B
    else if(userOption == "B" || userOption == "b")
    {
      
      accelerationFunction();
     
    }


    // C Motion
    else if(userOption == "C" || userOption == "c")
    {
        motionFunction();
    }
     


    // D Newton's Second Law
    else if(userOption == "D" || userOption == "d")
    { 
     
    }


    // E Weight
    else if(userOption == "E" || userOption == "e")
    {
      
    }

    // F Momentum
    else if(userOption == "F" || userOption == "f")
    {
      
    }
/******************************************************************************/
    //Exit (DON'T TOUCH)
    else if(userOption == "G" || userOption == "g")
    {
      cout << "\033[2J\033[1;1H"; 
      cout << "\x1b[" + to_string(31) + ";1m"<<"\nDracarys!" << endl; 
    }
    
    //Clear screen (DON'T TOUCH)
    else if(userOption == "X" || userOption == "x")
    {
      string reset = "\x1b[0m";
      cout << reset; 
      cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
      //Windows: system("cls"); 
      system("clear"); //for ubuntu Linux Option 2 of 2
    }

    
    
    //Input validation (DON'T TOUCH)
    else
    {
      cout << "\nInvalid input: try again." << endl; 
    }
}
/********************************************************************************/



//Velocity function (A)
void velocityFunction () {
double ds = 0, dt=0, velocity=0;
      string dsUnit= " ", dtUnit=" ";


      cout << "\nLet's calculate velocity\n";
      cout << "\nFirst, what is the displayment(dS)? :";
      ds = validateDouble(ds); //cin >> ds; 
      cout <<"What unit of measure? ";
      dsUnit= validateString(dsUnit);
      cout<< "And the time (dt)? ";
      dt = validateDouble(dt);
      cout<< "Lastly, unit of measure for time: ";
      dtUnit= validateString(dtUnit);
      velocity=ds/dt; //calculatin velocity
      cout<<"\n\t\tVelocity is "<< velocity <<" "<<dsUnit<<"/"<<dtUnit<<endl<<endl;

}

//Acceleration function (B)
void accelerationFunction(){
double v0 = 0,vF=0, dt=0, acceleration=0;
      string dvUnit= " ", dtUnit=" ";


      cout << "\nLet's calculate acceleration\n";
      cout << "\nFirst, what is the initial velocity? :";
      v0 = validateDouble(v0); 
      cout << "Final velocity? :" ;
      vF = validateDouble(vF); 
      cout <<"What unit of measure? ";
      dvUnit= validateString(dvUnit);
      cout<< "What was the time? ";
      dt = validateDouble(dt);
      cout<< "Lastly, unit of measure for time: ";
      dtUnit= validateString(dtUnit);

      acceleration=(vF-v0)/dt; //calculatin velocity
      cout<<"\nAcceleration is "<< acceleration <<" "<<dvUnit<<"/"<<dtUnit<<endl<<endl;

}

//Motion function (C)
void motionFunction(){
  double v0,  //initial velocity
         v,   //final velocity
         a,   //acceleration
         t,   //time
         s,   //final displayment
         s0,  //initial displayment
         dv;  //delta velocity
  string reset = "\x1b[0m";
  string formulaOption;


      string c1 = "\x1b[" + to_string(30) + ";1m"; // Green color 
      string c2 = "\x1b[" + to_string(35) + ";1m" ;//  Red color
      cout<<c2;
      cout << "\n\tFunctions" << endl; 
      cout << c1<< "A:"<<c2<< " v = v0 + at" <<endl<<endl; 
      cout << c1<< "B:"<<c2<< " s = s0 + v0t + ½at2" << endl<<endl; 
      cout << c1<< "C:"<<c2<< " v2 = v02 + 2a(s − s0)" << endl<<endl; 
      cout << c1<< "D:"<<c2<< " v̅ = ½(v + v0)" << endl<<endl; 
      cout<< "What function would you like to use?";
      cout << reset;
      formulaOption = validateString(formulaOption);

      if(formulaOption == "A" || formulaOption == "a")
    {
      cout<<"You selected: v = v0 + at";
    }
    else if(formulaOption == "B" || formulaOption == "b")
    {
      cout<<"You selected: s = s0 + v0t + ½at2";
    }
    else if(formulaOption == "C" || formulaOption == "c")
    {
      cout<<"You selected: v2 = v02 + 2a(s − s0";
    }
    else if(formulaOption == "D" || formulaOption == "d")
    { 
      cout<<"You selected: v̅ = ½(v + v0)";
    }
    
    else
    {
      cout << "\nInvalid input: try again." << endl; 
    }

}
#endif