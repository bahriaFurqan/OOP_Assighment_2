#pragma once
#include "section.h"
#include "course.h"
#include "teacher.h"
#include "room.h"
#include "time_.h"
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
class Timetable {
public:
	vector<student> students;
	vector<section> sections = {
	section("A"),
	section("B"),
	section("C"),
	section("D"),
	section("E")
	};
	vector<teacher> teachers = { teacher("Mr. Waleed", "1"), teacher("DR AWAIS MAJEED", "2"),
	teacher("DR TAMIM AHMAD KHAN", "3"), teacher("GHULAM QAMAR", "4"),
	teacher("ZUBAIR ABBASI", "5"),
	};
	vector<course> courses =
	{
	course("OOP"),
	course("ISE"),
	course("DS"), course("English"), course("LA"),
	};
	vector<room> rooms = {
	room("4-15"),
	room("4-16"),
	room("4-17"),
	room("4-02"),
	room("4-01"),
	};
public:
	struct TimetableEntry {
		string day;
		course Course; teacher Teacher; room Room; time_ Time; section Section;

		TimetableEntry(string d, course c, teacher t, room r, time_ ti, section s)
			: day(d), Course(c), Teacher(t), Room(r), Time(ti), Section(s) {}
	};
	vector<TimetableEntry> entries;

	void addCourse(const string& course_name);
	void addStudent(const string& name, const string& enrollment);
	void addTeacher(const string& name, const string& teacher_id);

	void addSection(const string& section_name, const string& student_name, const string& enrollment);
	void addStudentToSection(const string& section_name, const string& student_name, const string& enrollment);
	void addCourse(const string& day, const course& c, const teacher& t, const room& r, const time_& ti, const section& s);
	void add_room(const string& room_no);
	void printTimetable();
	void printTeacherTimetable(string teacher_name);
	void printSectionTimetable(string section_name);
	void printStudentTimetable(string student_name);
	void printRoomTimetable(string room_no);
	string getTeacherAtTime(string day, string time);
	void printTimetableForDay(string day);

	void clearTimetable();
	void appendEntry(const TimetableEntry& entry);
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);
};
