#include <iostream>
#include <string>

int main()
{
    //create some stuff
    std::cout << "HelloWorld!\n";

    //Program Loop
    bool exitCondition = false;
    std::string uInput = "a";
    while(!exitCondition)
    {
        std::cout << "Enter Command:";
        std::cin >> uInput;
        if(uInput == "exit"){
            exitCondition = true;
        }
    }
    std::cin >> uInput;
    return 0;
}