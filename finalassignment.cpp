#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include "finalassignment.hpp"


using namespace std;

//helper operator overload function
bool operator==(const CovidGraph::Person &lhs, const CovidGraph::Person &rhs) {

    if (lhs.identifier != rhs.identifier)
        return false;
    return true;
}

//helper function to get the pointer that points to a person given the person’s identifier
CovidGraph::Person *CovidGraph::getPointerToPerson(string person_id) {
    //initialize a counter to iterate through the vector allPeople
    int count = 0;

    //iterate through the vector to look for the Person
    while (count < this->allPeople.size()) {

        //checks if the identifier at the given index matches the passed in person_id
        if (allPeople[count]->identifier == person_id) {
            //returns the pointer that points to the location of the person in the graph
            return this->allPeople[count];
        }
        count++;
    }
    //if person_id not found in graph return null
    return nullptr;
}

void CovidGraph::insertPerson(CovidGraph::Person val) {
    this->allPeople.push_back(new Person(val)); //add new instance of Person to end of vector
}

bool CovidGraph::connectEdges(string identifier1, string identifier2, unsigned int numDays, string place) {
    Person* person1; //initialize two pointers
    Person* person2;

    //iterate through allPeople and search for identifier of person 1
    for(int index = 0; index < allPeople.size(); index++){
        if (allPeople[index]->identifier == identifier1)
            person1 = allPeople[index];//if found, set person1 pointer to point to spot

        else if(allPeople[index]->identifier == identifier2) //repeat same process for person 2
            person2 = allPeople[index];

    }
    if (!person1 || !person2) return false;

    person1->contactList.push_back(person2); //add person 2 to person 1's contact list
    person2->contactList.push_back(person1); //add person 1 to person 2's contact list

    person1->lastContact.push_back(numDays); //repeat same process for lastContact
    person2->lastContact.push_back(numDays);

    person1->location.push_back(place); //repeat same process for location
    person2->location.push_back(place);

    return true;

}

int CovidGraph::count_virus_positive_contacts(string person_id) {
    //call helper function to get the pointer for the starting Person
    CovidGraph::Person *root = getPointerToPerson(person_id);

    //if the person doesn’t exist in the graph, return 0
    if (root == NULL) {
        return 0;
    }

        //if the person exists:
    else {
        //initialize counter to track the number of coronavirus positive contacts
        int covidCount = 0;

        //temporary vector called visited to keep track of visited contacts
        vector<bool> visited(allPeople.size(), false);

        queue<CovidGraph::Person *> temp; //create queue for BFS
        temp.push(root);

        while (!temp.empty()) { //if person_id is found in graph, traverse
            if (!isVisited(*temp.front(), visited)) {
                //only increment count if temp.front is not the root Person, and the person is positive
                if (temp.front() != root && root->hasCovid) {
                    covidCount++;
                }
            }

            //iterate through the surrounding people for each person
            for (int i = 0; i < temp.front()->contactList.size(); i++) {
                //check if the person has been visited, if they haven’t then add the person to the queue
                if (!isVisited(*temp.front()->contactList[i], visited)) {
                    temp.push(temp.front()->contactList[i]);
                }
            }
            //update visited to true
            visited[findIndexOfPerson(temp.front()->identifier)]=true;

            //remove temp from queue
            temp.pop();
        }
        //return count
        return covidCount;
    }
}

//helper function: pass node, iterates though array of people
unsigned int CovidGraph::findIndexOfPerson(string person_id) {

    for (int index = 0; index < allPeople.size(); index++) { //iterate through allPeople
        if (allPeople[index]->identifier == person_id);
            return index; //returns index of node with identifier matching person_id
    }
    return -1;
}


//helper function for step 2: checks if a person has been visited in the traversal
bool CovidGraph::isVisited(Person val, vector<bool> visited) {
    for(int index = 0; index<allPeople.size(); index++){
        if (val == *allPeople[index])
            return visited[index]; // find the index of val in allPeople
    }

    return false;
}

int CovidGraph::find_largest_cluster_with_two_positive() {
    //temporary vector called visited to keep track of visited contacts
    vector<bool> visited(allPeople.size(), false);

    int maxClusterSize = -1;

    for (int i = 0; i < allPeople.size(); i++) {
        if (!isVisited(*allPeople[i], visited)) {
            queue<CovidGraph::Person *> temp; //create queue for BFS
            temp.push(allPeople[i]);

            int positiveCount = 0;
            int clusterSize = 0;

            while (!temp.empty()) { //if person_id is found in graph, traverse
                if (!isVisited(*temp.front(), visited)) {
                    //iterate through the surrounding people for each person
                    for (int i = 0; i < temp.front()->contactList.size(); i++) {
                        if (!isVisited(*temp.front()->contactList[i], visited)) {
                            temp.push(temp.front()->contactList[i]);
                        }

                        //increment clusterSize
                        clusterSize++;

                        //increment postiveCount if person is positive
                        if (temp.front()->contactList[i]->hasCovid) {
                            positiveCount++;
                        }
                    }
                }
                //update visited to true
                visited[findIndexOfPerson(temp.front()->identifier)]=true;

                //remove temp from queue
                temp.pop();

            }
            if (positiveCount >= 2 && clusterSize > maxClusterSize) {
                maxClusterSize = clusterSize;
            }
        }
    }
    return maxClusterSize;
}
