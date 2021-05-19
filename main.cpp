#include <iostream>

//Include command parser
#include "cpparser.hpp"

int main()
{
    //create some stuff
    

    //Program Loop
    bool exitCondition = false;
    std::string input;
    while(!exitCondition)
    {
        std::cin >> input;
        if(input == "exit"){
            exitCondition = true;
        }else{
            cpparser::process(input);
        }
    }
    std::cin >> input;
    return 0;
}