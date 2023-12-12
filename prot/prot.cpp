#include <iostream>
#include <string>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
};

class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototype: " << data << std::endl;
    }
};

int main() {
    ConcretePrototype original("Original Data");
    original.display();

    ConcretePrototype* clone = dynamic_cast<ConcretePrototype*>(original.clone());
    clone->display();

    delete clone;

    return 0;
}
