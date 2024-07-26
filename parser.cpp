#include <string>
#include <vector>

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