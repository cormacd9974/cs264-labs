#include "Placement.h"
Placement::Placement(const std::string& name,
                     const std::string& description,
                     unsigned int students)
    : Module(name, 15, students),  
      _description(description) {}

std::string Placement::getDescription() const {
    return _description;
}
void Placement::setDescription(const std::string& description) {
    _description = description;
}
