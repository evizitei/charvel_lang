#include <string>

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