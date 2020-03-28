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
void weightFunction();
void momentumFunction();


string highlight="\x1b[" + to_string(41) + ";1m" ;
string reset = "\x1b[0m";
string bold = "\x1b[" + to_string(50) + ";1m" ;
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
  cout << red<< "F:"<<green<< " Weight" <<endl;
  cout << red<< "H:"<<green<< " Momentum" <<endl;
  cout << red<< "E:"<<green<< " Exit" << endl; 
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


    // F Weight
    else if(userOption == "F" || userOption == "f")
    {
      weightFunction();
    }

    // F Momentum
    else if(userOption == "H" || userOption == "h")
    {
      momentumFunction();
    }
/******************************************************************************/
    //Exit (DON'T TOUCH)
    else if(userOption == "e" || userOption == "E")
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


      cout <<endl;
      cout <<highlight<<"\t\tv  = ds / dt"<<reset<<endl;
      cout << "\n\nFirst, what is the displayment(dS)? :";
      ds = validateDouble(ds); //cin >> ds; 
      cout <<"What unit of measure? ";
      dsUnit= validateString(dsUnit);
      cout<< "And the time (dt)? ";
      dt = validateDouble(dt);
      cout<< "Lastly, unit of measure for time: ";
      dtUnit= validateString(dtUnit);
      velocity=ds/dt; //calculatin velocity
      cout<<bold<<"\n\t\tVelocity is "<< velocity <<" "<<dsUnit<<"/"<<dtUnit<<reset<<endl<<endl;

}

//Acceleration function (B)
void accelerationFunction(){
double v0 = 0,vF=0, dt=0, acceleration=0;
      string dvUnit= " ", dtUnit=" ";


      cout <<endl;
      cout<<highlight<<"\t\ta= dv/dt"<<reset<<endl;

      cout << "\n\nFirst, what is the initial velocity? :";
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
      cout<<bold<<"\nAcceleration is "<< acceleration <<" "<<dvUnit<<"/"<<dtUnit<<reset<<endl<<endl;

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


      string c1 = "\x1b[" + to_string(30) + ";1m"; //  color 
      string c2 = "\x1b[" + to_string(35) + ";1m" ;//  color
      cout<<c2;
      cout << "\n\tFunctions" << endl; 
      cout << c1<< "A:"<<c2<< " v = v0 + at" <<endl<<endl; 
      cout << c1<< "B:"<<c2<< " s = s0 + v0t + ½at^2" << endl<<endl; 
      cout << c1<< "C:"<<c2<< " v^2 = v0^2 + 2a(s − s0)" << endl<<endl; 
      cout << c1<< "D:"<<c2<< " v̅ = ½(v + v0)" << endl<<endl; 
      cout<< "What function would you like to use? ";
      cout << reset;
      formulaOption = validateString(formulaOption);

    if(formulaOption == "A" || formulaOption == "a"){
      cout <<highlight<< "\n\t\tv = v0 + at"<<reset;

      cout << "\n\nWhat is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      cout << "What is the time? ";
      t=validateDouble(t);
      v=(v0+(a*t)); //calculating velocity
      cout <<bold<<"\t\tv = "<<v<<reset<<endl;

    }
    else if(formulaOption == "B" || formulaOption == "b")
    {
      cout<<highlight<<"\n\t\ts = s0 + v0t + ½at^2"<<reset;
      

      cout <<"\n\nWhat is the initial displayment?";
      s0=validateDouble(s0);
      cout << "What is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      cout << "What is the time? ";
      t=validateDouble(t);
      s=(s0+ (v0*t)+(0.5*a*(t*t))); //calculating displayment
      cout <<bold<<"\t\ts = "<<s<<reset<<endl;

    }
    else if(formulaOption == "C" || formulaOption == "c")
    {
      cout<<highlight<<"\n\t\tv^2 = v0^2 + 2a(s − s0)"<<reset;

      cout <<"\n\nWhat is the initial displayment?";
      s0=validateDouble(s0);
      cout <<"What is the final displayment?";
      s=validateDouble(s);
      cout << "What is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the acceleration? ";
      a= validateDouble(a);
      
      v=(v0*v0)+((2*a)*(s-s0)); //calculating v^2
      cout <<bold<<"\t\tv^2 = "<<v<<" and v = "<<sqrt(v)<<endl<<reset;

    }
    else if(formulaOption == "D" || formulaOption == "d")
    { 
      cout<<highlight<<"\n\t\t v̅ = ½(v + v0)"<<endl<<reset;


      cout << "\n\nWhat is the initial velocity? ";
      v0=validateDouble(v0);
      cout << "What is the final velocity? ";
      v=validateDouble(v);
      
      dv= (0.5)*(v+v0); //calculating delta v
      cout <<bold<<"\t\tv̅ = "<<dv<<reset<<endl;

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


    cout<<highlight;
    cout<<"\t\t∑F = ma ";
    cout<<reset;

    cout<<"\nWhat is the mass? ";
    mass=validateDouble(mass);
    cout<<"What is the unit of measure for mass? ";
    mU=validateString(mU);
    cout<<"What is the acceleration? ";
    acceleration=validateDouble(acceleration);
    cout<<"Lastly, what is the unit of measure for acceleration? ";
    aU=validateString(aU);

    cout<<bold ;
    cout<<"\t\tN = "<<(mass*acceleration)<<" "<<mU<<"/"<<aU<<endl<<endl<<reset;

}

//Weight function (F)
void weightFunction(){
  double mass=0, gravity=0;
  string uM="";

  cout<<highlight;
  cout<<"\n\tWeight = Mass x Gravity ";
  cout<<reset;


  cout<<"\n\nWhat is the mass? ";
  mass= validateDouble(mass);
  cout<<"What is the force of gravity? ";
  gravity= validateDouble(gravity);
  cout<<"What is the expected unit of measurement? ";
  uM = validateString(uM);



  cout<<bold<<"\t\tWeight = "<<(mass*gravity)<<" "<<uM<<".\n\n"<<reset;
}


//Momentum function (H)
void momentumFunction(){

  double mass=0, velocity=0;
  string uV="",uM;


  cout<<bold <<"\tMomentum keeps me going. "<<reset;

  cout<<highlight<<"\n\n\tMomentum = Mass x Velocity "<<reset<<endl;

  cout<<"\nWhat is the mass? ";
  mass = validateDouble(mass);

  cout<<"Expected unit of measure for mass? ";
  uM= validateString(uM);


  cout<<"What is the velocity? ";
  velocity = validateDouble(velocity);
  cout<<"Expected unit of measure for velocity? ";
  uV= validateString(uV);
  

  cout<< bold <<"\tMomentum = "<<(mass*velocity)<<" "<<uM<<"/" <<uV<<".\n\n"<<reset;





}

#endif