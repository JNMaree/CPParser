#include <vector>
#include <memory>

namespace command
{

    class cmd{

    };

    extern std::vector<std::unique_ptr<cmd>> cmdVector;

}//namespace:command