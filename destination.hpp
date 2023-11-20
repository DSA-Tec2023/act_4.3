#include <iostream>
#include <vector> 
#include <queue> 
#pragma once

class Destination {
private:
    std::string name;
    int id;
public:

    Destination(std::string name_, int id_) {
        name = name_;
        id = id_;
    }
    void print_info() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << id << std::endl;
    }

    bool operator==(const Destination &other) const { // This is in order to be able to compare between different objects, it only compares whether the name is the same or not.
        return (name == other.name);
    }

    int get_id() {
        return id;
    }

    std::string get_name() {
        return name;
    }
};