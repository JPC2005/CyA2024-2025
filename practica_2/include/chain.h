/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 2: Cadenas y lenguajes
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 22/09/2024
  Archivo cy: programa cliente.
	Clase Chain

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
  25/09/2024 - Modificacion en clase
*/
#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

#include "symbol.h"
#include "alphabet.h"

class Chain {
  public:

    Chain(const std::string& ChainStr);
    const std::vector<Symbol>& get_chain() const { return chain_;}
    size_t get_size() const {return chain_.size();}
    
    void Length(std::ofstream& output) const;
    void Prefix(std::ofstream& output) const;
    void Suffix(std::ofstream& output) const;
    void PrintInverse(std::ofstream& output) const;

    // Modificacion
    void NumberLength(std::ofstream& output, int length) const;

  private:
    std::vector<Symbol> chain_;
};

#endif
