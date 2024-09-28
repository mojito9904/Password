#include <iostream>    
#include <string>           // Libreria per le stringhe 
#include <cstdlib>          // Per usare il rand
#include <ctime>            // Per usare il time(0)
#include <cctype>           // Per rendere tutto maiuscolo un carattere 
#include <algorithm>        // Per usare il transform 

using namespace std;

// Prototipi
bool continuare(string& risposta);  //prototipo per decidere se continuare oppure no 

int main() {
    srand(time(0));  
    
    // Array unificato con tutti gli elementi a disposizione 
    string caratteri = "0123456789"
                       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "abcdefghijklmnopqrstuvwxyz"
                       "!@#$%&?";
    
    int lunghezza_password = 10;  //la lunghezza che deve essere la nostra password
    bool ciclo = true;            //variabile booolena per la gestione del ciclo 
    
    while (ciclo) { 
        cout << "Generazione delle prime 10 password" << endl; 
        
        for (int i = 0; i < 10; i++) {              //ciclo che viene eseguito per 10 volte 
            string password = "";                   //dichiarazizone della stringa password che è vuota 
            
            for (int j = 0; j < lunghezza_password; j++) {  //ciclo che viene eseguito per la creazione della password
                int index = rand() % caratteri.length();    // Scelta casuale dalla stringa caratteri 
                password += caratteri[index];               // Aggiunge il carattere casuale alla password
            }
            
            cout << "[" << i + 1 << "] password generata: " << password << endl;        //stampa le varie password 
        }
        
        // Richiedi se continuare
        cout << "Vuoi continuare con altre password: [si] o [no] ";
        string risposta;
        cin >> risposta;
        ciclo = continuare(risposta);
    }
    
    return 0;
}

// Funzione per gestire la scelta di continuare
bool continuare(string& risposta) {
    transform(risposta.begin(), risposta.end(), risposta.begin(), [](unsigned char c) { return toupper(c); }); //permette di trasformare la stringa della risposta in maiuscolo 

    if (risposta == "NO") {
        return false;               //se la rispsota è uguale a NO allora la funzione fa un return di una variabile booleana su falso 
    } else if (risposta == "SI") {
        return true;                //se invece la risposta è uguale a SI allora la funzione restituisce una variabile booleana su vero 
    } else {
        //altrimenti si fa una chiamata ricorsiva della stessa funzione fino a quando non si effettua una scelta giusta 
        cout << "Risposta sbagliata, si prega di reinserire la scelta [si] o [no]: " << endl;
        string nuovaRisposta;                               
        cin >> nuovaRisposta;
        return continuare(nuovaRisposta); 
    }
}
