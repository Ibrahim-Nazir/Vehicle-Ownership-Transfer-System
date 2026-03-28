#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// class car-seller-property define
class Car_Seller {
public:
    string Owner_Name;
    string Citizen_Ship;
    string Owner_ID_Number;
};

// class car buyear property
class Car_Buyer {
public:
    string Buyer_Name;
    string Citizen_Ship;
    string Buyer_ID_Number;
};

// class define for car specification 
class Car_Specification {
public:
    string Car_Number;
    string Car_Name;
    string Chasi_Number;
    int Car_Model;
    string Vehicle_Category;
    string Fuel_Speciality;
    float Payment;
};

// Function declared
int Car_Seller_Data(Car_Seller &Seller_Properties);
void Car_Specification_Data(Car_Specification &Car_Properties);
int Car_Buyer_Data(Car_Buyer &Buyer_Properties);
int Check_Taxes_Paid();
int Check_Crime_Record();
bool Check_bool_status(int resived_value);
string Check_Citizen_Shipe();
void Print_Recipt(Car_Seller &S, Car_Buyer &B, Car_Specification &C, bool Tax_Status, bool Crime_Status);

// main function----
int main() {
    bool Tax_Paid_Status, Crime_Status;

    class Car_Seller Seller_Properties;
    class Car_Buyer Buyer_Properties;
    class Car_Specification Car_Properties;

    Car_Seller_Data(Seller_Properties);
    Car_Specification_Data(Car_Properties);
    Car_Buyer_Data(Buyer_Properties);

    // store 0/1 value
    Tax_Paid_Status = Check_Taxes_Paid();
    Crime_Status = Check_Crime_Record();

    // replace 0/1 to bool value
    Tax_Paid_Status = Check_bool_status(Tax_Paid_Status);
    Crime_Status = Check_bool_status(Crime_Status);

    // print recipt
    Print_Recipt(Seller_Properties, Buyer_Properties, Car_Properties, Tax_Paid_Status, Crime_Status);

    return 0;
}
//end of main function---------

// Function enter car Seller detail
int Car_Seller_Data(Car_Seller &Seller_Properties) {
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Enter Owner Name : ";
    std::getline(std::cin, Seller_Properties.Owner_Name);
    cout << "Seller Citizen Ship :";
    std::getline(std::cin, Seller_Properties.Citizen_Ship);
    Seller_Properties.Owner_ID_Number = Check_Citizen_Shipe();

    return 0;
}

// car specification Data
void Car_Specification_Data(Car_Specification &Car_Properties) {
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cin.ignore(); // This clears the 'Enter' key from the buffer
    cout << "Vehicle Category :";
    std::getline(std::cin, Car_Properties.Vehicle_Category);
    cout << "Fuel Specification : ";
    std::getline(std::cin, Car_Properties.Fuel_Speciality);
    cout << "Car Name : ";
    std::getline(std::cin, Car_Properties.Car_Name);
    cout << "Unique Registration ID :";
    std::getline(std::cin, Car_Properties.Car_Number);
    cout << "Car Model : ";
    cin >> Car_Properties.Car_Model;
    cout << "Car Chassis Number : ";
    cin >> Car_Properties.Chasi_Number;
    cout << "Car Buying Price : ";
    cin >> Car_Properties.Payment;
}

// Function enter car buyer detail
int Car_Buyer_Data(Car_Buyer &Buyer_Properties) {
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cin.ignore(); // This clears the 'Enter' key from the buffer
    cout << "Enter Buyer Name : ";
    std::getline(std::cin, Buyer_Properties.Buyer_Name);
    cout << "Buyer Citizen Ship :";
    std::getline(std::cin, Buyer_Properties.Citizen_Ship);
    Buyer_Properties.Buyer_ID_Number = Check_Citizen_Shipe();

    return 0;
}

// Function check taxes paid or not
int Check_Taxes_Paid() {
    int choice = 0;
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Vehicle Taxe Paid or not :" << endl;
    cout << "Press 1 if Paid & 0 Not Paid :";
    cin >> choice;

    return choice;
}

// Function check crime 
int Check_Crime_Record() {
    int choice = 0;
    cout << endl;
    cout << "Vehicle Crime_Record :" << endl;
    cout << "Press 1 if NOt Record & 0 Record :";
    cin >> choice;

    return choice;
}

//Function check true false
bool Check_bool_status(int resived_value) {
    return (resived_value == 1) ? true : false;
}

// function check citizen shi
string Check_Citizen_Shipe() {
    int choice = 1;
    string id;
    cout << endl;
    cout << "Press 1 Pakistani & 0 for Fornear:";
    cin >> choice;
    cin.ignore(); // This clears the "Enter" key from the memory
    if (choice == 1) {
        cout << "Enter Owner Cnic : ";
        std::getline(std::cin, id);
    }
    else {
        cout << "Enter Owner Passboard Number :";
        std::getline(std::cin, id);
    }

    return id;
}

// Display trannfear resipt 
void Print_Recipt(Car_Seller &S, Car_Buyer &B, Car_Specification &C, bool Tax_Status, bool Crime_Status) {
    cout << endl;
    cout << endl;
    // use to display date and time
    time_t now = time(0);           // Get current system time
    char* dt = ctime(&now);
    cout << "******************************** ********************" << endl;
    cout << "   " << "      CAR OWNERSHIP TRANSFER TICKET" << "         " << endl;
    cout << "*****************************************************" << endl;
    cout << " ID:" << "VEHICLE-NAT-GOV-PK" << endl;
    cout << "DATE/TIME:" << dt << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "VEHICLE: " << C.Car_Name << " " << C.Car_Model << " " << "(Reg:" << C.Car_Number << ")" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "FROM: " << S.Owner_Name << "  " << "(ID:" << S.Owner_ID_Number << ")" << endl;
    cout << "TO: " << B.Buyer_Name << "  " << "(ID:" << B.Buyer_ID_Number << ")" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "TAX STATUS : " << (Tax_Status ? "PAID" : "UN-PAID") << endl;
    cout << "LEGAL STATUS: " << (Crime_Status ? "CLEARED" : "UN-CLEARED") << endl;
    cout << "----------- -----------------------------------------" << endl;
    cout << "    " << "   OWNERSHIP TRANSFERRED SUCCESSFULLY    " << "     " << endl;
    cout << "*****************************************************" << endl;
}