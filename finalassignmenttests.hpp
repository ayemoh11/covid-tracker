#ifndef finalassignmenttestshpp
#define finalassignmenttestshpp

#include "finalassignment.hpp"

#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

#define ASSERT_TRUE(T) if (!(T)) return false;

class CovidGraphTest {
public:
    bool testdriver1() {
        //TEST 1: Create null graph
        CovidGraph graph1;
        ASSERT_TRUE(graph1.allPeople.size() == 0);

        //TEST 2: Create a one node graph
        CovidGraph::Person p1("Bob", "123", false, "Jun2");
        graph1.insertPerson(p1);
        ASSERT_TRUE(graph1.allPeople.size() == 1);

        //TEST 3: Create a two node graph (1 cluster);
        CovidGraph::Person p2("Leafy", "670", true, "Jun10");
        graph1.insertPerson(p2);
        graph1.connectEdges("123", "670", 4, "park");
        ASSERT_TRUE(graph1.allPeople.size() == 2);

        //Test 4: Create a multiple cluster graph
        CovidGraph::Person p3("Azhar", "525", false, "Jul15");
        graph1.insertPerson(p3);
        graph1.connectEdges("525", "123", 2, "park");
        graph1.connectEdges("525", "670", 3, "mall");
        ASSERT_TRUE(graph1.allPeople.size() == 3);

        return true;
    }

    bool testdriver2() {
        //TEST 1: Test null graph
        CovidGraph graph1;
        ASSERT_TRUE(graph1.count_virus_positive_contacts("111") == 0);

//        //TEST 2: Single node graph that hasn’t tested positive
//        CovidGraph::Person p1("Jim", "150", false, "May3");
//        graph1.insertPerson(p1);
//        ASSERT_TRUE(graph1.count_virus_positive_contacts("150") == 0);
//
//        //TEST 3: single node graph that tested positive
//        CovidGraph graph2;
//        CovidGraph::Person p2("Henry", "200", true, "Jul7");
//        graph2.insertPerson(p2);
//        ASSERT_TRUE(graph2.count_virus_positive_contacts("200") == 0);
//
//        //TEST 4: multiple node graph no contacts tested positive
//        CovidGraph::Person p3("Sam", "444", false, "May17");
//        CovidGraph::Person p4("Marcus", "585", false, "Apr4");
//        graph2.insertPerson(p1);
//        graph2.insertPerson(p3);
//        graph2.insertPerson(p4);
//        graph2.connectEdges("444", "585", 5, "park");
//        graph2.connectEdges("444", "150", 2, "store");
//        ASSERT_TRUE(graph2.count_virus_positive_contacts("585") == 0);
//
//        //TEST 5: multiple node graph no direct contacts tested positive, indirect all tested positive
//        CovidGraph graph3;
//        CovidGraph::Person p5("Andrew", "100", false, "May30");
//        CovidGraph::Person p6("Tina", "423", true, "Aug1");
//        CovidGraph::Person p7("Julie", "322", false, "Jul4");
//        CovidGraph::Person p8("Harry", "655", true, "Aug3");
//        graph3.insertPerson(p5);
//        graph3.insertPerson(p6);
//        graph3.insertPerson(p7);
//        graph3.insertPerson(p8);
//        graph3.connectEdges("100", "423", 6, "park");
//        graph3.connectEdges("423", "322", 4, "mall");
//        graph3.connectEdges("322", "655", 1, "store");
//        ASSERT_TRUE(graph3.count_virus_positive_contacts("423") == 1);
//
//        //TEST 6: regular multiple node graph some positive
//        CovidGraph graph4;
//        CovidGraph::Person p9("Alan", "090", true, "May31");
//        CovidGraph::Person p10("Mike", "417", true, "Apr14");
//        CovidGraph::Person p11("Rachel", "320", false, "Jun7");
//        CovidGraph::Person p12("Ron", "543", true, "Aug11");
//        CovidGraph::Person p13("Gabe", "999", false, "Apr20");
//        graph4.insertPerson(p9);
//        graph4.insertPerson(p10);
//        graph4.insertPerson(p11);
//        graph4.insertPerson(p12);
//        graph4.insertPerson(p13);
//        graph4.connectEdges("999", "090", 2, "store");
//        graph4.connectEdges("999", "545", 4, "park");
//        graph4.connectEdges("320", "417", 4, "school");
//        graph4.connectEdges("543", "417", 6, "school");
//        graph4.connectEdges("090", "417", 3, "park");
//        ASSERT_TRUE(graph4.count_virus_positive_contacts("543") == 2);
//
//        //TEST 7: multiple node graph all positive
//        CovidGraph graph5;
//        CovidGraph::Person p14("Paul", "388", true, "May12");
//        CovidGraph::Person p15("Brock", "471", true, "Aug7");
//        CovidGraph::Person p16("Misty", "209", true, "Jun5");
//        CovidGraph::Person p17("Ash", "944", true, "Mar2");
//        CovidGraph::Person p18("Garry", "190", true, "Apr29");
//        graph5.insertPerson(p14);
//        graph5.insertPerson(p15);
//        graph5.insertPerson(p16);
//        graph5.insertPerson(p17);
//        graph5.insertPerson(p18);
//        graph5.connectEdges("388", "209", 1, "park");
//        graph5.connectEdges("471", "944", 3, "park");
//        graph5.connectEdges("944", "190", 3, "park");
//        graph5.connectEdges("209", "190", 5, "school");
//        graph5.connectEdges("388", "471", 4, "park");
//        ASSERT_TRUE(graph5.count_virus_positive_contacts("944") == 4);

        return true;
    }

    bool testdriver3() {
        //TEST 1: null graph return -1
        CovidGraph graph5;
        ASSERT_TRUE(graph5.find_largest_cluster_with_two_positive() == -1);

        //TEST 2: 0 individuals tested positive in cluster
        CovidGraph::Person p1("Jim", "150", false, "May3");
        CovidGraph::Person p2("Sam", "444", false, "May17");
        CovidGraph::Person p3("Putin", "599", false, "Apr4");
        graph5.insertPerson(p1);
        graph5.insertPerson(p2);
        graph5.insertPerson(p3);
        graph5.connectEdges("444", "599", 5, "train station");
        graph5.connectEdges("444", "150", 5, "hotel");
        ASSERT_TRUE(graph5.find_largest_cluster_with_two_positive() == -1);

        //TEST 3: 1 individuals tested positive in cluster
        CovidGraph::Person p4("Trump", "150", true, "May3");
        graph5.insertPerson(p4);
        graph5.connectEdges("599", "150", 2, "bunker");
        ASSERT_TRUE(graph5.find_largest_cluster_with_two_positive() == -1);

        //TEST 4: 2 individuals tested positive in cluster
        CovidGraph::Person p5("Ivan", "329", true, "May8");
        graph5.insertPerson(p5);
        graph5.connectEdges("329", "599", 8, "taxi");
        ASSERT_TRUE(graph5.find_largest_cluster_with_two_positive() == 2);

        //TEST 5: multiple clusters different numbers of positive cases in each cluster
        CovidGraph::Person p6("Rob", "497", true, "May8");
        graph5.insertPerson(p6);
        CovidGraph::Person p7("Bill", "411", true, "Feb2");
        graph5.insertPerson(p7);
        CovidGraph::Person p8("Dana", "327", true, "Mar18");
        graph5.insertPerson(p8);
        graph5.connectEdges("497", "411", 3, "laundromat");
        graph5.connectEdges("411", "327", 6, "party");
        CovidGraph::Person p9("Julia", "999", true, "Jun21");
        graph5.insertPerson(p9);
        CovidGraph::Person p10("Dan", "635", true, "Jun6");
        graph5.insertPerson(p10);
        CovidGraph::Person p11("Juan", "234", true, "Jun5");
        graph5.insertPerson(p11);
        CovidGraph::Person p12("Pablo", "829", true, "Jul1");
        graph5.insertPerson(p12);
        graph5.connectEdges("999", "635", 2, "forest");
        graph5.connectEdges("635", "234", 4, "park");
        graph5.connectEdges("635", "829", 9, "school");
        ASSERT_TRUE(graph5.find_largest_cluster_with_two_positive() == 4);

        return true;
    }

};
#endif

