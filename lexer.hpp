#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>
#include <vector>

// Character definitions to be used by the lexer to tokenise the input string.

/** delimiter:          - char: seperates tokens
*/
#define delimiter ' '

/** whiteSpace:         - String: characters considered to be whiteSpace
*/
#define whiteSpace " \t"

/*flagPre:              - char: parse the following text as a flag/switch
*/
#define flagPre '-'

/*commentLinePre:         - String/char: treats subsequent text on line as a comment
*/
#define commentLinePre ["//","#"]

/*commentMultiLinePre/Post:    - pre-String: treats subsequent text as a comment 
                                until post-String is parsed
*/
#define commentMultiLinePre ["/*"]
#define commentMultiLinePost ["*/"]

/*stringPre:            - char: the pre- and -post markers for strings
*/
#define stringPre '"'
/*bracketPre:            - char: the pre- and -post markers for strings

*/
#define parenthesisPre '('
#define parenthesisPost ')'

namespace cpparser
{
namespace lexer
{
    
    enum Type{
        undetermined,
        flag,
        flagFull,
        string,
        integer,
        decimal,
    };

    class Token{
    public:
        std::string text;
        Type type = undetermined;
        Token(std::string* source);
        Token(std::string& source);
        void set();
    };


    //Function Prototypes

    std::vector<Token> tokenise(std::string* source);
    void condense(std::string* source);


}//namespace:lexer
}//namespace:cpparser
#endif