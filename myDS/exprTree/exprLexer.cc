#include "exprLexer.hh"

#define RUN_EXPRLEXER 1

strVec readFile(std::string fileName) {
    std::fstream file;
    file.open(fileName, std::ios_base::in);
    if (!file.is_open()) {
        std::cout << "No file under given name: "
                  << fileName
                  << std::endl;
        file.close();
        exit(0);
    }

    strVec expressions;
    std::string line;
    while (getline(file, line))
        expressions.push_back(line);
    file.close();

    return expressions;
}

exprVec lexer(std::string & line) {
    exprVec lexed;
    std::cout << line << std::endl;

    return lexed;
}

void test () {
    std::string tName = "test_expr.txt";
    std::string aName = "ans_expr.txt";
    
    strVec tFile = readFile(tName);
    strVec aFile = readFile(aName);
    
    exprsVec exprs;
    for (std::string line : tFile){
        exprVec expr = lexer(line);
        exprs.push_back(expr);
    }
    std::cout << "Tot size = " << exprs.size() << std::endl;
}

#if RUN_EXPRLEXER
    int main () {
        test();
        return 0;
    }
#endif