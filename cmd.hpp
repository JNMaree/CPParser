#ifndef CMD_HPP_
#define CMD_HPP_

#include <string>
#include <vector>
#include "lexer.hpp"

namespace cpparser
{
namespace command
{

    struct option
    {
        std::string name = "";
        std::string fullname = "";

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
        cmd(std::string cmdName, std::string cmdFullname = "");
        ~cmd();


    };

    extern std::vector<cmd> cmdList;

} //namespace::command
} //namespace::cpparser
#endif