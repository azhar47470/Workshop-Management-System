#include<iostream>
#include <fstream>
using namespace std;

struct vehicle
{
    string company, License_plate, model;
    int year;
};
int total_vehicles = 0;

struct customer
{
    string name, contact;
    vehicle v;
};
int total_customers = 0;

struct mechanic
{
    string name, specialization, assigned_job;
};
int total_mechanics = 0;

struct spare_parts
{
    string name;
    int part_id, price_per_unit, quantity; 
};
int total_spareparts = 0;

struct jobcard
{
    int vehicle_id, parts_cost, labor_cost;
    string issue, assigned_mechanic, status;
};
int total_jobcards = 0;

// Vehicle Functions

void add_vehicle(vehicle v[], int total_vehicles){
    
    cout<<"Vehicle "<<total_vehicles+1<<endl<<endl;
    cout<<"company: ";
    cin>>v[total_vehicles].company;

    cout<<"model: ";
    cin.ignore();
    getline(cin,v[total_vehicles].model);

    cout<<"year: ";
    cin>>v[total_vehicles].year;

    cout<<"License_plate: ";
    cin>>v[total_vehicles].License_plate;
    
    cout<<"\nSuccessfully Added"<<endl<<endl;
}

void display_vehicle(vehicle v[], int total_vehicles){
    
    for (int i = 0; i < total_vehicles; i++)
    {
        cout<<"Vehicle "<<i+1<<endl<<endl;
        cout<<"company: "<<v[i].company<<endl;
        cout<<"model: "<<v[i].model<<endl;
        cout<<"year: "<<v[i].year<<endl;
        cout<<"License_plate: "<<v[i].License_plate<<endl<<endl;       
    }   
}

void search_vehicle(vehicle v[], int total_vehicles, string choice_v){

    bool found = false;

    for (int i = 0; i < total_vehicles; i++)
    {
        if (choice_v == v[i].License_plate)
        {
            found = true;

            cout<<"company: "<<v[i].company<<endl;
            cout<<"model: "<<v[i].model<<endl;
            cout<<"year: "<<v[i].year<<endl;
            cout<<"License_plate: "<<v[i].License_plate<<endl<<endl;
        }   
    } 
    
    if (found == false)
    {
        cout<<"Record Not Found\n";
    }   
}

void save_vehicle(vehicle v[], int total_vehicles)
{
    ofstream file("vehicles.txt");

    file << total_vehicles << endl;

    for (int i = 0; i < total_vehicles; i++)
    {
        file << v[i].company << endl;
        file << v[i].model << endl;
        file << v[i].year << endl;
        file << v[i].License_plate << endl;
    }

    file.close();
}

void load_vehicle(vehicle v[], int &total_vehicles)
{
    ifstream file("vehicles.txt");

    if (!file)
    {
        return;
    }

    file >> total_vehicles;

    file.ignore();

    for (int i = 0; i < total_vehicles; i++)
    {
        getline(file, v[i].company);

        getline(file, v[i].model);

        file >> v[i].year;

        file.ignore();

        getline(file, v[i].License_plate);
    }

    file.close();
}

// Customer Functions

void add_customer(customer c[],int total_customers){
    
    cout<<"Customer "<<total_customers+1<<endl<<endl;
    cout<<"Name: ";
    cin.ignore();
    getline(cin, c[total_customers].name);

    cout<<"Contact Number: ";
    getline(cin, c[total_customers].contact);

    cout<<"company: ";
    cin>>c[total_customers].v.company;

    cout<<"model: ";  
    cin.ignore();
    getline(cin, c[total_customers].v.model);

    cout<<"year: ";
    cin>>c[total_customers].v.year;

    cout<<"License_plate: ";
    cin>>c[total_customers].v.License_plate;
    cout<<"\nSuccessfully Added"<<endl<<endl;
}

void display_customer(customer c[],int total_customers){
    
    for (int i = 0; i < total_customers; i++)
    {
        cout<<"Customer "<<i+1<<endl<<endl;
        cout<<"Name: "<<c[i].name<<endl;
        cout<<"Contact Number: "<<c[i].contact<<endl;
        cout<<"company: "<<c[i].v.company<<endl;
        cout<<"model: "<<c[i].v.model<<endl;
        cout<<"year: "<<c[i].v.year<<endl;
        cout<<"License_plate: "<<c[i].v.License_plate<<endl<<endl;       
    }   
}

void search_customer(customer c[],int total_customers,string choice_c){

    bool found = false;

    for (int i = 0; i < total_customers; i++)
    {
        if (choice_c == c[i].name)
        {
            found = true;

            cout<<"Name: "<<c[i].name<<endl;
            cout<<"Contact Number: "<<c[i].contact<<endl;
            cout<<"company: "<<c[i].v.company<<endl;
            cout<<"model: "<<c[i].v.model<<endl;
            cout<<"year: "<<c[i].v.year<<endl;
            cout<<"License_plate: "<<c[i].v.License_plate<<endl;
        }   
    }   

    if (found == false)
    {
        cout<<"Record Not Found\n";
    }  
}

void save_customer(customer c[], int total_customers)
{
    ofstream file("customers.txt");

    file << total_customers << endl;

    for (int i = 0; i < total_customers; i++)
    {
        file << c[i].name << endl;
        file << c[i].contact << endl;
        
        file << c[i].v.company << endl;
        file << c[i].v.model << endl;
        file << c[i].v.year << endl;
        file << c[i].v.License_plate << endl;
    }

    file.close();
}

void load_customer(customer c[], int &total_customers)
{
    ifstream file("customers.txt");

    if(!file)
    {
        return;
    }

    file >> total_customers;

    file.ignore();

    for(int i=0; i<total_customers; i++)
    {
        getline(file, c[i].name);

        getline(file, c[i].contact);

        getline(file, c[i].v.company);

        getline(file, c[i].v.model);

        file >> c[i].v.year;

        file.ignore();

        getline(file, c[i].v.License_plate);
    }

    file.close();
}

// Mechanic Functions

void add_mechanic(mechanic m[], int total_mechanics){
    
    cout<<"Mechanic "<<total_mechanics+1<<endl<<endl;
    cout<<"Name: ";
    cin.ignore();
    getline(cin,m[total_mechanics].name);

    cout<<"Specialization (Engine, Electrical, Bodywork): ";
    getline(cin, m[total_mechanics].specialization);

    cout<<"Job Assigned: ";
    getline(cin,m[total_mechanics].assigned_job);
    cout<<"\nSuccessfully Added"<<endl<<endl;
}

void display_mechanic(mechanic m[], int total_mechanics){
    
    for (int i = 0; i < total_mechanics; i++)
    {
        cout<<"Mechanic: "<<i+1<<endl<<endl;
        cout<<"Name : "<<m[i].name<<endl;
        cout<<"Specialization: "<<m[i].specialization<<endl;
        cout<<"Job Assigned: "<<m[i].assigned_job<<endl<<endl;
    }   
}

void save_mechanic(mechanic m[], int total_mechanics)
{
    ofstream file("mechanics.txt");

    file << total_mechanics << endl;

    for (int i = 0; i < total_mechanics; i++)
    {
        file << m[i].name << endl;
        file << m[i].specialization << endl;
        file << m[i].assigned_job << endl;
    }

    file.close();
}

void load_mechanic(mechanic m[], int &total_mechanics)
{
    ifstream file("mechanics.txt");

    if (!file)
    {
        return;
    }

    file >> total_mechanics;

    file.ignore();

    for (int i = 0; i < total_mechanics; i++)
    {
        getline(file, m[i].name);

        getline(file, m[i].specialization);

        getline(file, m[i].assigned_job);
    }

    file.close();
}

// Spare Parts Functions

void add_part(spare_parts p[], int total_spareparts){

    cout<<"Name: ";
    cin.ignore();
    getline(cin,p[total_spareparts].name);

    cout<<"Part id: ";
    cin>>p[total_spareparts].part_id;

    cout<<"quantity: ";
    cin>>p[total_spareparts].quantity;

    cout<<"Price Per Unit: ";
    cin>>p[total_spareparts].price_per_unit;

    cout<<"\nSuccessfully Added"<<endl<<endl;
}

void display_parts(spare_parts p[], int total_spareparts){

    cout<<"Spare Parts Available"<<endl<<endl;

    for (int i = 0; i < total_spareparts; i++)
    {
        cout<<"Name : "<<p[i].name<<endl;
        cout<<"Part id: "<<p[i].part_id<<endl;
        cout<<"Price Per Unit: "<<p[i].price_per_unit<<endl;
        cout<<"In Stock: "<<p[i].quantity<<endl<<endl;
    }       
}

void search_part(spare_parts p[], int total_spareparts, int choice_p){

    bool found = false;

    for (int i = 0; i < total_spareparts; i++)
    {
        if (choice_p == p[i].part_id)
        {
            found = true;

            cout<<"Name: "<<p[i].name<<endl;
            cout<<"Part id: "<<p[i].part_id<<endl;
            cout<<"Price Per Unit: "<<p[i].price_per_unit<<endl;
            cout<<"Stock: "<<p[i].quantity<<endl;
        }   
    } 
    
    if(found == false)
    {
        cout<<"Record Not Found\n";
    }
}

void save_parts(spare_parts p[], int total_spareparts)
{
    ofstream file("inventory.txt");

    file << total_spareparts << endl;

    for (int i = 0; i < total_spareparts; i++)
    {
        file << p[i].name << endl;
        file << p[i].part_id << endl;
        file << p[i].quantity << endl;
        file << p[i].price_per_unit << endl;
    }

    file.close();
}

void load_parts(spare_parts p[], int &total_spareparts)
{
    ifstream file("inventory.txt");

    if (!file)
    {
        return;
    }

    file >> total_spareparts;

    file.ignore();

    for (int i = 0; i < total_spareparts; i++)
    {
        getline(file, p[i].name);

        file >> p[i].part_id;

        file >> p[i].quantity;

        file >> p[i].price_per_unit;

        file.ignore();
    }

    file.close();
}

// Job Card Functions

void add_job(jobcard j[], int total_jobcards){

    cout<<"Vehicle id: ";
    cin>>j[total_jobcards].vehicle_id;

    cout<<"Issue: ";
    cin.ignore();
    getline(cin, j[total_jobcards].issue);;

    cout<<"Assigned Mechanic: ";
    getline(cin,j[total_jobcards].assigned_mechanic);

    cout<<"Labor Cost: ";
    cin>>j[total_jobcards].labor_cost;

    cout<<"Parts Cost: ";
    cin>>j[total_jobcards].parts_cost;

    j[total_jobcards].status = "In Progress";
    cout<<"\nSuccessfully Added"<<endl<<endl;
}

void display_job(jobcard j[], int total_jobcards){

    cout<<"Job Cards"<<endl<<endl;

    for (int i = 0; i < total_jobcards; i++)
    {
        cout<<"Vehicle id: "<<j[i].vehicle_id<<endl;
        cout<<"Issue: "<<j[i].issue<<endl;
        cout<<"Assigned Mechanic: "<<j[i].assigned_mechanic<<endl;
        cout<<"Labor Cost: "<<j[i].labor_cost<<endl;
        cout<<"Status: "<<j[i].status<<endl;
    }       
}

void search_job(jobcard j[], int total_jobcards , int choice_j){

    bool found = false;

    for (int i = 0; i < total_jobcards; i++)
    {
        if (choice_j == j[i].vehicle_id)
        {
            found = true;

            cout<<"Vehicle id: "<<j[i].vehicle_id<<endl;
            cout<<"Issue: "<<j[i].issue<<endl;
            cout<<"Assigned Mechanic: "<<j[i].assigned_mechanic<<endl;
            cout<<"Labor Cost: "<<j[i].labor_cost<<endl;
            cout<<"Status: "<<j[i].status<<endl;
        }   
    }   

    if(found == false)
    {
        cout<<"Record Not Found\n";
    }
}

void update_status(jobcard j[], int total_jobcards)
{
    int ch;
    cout<<"1. View Pending Jobs\n2. Update Status with Vehicle id\nPress 1/2 : ";
    cin>>ch;

    if (ch==1)
    {
        cout << "\nPending Jobs\n\n";

        for (int i = 0; i < total_jobcards; i++)
        {
            if (j[i].status == "In Progress")
            {
                cout << "Vehicle id: "<< j[i].vehicle_id << endl;
                cout << "Issue: "<< j[i].issue << endl;
                cout << "Mechanic: "<< j[i].assigned_mechanic << endl;
                cout << endl;
            }
        }
    }
    else
    {
        bool found = false;
        int id;
        cout << "Enter Vehicle ID to update status: ";
        cin >> id;

        for (int i = 0; i < total_jobcards; i++)
        {
            if (j[i].vehicle_id == id)
            {
                found = true;

                cout << "\n1. In Progress";
                cout << "\n2. Completed";

                int choice;
                cout << "\nEnter choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    j[i].status = "In Progress";
                }
                else if (choice == 2)
                {
                    j[i].status = "Completed";
                }
                cout << "\nStatus Updated Successfully\n\n";
                return;
            }
        }

        if (found == false)
        {
            cout<< "Job not found.\n";
        }
    }    
}

void save_jobs(jobcard j[], int total_jobcards)
{
    ofstream file("jobcard.txt");

    file << total_jobcards << endl;

    for (int i = 0; i < total_jobcards; i++)
    {
        file << j[i].vehicle_id << endl;
        file << j[i].issue << endl;
        file << j[i].assigned_mechanic << endl;
        file << j[i].labor_cost << endl;
        file << j[i].parts_cost << endl;
        file << j[i].status << endl;
    }

    file.close();
}

void load_jobs(jobcard j[], int &total_jobcards)
{
    ifstream file("jobcard.txt");

    if (!file)
    {
        return;
    }

    file >> total_jobcards;

    file.ignore();

    for (int i = 0; i < total_jobcards; i++)
    {
        file >> j[i].vehicle_id;

        file.ignore();

        getline(file, j[i].issue);

        getline(file, j[i].assigned_mechanic);

        file >> j[i].labor_cost;

        file >> j[i].parts_cost;

        file.ignore();

        getline(file, j[i].status);
    }

    file.close();
} 

// Billing Invoice

void generate_bill(jobcard j[], int total_jobcards, int choice_b){
    int total = 0;

    bool found = false;

    for (int i = 0; i < total_jobcards; i++)
    {
        if (choice_b == j[i].vehicle_id)
        {
            found = true;

            total = j[i].labor_cost + j[i].parts_cost;

            cout<<"===== INVOICE ======"<<endl;
            cout<<"Vehicle ID: "<<j[i].vehicle_id<<endl;
            cout<<"Issue: "<<j[i].issue<<endl;
            cout<<"Mechanic: "<<j[i].assigned_mechanic<<endl;
            cout<<"--------------------"<<endl;
            cout<<"Parts Cost: Rs."<<j[i].parts_cost<<endl;
            cout<<"Labor Cost: Rs."<<j[i].labor_cost<<endl;
            cout<<"--------------------"<<endl;
            cout<<"Total:      Rs."<<total<<endl;
            cout<<"===================="<<endl;
        }   
    }
    
    if(found == false)
    {
        cout<<"Record Not Found\n";
    }
}

int main(){
    vehicle v[100];
    customer c[100];
    mechanic m[100];
    spare_parts p[100];
    jobcard j[100];

    load_vehicle(v, total_vehicles);
    load_customer(c, total_customers);
    load_mechanic(m, total_mechanics);
    load_parts(p, total_spareparts);
    load_jobs(j, total_jobcards);

    int main_choice;
    do
    {
        cout<<"1. Vehicle Module\n2. Customer Module\n3. Mechanic Module\n4. Spare Parts Module\n5. Job Card Module\n6. Billing & Invoice\n0. Exit\n\nPress (0-6) : ";
        cin>>main_choice;
        cout<<endl;
        if (main_choice == 1)
        {
            int vm;
            cout<<"1. Add Vehicle\n2. Display All Vehicles\n3. Search a Vehicle\n\nPress 1/2/3 : ";
            cin>>vm;
            cout<<endl;
            if (vm == 1)
            {
                add_vehicle(v,total_vehicles);
                total_vehicles++;
                save_vehicle(v, total_vehicles);
            }
            else if (vm == 2)
            {
                display_vehicle(v,total_vehicles);
            }
            else
            {
                string choice_v;
                cout<<"Enter License Plate Number: ";
                cin>>choice_v;
                search_vehicle(v,total_vehicles,choice_v);
            }   
        }
        else if (main_choice == 2)
        {
            int cm;
            cout<<"1. Add Customer Information\n2. Display All Customers Data\n3. Search a Customer's Details\n\nPress 1/2/3 : ";
            cin>>cm;
            cout<<endl;
            if (cm == 1)
            {
                add_customer(c,total_customers);
                total_customers++;
                save_customer(c, total_customers);
            }
            else if (cm == 2)
            {
                display_customer(c,total_customers);
            }
            else
            {
                string choice_c;
                cout<<"Enter Name: ";
                cin>>choice_c;
                search_customer(c,total_customers,choice_c);
            }   
        }
        else if (main_choice == 3)
        {
            int mc;
            cout<<"1. Add Mechanic Information\n2. Display All Mechanics Data\n\nPress 1/2 : ";
            cin>>mc;
            cout<<endl;
            if (mc == 1)
            {
                add_mechanic(m,total_mechanics);
                total_mechanics++;
                save_mechanic(m, total_mechanics);
            }
            else
            {
                display_mechanic(m,total_mechanics);
            }
        }
        else if (main_choice == 4)
        {
            int sp;
            cout<<"1. Add a Spare part\n2. Display All Parts in Inventory\n3. Search a Part\n\nPress 1/2/3 : ";
            cin>>sp;
            cout<<endl;
            if (sp == 1)
            {
                add_part(p,total_spareparts);
                total_spareparts++;
                save_parts(p, total_spareparts);
            }
            else if (sp == 2)
            {
                display_parts(p,total_spareparts);
            }
            else
            {
                int choice_p;
                cout<<"Enter Part's id: ";
                cin>>choice_p;
                search_part(p,total_spareparts,choice_p);
            }   
        }
        else if (main_choice == 5)
        {
            int jc;
            cout<<"1. Add a Job\n2. Display All Job Cards\n3. Search a Job\n4. Check/Update Status\n\nPress 1/2/3/4 : ";
            cin>>jc;
            cout<<endl;
            if (jc == 1)
            {
                add_job(j,total_jobcards);
                total_jobcards++;
                save_jobs(j, total_jobcards);
            }
            else if (jc == 2)
            {
                display_job(j,total_jobcards);
            }
            else if (jc == 3)
            {
                int choice_jc;
                cout<<"Enter Vehicles's id: ";
                cin>>choice_jc;
                search_job(j,total_jobcards,choice_jc);
            }
            else
            {
                update_status(j, total_jobcards);

                save_jobs(j, total_jobcards);
            }   
        }
        else if (main_choice == 6)
        {
                int choice_b;
                cout<<"Enter Vehicles's id: ";
                cin>>choice_b;
                generate_bill(j,total_jobcards,choice_b);
        }
    } while (main_choice != 0);
    return 0;
}