#include <iostream>
#include <string>
#include <vector>

using namespace std;


class section{
    private:
        std::string instructor;
        int section_number;
        int CRN;
        int time;
        string location; //npt configured yet
        bool day; //0 for UW and 1 for MR
    public:
        bool filler;

        section(int x)
        {
            filler = true;
        }

        section(){
            filler = false;
           std::cin.ignore();
            cout<<"enter the name of the instructor: ";
            std::getline (std::cin, instructor);


            cout<<"enter the section number: ";
            cin >> section_number;

            cout<<"\nenter the CRN: ";
            cin >> CRN;

            cout<<"\n choose a time \n 1-    8:30\n 2-    10:00 \n 3-   11:30 \n 4-    2:00 \n 5-    3:30 \n 6-    5:00 \n 7-    6:15 \n ";
            cin >> time;

            cout<<"on which two days is this section offered?\n"<< "\t1 for MR \n\t0 for UW" << endl;
            cin >> day;
        }

        int time_returner()
        {
            return time;
        }
        bool days()
        {
            //0 for UW and 1 for MR
            return day;
        }
};


class course{
    private:
        bool only_one;
        bool has_a_lab;
        bool special_length;
        int number_of_sections;
        string course_name;
        double duration;
        section **array;


    public:
        bool registered = false;

        course()
        {

            cout << "Please enter course name: " << endl;
            std::cin.ignore();
            std::getline(std::cin, course_name);

            cout << "Does this course have only one section: " << endl << "\t1 for Yes \n\t0 for No" << endl;
            cin >> only_one;

        if(!only_one)
          {
            cout << "How many sections does this course have \n";
            cin >> number_of_sections;

            if(number_of_sections == 0) {cout <<"\n Kosomk yasta, a3ml lden omk eh?\n"; return;}
          }
        else number_of_sections = 1;


        cout << "Is this course longer or shorter than 1.25 hours? " << endl <<  "\t1 for Yes \n\t0 for No" << endl;
        cin >> special_length;

        if(special_length)
        {
            cout<<"Please enter the length of the course in hours as decimal: ";
            cin >> duration;
        }

        else duration = 1.5;

        cout << "Does this course have a lab: " << endl << "\t1 for Yes \n\t0 for No" << endl;
        cin >> has_a_lab;

        //needs a lab time handler or treat the lab as a separate course

        createSections();

}

void createSections ()
{
  array = new section* [number_of_sections];
  for(int i=0; i<number_of_sections; i++)
  {
        cout<<"\t section number "<<i+1<<" :"<<endl;
        array[i] = new section();
  }
}

bool only_1()
        {
            return only_one;
        }

int section_time(int i)
        {
            return (array[i]->time_returner()-1); //this would return the corresponding index in the schedule array
        }

bool day(int i)
{
    //0 for UW and 1 for MR
    return array[i]->days();
}

section* section_returner(int i)
{
    return array[i];
}
int returnNumberOfSections(){
  return number_of_sections;
}
void printCourse(){
	cout << "---------------------------" << course_name << "---------------------------" << endl;
	cout << "Number of sections: " << number_of_sections << endl;
	for (int i=0; i< number_of_sections; i++){
		cout << "Section number " << i << " :" << endl;
		cout << "Time is: " << array[i]->getTime() << endl;
		cout << "Instructor is: "<< array[i]->getInstructor() << endl;

	}

}

};




int main()
{
    int number_of_courses = 0;

    cout<<"please enter the number of courses that you want to take: ";
    cin >> number_of_courses;

    course** C = new course* [number_of_courses];
    for(int i=0; i<number_of_courses; i++)
    {
        cout<<"\n\t Course number "<<i+1<<" :"<<endl;
        C[i] = new course();
    }





    //generating schedules
    section* MR[7];
    section* UW[7];
    section* fill(0);

    for(int i=0; i<7; i++)
    {
        MR[i] = fill;
        UW[i] = fill;
    }

for(int i=0; i<number_of_courses; i++)
{
    if(C[i]->only_1())
    {

        //0 for UW and 1 for MR
        if(C[i]->day(0))
        {
            MR[C[i]->section_time(0)] = C[i]->section_returner(0);
        }

        else UW[C[i]->section_time(0)] = C[i]->section_returner(0);
    }
}
    return 0;
}

bool isSafe (section * gadwal, i){
  if(gadwal[i] == NULL )
  return true;

  else
  return false;
}

void solveSchedule(section *schedule){
if() // check if all the course are registered
for(int i=0; i<no_of_courses; i++){

  if(C[i]->registered == false){
    for(int j=0; j<C[i]->returnNumberOfSections(); j++){
      int timeIndex = C[i]->section_time(i);
      if (isSafe(MR,timeIndex)){
        MR[i]=C[i];
      }
    }

  }
}
solveSchedule(schedule +1);
}
