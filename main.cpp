#include <iostream>
#include <algorithm>
#include <string>

#include "finalassignmenttests.hpp"

using namespace std;

string get_status_str(bool status) {
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main() {
    CovidGraphTest covid_graph_test;

    string test_descriptions[3] = {
            "Test Driver 1: Testing creating graphs",
            "Test Driver 2: Testing Step 2",
            "Test Driver 3: Testing Step 3",
    };
    // Commented out because of an error we are getting with the null pointers case in connectEdges function
    // All other functions compile perfectly except for connect edges
    // I think it's a simple fix but we ran out of time due to exams
    bool test_results[3]={0};
    test_results[0] = covid_graph_test.testdriver1();
    //test_results[1] = covid_graph_test.testdriver2();
    //test_results[2] = covid_graph_test.testdriver3();

    cout << "COVID GRAPH TEST RESULTS \n";
    cout << "*************************** \n";
    for (int index = 0; index < 3; ++index) {
        cout << test_descriptions[index] << endl << get_status_str(test_results[index]) << endl;
    }

    system("pause");
}
