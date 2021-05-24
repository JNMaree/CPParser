#ifndef CPPARSER_HPP_
#define CPPARSER_HPP_

#include <string>


namespace cpparser{

    //Function Prototypes
    int process(std::string& cmdArgs);

    void create(std::string commandName, int response);

}//namespace:cpparser

#endif