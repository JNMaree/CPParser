#include "cmd.hpp"

namespace cpparser
{
namespace command
{
    std::vector<cmd> cmdList;

    cmd::cmd(std::string mnemonic)
    {
        cmd push;
        cmdList.push_back(push);
    }

    cmd::~cmd()
    {
        for (size_t i = 0; i < cmdList.size(); ++i)
        {
            if(cmdList[i].mnemonic == mnemonic)
                cmdList.erase(cmdList.begin() + i);
        }
        
    }

    void add(std::string mnemonic,)
    {
        
    }

} //namespace:command
} //namespace:cpparser
