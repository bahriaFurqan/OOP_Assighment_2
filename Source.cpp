#include"person.h"
#include"course.h"
#include"teacher.h"
#include"room.h"
#include"student.h"
#include"section.h"
#include"timetable.h"

int main() {
	Timetable timetable;
	//HERE RANDOMLY GENERATED TIMETABLE IS CREATED
	srand(time(0));
	vector<time_> timeslots = {
	time_("Monday", "9:00 - 10:00"),
	time_("Tuesday", "10:00 - 11:00"),
	time_("Wednesday", "11:00 - 12:00"),

	time_("Thursday", "12:00 - 1:00"),
	time_("Friday", "1:00 - 2:00"),
	};



	for (;;) {
		int option;
		cout << "1. Generate timetable" << endl; cout << "2. Print timetable" << endl;
		cout << "3. Add student" << endl; //added this option to add student
		cout << "4.Add student to section" << endl; //added this option to add student to section
		cout << "5.Add teacher" << endl; //added this option to add teacher
		cout << "6. Add course" << endl; //added this option to add course
		cout << "7. ADD room" << endl; //added this option to add room
		cout << "8.Add section" << endl; //added this option to add section
		cout << "9. Print timetable for a specific day" << endl; cout << "10. Print timetable for a specific teacher" << endl; cout << "11. Print timetable for a specific section" << endl; cout << "12. Print timetable for a specific room" << endl; 
		cout<<"13.print timetable for a specific student"<<endl; //added this option to print timetable for a specific student
		cout << "14. print course vector" << endl; //added this option to print course vector
		cout << "15. print student vector" << endl; //added this option to print student vector		
		cout << "16.print teacher vector" << endl; //added this option to print teacher vector	
		cout << "17print the section vector and its student" << endl; //added this option to print the section vector and its student
		cout<<"18.print room vector" << endl; //added this option to print room vector
		cout << "19. Save to file" << endl; cout << "20. Load from file" << endl;
		cout << "21. Exit" << endl;
		cout << "Enter option: ";

		cin >> option;
		if (option == 1) {
			timetable.clearTimetable();
			for (int i = 0; i < 10; i++) {
				course c = timetable.courses[rand() % timetable.courses.size()]; teacher t = timetable.teachers[rand() % timetable.teachers.size()]; room r = timetable.rooms[rand() % timetable.rooms.size()];
				time_ ti = timeslots[rand() % timeslots.size()];

				section s = timetable.sections[rand() % timetable.sections.size()]; timetable.addCourse(ti.day, c, t, r, ti, s);
			}

		}
		else if (option == 2) {
			timetable.printTimetable();
		}
		else if (option == 3)
		{
			string name, enrollment;
			cout << "Enter student name: ";
			cin >> name;
			cout << "Enter enrollment: ";
			cin >> enrollment;
			timetable.addStudent(name, enrollment);
		}
		else if (option == 4)
		{
			string section_name, student_name, enrollment;
			cout << "Enter section name: ";
			cin >> section_name;
			cout << "Enter student name: ";
			cin >> student_name;
			cout << "Enter enrollment: ";
			cin >> enrollment;
			timetable.addSection(section_name, student_name, enrollment);
		}
		
		else if (option == 5)
		{
			string name, teacher_id;
			cout << "Enter teacher name: ";
			cin >> name;
			cout << "Enter teacher id: ";
			cin >> teacher_id;
			timetable.addTeacher(name, teacher_id);
		}
		else if (option == 6)
		{
			string course_name;
			cout << "Enter course name: ";
			cin >> course_name;
			timetable.addCourse(course_name);
		}
		else if (option == 7)
		{
			string room_no;
			cout << "Enter room number: ";
			cin >> room_no;
			timetable.add_room(room_no);
		}
		else if (option == 8)
		{
			string section_name, student_name, enrollment;
			cout << "Enter section name: ";
			cin >> section_name;
			cout << "Enter student name: ";
			cin >> student_name;
			cout << "Enter enrollment: ";
			cin >> enrollment;
			timetable.addSection(section_name, student_name, enrollment);
		}
		else if (option == 9) {
			string day;
			for (;;)
			{
				cout << "Enter day: "; cin >> day;
				if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day ==
					"Friday")
				{
					break;
				}
				else
				{
					cout << "Invalid day. Please enter a valid day." << endl;
				}

			}
			timetable.printTimetableForDay(day);

		}
		else if (option == 10) {
			string teacher_name;
			for (int i = 0; i < timetable.teachers.size(); i++)
			{
				cout << "TEACHERS:" << endl; cout << timetable.teachers[i].name << endl;
			}

			cout << "Enter teacher name: "; cin.ignore();
			getline(cin, teacher_name); if (teacher_name.empty())
			{
				cout << "Invalid teacher name." << endl; continue;
			}
			else if (find_if(timetable.teachers.begin(), timetable.teachers.end(), [&teacher_name](const teacher& t) { return t.name == teacher_name; }) == timetable.teachers.end())
			{
				cout << "Teacher not found." << endl; continue;
			}
			timetable.printTeacherTimetable(teacher_name);
		}
		else if (option == 11) {
			string section_name;
			for (int i = 0; i < timetable.sections.size(); i++)
			{
				cout << "SECTION:" << endl;
				cout << "Section:" << timetable.sections[i].section_name << endl;

			}
			cout << "Enter section name: "; cin >> section_name;
			timetable.printSectionTimetable(section_name);
		}

		else if (option == 12) {
			string room_no;
			for (int i = 0; i < timetable.rooms.size(); i++) {
				cout << "ROOM:" << endl;
				cout << "Room:" << timetable.rooms[i].room_no << endl;
			}

			cout << "Enter room number: "; cin >> room_no;
			timetable.printRoomTimetable(room_no);

		}
		else if (option == 13) {
			string student_name;
			cout << "Enter student name: ";
			cin.ignore();
			getline(cin, student_name);
			if (student_name.empty()) {
				cout << "Invalid student name." << endl;
				continue;
			}
			else {
				bool student_found = false;  // Initialize student_found
				for (const auto& section : timetable.sections) {
					for (const auto& student : section.students) {
						if (student.name == student_name) {
							student_found = true;
							break;
						}
					}
					if (student_found) {
						break;
					}
				}
				if (!student_found) {
					cout << "Student not found." << endl;
					continue;
				}
			}
			}
		
		else if (option == 14)
		{
			for (int i = 0; i < timetable.courses.size(); i++)
			{
				cout << "COURSES:" << endl;
				cout << "Course:" << timetable.courses[i].course_name << endl;
			}
			}
		
		else if (option == 15) {
				for (const auto& section : timetable.sections) {
					cout << "STUDENTS in Section " << section.section_name << ":" << endl;
					for (const auto& student : section.students) {
						cout << "Student: " << student.name << endl;
					}
					cout << endl;
				}
		}

		else if (option == 16)
		{
			for (int i = 0; i < timetable.teachers.size(); i++)
			{
				cout << "TEACHERS:" << endl;
				cout << "Teacher:" << timetable.teachers[i].name << endl;
			}
			}
		else if (option == 17) {
				for (const auto& section : timetable.sections) {
					cout << "SECTION:" << endl;
					cout << "Section: " << section.section_name << endl;
					for (const auto& student : section.students) {
						cout << "Student: " << student.name << endl;
					}
					cout << endl;
				}
				}
		else if (option == 18)
		{
			for (int i = 0; i < timetable.rooms.size(); i++)
			{
				cout << "ROOM:" << endl;
				cout << "Room:" << timetable.rooms[i].room_no << endl;
			}
			}

		else if (option == 19) {
			string path = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/timetable.txt"; ofstream file(path, ios::trunc);
			if (file.is_open()) {
				for (const auto& entry : timetable.entries) {
					file << entry.day << ","
						<< entry.Course.course_name << ","
						<< entry.Teacher.name << ","
						<< entry.Room.room_no << ","

						<< entry.Time.time_slot << ","
						<< entry.Section.section_name << ","<< "\n";
				}
				file.close();

				cout << "Timetable saved to file." << endl;
			}
			else {
				cout << "Unable to open file for saving." << endl;

			}
		}
		else if (option == 20) {
			string path = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/timetable.txt";
			timetable.clearTimetable();
			ifstream file(path);
			if (file.is_open()) {
				string line;
				while (getline(file, line)) {
					stringstream ss(line);
					string day, course_name, teacher_name, room_no, time_slot, section_name; // Removed student_name
					getline(ss, day, ',');
					getline(ss, course_name, ',');
					getline(ss, teacher_name, ',');
					getline(ss, room_no, ',');
					getline(ss, time_slot, ',');
					getline(ss, section_name, ',');
					// Removed student_name
					timetable.appendEntry(Timetable::TimetableEntry(day, course(course_name), teacher(teacher_name, ""), room(room_no), time_(day, time_slot), section_name)); // Removed student_name
				}
				file.close();
				cout << "Timetable loaded from file." << endl;
			}
			else {
				cout << "Unable to open file for loading." << endl;
			}
			}

		else if (option == 21) {
			break;
		}

		else if (option < 1 || option > 9)
		{
			cout << "Invalid option." << endl; continue;
		}
	}
	system("pause"); return 0;
}
