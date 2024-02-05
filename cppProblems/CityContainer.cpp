#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class City{
    string name;
    int inhabitants;
public:
    City() {}
    City (string name1, int inh){ name = name1; inhabitants = inh; }
    string getName() const { return name; }
    int getInhabitants() { return inhabitants; }
};

class Container{
    int capacity, numberOfCities;
    City *data;
public:
    Container(int cap){
        capacity = cap;
        numberOfCities = 0;
        data = new City[capacity];
    }
    ~Container() { delete[] data; }
    Container(const Container &c){
        capacity = c.capacity;
        numberOfCities = c.numberOfCities;
        data = new City[c.capacity];
        for (int i = 0; i < c.capacity; i++) data[i] = c.data[i];
    }
    Container &operator =(const Container &c){
        if (&c != this){
            capacity = c.capacity;
            numberOfCities = c.numberOfCities;
            delete[] data;
            data = new City[c.capacity];
            for (int i = 0; i < c.capacity; i++) data[i] = c.data[i];
        }
    }
    void addCity(string name, int no){
        if (numberOfCities == capacity) throw domain_error("Container is full!");
        for (int i = 0; i < numberOfCities; i++)
            if (data[i].getName() == name) throw domain_error("Given city already exists!");
        City c(name, no);
        data[numberOfCities] = c;
        numberOfCities++;
    }
    int getNoOfInhByCityName(string name) const {
        for (int i = 0; i < numberOfCities; i++)
            if (data[i].getName() == name) return data[i].getInhabitants();

        throw domain_error("No such city!");
    }
    void Display() const {
        cout << "Registered cities: " << endl;
        for (int i = 0; i < numberOfCities; i++)
            cout << data[i].getName() << " : " << data[i].getInhabitants() << endl;
    }
};

int main(){

    Container c(10);
    c.addCity("Sarajevo", 350000);
    c.addCity("Banja Luka", 190000);
    c.addCity("Tuzla", 130000);
    c.Display();
    cout << c.getNoOfInhByCityName("Banja Luka");
return 0;
}
