#ifndef CMD_HPP_
#define CMD_HPP_

#include <string>
#include <vector>
#include "lexer.hpp"

namespace cpparser
{
namespace command
{

    struct flag
    {
        std::string name = "";
        std::string fullname = "";

        std::string description;
    };

    class cmd
    {
    private:
        std::vector<flag> flags;
        
    public:
        std::string mnemonic;
        cmd();
        cmd(std::string mnemonic);
        ~cmd();
    };

    extern std::vector<cmd> cmdList;

} //namespace::command
} //namespace::cpparser
#endif