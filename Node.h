//
// Created by Esteban Montesinos on 10/16/18.
//

#ifndef HOMEWORK8_NODE_H
#define HOMEWORK8_NODE_H
#include <map>
#include <istream>

using namespace std;



class Node {
public:
    string state;
    map<char,Node*>m2;
    Node(string s);

};


#endif //HOMEWORK8_NODE_H
