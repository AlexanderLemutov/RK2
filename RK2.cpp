#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class ElectronicDevice{
protected: 
    string brand;
    string model; 
public:
    ElectronicDevice(const string& brand, const string& model): brand(brand), model(model){};
    
    virtual void display() const{
        cout << brand << " " << model << endl;
    }
    
    void EditBrand(const string& newBrand){
        brand = newBrand;
    }
    
    void EditModel(const string& newModel){
        model = newModel;
    }
    
    virtual ~ElectronicDevice(){};
};

class Smartphone: public ElectronicDevice{
protected:
    string os;
public:
    Smartphone(const string& brand, const string& model, const string& os): ElectronicDevice(brand, model), os(os){};
    void display() const override{
        cout << brand << " " << model << " " << os << endl;
    }
    
    ~Smartphone(){};
};

class Laptop: public ElectronicDevice{
protected:
    double screenSize;
public:
    Laptop(const string& brand, const string& model, const double& screenSize): ElectronicDevice(brand, model), screenSize(screenSize){};
    void display() const override{
        cout << brand << " " << model << " " << screenSize << endl;
    }
    
    ~Laptop(){};
};

void editDevice(ElectronicDevice* ptr){
    ptr->EditBrand("New Brand");
    ptr->EditModel("New Model");
}

int main()
{
    vector<ElectronicDevice*> data;
    data.resize(5);
    data[0] = new ElectronicDevice("Samsung", "SyncMaster 943");
    data[1] = new Smartphone("Apple", "iPhone 11 Pro Max", "iOS 17");
    data[2] = new Smartphone("Samsung", "Galaxy S7", "Android 8");
    data[3] = new Laptop("Apple", "MacBook Pro", 16.1);
    data[4] = new Laptop("Samsung", "Galaxy Book", 15.5);
    
    for (const auto i: data){
        i->display();
    }
    
    cout << " " << endl;
    
    for (const auto i: data){
        editDevice(i);
        i->display();
        delete i;
    }
    
    return 0;
}
