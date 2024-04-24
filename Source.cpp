#include"person.h"
#include"course.h"
#include"teacher.h"
#include"room.h"
#include"student.h"
#include"section.h"
#include"timetable.h"

int main() {
	string pathfor_student = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/Student.txt";
    string pathfor_teacher = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/Teacher.txt";
    string pathfor_course = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/Course.txt";
    string pathfor_room = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/Room.txt";
    string pathfor_section = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/Section.txt";

	Timetable timetable;
	srand(time(0));
	vector<time_> timeslots = {
	time_("Monday", "9:00 - 10:00"),
	time_("Tuesday", "10:00 - 11:00"),
	time_("Wednesday", "11:00 - 12:00"),
	time_("Thursday", "12:00 - 1:00"),
	time_("Friday", "1:00 - 2:00"),
	};

	timetable.load_studentdata_from_file(pathfor_student);
    timetable.load_teacherdata_from_file(pathfor_teacher);
    timetable.load_coursedata_from_file(pathfor_course);
    timetable.load_roomdata_from_file(pathfor_room);
    timetable.load_sectiondata_from_file(pathfor_section);

	cout<<"********************WELCOME TO TIMETABLE MANAGEMENT SYSTEM*********************"<<endl;
	for (;;) {
		int option;
		cout << "1. Generate timetable" << endl;
		cout << "2. Print timetable" << endl;
		cout << "3. Add student to section"<< endl; 
		cout << "4. Add teacher" << endl; 
		cout << "5. Add course" << endl; 
		cout << "6. ADD room" << endl; 
		cout << "7. Add section" << endl; 
		cout << "8. Print timetable for a specific day" << endl; 
		cout << "9. Print timetable for a specific teacher" << endl; 
		cout << "10. Print timetable for a specific section" << endl;
		cout << "11. Print timetable for a specific room" << endl; 
		cout << "12. print timetable for a specific student"<<endl; 
		cout<<"13. Modify the timetable"<<endl;
		cout << "14. Save to file" << endl; 
		cout << "15. Load from file" << endl;
		cout << "16. Exit" << endl;
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
			string section_name, student_name, enrollment;
			cout << "SECTIONS:-" << endl;
			for(int i = 0; i < timetable.sections.size(); i++)
			{
				cout<<"**********"<<endl;
				cout << "Section:" << timetable.sections[i].section_name << endl;
			}
			cout << "Enter section name: ";
			cin >> section_name;
			cout << "Enter student name: ";
			cin.ignore();
			getline(cin, student_name);
			cout << "Enter enrollment: ";
			cin >> enrollment;
			cout<<"Student added to section successfully"<<endl;
			timetable.add_to_Section(section_name, student_name, enrollment);
		}
		
		else if (option == 4)
		{
			string name, teacher_id;
			cout << "Enter teacher name: ";
			cin.ignore();
            getline(cin, name);
			cout << "Enter teacher id: ";
			cin >> teacher_id;
            cout<<"Teacher added successfully"<<endl;
			timetable.addTeacher(name, teacher_id);
		}
		else if (option == 5)
		{
			string course_name;
			cout << "Enter course name: ";
			cin >> course_name;
            cout<<"Course added successfully"<<endl;
			timetable.addCourse(course_name);
		}
		else if (option == 6)
		{
			string room_no;
			cout << "Enter room number: ";
			cin >> room_no;
            cout<<"Room added successfully"<<endl;
			timetable.add_room(room_no);
		}
		else if (option == 7)
		{
			string section_name;
			cout << "Enter section name: ";
			cin.ignore();
            getline(cin, section_name);
			cout<<"Section added successfully"<<endl;
            timetable.addSection(section_name);
			
		}
		else if (option == 8) {
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
		else if (option == 9) {
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
		else if (option == 10) {
			string section_name;
			for (int i = 0; i < timetable.sections.size(); i++)
			{
				cout << "SECTION:" << endl;
				cout << "Section:" << timetable.sections[i].section_name << endl;

			}
			cout << "Enter section name: "; cin >> section_name;
			timetable.printSectionTimetable(section_name);
		}

		else if (option == 11) {
			string room_no;
			for (int i = 0; i < timetable.rooms.size(); i++) {
				cout << "ROOM:" << endl;
				cout << "Room:" << timetable.rooms[i].room_no << endl;
			}
			cout << "Enter room number: "; cin >> room_no;
			timetable.printRoomTimetable(room_no);
		}
		else if (option == 12) {
			string student_name;
			string section_name;
			cout << "SECTIONS:-" << endl;
			for(int i = 0; i < timetable.sections.size(); i++)
			{
				cout<<"**********"<<endl;
				cout << "Section:" << timetable.sections[i].section_name << endl;
				for(int j = 0; j < timetable.sections[i].students.size(); j++)
				{
					cout<< j+1 << "Student:" << timetable.sections[i].students[j].name << endl;
				}
			}
           cout << "Enter section name: ";
			cin.ignore();
			getline(cin, section_name);
			cout << "Enter student name: ";
			cin.ignore();
			getline(cin, student_name);
           timetable.printStudentTimetable(section_name,student_name);
		}
		 
            else if (option == 13)
            {
                string section_name, teacher_name, new_day, new_time;
                cout << "Enter section name: ";
                cin.ignore();
                getline(cin, section_name);
                cout << "Enter teacher name: ";
                getline(cin, teacher_name);
                cout << "Enter new day: ";
               getline(cin, new_day);
                cout << "Enter new time: ";
                getline(cin, new_time);
                timetable.Modify_the_timetable(section_name, teacher_name, new_day, new_time);
            }
		else if (option == 14) {
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
		else if (option == 15) {
			string path = "C:/Users/DELL PRECISION 5530/OneDrive/Desktop/timetable.txt";
			timetable.clearTimetable();
			ifstream file(path);
			if (file.is_open()) {
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
					timetable.appendEntry(Timetable::TimetableEntry(day, course(course_name), teacher(teacher_name, ""), room(room_no), time_(day, time_slot), section_name)); // Removed student_name
				}
				file.close();
				cout << "Timetable loaded from file." << endl;
			}
			else {
				cout << "Unable to open file for loading." << endl;
			}
			}


		else if (option == 16) {
        cout << "Exiting program." << endl;
         timetable.save_studentdata_to_file(pathfor_student);
         timetable.save_teacherdata_to_file(pathfor_teacher);
         timetable.save_coursedata_to_file(pathfor_course);
         timetable.save_roomdata_to_file(pathfor_room);
         timetable.save_sectiondata_to_file(pathfor_section);
			break;
		}

		else if (option < 1 || option > 9)
		{
			cout << "Invalid option." << endl; continue;
		}
	}
	system("pause"); return 0;
}
