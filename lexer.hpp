#include <string>
#include <vector>

/*delimiter:              - char: seperates tokens
*/
#define delimiter " _"
/*whiteSpace:     - String: characters considered to be whiteSpace
*/
#define whiteSpace " \t"

namespace lexer{

    //Function Prototypes
    std::vector<std::string> tokenise(std::string* source);
    void condense(std::string* source);


}//namespace:lexer