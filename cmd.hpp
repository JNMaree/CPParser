#ifndef CMD_HPP_
#define CMD_HPP_

#include <string>
#include <vector>
#include <functional>
#include "lexer.hpp"

namespace cpparser
{
namespace command
{

    struct option
    {
        std::string flag;
        std::string flagFull;
        std::string description;
    };

    class cmd
    {
    private:
        std::vector<option> options;
        
    public:
        std::string name;
        std::string nameFull;
        std::string description;

        cmd();
        cmd(std::string cmdName, 
            std::string cmdFullname = "");
        ~cmd();

        void addOption(std::string optionName, 
                       std::string optionFullName = "", 
                       std::string description = "");
    };

    //function prototypes

    void add(std::string mnemonic, std::function<int(std::vector<lexer::Token>)>);

    int execute(std::vector<lexer::Token>* tokenVector);

} //namespace::command
} //namespace::cpparser
#endif