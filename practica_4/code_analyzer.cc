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
  05/10/2024 - Creacion (primera version) del codigo
  06/10/2024 - Funciones de variables y loops añadido
  07/10/2024 - Contador de lineas añadido
  09/10/2024 - Modificacion
*/
#include <iostream>

#include "code_analyzer.h"

CodeAnalyzer::CodeAnalyzer(const std::string& file_path) : file_path_(file_path){
  content_ = "";
}
  
void CodeAnalyzer::ReadFile() {
  std::ifstream in_file(Path());
  if (in_file.is_open()) {
    std::string line;
    while (getline(in_file, line)) {
      content_ += line + "\n";
    }
    in_file.close();
  } else {
    std::cerr << "ERROR: " << Path() << " couldn't open\n";
  }
}

std::vector<std::string> CodeAnalyzer::SplitByLines(const std::string& content) {
    std::vector<std::string> lines;
    std::stringstream ss(content);
    std::string line;

    while (std::getline(ss, line)) {
        lines.push_back(line);
    }

    return lines;
}

/*
  @brief: grabs the first comments and titles it as the descpription of the file
  @problems: only grabs the first one, if its multiple single line comments it  
             doesn't grab all of them
*/

std::string CodeAnalyzer::ExtractDescription() {
  std::regex comment_pattern = Patterns().GetDescriptionPattern();
  std::smatch match;

  if (std::regex_search(Content(), match, comment_pattern)) {
    std::string first_comment = match[0];

    std::string::const_iterator search_start = match.suffix().first;
    while (std::regex_search(search_start, Content().cend(), match,
     comment_pattern)) {
      if (first_comment.find("//") == 0) {
        first_comment += "\n" + match[0].str();
        search_start = match.suffix().first;
      } else {
        break;
      }
    }
    return  first_comment;
  } 
  return "No description found";
}

/*
  @brief: searches line by line to see if it can find the pattern
          (\s\/\/.*|\/\*[\s\S]*?\*\/) which captures single line 
          and multi line comments, if one is found it adds it to the
          vector in a pair with its line number
  @problem: can't find multi-line comments
*/

std::vector<std::pair<int, std::string>> CodeAnalyzer::ExtractComments() {
  std::vector<std::pair<int, std::string>> comments;
  std::regex comment_pattern = Patterns().GetCommentPattern();
  std::vector<std::string> lines = CodeAnalyzer::SplitByLines(Content());
  std::string current_multiline_comment;
  bool inside_multiline_comment = false;
  int multiline_start_line = -1;

  for (int i = 0; i < lines.size(); ++i) {
    std::smatch match;
    if (inside_multiline_comment) {
      // We are inside a multi-line comment, accumulate lines until we find the end
      current_multiline_comment += lines[i] + "\n";
      
      if (lines[i].find("*/") == std::string::npos) {
        // End of multi-line comment found
        comments.push_back({multiline_start_line, current_multiline_comment});
        inside_multiline_comment = false;
        current_multiline_comment.clear();
      } 
    } else if (std::regex_search(lines[i], match, comment_pattern)) {
        std::string current_comment = match[0];

        if (current_comment.find("/*") != std::string::npos && current_comment.find("*/") != std::string::npos) {
              // Start of a multi-line comment, set flag and start accumulating
              inside_multiline_comment = true;
              multiline_start_line = i + 1;
              current_multiline_comment = current_comment + "\n";
        } else {
          // Single line comments
          comments.push_back({i + 1, current_comment});
        }
      }
    } 

  return comments;
}

/*
  @brief: searches line by line to see if it can find the pattern
          (\b(int|double)\s+(\w*)\s*(=\s*[^;]+|(\{\s*[^;]+\}))?\s*;)
          which captures most basic type of variables and string and if it finds
          one it adds it to the vector in a pair with its line number
*/

std::vector<std::pair<int, std::string>> CodeAnalyzer::ExtractVariables() {
  std::vector<std::pair<int, std::string>> variables;
  std::regex variables_pattern = Patterns().GetVariablePattern();
  std::vector<std::string> lines = CodeAnalyzer::SplitByLines(Content());

  for (int i = 0; i < lines.size(); ++i) {
    std::smatch match;
    if (std::regex_search(lines[i], match, variables_pattern)) {
      bool is_const = lines[i].find("const") != std::string::npos;
      // stores the line number and the variables
      if (is_const) {
        variables.push_back({i + 1, "CONST: " + match[0].str()});        
      } else {
        variables.push_back({i + 1, match[0]});
      }
    }
  }
  return variables;
}

/*
  @brief: searches line by line to see if it can find the pattern
          (\b(for|while)\b\s*\(.*?\)) which captures for and while statements
          and if it finds one it adds it to the vector in a pair with its line 
          number
*/

std::vector<std::pair<int, std::string>> CodeAnalyzer::ExtractLoops() {
  std::vector<std::pair<int, std::string>> loops;
  std::regex loop_pattern = Patterns().GetLoopsPattern();
  std::vector<std::string> lines = CodeAnalyzer::SplitByLines(Content());

  for (int i = 0; i < lines.size(); ++i) {
    std::smatch match;
    if (std::regex_search(lines[i], match, loop_pattern)) {
      // Store line number and loop type
      loops.push_back({i + 1, match[1]});
    }
  }
  return loops;
}


bool CodeAnalyzer::CheckForMain() {
  return Content().find("int main") != std::string::npos;
}

void CodeAnalyzer::WriteAnalysis(const std::string& output_file) {
  std::ofstream output(output_file);
  if (output.is_open()) {
    output << "PROGRAM: " << Path() << "\n";

    output << "DESCRIPTION: \n" << ExtractDescription() << "\n\n";

    output << "VARIABLE: \n";
    for (const auto& variable : ExtractVariables()) {
      output << "[Line " << variable.first << "] " << variable.second << "\n";
    }
    output << "\n";

    output << "STATEMENTS: \n";
    for (const auto& statement : ExtractLoops()) {
      output << "[Line " << statement.first << "] " << statement.second << "\n";
    }
    output << "\n";

    output << "MAIN: \n" << (CheckForMain() ? "True" : "False") << "\n";
    output << "\n";

    output << "COMMENTS: \n";
    for (const auto& comment : ExtractComments()) {
      output << "[Line " << comment.first << "] " << comment.second << "\n";
    }
    output << "\n";
    
    output.close();
  } else {
    std::cerr <<"ERROR: " << output_file << " couldn't open\n";
  }
}
