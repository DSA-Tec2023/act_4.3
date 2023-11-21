#include <iostream>
#include <vector> 
#include <queue> 
#pragma once

/*
Declaración e implementación de la clase Destination,
utilizada para guardar tanto el nombre del puerto como su
posición en forma de id.

Equipo:
Andrés Martínez, A00227463
Fernanda Granados, A01252895
Santiago Poblete, A01254609
Martín Tánori, A01252900

Fecha: 19 de noviembre de 2023
*/

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