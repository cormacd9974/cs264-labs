#ifndef MODULE_H
#define MODULE_H
#include <string>

class Module {
private:
    std::string _name;
    unsigned int _students;
    unsigned int _credits;

public:
    Module();
    Module(const std::string& name, unsigned int credits = 2, unsigned int students = 0);

    std::string getName() const;
    unsigned int getStudents() const;
    unsigned int getCredits() const;

    void setName(const std::string& name);
    void setStudents(unsigned int students);
    void setCredits(unsigned int credits);

    bool operator==(const Module& other) const;
};
#endif 
