#pragma once
#include "student.h"
#include <vector>
class section {
public:
    string section_name;
    vector <student> students; // Vector to hold multiple students
    section(string n) : section_name(n) {}

};
