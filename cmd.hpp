#include <string>
#include <vector>
#include "lexer.hpp"

// Character definitions to be used by the lexer to tokenise the input string.

/*flagPre:                - char: parse the following text as a flag/switch
*/
#define flagPre "-/"
/*flagFullPre:            - String: full name for flag/switch
*/
#define flagFullPre "--"
/*commentLinePre:         - String/char: treats subsequent text on line as a comment
*/
#define commentLinePre ["//","#"]
/*commentMultiLinePre/Post:    - pre-String: treats subsequent text as a comment 
                                until post-String is parsed
*/
#define commentMultiLinePre ["/*"]
#define commentMultiLinePost ["*/"]

namespace cpparser{

    struct flag
    {
        std::string name;
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



