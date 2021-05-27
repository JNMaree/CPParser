#include <iostream>

#include "cpparser.hpp"

int writeFunction(std::vector<cpparser::lexer::Token> tokenVector);

int main()
{
    //Create Commands
    cpparser::command::add("write", writeFunction);

    //Program Loop
    bool exitCondition = false;
    std::string uInput;
    while(!exitCondition)
    {
        std::cout << std::endl << "Enter Command:";
        std::cin >> uInput;
        int proc = cpparser::process(uInput);
        if (proc == 0)
            exitCondition == true;
        else if(proc < 0)
            std::cerr << "INput Error:" << uInput << " not recognised.";
    }
    std::cin.get();
    return 0;
}

int writeFunction(std::vector<cpparser::lexer::Token> tokenVector)
{
    std::cout << "writeFunctionEXECUTE:" << std::endl;

}