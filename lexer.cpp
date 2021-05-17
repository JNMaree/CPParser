#include "lexer.hpp"

namespace lexer{

    std::vector<std::string> tokenise(std::string* source)
    {
        std::vector<std::string> retVec;
        if (source->size() < 1){   //Empty String
            return retVec;
        }

        condense(source);

    }

    void condense(std::string* source)
    {
        //remove pre- & -post whiteSpace
        source->erase(0, source->find_first_not_of(whiteSpace));
        source->erase(source->find_last_not_of(whiteSpace) + 1);

        //condense whiteSpace to remove false occurences and accidental doubles
        size_t f = source->find_first_of(whiteSpace);
        while(f != std::string::npos)
        {
            size_t g = source->find_first_not_of(whiteSpace, f) - f;
            source->replace(f, g, 1, delimiter[0]);
            f = source->find_first_of(whiteSpace, f + 1);
        }
    }

}//namespace:lexer