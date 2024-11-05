/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 7: Forma Canonica de Chomsky
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 06/11/2024
  Archivo: CNFConverter.h.
  	    Initializes the converter class which contains the functions that are used to transform the grammar into a CNF grammar

  Historial de revisiones
  02/11/2024 - Creacion (primera version) del codigo
*/
#ifndef CNFCONVERTER_H
#define CNFCONVERTER_H

#include "Grammar.h"

class CNFConverter {
public:
    void RemoveEmptyProductions(Grammar& grammar);
    void RemoveUnitProductions(Grammar& grammar);
    void ConvertToCNF(Grammar& grammar);                  // Convertir a CNF
};

#endif
