#include "studymor.h"

studyMor::studyMor(int& key, int age, char gender, string fName, string lName, string placebo){
    this->age = age;
    this->gender = gender;
    this->fName = fName;
    this->lName = lName;
    this->placebo = placebo;
    this->key = key;
}

//Getters for our database
int studyMor::getAge() const{
    return age;
}

int studyMor::getKey() const{
    return key;
}

char studyMor::getGender() const{
    return gender;
}

string studyMor::getfName() const{
    return fName;
}

string studyMor::getlName() const{
    return lName;
}

string studyMor::getPlacebo() const{
    return placebo;
}

//Setters for our database
void studyMor::setPlacebo(string placebo){
    this->placebo = placebo;
}

void studyMor::setKey(int key){
    this->key = key;
}

void studyMor::setAge(int age){
    this->age = age;
}

void studyMor::setGender(char gender){
    this->gender = gender;
}

void studyMor::setfName(string fName){
    this->fName = fName;
}

void studyMor::setlName(string lName){
    this->lName = lName;
}

//Prints our initial menu
int studyMor::printMenu() const{
    int menuChoice;
    cout << "\n1. Add a New Participant\n2. Collect Survey for Participant\n3. Display Participants\n4. Quit" << endl;
    cout << "\nPlease enter a command to continue: ";
    cin >> menuChoice;
    return menuChoice;
}

//Sets our participant and stores it in the file. We check the file in main in order to not overwrite later on
void studyMor::setParticipant(int key, string participant, studyMor* participants){
    ofstream fout;
    string q1, q2, q5;
    int q3;
    char q4;
    participants[key].setKey(key);
    cout << "\nEnter the participant's first name: ";
    cin >> q1;
    participants[key].setfName(q1);
    cout << "Enter the participant's last name: ";
    cin >> q2;
    participants[key].setlName(q2);
    cout << "Enter " << participants[key].getfName() << " " << participants[key].getlName() << "'s age: ";
    cin >> q3;
    participants[key].setAge(q3);
    cout << "Enter " << participants[key].getfName() << " " << participants[key].getlName() << "'s gender: ";
    cin >> q4;
    participants[key].setGender(q4);

    if((key % 2) == 0){
        participants[key].setPlacebo("Yes");
    }else{
        participants[key].setPlacebo("No");
    }

    fout.open(participant, std::ofstream::out | std::ofstream::app);
    fout << key << " " << q1 << " " << q2 << " " << q3 << " " << q4 << placebo;
    fout.close();
}

//Gets all of our information for the participants saved in the current iteration of program
void studyMor::getParticipants(int key, studyMor* participants) const{
    for(int i = 1; i < key; i++){
        cout << "\nID: " << participants[i].getKey();
        cout << "\nName: " << participants[i].getfName() << " " << participants[i].getlName();
        cout << "\nAge: " << participants[i].getAge();
        cout << "\nGender: " << participants[i].getGender();
        cout << "\nStudyMor: " << participants[i].getPlacebo();
        cout <<"\n\n**************************************************";
    }
}

//This is our menu that actually selects our function based on users choice
void studyMor::setMenu(int& key, int menuChoice, string participant, string survey, studyMor* participants){
    switch(menuChoice){
        case 1:
            this->setParticipant(key, participant, participants);
            key++;
            break;
        case 2:
            this->survey(survey, key, participants);
            break;
        case 3:
            this->getParticipants(key, participants);
            break;
        case 4:
            exit(0);
        default:
            break;
    }
        
}

//Survey function, uses getline and saved to survey.dat (appends so we don't lose info)
void studyMor::survey(string survey, int key, studyMor* participants){
    ofstream fout;
    string q1, q2, q3, q4, q5;
    int choice;

    cout << "\nPlease choose the study participant: ";
    this->getParticipants(key, participants);
    cin >> choice;
    cout << "Ask the participant the following questions and enter their responses." << endl;
    cout << "\n1. Did you have any headaches using StudyMor? ";
    cin.ignore();
    getline(cin,q1);
    cout << "\n2. Did you have any constipation using StudyMor? ";
    getline(cin,q2);
    cout << "\n3. Did you experience any difficulty sleeping while using StudyMor?";
    getline(cin,q3);
    cout << "\n4. List any other potential side effects, you experienced using StudyMor.";
    getline(cin,q4);
    cout << "\n5. Did you feel like you could study more using StudyMor?";
    getline(cin,q5);

    fout.open(survey, std::ofstream::out | std::ofstream::app);

    fout << '\n' << key << q1 << q2 << q3 << q4 << q5;
    fout.close();

}