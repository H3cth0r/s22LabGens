#include <iostream>
#include <fstream> // leer el archivo
#include <sstream>// tokenizar el string 
#include <vector>
#include <string>
#include <list>
#include <functional>
using namespace std;
#include "hashTable.h"

void cargaWuhanFasta(vector<string> & datos){
  string archivo = "wuhan.fasta";
  ifstream lector(archivo);
  if(lector.fail()){
    cout << "error ";
    return;
  }

  string linea;
  getline(lector, linea); // salta el primer renglón.
  while( getline(lector, linea)){
      datos.push_back(linea);
  }
  lector.close();
}
int main() {
  vector<string> genoma;
  
  cargaWuhanFasta(genoma);

  // vector dictionary of bases
  vector<vector<string>> bases_dictionary = {{"UUU", "Phe"}, {"UUC", "Phe"}, {"UUA", "Leu"}, {"UUG", "Leu"},
                                             {"CUU", "Leu"}, {"CUC", "Leu"}, {"CUA", "Leu"}, {"CUG", "Leu"},
                                             {"UCU", "Ser"}, {"UCC", "Ser"}, {"UCA", "Ser"}, {"UCG", "Ser"},
                                             {"CCU", "Pro"}, {"CCC", "Pro"}, {"CCA", "Pro"}, {"CCG", "Pro"},
                                             {"UAU", "Tyr"}, {"UAC", "Tyr"}, {"UAA", "sto"}, {"UAG", "sto"},
                                             {"CAU", "His"}, {"CAC", "His"}, {"CAA", "Gln"}, {"CAG", "Gln"},
                                             {"UGU", "Cys"}, {"UGC", "Cys"}, {"UGA", "sto"}, {"UGG", "Trp"},
                                             {"CGU", "Arg"}, {"CGC", "Arg"}, {"CGA", "Arg"}, {"CGG", "Arg"},
                                             {"AUU", "Ile"}, {"AUC", "Ila"}, {"AUA", "Ile"}, {"AUG", "Met"},
                                             {"ACU", "Thr"}, {"ACC", "Thr"}, {"ACA", "Thr"}, {"ACG", "Thr"},
                                             {"AAU", "Asn"}, {"AAC", "Asn"}, {"AAA", "Lys"}, {"AAG", "Lys"},
                                             {"AGU", "Ser"}, {"AGC", "Ser"}, {"AGA", "Arg"}, {"AGG", "Arg"},
                                             {"GUU", "Val"}, {"GUC", "Val"}, {"GUA", "Val"}, {"GUG", "Val"},
                                             {"GCU", "Ala"}, {"GCC", "Ala"}, {"GCA", "Ala"}, {"GCG", "Ala"},
                                             {"GAU", "Asp"}, {"GAC", "Asp"}, {"GAA", "Glu"}, {"GAG", "Glu"},
                                             {"GGU", "Gly"}, {"GGC", "Gly"}, {"GGA", "Gly"}, {"GGG", "Gly"}};

int num_nucletides = 0, j;
string chain="";
for(int i = 0; i < genoma.size(); i++){
  for(j = 0; j < genoma[i].size(); j++){ 
    if(genoma[i][j] == 'T') genoma[i][j] = 'U';
    chain+=genoma[i][j];
  }
}




// for this version  the key will be the base's and the value will act as a counter
Hashtable<string, int> second_counter_bases(8000);
for(int i = 0; i < bases_dictionary.size(); i++) second_counter_bases.put(bases_dictionary[i][0], 0);
for(int i = 0; i < chain.size(); i++){
  second_counter_bases.counter_addition(chain.substr(i, 3), 1);
}
second_counter_bases.print_filled();
cout << "=============================" << endl;
second_counter_bases.delete_values(100);
second_counter_bases.print_filled();
cout << "=============================" << endl;
second_counter_bases.print_starting_with('A');


/*
Laboratorio del Genoma del SARS-COV2 & HashTable
Ejercicio 1:
Usando una tabla hash crea un contador del total de número de bases de toda la secuencia. ¿Recuerdas cuáles son los nucleótidos en un genoma?

Ejercicio 2:

¿Recuerdas el dogma central de la biología molecular?
Revisa los conceptos:
https://www.nature.com/scitable/topicpage/translation-dna-to-mrna-to-protein-393/#:~:text=During%20transcription%2C%20the%20enzyme%20RNA,encoded%20by%20the%20original%20gene.

Revisa una transcripción -> traducción:
http://biomodel.uah.es/en/lab/cybertory/analysis/trans.htm

Utilizando una tabla hash:
  1. Llena la tabla con los codones (o tripletes permitidos SIN repetidos). Cada codón es una llave en una tabla hash. Imprime todas las llaves de la tabla.
  2. Encuentra todas las repeticiones de cada codón utilizando la tabla hash.
  3. Imprime el contenido de toda la tabla.
  4. Borra los codones que no tengan más de 100 repeticiones.
  5. Imprime la tabla.
  6. Imprime las repeticiones de todos los codones que inicien con A.
*/

} 