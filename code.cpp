#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>  
#include <cctype>
#include <algorithm>
using namespace std;

//prototipi
bool continuare (string& risposta);

int main() {
    srand(time(0));  
    int lunghezza_password=10;
    int numeri[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char lettere_maiuscole[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    char lettere_minuscole[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    char caratteri[7] = {'!', '?', '@', '#', '$', '%', '&'};
    bool ciclo=true;
    while (ciclo) { 
        cout<<"Generazione delle prime 10 password"<<endl; 
        for (int i=0;i<10;i++){
            string password = ""; 
            for (int i = 0; i < lunghezza_password; i++) {  
            int scelta = (rand() % 4) + 1; 
            switch (scelta) {
                case 1: {
                    int index = rand() % 10;  // Indice per i numeri (0-9)
                    //cout << "caso 1: " << numeri[index] << endl;
                    password += to_string(numeri[index]);  
                    break;
                }
                case 2: {
                    int index = rand() % 26;  // Indice per lettere maiuscole
                    //cout << "caso 2: " << lettere_maiuscole[index] << endl;
                    password += lettere_maiuscole[index];
                    break;
                }
                case 3: {
                    int index = rand() % 26;  // Indice per lettere minuscole
                    //cout << "caso 3: " << lettere_minuscole[index] << endl;
                    password += lettere_minuscole[index];
                    break;
                }
                case 4: {
                    int index = rand() % 7;  // Indice per i caratteri speciali
                    //cout << "caso 4: " << caratteri[index] << endl;
                    password += caratteri[index];
                    break;
                }
                default:
                    break;
            }
        }
        cout<<"["<<i+1<<"]"<<"password generata :"<<password<<endl;
        }
        
        cout<<"vuoi continuare con altre password: [si] o [no]";
        string risposta;
        cin>>risposta;
        ciclo=continuare(risposta);
    }
    return 0;
}
//funzione

bool continuare(string& risposta){
    
    transform(risposta.begin(), risposta.end(), risposta.begin(),[](unsigned char c) { return toupper(c); });

    if (risposta == "NO") {
        return false;
    } else if (risposta == "SI") {
        return true;
    } else {
        cout << "Risposta sbagliata, si prega di rinserire la scelta [si] o [no]: " << endl;
        string nuovaRisposta;
        cin >> nuovaRisposta;
        return continuare(nuovaRisposta); 
    }
}
