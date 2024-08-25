#ifndef STUDYMOR_H
#define STUDYMOR_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class studyMor{
    public:
        studyMor(int& key, int age, char gender, string fName, string lName, string placebo);
        studyMor() = default;

        int getKey() const;
        int getAge() const;
        char getGender() const;
        string getfName() const;
        string getlName() const;
        string getPlacebo() const;

        int printMenu() const;
        void setMenu(int& key, int menuChoice, string participant, string survey, studyMor* participants);
        void setParticipant(int surveyChoice, string participant, studyMor* participants);
        void survey(string survey, int key,studyMor* participants);
        void getParticipants(int key, studyMor* participants) const;

        void setKey(int key);
        void setAge(int age);
        void setGender(char gender);
        void setfName(string fName);
        void setlName(string lName);
        void setPlacebo(string placebo);

    private:
        int key;
        int age;
        string placebo;
        char gender;
        string fName;
        string lName;
};

#endif