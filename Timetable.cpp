#include "Timetable.h"
#include <iostream>

void Timetable:: addCourse(const string& course_name) {
	course new_course(course_name);
	courses.push_back(new_course);
}
void Timetable:: addStudent(const string& name, const string& enrollment) {
	student new_student(name, enrollment);
	students.push_back(new_student);
}
void Timetable:: addTeacher(const string& name, const string& teacher_id) {
	teacher new_teacher(name, teacher_id);
	teachers.push_back(new_teacher);
}
void Timetable::addSection(const string& section_name, const string& student_name, const string& enrollment) {
	// Check if the section exists in the sections vector
	auto it = find_if(sections.begin(), sections.end(), [&](const section& s) {
		return s.section_name == section_name;
		});

	if (it != sections.end()) {
		// If the section exists, add the student to it
		student new_student(student_name, enrollment);
		it->students.push_back(new_student);
	}
	else {
		// If the section doesn't exist, create a new section and add the student to it
		section new_section(section_name);
		student new_student(student_name, enrollment);
		new_section.students.push_back(new_student);
		sections.push_back(new_section);
	}
}
void Timetable::addStudentToSection(const string& section_name, const string& student_name, const string& enrollment) {
	for (auto& section : sections) {
		if (section.section_name == section_name) {
			student new_student(student_name, enrollment);
			section.students.push_back(new_student); // Add student to the section's students vector
			return;
		}
	}
	cout << "Section " << section_name << " not found." << endl;
}
void Timetable::addCourse(const string& day, const course& c, const teacher& t, const room& r, const time_& ti, const section& s) {
	entries.push_back(TimetableEntry(day, c, t, r, ti, s));
}
void Timetable::add_room(const string& room_no) {
	room new_room(room_no);
	rooms.push_back(new_room);
}
void Timetable::printTimetable() {
	// Sort entries by day using a lambda function
	sort(entries.begin(), entries.end(), [](const TimetableEntry& a, const TimetableEntry& b) {
		static const map<string, int> dayOrder = {
			{"Monday", 1},
			{"Tuesday", 2},
			{"Wednesday", 3},
			{"Thursday", 4},
			{"Friday", 5}
		};
		return dayOrder.at(a.day) < dayOrder.at(b.day);
		});

	// Print each entry in the timetable
	for (const auto& entry : entries) {
		cout << "*******************************************************" << endl;
		cout << "Day: " << entry.day << ", "
			<< "Course: " << entry.Course.course_name << ", "
			<< "Teacher: " << entry.Teacher.name << ", "
			<< "Room: " << entry.Room.room_no << ", "
			<< "Time: " << entry.Time.time_slot << ", "
			<< "Section: " << entry.Section.section_name << endl << endl;
	}
}
void Timetable::printTeacherTimetable(string teacher_name) {
	for (const auto& entry : entries) {
		if (entry.Teacher.name == teacher_name) {
			cout << "***************************************************" << endl;
			cout << "Day: " << entry.day << ", "
				<< "Course: " << entry.Course.course_name << ", "
				<< "Room: " << entry.Room.room_no << ", "
				<< "Time: " << entry.Time.time_slot << ", "
				<< "Section: " << entry.Section.section_name << endl;

			// Print each student's name in the section
			cout << "Students: ";
			for (const auto& student : entry.Section.students) {
				cout << student.name << ", ";
			}
			cout << endl << endl;
		}
	}
}
void Timetable::printSectionTimetable(string section_name) {
	for (const auto& entry : entries) {
		if (entry.Section.section_name == section_name) {
			cout << "***************************************************" << endl;
			cout << "Day: " << entry.day << ", "
				<< "Course: " << entry.Course.course_name << ", "
				<< "Teacher: " << entry.Teacher.name << ", "
				<< "Room: " << entry.Room.room_no << ", "
				<< "Time: " << entry.Time.time_slot << ", "
				<< "Section: " << entry.Section.section_name << endl;

			// Print each student's name in the section
			cout << "Students: ";
			for (const auto& student : entry.Section.students) {
				cout << student.name << ", ";
			}
			cout << endl << endl;
		}
	}
}
void Timetable::printStudentTimetable(string student_name) {
	for (const auto& entry : entries) {
		for (const auto& student : entry.Section.students) {
			if (student.name == student_name) {
				cout << "***************************************************" << endl;
				cout << "Day: " << entry.day << ", "
					<< "Course: " << entry.Course.course_name << ", "
					<< "Teacher: " << entry.Teacher.name << ", "
					<< "Room: " << entry.Room.room_no << ", "
					<< "Time: " << entry.Time.time_slot << ", "
					<< "Section: " << entry.Section.section_name << endl << endl;
				break; // No need to continue checking other students in the section
			}
		}
	}
}
void Timetable::printRoomTimetable(string room_no) {
	for (const auto& entry : entries) {
		if (entry.Room.room_no == room_no) {
			cout << "***************************************************" << endl; cout << "Day: " << entry.day << ", "
				<< "Course: " << entry.Course.course_name << ", "
				<< "Teacher: " << entry.Teacher.name << ", "
				<< "Time: " << entry.Time.time_slot << ", "
				<< "Section: " << entry.Section.section_name << ", "
				;
		}
	}
}
string Timetable::getTeacherAtTime(string day, string time) {
	for (const auto& entry : entries) {
		if (entry.day == day && entry.Time.time_slot == time) {
			return entry.Teacher.name;
		}
	}
	return "No teacher found at this time.";
}
void Timetable::printTimetableForDay(string day) {
	for (const auto& entry : entries) {
		if (entry.day == day) {
			cout << "Course: " << entry.Course.course_name << ", "
				<< "Teacher: " << entry.Teacher.name << ", "
				<< "Room: " << entry.Room.room_no << ", "
				<< "Time: " << entry.Time.time_slot << ", "
				<< "Section: " << entry.Section.section_name << ", "<<endl;
		}
	}
}
void Timetable::clearTimetable() {
	entries.clear();
}
void Timetable::appendEntry(const TimetableEntry& entry) {
	entries.push_back(entry);
}
void Timetable::saveToFile(const string& filename) {
	ofstream file(filename);
	for (const auto& entry : entries) {
		file << entry.day << ","
			<< entry.Course.course_name << ","
			<< entry.Teacher.name << ","
			<< entry.Room.room_no << ","

			<< entry.Time.time_slot << ","
			<< entry.Section.section_name << ","<< "\n";
	}
}
void Timetable::loadFromFile(const string& filename) {
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string day, course_name, teacher_name, room_no, time_slot, section_name;
		getline(ss, day, ',');
		getline(ss, course_name, ',');
		getline(ss, teacher_name, ',');
		getline(ss, room_no, ',');
		getline(ss, time_slot, ',');
		getline(ss, section_name, ',');

		// Add the course entry to the timetable
		addCourse(day, course(course_name), teacher(teacher_name, ""), room(room_no), time_(day, time_slot),section_name);
	}
}
