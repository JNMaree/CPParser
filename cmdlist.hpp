#include <vector>
#include <memory>

namespace command
{

    class cmd{
        const char* mnemonic;
        
    };

    extern std::vector<std::unique_ptr<cmd>> cmdVector;

}//namespace:command