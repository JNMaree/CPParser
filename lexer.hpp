#ifndef LEXER_HPP_
#define LEXER_HPP_

#include <string>
#include <vector>
#include <algorithm>

// Character definitions to be used by the lexer to tokenise the input string.

/** delimiter:          - char: seperates tokens
*/
#define delimiter " "

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
        quoted,
        integer,
        decimal,
        file,
        directory
    };

    class Token{
        std::string* text;
        static Type type;
        void setType();

    public:
        Token();
        Token(std::string* source);
        Token(std::string& source);
        
        Type getType();
    };

    class Tokentainer{
    private:
        Token* arrayPtr;
        static size_t arraySize;
        static size_t arrayCapacity;

    public:
        Token& operator[](size_t index){
            if(index < 0 || index >= arraySize)
                throw "Tokentainer:OutOfBounds\n";
            return arrayPtr[index];
        }

        Tokentainer();
        Tokentainer(size_t size, Token default = Token());
        ~Tokentainer();

        void push(Token& toki);

        bool empty();
    };


    //Function Prototypes
    Tokentainer tokenise(std::string* source);
    void condense(std::string* source);
    bool isSame(std::string& str, std::string& cmp);
    bool isSameCase(std::string& str, std::string& cmp);

}//namespace:lexer
}//namespace:cpparser
#endif