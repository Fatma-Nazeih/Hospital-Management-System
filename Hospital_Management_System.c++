#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <set>
using namespace std;


int menu1()
{
    int choice;
    std::cout << "1. Admin Login" << endl;
    std::cout << "2. Exit" << endl;
    std::cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2()
{
    int choice;
    std::cout << "1. Patient Management" << endl;
    std::cout << "2. Doctors Management" << endl;
    std::cout << "3. Admin Management" << endl;
    std::cout << "4. Exit" << endl;
    std::cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2_1()
{
    int choice;
    std::cout << "1. Add New Patient" << endl; //check if found , add to list of U or R 
    std::cout << "2. Delete Patient" << endl; //re-order the list
    std::cout << "3. Update Patient Information" << endl; //re-order the list 
    std::cout << "4. Show Patient Information" << endl;
    std::cout << "5. Show All Patients" << endl;
    std::cout << "6. Exit" << endl;
    std::cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2_2()
{
    int choice;
    std::cout << "1. Add New Doctor" << endl; //check if found 
    std::cout << "2. Delete Doctor" << endl; // Redistribution of the patients in the list
    std::cout << "3. Update Doctor Information" << endl;
    std::cout << "4. Show Doctor Information" << endl;
    std::cout << "5. Show Doctor List of Patients " << endl;
    std::cout << "6. Show All Doctors" << endl;
    std::cout << "7. Exit" << endl;
    std::cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}



int menu2_4()
{
    int choice;
    std::cout << "1. Add New Admin" << endl; //check if found 
    std::cout << "2. Delete Admin" << endl; // Redistribution of the patients in the list
    std::cout << "3. Update Admin Information" << endl;
    std::cout << "4. Show Admin Information" << endl;
    std::cout << "5. Show All Admin" << endl;
    std::cout << "6. Exit" << endl;
    std::cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}


struct patient
{
    int age, id, phone, relatives_phone, specid;
    string situation; //In case the patient is pregnant or has a certain allergy or chronic disease 
    string name, gender, specialization_patient;
    bool urgent;
    int doctorID;
};


struct doctor
{
    string specialization_doctor, name, address;
    int age, salary, doctorID;

};

struct specialization
{
    int iid;
    string name;
    int num_doctors;

};

struct admin
{
    int id, phone, salary;
    string address, name, username, passward;
};


struct hospital
{
    list<patient> patients;
    list<doctor> doctors;
    list<specialization> specializations;
    list<admin> admins;

    //add

    void add_patient(const patient& p)
    {
        patients.push_back(p);
    }


    void add_doctor(const doctor& d)
    {
        doctors.push_back(d);
    }


    void add_admin(const admin& m)
    {
        admins.push_back(m);
    }

    //check

    bool check_if_found_patient(int id)
    {
        for (const patient& it : patients)
        {
            if (it.id == id)
            {
                return true;
            }
        }
        return false;
    }

    bool check_if_found_admin2(int id)
    {
        for (const patient& it : patients)
        {
            if (it.id == id)
            {
                return true;
            }
        }
        return false;
    }


    bool check_if_found_admin(string name, string passward)
    {
        for (const admin& it : admins)
        {
            if (it.username == name && it.passward == passward)
            {
                return true;
            }
        }
        return false;
    }

    bool check_if_found_doctor(int id)
    {
        for (const doctor& it : doctors)
        {
            if (it.doctorID == id)
            {
                return true;
            }
        }
        return false;
    }


    //update

    void update_patient(int id, const patient& p)
    {
        for (patient& it : patients)
        {
            if (it.id == id)
            {
                it = p;
                break;
            }
        }
    }

    void update_doctor(int id, const doctor& d)
    {
        for (doctor& it : doctors)
        {
            if (it.doctorID == id)
            {
                it = d;
                break;
            }
        }
    }

    void update_admin(int id, const admin& m)
    {
        for (admin& it : admins)
        {
            if (it.id == id)
            {
                it = m;
                break;
            }
        }
    }


    //delete

    void delete_patient(int id)
    {
        for (auto it = patients.begin(); it != patients.end(); ++it)
        {
            if (it->id == id)
            {
                patients.erase(it);
                break;
            }
        }
    }

    void delete_doctor(int id)
    {
        for (auto it = doctors.begin(); it != doctors.end(); ++it)
        {
            if (it->doctorID == id)
            {

                doctors.erase(it);
                break;
            }
        }
    }


    void delete_admin(int id)
    {
        for (auto it = admins.begin(); it != admins.end(); ++it)
        {
            if (it->id == id)
            {
                admins.erase(it);
                break;
            }
        }
    }


    //show one ////////
    void show_patient(int id)
    {
        for (const patient& p : patients)
        {
            if (p.id == id)
            {
                std::cout << "ID: " << p.id
                    << ", Name: " << p.name
                    << ", Age: " << p.age
                    << ", Phone Number: " << p.phone
                    << ", Patient Situation: " << p.situation
                    << ", Doctor ID: " << p.doctorID << endl;
            }
        }
    }

    void show_doctor(int id)
    {
        for (const doctor& d : doctors)
        {
            if (d.doctorID == id)
            {
                std::cout << "ID: " << d.doctorID
                    << ", Name: " << d.name
                    << ", Address: " << d.address
                    << ", Salary: " << d.salary

                    << ", Specialization: " << d.specialization_doctor << endl;
            }
        }
    }

    void show_admin(int id)
    {
        for (const admin& m : admins)
        {
            if (m.id == id)
            {
                std::cout << "ID: " << m.id
                    << ", Name: " << m.name
                    << ", Address: " << m.address
                    << ", Salary: " << m.salary
                    << ", Username: " << m.username << endl;
            }
        }
    }

    ////////////////////////

    //show all

    void show_doctor_list_of_patients(int doctorID)
    {
        for (const doctor& d : doctors)
        {
            if (d.doctorID == doctorID)
            {
                std::cout << "Doctor: " << d.name << endl;
                std::cout << "Patients:" << endl;
                for (const patient& p : patients)
                {
                    if (p.doctorID == doctorID)
                    {
                        std::cout << " - " << p.name << ", ID: " << p.id << ", Situation: " << p.situation << endl;
                    }
                }
                return;
            }
        }
        std::cout << "Doctor with ID " << doctorID << " not found." << endl;
    }

    void show_all_patients()
    {
        for (const patient& p : patients)
        {
            std::cout << "ID: " << p.id
                << ", Name: " << p.name
                << ", Age: " << p.age
                << ", Phone Number: " << p.phone
                << ", Patient Situation: " << p.situation
                << ", Doctor ID: " << p.doctorID << endl;
        }
    }

    void show_all_admins()
    {
        for (const admin& m : admins)
        {
            std::cout << "ID: " << m.id
                << ", Name: " << m.name
                << ", Phone Number: " << m.phone
                << ", Address: " << m.address
                << ", Salary: " << m.salary
                << ", User name: " << m.username << endl;
        }
    }


    void show_all_doctors()
    {
        for (const doctor& d : doctors)
        {
            std::cout << "ID: " << d.doctorID
                << ", Name: " << d.name

                << ", Address: " << d.address
                << ", Salary: " << d.salary
                << ", Specialization: " << d.specialization_doctor << endl;
        }
    }

};


int main() {
    hospital h;
    admin m;
    doctor d;
    patient p;
    specialization s;

    admin mm = { 20230284, 11447895, 25000, "El Sheikh Zayed", "fatma", "fatma", "1234" };
    h.add_admin(mm);

    while (true)
    {
        int choice1 = menu1();
        if (choice1 == 1) {
            cin.ignore();

            string name, pass;
            std::cout << "Enter Your Name: ";
            std::getline(cin, name);


            std::cout << "Enter Your Password: ";
            std::getline(cin, pass);


            if (h.check_if_found_admin(name, pass)) {
                std::cout << "Login successful!" << endl;

                ofstream login("admin.txt", ios::app);
                if (login.is_open()) {
                    login << "The Name is: " << name << endl;
                    login << "The Password is: " << pass << endl;
                    login.close();
                }
                else {
                    std::cout << "Error: Unable to open file." << endl;
                }

                int choice2 = menu2();
                if (choice2 == 1)
                {
                    int choice3 = menu2_1();
                    if (choice3 == 1)
                    {
                        std::cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        std::cout << "Enter patient name: ";
                        std::getline(cin, p.name);
                        cin.ignore();

                        std::cout << "Enter patient age: ";
                        cin >> p.age;
                        cin.ignore();

                        std::cout << "Enter patient gender (Male/Female): ";
                        cin >> p.gender;
                        cin.ignore();

                        std::cout << "Enter patient phone number: ";
                        cin >> p.phone;
                        cin.ignore();

                        std::cout << "Enter patient's relative's phone number: ";
                        cin >> p.relatives_phone;
                        cin.ignore();

                        std::cout << "Enter patient situation (e.g., pregnant, allergy, chronic disease): ";
                        std::getline(cin, p.situation);

                        std::cout << "Enter patient specialization: ";
                        cin >> p.specialization_patient;
                        cin.ignore();

                        std::cout << "Enter patient specialization ID: ";
                        cin >> p.specid;
                        cin.ignore();

                        std::cout << "Is the patient urgent? (1 for Yes, 0 for No): ";
                        cin >> p.urgent;
                        cin.ignore();

                        std::cout << "Enter the doctor ID: ";
                        cin >> p.doctorID;
                        cin.ignore();

                        if (h.check_if_found_patient(p.id)) {
                            cout << "Patient is already added" << endl;
                        }
                        else {
                            h.add_patient(p);
                            cout << "Patient added Successfully." << endl;
                        }

                    }
                    else if (choice3 == 2)
                    {
                        std::cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        std::cout << "Enter patient name: ";
                        std::getline(cin, p.name);


                        if (h.check_if_found_patient(p.id))
                        {
                            h.delete_patient(p.id);
                            std::cout << "Patient deleted Successfully" << endl;
                        }
                        else {
                            std::cout << "Patient is not exist already" << endl;
                        }
                    }
                    else if (choice3 == 3)
                    {
                        std::cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        std::cout << "Enter patient name: ";
                        std::getline(cin, p.name);
                        cin.ignore();

                        std::cout << "Enter patient age: ";
                        cin >> p.age;
                        cin.ignore();

                        std::cout << "Enter patient gender (Male/Female): ";
                        cin >> p.gender;
                        cin.ignore();

                        std::cout << "Enter patient phone number: ";
                        cin >> p.phone;
                        cin.ignore();

                        std::cout << "Enter patient's relative's phone number: ";
                        cin >> p.relatives_phone;
                        cin.ignore();

                        std::cout << "Enter patient situation (e.g., pregnant, allergy, chronic disease): ";
                        std::getline(cin, p.situation);
                        cin.ignore();

                        std::cout << "Enter patient specialization: ";
                        cin >> p.specialization_patient;
                        cin.ignore();

                        std::cout << "Is the patient urgent? (1 for Yes, 0 for No): ";
                        cin >> p.urgent;
                        cin.ignore();

                        std::cout << "Enter the doctor ID: ";
                        cin >> p.doctorID;
                        cin.ignore();
                        h.update_patient(p.id, p);
                    }
                    else if (choice3 == 4)
                    {
                        std::cout << "Enter The Patient ID:" << endl;
                        cin >> p.id;
                        h.show_patient(p.id);
                    }
                    else if (choice3 == 5)
                    {
                        h.show_all_patients();
                    }
                    else
                    {
                        std::cout << "Invalid Input" << endl;
                    }

                }
                else if (choice2 == 2) {
                    int choice4 = menu2_2();
                    if (choice4 == 1)
                    {

                        std::cout << "Enter doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        std::cout << "Enter doctor name: ";
                        std::getline(cin, d.name);
                        cin.ignore();

                        std::cout << "Enter doctor age: ";
                        cin >> d.age;
                        cin.ignore();

                        std::cout << "Enter doctor address: ";
                        std::getline(cin, d.address);
                        cin.ignore();

                        std::cout << "Enter doctor salary: ";
                        cin >> d.salary;
                        cin.ignore();

                        std::cout << "Enter doctor's specialization: ";
                        std::getline(cin, d.specialization_doctor);

                        if (h.check_if_found_doctor(d.doctorID)) {

                            std::cout << "Doctor is already exist." << endl;
                        }
                        else {
                            h.add_doctor(d);
                            std::cout << "Doctor added Successfully" << endl;
                        }


                    }
                    else if (choice4 == 2)
                    {
                        std::cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        std::cout << "Enter Doctor name: ";
                        std::getline(cin, d.name);
                        cin.ignore();

                        if (h.check_if_found_doctor(d.doctorID))
                        {
                            h.delete_doctor(d.doctorID);
                            std::cout << "Doctor deleted Successfully" << endl;
                        }
                        else
                        {
                            std::cout << "Doctor does not exist" << endl;
                        }
                    }

                    else if (choice4 == 3)
                    {
                        std::cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        std::cout << "Enter Doctor name: ";
                        std::getline(cin, d.name);
                        cin.ignore();

                        std::cout << "Enter Doctor age: ";
                        cin >> d.age;
                        cin.ignore();

                        std::cout << "Enter Doctor address: ";
                        std::getline(cin, d.address);
                        cin.ignore();

                        std::cout << "Enter Doctor salary: ";
                        cin >> d.salary;
                        cin.ignore();

                        h.update_doctor(d.doctorID, d);
                    }
                    else if (choice4 == 4)
                    {
                        std::cout << "Enter The Doctor ID:" << endl;
                        cin >> d.doctorID;
                        cin.ignore();

                        h.show_doctor(d.doctorID);
                    }
                    else if (choice4 == 5)
                    {
                        std::cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        h.show_doctor_list_of_patients(d.doctorID);

                    }
                    else if (choice4 == 6)
                    {
                        h.show_all_doctors();
                    }
                    else if (choice4 == 7)
                    {
                        exit(0);
                    }
                    else {
                        std::cout << "Invalid Input " << endl;
                    }
                }

                else if (choice2 == 3)
                {
                    int choice5 = menu2_4();
                    if (choice5 == 1) {

                        std::cout << "Enter ID: ";
                        cin >> m.id;
                        cin.ignore();

                        std::cout << "Enter phone number: ";
                        cin >> m.phone;
                        cin.ignore();

                        std::cout << "Enter salary: ";
                        cin >> m.salary;
                        cin.ignore();

                        std::cout << "Enter address: ";
                        std::getline(cin, m.address);


                        std::cout << "Enter name: ";
                        std::getline(cin, m.name);
                        cin.ignore();


                        std::cout << "Enter username: ";
                        std::getline(cin, m.username);


                        std::cout << "Enter password: ";
                        std::getline(cin, m.passward);


                        if (h.check_if_found_admin2(m.id))
                        {
                            std::cout << "Admin is already exist" << endl;
                        }
                        else {
                            h.add_admin(m);
                            std::cout << "Admin added Successfully" << endl;
                            
                        }

                    }
                    else if (choice5 == 2) {
                        std::cout << "Enter Admin ID: ";
                        cin >> m.id;
                        cin.ignore();

                        std::cout << "Enter Admin name: ";
                        std::getline(cin, m.username);
                        cin.ignore();

                        if (h.check_if_found_admin2(m.id))
                        {
                            h.delete_admin(m.id);
                            std::cout << "Admin deleted Successfully" << endl;
                        }
                        else
                        {
                            std::cout << "Admin does not exist" << endl;
                        }
                    }
                    else if (choice5 == 3) {
                        std::cout << "Enter Admin ID: ";
                        cin >> m.id;
                        cin.ignore();

                        std::cout << "Enter Admin name: ";
                        std::getline(cin, m.name);


                        std::cout << "Enter Admin user name: ";
                        std::getline(cin, m.username);


                        std::cout << "Enter Admin address: ";
                        std::getline(cin, m.address);
                        cin.ignore();

                        std::cout << "Enter Admin salary: ";
                        cin >> m.salary;
                        cin.ignore();
                        h.update_admin(m.id, m);
                    }
                    else if (choice5 == 4) {
                        std::cout << "Enter The Admin ID:" << endl;
                        cin >> m.id;
                        h.show_admin(m.id);
                    }
                    else if (choice5 == 5) {
                        h.show_all_admins();
                    }
                    else if (choice5 == 6) {
                        exit(0);
                    }
                    else {
                        std::cout << "Invalid Input " << endl;
                    }
                }
                else if (choice2 == 4) {
                    exit(0);
                }
                else
                {
                    std::cout << "Invalid information" << endl;
                }

            }
            else {
                std::cout << "Login Failed, Wrong name or password" << endl;
            }


        }
        else if (choice1 == 2)
        {
            exit(0);
        }
        else
        {
            std::cout << "Invalid Input Please Try Again." << endl;
        }

    }


    return 0;
}

