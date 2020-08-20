#ifndef finalassignmenthpp
#define finalassignmenthpp
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class CovidGraph {
protected:
    struct Person {
        string name;
        string identifier;
        bool hasCovid;
        string testDate;

        vector<Person*> contactList;
        vector<unsigned int> lastContact;
        vector<string> location;

        //default constructor
        Person() : name(""), identifier(""), hasCovid(false), testDate("") {}

        //constructor
        Person(string new_name, string new_identifier, bool new_hasCovid, string new_testDate) : name(new_name), identifier(new_identifier), hasCovid(new_hasCovid), testDate(new_testDate) {}

    };

public:
    friend class CovidGraphTest;

    friend bool operator==(const Person &lhs,
                           const Person &rhs);

    //initialize a vector allPeople to record all the Person objects in the graph
    vector<Person*> allPeople;
    Person* getPointerToPerson(string person_id);
    void insertPerson(Person val);
    bool connectEdges(string identifier1, string identifier2, unsigned int numDays, string place);
    int count_virus_positive_contacts(string person_id);
    int find_largest_cluster_with_two_positive();
    bool isVisited(Person val, vector<bool> visited);
    unsigned int findIndexOfPerson(string person_id);

    //graph constructor
    CovidGraph() : allPeople ({}) {};

};
#endif