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
class Timetable 
{
public:
	vector<student> students;
	vector<section> sections;
	vector<teacher> teachers;
	vector<course> courses;
	vector<room> rooms;
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
	void addSection(const string& section_name);
	void add_to_Section(const string& section_name, const string& student_name, const string& enrollment);
	void addStudentToSection(const string& section_name, const string& student_name, const string& enrollment);
	void addCourse(const string& day, const course& c, const teacher& t, const room& r, const time_& ti, const section& s);
	void add_room(const string& room_no);
	void printTimetable();
	void printTeacherTimetable(string teacher_name);
	void printSectionTimetable(string section_name);
	void printStudentTimetable(string section_name,string student_name);
	void printRoomTimetable(string room_no);
	string getTeacherAtTime(string day, string time);
	void printTimetableForDay(string day);
	void Modify_the_timetable(string section_name, string teacher_name, string new_day, string new_time);
	void clearTimetable();
	void appendEntry(const TimetableEntry& entry);
	void saveToFile(const string& filename);
	void loadFromFile(const string& filename);
	void load_studentdata_from_file(const string& filename);
	void save_studentdata_to_file(const string& filename);
	void load_teacherdata_from_file(const string& filename);
	void save_teacherdata_to_file(const string& filename);
	void load_coursedata_from_file(const string& filename);
	void save_coursedata_to_file(const string& filename);
	void load_roomdata_from_file(const string& filename);
	void save_roomdata_to_file(const string& filename);
	void load_sectiondata_from_file(const string& filename);
	void save_sectiondata_to_file(const string& filename);
};
