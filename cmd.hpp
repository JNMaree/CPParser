#ifndef CMD_HPP_
#define CMD_HPP_

#include <string>
#include <vector>
#include "lexer.hpp"





namespace cpparser{

    struct flag
    {
        std::string name = "";
        std::string fullname = "";
    
        std::string description;
    };

    struct flagValue : flag
    {
        union val{
            bool boolean = false;
            char character;
            char* characterSet;
            int integer;
            float floatingPoint;
        };
    };

    class cmd
    {
        public:
            std::string mnemonic;

        private:
            std::vector<flag> flags;
        
    };

    //Function Prototypes
    int process(std::string& cmdArgs);


}//namespace:cpparser


#endif