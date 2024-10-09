/*
  Universidad de La Laguna
  Escuela Superior de Ingenieria y Tecnologia
  Grado en Ingenieria Informatica
  Asignatura: Computabilidad y Algoritmia
  Curso: 2º
  Practica 4: Cadenas y lenguajes
  Autor: Juan Pablo Calzadilla Gonzalez
  Correo: alu0101651@ull.edu.es
  Fecha: 17/09/2024
  Archivo cy: programa cliente.
  	    Contiene la funcion main del proyecto que usa las clases X e Y
  	    para ... (indicar brevemente el objetivo)
  Referencias:
  	    Enlaces de interes

  Historial de revisiones
  5/10/2024 - Creacion (primera version) del codigo
  06/10/2024 - Funciones de variables y loops añadido
  07/10/2024 - Contador de lineas añadido
  09/10/2024 - Modificacion
*/
#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "regex_patterns.h"

class CodeAnalyzer {
  public:
    CodeAnalyzer(const std::string& file_path);
    const RegexPatterns& Patterns() const { return patterns_;}
    const std::string& Path() const { return file_path_;}
    const std::string& Content() const { return content_;}

    void ReadFile();

    std::vector<std::string> SplitByLines(const std::string& content);
    std::string ExtractDescription();
    std::vector<std::pair<int, std::string>> ExtractComments();
    std::vector<std::pair<int, std::string>> ExtractVariables();
    std::vector<std::pair<int, std::string>> ExtractLoops();
    bool CheckForMain();

    void WriteAnalysis(const std::string& output_file);
  private:
  std::string file_path_;
  std::string content_;
  RegexPatterns patterns_;
};

#endif