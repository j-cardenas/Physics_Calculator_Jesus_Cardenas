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
#include <cmath>

using namespace std;

//Function Prototypes 
void showMenu();//Menu DON'T TOUCH

void handleOption(string); //function prototype 
void velocityFunction();
void accelerationFunction();
void motionFunction();
void newtonsFunction();

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
     newtonsFunction();
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
      cout << c1<< "B:"<<c2<< " s = s0 + v0t + ½at^2" << endl<<endl; 
      cout << c1<< "C:"<<c2<< " v^2 = v0^2 + 2a(s − s0)" << endl<<endl; 
      cout << c1<< "D:"<<c2<< " v̅ = ½(v + v0)" << endl<<endl; 
      cout<< "What function would you like to use? ";
      cout << reset;
      formulaOption = validateString(formulaOption);

      if(formulaOption == "A" || formulaOption == "a")
    {
      cout << "\nYou selected: v = v0 + at";

      cout << "\n\nWhat is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      cout << "What is the time? ";
      t=validateDouble(t);
      v=(v0+(a*t)); //calculating velocity
      cout <<"\t\tv = "<<v<<endl;

    }
    else if(formulaOption == "B" || formulaOption == "b")
    {
      cout<<"\nYou selected: s = s0 + v0t + ½at^2";
      

      cout <<"\n\nWhat is the initial displayment?";
      s0=validateDouble(s0);
      cout << "What is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      cout << "What is the time? ";
      t=validateDouble(t);
      s=(s0+ (v0*t)+(0.5*a*(t*t))); //calculating displayment
      cout <<"\t\ts = "<<s<<endl;

    }
    else if(formulaOption == "C" || formulaOption == "c")
    {
      cout<<"\nYou selected: v^2 = v0^2 + 2a(s − s0)";

      cout <<"\n\nWhat is the initial displayment?";
      s0=validateDouble(s0);
      cout <<"What is the final displayment?";
      s=validateDouble(s);
      cout << "What is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      
      v=(v0*v0)+((2*a)*(s-s0)); //calculating v^2
      cout <<"\t\tv^2 = "<<v<<" and v = "<<sqrt(v)<<endl;

    }
    else if(formulaOption == "D" || formulaOption == "d")
    { 
      cout<<"\nYou selected: v̅ = ½(v + v0)";


      cout << "\n\nWhat is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the final velocity? ";
      v=validateDouble(v);
      
      dv= (0.5)*(v+v0); //calculating delta v
      cout <<"\t\tv̅ = "<<dv<<endl;

    }
    
    else
    {
      cout << "\nInvalid input: try again." << endl; 
    }

}

//Newton's Second Law (D)
void newtonsFunction(){
double mass=0, acceleration=0;
string mU="", aU="";
cout<<"You have selected: ∑F = ma ";
cout<<"\nWhat is the mass? ";
mass=validateDouble(mass);
cout<<"What is the unit of measure for mass? ";
mU=validateString(mU);
cout<<"What is the acceleration? ";
acceleration=validateDouble(acceleration);
cout<<"Lastly, what is the unit of measure for acceleration? ";
aU=validateString(aU);

cout<<"\t\tN = "<<(mass*acceleration)<<" "<<mU<<"/"<<aU<<endl<<endl;


}


#endif