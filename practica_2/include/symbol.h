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
	Clase symbol

  Historial de revisiones
  22/09/2024 - Creacion (primera version) del codigo
*/

#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
  public:

  Symbol(char val);

  char get_value() const {return value_;}

  bool operator<(const Symbol& other) const {
    return get_value() < other.get_value();
  }

  private:
    char value_;
};
#endif
