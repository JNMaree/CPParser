#ifndef CMD_HPP_
#define CMD_HPP_

#include <string>
#include <vector>
#include "lexer.hpp"


    struct flag
    {
        std::string name = "";
        std::string fullname = "";
    
        std::string description;
    };

    class cmd
    {
        public:
            std::string mnemonic;
            void help();

        private:
            std::vector<flag> flags;
        
    };





#endif