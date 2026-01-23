#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "Module.h"
#include <string>

class Placement : public Module {
private:
    std::string _description;

public:
    Placement(const std::string& name,
              const std::string& description,
              unsigned int students = 0);

    std::string getDescription() const;
    void setDescription(const std::string& description);
};
#endif 
