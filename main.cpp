#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Person
{
private:
    int id;
public:
    string name;
    Person(string givenName, int givenId){
        name = givenName;
        id = givenId;
    }
    int getId();
    void setId(int);
};

void Person::setId(int value){
    id = value; 
}

int Person::getId(){
    return id; 
}

void addPerson(int &i, string firstName, vector<Person*> &arr){ 
    Person* pointerToPerson = new Person(firstName, i);
    arr.push_back(pointerToPerson);
    i++;
}

void printPeople(vector<Person*> &array){
    if(array.size() == 0){
        cout << "list is empty" << endl; 
        system("pause");
        return;
    } 
    
    for(int i=0; i<array.size(); i++){
        cout << "name: " << array.at(i)->name << " id: " << array.at(i)->getId() << endl;
    }
    system("pause");
}

void modifyPerson(vector<Person*> &array, int givenId){
    Person* person = NULL;
    string newName; 
    int newId;

    for(int i=0; i<array.size(); i++){
        if(array.at(i)->getId() == givenId) person = array.at(i); 
    }

    if(person == NULL){
        cout << "user with the given Id was not found.";
        system("pause");
        return;
    }

    cout << "enter new name: ";
    cin >> newName;
    cout << "enter new id: ";
    cin >> newId;

    person->setId(newId);
    person->name = newName;
}

int main(){
    vector<Person*> People;

    int iterator = 0;
    char input;
    string name;

    do{
        cout << "1. add person" << endl;
        cout << "2. view people" << endl;
        cout << "3. modify person" << endl;
        cout << "0. exit" << endl << "----------------------------" << endl;
        cin >> input;
        switch (input)
        {
            case '0': break;
            case '1':
                cout << "enter the person's name: ";
                cin >> name;
                addPerson(iterator, name, People);
                break;
            case '2':
                printPeople(People);
                break;
            case '3':
                int temp;
                cout << "enter the person's id: ";
                cin >> temp;
                modifyPerson(People, temp);
                break;
            default:
                cout << "incorrect input" << endl;
                system("pause");
                break;
        }

        system("cls");
    } while(input != '0');

    return 0;
}