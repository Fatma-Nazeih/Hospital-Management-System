#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <set>
using namespace std;


int menu1()
{
    int choice;
    cout << "1. Admin Login" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2()
{
    int choice;
    cout << "1. Patient Management" << endl;
    cout << "2. Doctors Management" << endl;
    cout << "3. Show All Specializations" << endl;
    cout << "4. Admin Management" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2_1()
{
    int choice;
    cout << "1. Add New Patient" << endl; //check if found , add to list of U or R 
    cout << "2. Delete Patient" << endl; //re-order the list
    cout << "3. Update Patient Information" << endl; //re-order the list 
    cout << "4. Show Patient Information" << endl;
    cout << "5. Show All Patients" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

int menu2_2()
{
    int choice;
    cout << "1. Add New Doctor" << endl; //check if found 
    cout << "2. Delete Doctor" << endl; // Redistribution of the patients in the list
    cout << "3. Update Doctor Information" << endl;
    cout << "4. Show Doctor Information" << endl;
    cout << "5. Show Doctor List of Patients " << endl;
    cout << "6. Show All Doctors in one Specialization" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}



int menu2_4()
{
    int choice;
    cout << "1. Add New Admin" << endl; //check if found 
    cout << "2. Delete Admin" << endl; // Redistribution of the patients in the list
    cout << "3. Update Admin Information" << endl;
    cout << "4. Show Admin Information" << endl;
    cout << "5. Show All Admin" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}


struct patient
{
    int age, id, phone, relatives_phone;
    string situation; //In case the patient is pregnant or has a certain allergy or chronic disease 
    string name, gender, specialization_patient;
    bool urgent;
    int doctorID;
};


struct doctor
{
    string specialization_doctor, name, address;
    int age, salary, doctorID;
    list <string> pats;

};

struct specialization
{
    int iid;
    string name;
    int num_doctors;
    list <int> docs;
    list <int> speces;
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

    bool check_if_found_spec(int id)
    {
        for (const specialization& it : specializations)
        {
            if (it.iid == id)
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
                for (auto& patient : patients)
                {
                    if (patient.doctorID == id) {
                        if (patient.urgent) {
                            it->pats.remove(patient.name);
                        }
                    }
                }
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

    void show_all_patients()
    {
        for (const patient& p : patients)
        {
            cout << "ID: " << p.id
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
            cout << "ID: " << m.id
                << ", Name: " << m.name
                << ", Phone Number: " << m.phone
                << ", Address: " << m.address
                << ", Salary: " << m.salary
                << ", User name: " << m.username << endl;
        }
    }

    void show_all_spec()
    {
        for (const specialization& s : specializations)
        {
            cout << "Specialization: " << s.name << " - " << "ID : " << s.iid << " - " << "Has a number of doctors = " << s.num_doctors << endl;
        }
    }


    void show_patient(int id)
    {
        for (const patient& p : patients)
        {
            if (p.id == id)
            {
                cout << "ID: " << p.id
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
                cout << "ID: " << d.doctorID
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
                cout << "ID: " << m.id
                    << ", Name: " << m.name
                    << ", Address: " << m.address
                    << ", Salary: " << m.salary
                    << ", Username: " << m.username << endl;
            }
        }
    }

    bool search_doc(int i) {
        for (patient& it : patients)
        {
            if (it.id == i)
            {
                return true;
            }
        }
        return false;
    }

    void show_doctor_list_of_patients(int doctorID)
    {
        for (const doctor& d : doctors)
        {
            if (d.doctorID == doctorID)
            {
                cout << "Doctor: " << d.name << endl;
                cout << "Patients:" << endl;
                for (const patient& p : patients)
                {
                    if (p.doctorID == doctorID)
                    {
                        cout << " - " << p.name << ", ID: " << p.id << ", Situation: " << p.situation << endl;
                    }
                }
                return;
            }
        }
        cout << "Doctor with ID " << doctorID << " not found." << endl;
    }

    void show_all_doctors_in_specialization(int specializationID)
    {
        bool found = false;
        for (const specialization& s : specializations)
        {
            if (s.iid == specializationID)
            {
                cout << "Specialization: " << s.name << endl;
                cout << "Doctors:" << endl;
                for (int doctorID : s.docs)
                {
                    for (const doctor& d : doctors)
                    {
                        if (d.doctorID == doctorID)
                        {
                            cout << " - " << d.name << ", ID: " << d.doctorID << endl;
                            found = true;
                            break;
                        }
                    }
                }
                if (!found)
                {
                    cout << "No doctors found in this specialization." << endl;
                }
                return;
            }
        }
        cout << "Specialization with ID " << specializationID << " not found." << endl;
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
            cout << "Enter Your Name: ";
            getline(cin, name);
            

            cout << "Enter Your Password: ";
            getline(cin, pass);
            

            if (h.check_if_found_admin(name, pass)) {
                cout << "Login successful!" << endl;

                ofstream login("admin.txt", ios::app);
                if (login.is_open()) {
                    login << "The Name is: " << name << endl;
                    login << "The Password is: " << pass << endl;
                    login.close();
                }
                else {
                    cout << "Error: Unable to open file." << endl;
                }

                int choice2 = menu2();
                if (choice2 == 1)
                {
                    int choice3 = menu2_1();
                    if (choice3 == 1)
                    {
                        cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        cout << "Enter patient name: ";
                        getline(cin, p.name);
                      

                        cout << "Enter patient age: ";
                        cin >> p.age;
                        cin.ignore();

                        cout << "Enter patient gender (Male/Female): ";
                        cin >> p.gender;
                        cin.ignore();

                        cout << "Enter patient phone number: ";
                        cin >> p.phone;
                        cin.ignore();

                        cout << "Enter patient's relative's phone number: ";
                        cin >> p.relatives_phone;
                        cin.ignore();

                        cout << "Enter patient situation (e.g., pregnant, allergy, chronic disease): ";
                        getline(cin, p.situation);
                      
                        cout << "Enter patient specialization: ";
                        cin >> p.specialization_patient;
                        cin.ignore();

                        cout << "Enter patient specialization ID: ";
                        cin >> s.iid;
                        cin.ignore();

                        cout << "Is the patient urgent? (1 for Yes, 0 for No): ";
                        cin >> p.urgent;
                        cin.ignore();

                        cout << "Enter the doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        if (h.check_if_found_spec(s.iid)) {
                            if (h.search_doc(d.doctorID)) {
                                if (p.urgent) {
                                    if (s.docs.size() < 10) {
                                        d.pats.push_front(p.name);
                                    }
                                    else {
                                        cout << "No free space in the urgent list" << endl;
                                    }
                                }
                                else {
                                    if (s.docs.size() < 10) {
                                        d.pats.push_back(p.name);
                                    }
                                    else {
                                        cout << "No free space in the regular list" << endl;
                                    }
                                }
                            }
                            else {
                                s.docs.push_back(d.doctorID);
                                if (p.urgent) {
                                    if (s.docs.size() < 10) {
                                        d.pats.push_front(p.name);
                                    }
                                    else {
                                        cout << "No free space in the urgent list" << endl;
                                    }
                                }
                                else {
                                    if (s.docs.size() < 10) {
                                        d.pats.push_back(p.name);
                                    }
                                    else {
                                        cout << "No free space in the regular list" << endl;
                                    }
                                }
                            }
                        }
                        else {
                            s.speces.push_back(s.iid);
                            s.docs.push_back(d.doctorID);
                            if (p.urgent) {
                                if (s.docs.size() < 10) {
                                    d.pats.push_front(p.name);
                                }
                                else {
                                    cout << "No free space in the urgent list" << endl;
                                }
                            }
                            else {
                                if (s.docs.size() < 10) {
                                    d.pats.push_back(p.name);
                                }
                                else {
                                    cout << "No free space in the regular list" << endl;
                                }
                            }
                        }


                    }
                    else if (choice3 == 2)
                    {
                        cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        cout << "Enter patient name: ";
                        getline(cin, p.name);
                        

                        if (h.check_if_found_patient(p.id))
                        {
                            h.delete_patient(p.id);
                            cout << "Patient deleted Successfully" << endl;
                        }
                        else {
                            cout << "Patient is not exist already" << endl;
                        }
                    }
                    else if (choice3 == 3)
                    {
                        cout << "Enter patient ID: ";
                        cin >> p.id;
                        cin.ignore();

                        cout << "Enter patient name: ";
                        getline(cin, p.name);
                        cin.ignore();

                        cout << "Enter patient age: ";
                        cin >> p.age;
                        cin.ignore();

                        cout << "Enter patient gender (Male/Female): ";
                        cin >> p.gender;
                        cin.ignore();

                        cout << "Enter patient phone number: ";
                        cin >> p.phone;
                        cin.ignore();

                        cout << "Enter patient's relative's phone number: ";
                        cin >> p.relatives_phone;
                        cin.ignore();

                        cout << "Enter patient situation (e.g., pregnant, allergy, chronic disease): ";
                        getline(cin, p.situation);
                        cin.ignore();

                        cout << "Enter patient specialization: ";
                        cin >> p.specialization_patient;
                        cin.ignore();

                        cout << "Is the patient urgent? (1 for Yes, 0 for No): ";
                        cin >> p.urgent;
                        cin.ignore();

                        cout << "Enter the doctor ID: ";
                        cin >> p.doctorID;
                        cin.ignore();
                        h.update_patient(p.id, p);
                    }
                    else if (choice3 == 4)
                    {
                        cout << "Enter The Patient ID:" << endl;
                        cin >> p.id;
                        h.show_patient(p.id);
                    }
                    else if (choice3 == 5)
                    {
                        h.show_all_patients();
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }

                }
                else if (choice2 == 2) {
                    int choice4 = menu2_2();
                    if (choice4 == 1)
                    {
                        doctor d;
                        cout << "Enter doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        cout << "Enter doctor name: ";
                        getline(cin, d.name);

                        cout << "Enter doctor age: ";
                        cin >> d.age;
                        cin.ignore();

                        cout << "Enter doctor address: ";
                        getline(cin, d.address);
                        cin.ignore();

                        cout << "Enter doctor salary: ";
                        cin >> d.salary;
                        cin.ignore();

                        cout << "Enter doctor's specialization: ";
                        getline(cin, d.specialization_doctor);
                       

                        if (h.check_if_found_doctor(d.doctorID))
                        {
                            h.add_doctor(d);
                            cout << "Doctor added Successfully" << endl;
                        }
                        else {
                            cout << "Doctor is already exist" << endl;
                        }

                    }
                    else if (choice4 == 2)
                    {
                        cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        cout << "Enter Doctor name: ";
                        getline(cin, d.name);
                        cin.ignore();

                        if (h.check_if_found_doctor(d.doctorID))
                        {
                            h.delete_doctor(d.doctorID);
                            cout << "Doctor deleted Successfully" << endl;
                        }
                        else
                        {
                            cout << "Doctor does not exist" << endl;
                        }
                    }

                    else if (choice4 == 3)
                    {
                        cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        cin.ignore();

                        cout << "Enter Doctor name: ";
                        getline(cin, d.name);
                        cin.ignore();

                        cout << "Enter Doctor age: ";
                        cin >> d.age;
                        cin.ignore();

                        cout << "Enter Doctor address: ";
                        getline(cin, d.address);
                        cin.ignore();

                        cout << "Enter Doctor salary: ";
                        cin >> d.salary;
                        cin.ignore();

                        h.update_doctor(d.doctorID, d);
                    }
                    else if (choice4 == 4)
                    {
                        cout << "Enter The Doctor ID:" << endl;
                        cin >> d.doctorID;
                        cin.ignore();

                        h.show_doctor(d.doctorID);
                    }
                    else if (choice4 == 5)
                    {
                        cout << "Enter Doctor ID: ";
                        cin >> d.doctorID;
                        h.show_doctor_list_of_patients(d.doctorID);
                        
                    }
                    else if (choice4 == 6)
                    {
                        cout << "Enter The Specialization ID: ";
                        cin >> s.iid;
                        h.show_all_doctors_in_specialization(s.iid);
                    }
                    else if (choice4 == 7)
                    {
                        exit(0);
                    }
                    else {
                        cout << "Invalid Input " << endl;
                    }
                }
                else if (choice2 == 3)
                {
                    h.show_all_spec();
                }
                else if (choice2 == 4)
                {
                    int choice5 = menu2_4();
                    if (choice5 == 1) {

                        cout << "Enter ID: ";
                        cin >> m.id;
                        cin.ignore();

                        cout << "Enter phone number: ";
                        cin >> m.phone;
                        cin.ignore();

                        cout << "Enter salary: ";
                        cin >> m.salary;
                        cin.ignore();

                        cout << "Enter address: ";
                        getline(cin, m.address);
                       

                        cout << "Enter name: ";
                        getline(cin, m.name);
                        

                        cout << "Enter username: ";
                        getline(cin, m.username);
                        

                        cout << "Enter password: ";
                        getline(cin, m.passward);
                       

                        if (h.check_if_found_admin2(m.id))
                        {
                            h.add_admin(m);
                            cout << "Admin added Successfully" << endl;
                        }
                        else {
                            cout << "Admin is already exist" << endl;
                        }

                    }
                    else if (choice5 == 2) {
                        cout << "Enter Admin ID: ";
                        cin >> m.id;
                        cin.ignore();

                        cout << "Enter Admin name: ";
                        getline(cin, m.username);
                        cin.ignore();

                        if (h.check_if_found_admin2(m.id))
                        {
                            h.delete_admin(m.id);
                            cout << "Doctor deleted Successfully" << endl;
                        }
                        else
                        {
                            cout << "Doctor does not exist" << endl;
                        }
                    }
                    else if (choice5 == 3) {
                        cout << "Enter Admin ID: ";
                        cin >> m.id;
                        cin.ignore();

                        cout << "Enter Admin name: ";
                        getline(cin, m.name);
                        

                        cout << "Enter Admin user name: ";
                        getline(cin, m.username);
                        

                        cout << "Enter Admin address: ";
                        getline(cin, m.address);
                        cin.ignore();

                        cout << "Enter Admin salary: ";
                        cin >> m.salary;
                        cin.ignore();
                        h.update_admin(m.id, m);
                    }
                    else if (choice5 == 4) {
                        cout << "Enter The Admin ID:" << endl;
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
                        cout << "Invalid Input " << endl;
                    }
                }
                else if (choice2 == 5) {
                    exit(0);
                }
                else
                {
                    cout << "Invalid information" << endl;
                }

            }
            else {
                cout << "Login Failed, Wrong name or password" << endl;
            }


        }
        else if (choice1 == 2)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid Input Please Try Again." << endl;
        }

    }


    return 0;
}
