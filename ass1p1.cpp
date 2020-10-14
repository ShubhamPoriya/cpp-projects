// Student Name : SHUBHAM PORIYA
// Student ID   : 202005628
// STFX email   : x2020fem@stfx.ca  

// Assignment-1 : Problem-1 (Calculator)

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double num1, num2;        // Variables---> // assign input numbers double precision float type
    string op, format;                         // op is a character type i.e. "a", "b", etc. 
    double result;                             // result of the operation
    int pvalue, wvalue;                        // precision value and width value

    cout << "Number 1: \n";   
    cin >> num1;                               // input of num1
    cout << "Number 2: \n";
    cin >> num2;                               // input of num2
    cout << "Operation (a/s/d/m): \n";
    cin >> op;                                 // input of operator
    cout << "Choose output format:\n";
    cout << "'w' - set width\n";
    cout << "'p' - set precision\n";
    cout << "'r' - without formatting\n";
    cin >> format;                            // input for output format 

    if (format == "p"){
        cout << "Enter an integer precision value of your choice: \n";
        cin >> pvalue;                         // input precision value for setprecision format
    }else if(format == "w"){
        cout << "Enter an integer width value of your choice: \n";
        cin >> wvalue;                         // input precision value for setwidth format
    }else if(format == "r"){
        cout << "You will get output in regular format.\n";  // message 
    }else{
        cout << "Enter a valid format character (p/w/r)";     
        return 0;                                            // exit the program 
    }
                  

    if(op == "a"){
        result = num1 + num2;                  // addition if operator == "a"
    }else if(op == "s"){
        result = num1 - num2;                  // subtraction if operator == "s"
    }else if(op == "d"){
        if(num2 == 0){                         // handling exception case i.e. denominator != 0  
            throw runtime_error("Attempted to divide by zero");             // error message
            return 0;                                                        // exit from program
        } else{
            result = num1/num2;                // divide if operator == "d"
        }
    }else if(op == "m"){
        result = num1 * num2;                  // multiply if operator == "m" 
    } else{
        cout << "Incorrect operator! enter numbers for first two inputs and (a/s/d/m) for last input only.\n";   // print error message if operator input is other than (a/s/d/m)
    }
    

    if(format == "p"){                                   
        cout << setprecision(pvalue) << result;       // result in precision format 
    }else if(format == "w"){
        cout << "(" << setw(wvalue) << result << ")"; // result in specified width format 
    }else if(format == "r"){
        cout << result;                               // result without any formatting
    }
    return 0;                          
}