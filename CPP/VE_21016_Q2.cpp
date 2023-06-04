#include <iostream>
#include <string>
#include <stdbool.h>
#include <vector>

using namespace std;

class Character{

    string nome;
    string prof;

    public: 
        Character(string nome, string prof)
        {
            this->nome=nome;
            this->prof=prof;
        } 

        string PegarNome()
        {
            return nome;
        }

        void mudar(string nova_prof)
        {
            prof = nova_prof;
        }
};

class CharacterDatabase{
    
    vector <string> relacionamentos;
    vector <Character> pessoa;

    public: 
        
        string pequisar(string nome){
            for(int k = 0; k < pessoa.size(); k++){
                if(pessoa.at(k).PegarNome() == nome){
                    return "encontrado";
                }
            }
            return "não encontrado";
        }
        void adicionar(Character &l)
        {
            pessoa.push_back(l);
        }

        void editCharacter(string nome, string new_oc){
            Character *obj;
            for(int k = 0; k < pessoa.size(); k++)
            {
                if(pessoa.at(k).PegarNome() == nome)
                {
                    obj = &(pessoa.at(k));
                    break;
                }
            }
            obj->mudar(new_oc);

            return;
        }

        void relacionar(Character &c1, Character &c2, string rel){
            relacionamentos.push_back(c1.PegarNome() + " " + rel + " "+ c2.PegarNome());
        }

        void printar()
        {
            for(int k = 0; k < pessoa.size(); k++){
                cout << pessoa.at(k).PegarNome() << endl;
            }

            for(int k = 0; k < relacionamentos.size(); k++){
                cout << relacionamentos.at(k) << endl;
            }
        }
};

int main(){

    CharacterDatabase database;

    Character c1("Rachel", "Garçonete"); 
    Character c2("Monica", "Chef"); 
    Character c3("Phoebe", "Massagista"); 
    Character c4("Chandler", "Desconhecido"); 
    Character c5("Ross", "Professor"); 
    Character c6("Joey", "Ator"); 

    database.adicionar(c1);
    database.adicionar(c2);
    database.adicionar(c3);
    database.adicionar(c4);
    database.adicionar(c5);
    database.adicionar(c6);

    database.editCharacter("Rachel", "Design de moda");

    cout << database.pequisar("Gunther") << endl;
    cout << database.pequisar("Rachel") << endl;

    database.relacionar(c2, c5, "irmaos");
    database.relacionar(c2, c4, "casados");
    database.relacionar(c1, c2, "roommates");
    database.relacionar(c4, c6, "roommates");

    database.printar();
}