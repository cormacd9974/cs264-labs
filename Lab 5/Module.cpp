#include "Module.h"

Module::Module() : _name(""), _students(0), _credits(2) {}

Module::Module(const std::string& name, unsigned int credits, unsigned int students)
    : _name(name), _students(students), _credits(credits) {}

std::string Module::getName() const {
    return _name;
}

unsigned int Module::getStudents() const {
    return _students;
}

unsigned int Module::getCredits() const {
    return _credits;
}

void Module::setName(const std::string& name) {
    _name = name;
}

void Module::setStudents(unsigned int students) {
    _students = students;
}

void Module::setCredits(unsigned int credits) {
    _credits = credits;
}

bool Module::operator==(const Module& other) const {
    return (_name == other._name) && (_credits == other._credits);
}
