#include "parser.hpp"

namespace yy {

    class Scanner
    {
    public:
        Scanner();
        ~Scanner();
        yy::Parser::symbol_type lex();
    private:
        int count;
    };

}