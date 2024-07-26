#include <string>
#include <vector>
#include "lexer.h"

class ProperAST {
public:
    virtual ~ProperAST() = default;
};

class PerAnnumAST : public ProperAST {
    double Val;

public:
    PerAnnumAST(double Val) : Val(Val) {

    }
};

class VariableAST : public ProperAST {
    std::string Name;
    
public:
    VariableAST(const std::string &Name) : Name(Name) {}
};


class BinaryAST : public ProperAST {
    char Op;
    std::unique_ptr<ProperAST> LHS, RHS;

public:
    BinaryAST(char Op, std::unique_ptr<ProperAST> LHS, std::unique_ptr<ProperAST> RHS) 
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

class CallUponAST : public ProperAST {
    std::string Callee;
    std::vector<std::unique_ptr<ProperAST>> Args;

public:
    CallUponAST(const std::string &Callee, std::vector<std::unique_ptr<ProperAST>> Args) 
      : Callee(Callee), Args(std::move(Args)) {}
};


class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;

public:
    PrototypeAST(const std::string &Name, std::vector<std::string> Args) 
      : Name(Name), Args(std::move(Args)) {}
    
    const std::string &getName() const { return Name; }
};


class FunctionAST {
    std::unique_ptr<PrototypeAST> Proto;
    std::unique_ptr<ProperAST> Body;

public:
    FunctionAST(std::unique_ptr<PrototypeAST> Proto, std::unique_ptr<ProperAST> Body) 
        : Proto(std::move(Proto)), Body(std::move(Body)){}
};


static int CurrentToken;
static int getNextToken() {
    return CurrentToken = get_next_token();
}