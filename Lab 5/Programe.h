#ifndef PROGRAMME_H
#define PROGRAMME_H
#include <string>
#include "Module.h"

class Programme {
private:
    std::string _name;
    unsigned int _year;
    Module* _modules;         
    unsigned int _capacity;    
    unsigned int _count;       

public:
   
    Programme(const std::string& name,
              unsigned int year,
              unsigned int capacity);
    Programme(const Programme& other);
    Programme& operator=(const Programme& other);
    ~Programme();

    std::string getName() const;
    void setName(const std::string& name);

    unsigned int getYear() const;
    void setYear(unsigned int year);

    bool addModule(Module* module); 

    std::string toStr() const;
};

#endif 

