#pragma once
#include "person.h"
class student : public person {
public:
	string enrollment;
	student(string n, string en) :person(n) {
		enrollment = en;
	}
};

