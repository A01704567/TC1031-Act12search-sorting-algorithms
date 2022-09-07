// =================================================================
//
// File: main.cpp
// Author: Sofía Blanco Prigmore 
// Date: 01/01/2021
//
// =================================================================
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream input; 
  ofstream mysolution; 
  
  int num, q, cantidad_bubble, cantidad_insertion, cantidad_selection, key_value, search_sequencial, search_binary;

  
  //Establecer 3 vectores 
  vector<int> bubble, insertion, selection;  


  //abre mi archivo 
  mysolution.open(argv[2]);
  input>>num;
  bubble.resize(num);
  for (int i=0; i<num; i++){
    input>>bubble[i];
  }

  //Se le asigna a selection e insertion su vector
  selection.assign(bubble.begin(),bubble.end());
  insertion.assign(bubble.begin(),bubble.end());
  
  //Se escribe en mi archivo
  mysolution<<bubbleSort(bubble)<<" "<<selectionSort(selection)<<" "<<insertionSort(insertion)<<"\n\n";

//===============
  

  //Cantidad a buscar 
  input >> q;
  int v_busqueda[q];
  
  for(int i = 0; i < q; i++){
    input >> v_busqueda[i];
  }
  
  for (int i = 0; i < q; i++){
    key_value = sequentialSearch(bubble, v_busqueda[i]);
    search_sequencial = sequentialSearchContador(bubble, v_busqueda[i]);
    search_binary = binarySearch(bubble, v_busqueda[i]);
    mysolution << "\n" << key_value << " " << search_sequencial << " " << search_binary ; 
  }
  
  input.close();
  mysolution.close();
  
  return 0;
  
}