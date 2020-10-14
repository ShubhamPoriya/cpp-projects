// NAME       : Shubham Poriya
// Student ID : 202005628
// Email      : xfem2020@stfx.ca

// Assignment-1: Problem 2

#include <iostream>
#include <iterator>
#include <map>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    // ------------- VARIABLES --------------------------
    float gpa;  
    int sat_score, extra_activities, num_criteria;
    string name_student, next_student;
    char criteria;

    map<int,string, greater<int>> SAT_SCORE;         // mapping the int in sat_score with names of students and storing it in container.
    map<float,string, greater<int>> GPA;             // Here greater<> is the parameter to sort the mapping in descending order.
    map<int,string, greater<int>> EXTRACURRICULAR;

    // ------------------------------Main function of the program statrs HERE -------------------------------

    do                                                         // do-while loop for exit controlled loop to check condition at last.
    {
        cout << "Student name: " << endl;                      
        cin >> name_student;                                   // input for student name
        
        cout << "Combined SAT score: " << endl; 
        cin >> sat_score;                                      // input for sat score 
        
        cout << "High school GPA: " << endl;
        cin >> gpa;                                            // input for gpa
        
        cout << "# of extracurricular activities: " << endl;
        cin >> extra_activities;                               // input for extra activities

        if(extra_activities >= 5){    
            if(sat_score >= 1400 && gpa >= 2.8){                   // if sat score is >= 1400 and gpa >= 2.8 and extra activities >=5 then admit
                cout << name_student << " should be admitted!" << endl;
            } else{
                cout << name_student << " should not be admitted." << endl;
            }
        }else if(extra_activities >= 3 && extra_activities < 5){    // if extra ativities > 3 and < 5 and sat score >= 1600 and gpa >=3.0 then admit
            if(sat_score >= 1600 && gpa >= 3.0){
                cout << name_student << " should be admitted!" << endl;
            }else{
                cout << name_student << " should not be admitted." << endl;
            }
        }else{
            cout << name_student << " should not be admitted." << endl;
        }

        SAT_SCORE.insert(pair<int, string>(sat_score, name_student));             // storing the keys and values in a mapped container.
        GPA.insert(pair<double, string>(gpa, name_student));
        EXTRACURRICULAR.insert(pair<int, string>(extra_activities, name_student));

        cout << "------------------------------------------------------" << endl;
        cout << "Another student? (yes/no) " << endl;
        cin >> next_student;
        cout << "------------------------------------------------------" << endl;
    }while (next_student == "yes");

     
    // ------------------------Ordering the students according to criteria selected ------------------------------

    cout << "------------------------------------------------------" << endl;
    cout << "Select the criteria to rank and order your students." << endl;
    cout << "Enter the number of criteria to be displayed (max 3): " << endl;
    cin >> num_criteria;

    for (int i = 0; i < num_criteria; i++)     // iterating over number of criteria required
    {
        
        cout << "Combined SAT score (press 's') | By GPA (press 'g') | By # of extra-curricular activities (press 'e') " << endl;
        cin >> criteria;

        map<float, string>::iterator itr;     // mapping and iterating the keys and values to print out.
        map<int, string>::iterator itrr;

        switch (criteria)                    // switch statements to run different caes for different input.
        {
        case 's':

            cout << "\nThe order of students by SAT score:\n";
            cout << "\tNAME\tSAT Score\n";
            for (itrr = SAT_SCORE.begin(); itrr != SAT_SCORE.end(); ++itrr){         // iterating over beginning to end of the mapped container.
                cout << '\t' << itrr->second                                          // printing the key and value spaced by tab.
                 << '\t' << itrr->first << '\n';
            }
            cout << "------------------------------------------------------" << endl;
            break;

        case 'g':
            cout << "\nThe order of students by GPA score:\n";
            cout << "\tNAME\tGPA Score\n";
            for (itr = GPA.begin(); itr != GPA.end(); ++itr){
                cout << '\t' << itr->second 
                 << '\t' << itr->first << '\n';
            }
            cout << "------------------------------------------------------" << endl;
            break;

        case 'e':
            cout << "\nThe order of students by # of Extra-Activities:\n";
            cout << "\tNAME\tEXTRA-ACTIVITIES\n";
            for (itrr = EXTRACURRICULAR.begin(); itrr != EXTRACURRICULAR.end(); ++itrr){
                cout << '\t' << itrr->second 
                 << '\t' << itrr->first << '\n';
            }
            cout << "------------------------------------------------------" << endl;
        break;
        }
    }
}