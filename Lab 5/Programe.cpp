#include "Programme.h"
#include <sstream>

Programme::Programme(const std::string& name,
                     unsigned int year,
                     unsigned int capacity)
    : _name(name),
      _year(year),
      _capacity(capacity),
      _count(0)
{
    _modules = new Module[_capacity];
}

Programme::Programme(const Programme& other)
    : _name(other._name),
      _year(other._year),
      _capacity(other._capacity),
      _count(other._count)
{
    _modules = new Module[_capacity];
    for (unsigned int i = 0; i < _count; ++i) {
        _modules[i] = other._modules[i];
    }
}

Programme& Programme::operator=(const Programme& other) {
    if (this != &other) {
        delete[] _modules;
        _name = other._name;
        _year = other._year;
        _capacity = other._capacity;
        _count = other._count;
        _modules = new Module[_capacity];
        for (unsigned int i = 0; i < _count; ++i) {
            _modules[i] = other._modules[i];
        }
    }
    return *this;
}

Programme::~Programme() {
    delete[] _modules;
}

std::string Programme::getName() const {
    return _name;
}

void Programme::setName(const std::string& name) {
    _name = name;
}

unsigned int Programme::getYear() const {
    return _year;
}

void Programme::setYear(unsigned int year) {
    _year = year;
}

bool Programme::addModule(Module* module) {
    if (_count >= _capacity || module == nullptr) {
        return false;
    }
    _modules[_count] = *module;  
    ++_count;
    return true;
}

std::string Programme::toStr() const {
    std::ostringstream oss;
    oss << "Programme: " << _name << " (Year " << _year << ")\n";
    oss << "Modules (" << _count << "):\n";

    for (unsigned int i = 0; i < _count; ++i) {
        oss << "  - " << _modules[i].getName()
            << " | Credits: " << _modules[i].getCredits()
            << " | Students: " << _modules[i].getStudents()
            << "\n";
    }
    return oss.str();
}

