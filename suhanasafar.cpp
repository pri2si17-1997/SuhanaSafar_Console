#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include<conio.h>

using namespace std;
class flights;
class hotels;
class package;
class user;

template<class T>
double calc_fare(T obj, int N)
{
    return obj.fare*N;
}

class flights
{
    int f_id;
    string f_name;
    string from_;
    string to_;
    string date;
public:    double fare;
    string arr_time;
    string dep_time;
public:    int seats;
public:
    flights()
    {
        cout<<"Enter Flight Id : ";
        cin>>f_id;
        cout<<endl<<"Enter Flight Name : ";
        cin>>f_name;
        cout<<endl<<"Enter From : ";
        cin>>from_;
        cout<<endl<<"Enter To : ";
        cin>>to_;
        cout<<endl<<"Enter Date : ";
        cin>>date;
        cout<<endl<<"Enter Fare : ";
        cin>>fare;
        cout<<endl<<"Enter Arrival Time : ";
        cin>>arr_time;
        cout<<endl<<"Enter Departure Time : ";
        cin>>dep_time;
        cout<<endl<<"Enter Seats : ";
        cin>>seats;
    }

    flights(int i_d, string fname, string frm, string to, string dt, double cost, string a_t, string d_t, int st)
    {
        f_id = i_d;
        f_name = fname;
        from_ = frm;
        to_ = to;
        date = dt;
        fare = cost;
        arr_time = a_t;
        dep_time = d_t;
        seats = st;
    }

    flights(const flights &obj)
    {
        f_id = obj.f_id;
        f_name = obj.f_name;
        from_ = obj.from_;
        to_ = obj.to_;
        seats = obj.seats;
        date = obj.date;
        fare = obj.fare;
        arr_time = obj.arr_time;
        dep_time = obj.dep_time;
    }

    int get_fid()
    {
        return f_id;
    }

    double get_fare()
    {
        return fare;
    }

    int get_seats()
    {
        return seats;
    }

    string get_from()
    {
        return from_;
    }

    string get_to()
    {
        return to_;
    }

    string get_date()
    {
        return date;
    }

    void flight_display()
    {
        cout<<endl<<"Flight Id : "<<f_id<<endl<<endl;
        cout<<endl<<"Flight Name : "<<f_name<<endl<<endl;
        cout<<endl<<"From : "<<from_<<endl<<endl;
        cout<<endl<<"To : "<<to_<<endl<<endl;
        cout<<endl<<"Date : "<<date<<endl<<endl;
        cout<<endl<<"Fare : "<<fare<<endl<<endl;
        cout<<endl<<"Arrival Time : "<<arr_time<<endl<<endl;
        cout<<endl<<"Departure Time : "<<dep_time<<endl<<endl;
        cout<<endl<<"Seats Available : "<<seats<<endl<<endl;
    }

    bool check_availability(int S)
    {
        if(seats > S)
            return true;
        else
            return false;
    }

    virtual  void book_pkg_flight()
    {

    }

    void print_tkt_flight(double fare, int N, string name)
    {
        cout<<endl<<endl;
        printf("\t   *--------------------------Ticket---------------------------*");
        printf("\n");
        cout<<"Flight Name : "<<f_name<<endl;
        cout<<"Passenger Name : "<<name<<endl;
        cout<<"Date : "<<date<<endl;
        cout<<"Arrival Time : "<<arr_time<<endl;
        cout<<"Departure Time : "<<dep_time<<endl;
        cout<<"No Of Passengers : "<<N<<endl;
        cout<<"Fare : "<<fare<<endl;
    }
};

class room
{
    int room_id;
    string type;
    float rent;
public:
    room()
    {
        room_id = 0;
        type = "";
        rent = 0.0;
    }

    room(int id, string T, float R)
    {
        room_id = id;
        type = T;
        rent = R;
    }

    int get_room_id()
    {
        return room_id;
    }

    void room_display()
    {
        cout<<endl<<"Room Id : "<<room_id;
        cout<<endl<<"Type : "<<type;
        cout<<endl<<"Rent : "<<rent<<endl;
    }
};

class hotels
{
    int h_id;
    string h_name;
    long cont_no;
    int rating;
    string city;
    room *R[10];
    int ct;
public:    float fare;
    public : int r_avl;
public :
    hotels()
    {
        cout<<endl<<"Enter Hotel Id : ";
        cin>>h_id;
        cout<<endl<<"Enter Hotel Name : ";
        cin>>h_name;
        cout<<endl<<"Enter Contact Number : ";
        cin>>cont_no;
        cout<<endl<<"Enter Rating : ";
        cin>>rating;
        cout<<endl<<"Enter City : ";
        cin>>city;
        cout<<endl<<"Enter Rent : ";
        cin>>fare;
        ct = 0;
        r_avl = 5;
        R[0]=new room(1, "regular",7000);
        R[1]=new room(2, "deluxe",10000);
        R[2]=new room(3, "suite",12000);
        R[3]=new room(4, "deluxe",10000);
        R[4]=new room(5, "suite",12000);
    }

    hotels(int id, string name, long no, int R, string place, float rnt, int rm_avl)
    {
        h_id = id;
        h_name = name;
        cont_no = no;
        rating = R;
        city = place;
        fare = rnt;
        r_avl = rm_avl;
        ct = 0;
    }

    hotels(const hotels &obj)
    {
       h_id = obj.h_id;
       h_name = obj.h_name;
       cont_no = obj.cont_no;
       rating = obj.rating;
       city = obj.city;
       r_avl = obj.r_avl;
       fare = obj.fare;
       ct = obj.ct;
    }

    void hotels_display()
    {
        cout<<endl<<"Hotel Id : "<<h_id<<endl<<"Hotel Name : "<<h_name<<endl<<"Contact Number : "<<cont_no<<endl<<"Rating : "<<rating<<endl<<"City : "<<city<<endl<<"Rent : "<<fare<<endl<<"Rooms Available : "<<r_avl<<endl;
    }

    void addroom(room obj)
    {
        R[ct++] = &obj;
    }

    int check()
    {
        if(ct >= 10)
            throw 10;
        else
            return 1;
    }

    int get_room()
    {
        return r_avl;
    }

    string get_city()
    {
        return city;
    }

    void print_tkt_hotel(double fare, int N, string name)
    {
        cout<<endl<<endl;
        printf("\t   *--------------------------Ticket---------------------------*");
        printf("\n");
        cout<<"Hotel Name : "<<h_name<<endl;
        cout<<"Passenger Name : "<<name<<endl;
        cout<<"Contact No : "<<cont_no<<endl;
        cout<<"Rating : "<<rating<<endl;
        //cout<<"Departure Time : "<<dep_time<<endl;
        cout<<"No Of Rooms : "<<N<<endl;
        cout<<"Fare : "<<fare<<endl;
    }
};


class package:public flights, public hotels
{
    int pkg_id;
public:    double fare;
    string source;
    string dest;

public:
    package()
    {
        pkg_id = 0;
        fare = 0.0;
        source = "";
        dest = "";
    }

    package(int id, double cost, string src, string loc, flights O1, hotels O2):flights(O1), hotels(O2)
    {
        pkg_id = id;
        fare = cost;
        source = src;
        dest = loc;
    }

    void display_package()
    {
        cout<<endl<<"Package Id : "<<pkg_id<<endl<<"Fare : "<<fare<<endl<<"Source : "<<source<<endl<<"Destination : "<<dest<<endl;
    }

    void display_package_complete(flights O1, hotels O2)
    {
        cout<<endl<<"Package Id : "<<pkg_id<<endl<<"Fare : "<<fare<<endl<<"Source : "<<source<<endl<<"Destination : "<<dest<<endl;
        O1.flight_display();
        O2.hotels_display();
    }

    int get_id()
    {
        return pkg_id;
    }

    void print_tkt_flight(double fare, int N, string name)
    {
        cout<<endl<<endl;
        printf("\t   *--------------------------Ticket---------------------------*");
        printf("\n");
        cout<<"From : "<<source<<endl;
        cout<<"To : "<<dest<<endl;
        cout<<"Passenger Name : "<<name<<endl;
        //cout<<"Contact No : "<<cont_no<<endl;
        //cout<<"Rating : "<<rating<<endl;
        //cout<<"Departure Time : "<<dep_time<<endl;
        cout<<"No Of Passengers : "<<N<<endl;
        cout<<"Fare : "<<fare<<endl;
    }

    void book_pkg_flight()
    {
        seats=seats-1;
        cout<<seats<<endl;
    }
};

class user
{
    string u_name;
    string id;
    string pwd;
    string re_pwd;
    string email;
    string mob;
    flights *F[10];
    hotels *H[10];
    package *P[10];
    int cnt_fl;
    int cnt_hl;
    int cnt_pkg;
    char c;
    char d;
public:
    user()
    {
        cnt_fl = 0;
        cnt_hl = 0;
        cnt_pkg = 0;
        pwd = "";
        re_pwd = "";
        cout<<"Enter User Name : ";
        cin>>u_name;
        cout<<endl<<"Enter User Id : ";
        cin>>id;
        cout<<endl<<"Enter email id : ";
        cin>>email;
        cout<<endl<<"Enter Mobile Number : ";
        cin>>mob;
        cout<<endl;
        while(1)
        {
            cout<<"Enter Password : ";
            c = _getch();
            while(c != 13 && c != '\b')
            {
                pwd.push_back(c);
                cout << '*';
                c = _getch();
            }
            cout<<endl;
            cout<<endl<<"Re-enter Password : ";
            d = _getch();
            while(d != 13 && d != '\b')
            {
                re_pwd.push_back(d);
                cout << '*';
                d = _getch();
            }
            if(pwd == re_pwd)
            {
                cout<<endl<<endl<<"Successfully Registered!"<<endl;
                break;
            }
            else
            {
                cout<<endl<<endl<<"Password Not Matched!"<<endl;
                pwd = "";
                re_pwd = "";
            }
        }
    }

    user(string name, string u_id, string mail, string num, string pass, string re_pass)
    {
        cnt_pkg = 0;
        cnt_fl = 0;
        cnt_hl = 0;
        u_name = name;
        id = u_id;
        email = mail;
        mob = num;
        pwd = pass;
        re_pwd = re_pass;
        //c = "";
        //d = "";
    }

    void user_display()
    {
        cout<<"Name : "<<u_name<<endl;
        cout<<"User Id : "<<id<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"Mobile Number : "<<mob<<endl;
    }

    string get_id()
    {
        return id;
    }

    string get_pwd()
    {
        return pwd;
    }

    string get_name()
    {
        return u_name;
    }
    void book_flight(flights obj, int s)
    {
        F[cnt_fl++] = &obj;
        cout<<endl<<"Flight Suceesfully Booked!"<<endl;
        obj.seats = obj.seats - s;
        obj.flight_display();
    }

    void book_hotel(hotels obj, int r)
    {
        H[cnt_hl++] = &obj;
        cout<<endl<<"Hotel Suceesfully Booked!"<<endl;
        obj.r_avl = obj.r_avl-r;
        obj.hotels_display();
    }

    void book_package(package obj)
    {
        P[cnt_pkg++] = &obj;
        cout<<endl<<"Package Successfully Booked!"<<endl;
    }
};

int main()
{
    printf("\t*------------|WELCOME TO SUHANASAFAR|------------*");
    printf("\n");
    printf("\t\t     ------------------------");
    printf("\n");
    printf("\t-----------(Hospitality Beyond Borders!!!)-----------");
    printf("\n");
    printf("\tIt is the place where you can book your flights, find comfortable hotels to live in and best places in world to spend your holidays and enjoy it to fullest. So why wait for? Start Your SAFAR now..");
    printf("\n\n");
    printf("1. Login\t\t2. Signup");
    printf("\n\n      If you are a registered user press 1 to log in and if not then press 2 to create SAFAR account and enjoy its services.\n");
    int f_id, h_id;
    int choice;
    string from;
    string city;
    string to;
    string date;
    int seats;
    int pkg_id;
    int no_passengers;
    int ch, i, j;
    char c;
    string id;
    string password = "";
    int flag = 0;
    bool ok = false;
    bool hotel = false;
    bool pkg = false;
    int NOR;
    scanf("%d", &ch);
    //user obj;
    user reg_user[10] = {user("Priyanshu", "pri2si17", "pksinha217@gmail.com", "9958150222", "1234", "1234"), user("Chandni", "chandni_29", "chandnigarg217@gmail.com", "9958150223", "1234", "1234"), user("Rishabh", "snapdragon1", "rissach@gmail.com", "9958150224", "1234", "1234"), user("Sweta", "sweta_singh", "swetasurya@gmail.com", "9958150225", "1234", "1234"), user("Priyank", "pwarriors", "priyank.jain@gmail.com", "9958150226", "1234", "1234"), user("Archit", "archit910", "archit910@gmail.com", "9958150227", "1234", "1234"), user("Yash", "yash_chauhan28", "yashchauhan@gmail.com", "9958150228", "1234", "1234"), user("Saumya", "saumya_joshi", "saumset@gmail.com", "9958150229", "1234", "1234"), user("Vishesh", "vishesh_ahuja", "vishesh96@gmail.com", "9958150230", "1234", "1234"), user("Vardan", "vardan_magon", "vardanmagon@gmail.com", "9958150231", "1234", "1234")};
    flights reg_flight[10] = {flights(1, "Indian Airways", "Delhi", "Mumbai", "21-01-2016", 1200.00, "10:15", "10:45", 5), flights(2, "Sahara Airways", "Delhi", "Lucknow", "2-01-2016", 1200.00, "10:15", "10:45", 6), flights(3, "Etihad Airways", "Mumbai", "Lucknow", "22-02-2016", 1200.00, "10:15", "10:45", 7), flights(4, "Jet Airways", "Delhi", "Pune", "1-01-2016", 1200.00, "10:15", "10:45", 8), flights(5, "KingFisher", "Delhi", "Bangalore", "21-01-2016", 1200.00, "10:15", "10:45", 9), flights(6, "London Airways", "Britain", "America", "22-01-2016", 1200.00, "10:15", "10:45", 5), flights(7, "Special Airways", "Lucknow", "Delhi", "2-01-2016", 1200.00, "10:15", "10:45", 6), flights(8, "Etihad Airways", "Banglore", "Lucknow", "30-01-2016", 1200.00, "10:15", "10:45", 8), flights(9, "Jet Airways", "Delhi", "Mysore", "1-01-2016", 1200.00, "10:15", "10:45", 8), flights(10, "KingFisher", "Goa", "Lucknow", "26-01-2016", 1200.00, "10:15", "10:45", 9)};
    room reg_room[3]={room(1, "regular",7000),room(2, "delux",10000),room(3, "suite",13000)};
    hotels reg_hotel[10] = {hotels(1, "Taj_Lucknow", 9958150222, 5, "Lucknow", 15000.00, 15), hotels(2, "Taj_Delhi", 9958150223, 5, "Delhi", 15000.00, 15), hotels(3, "Taj_Mumbai", 9958150224, 5, "Mumbai", 15000.00, 15), hotels(4, "Taj_Kolkata", 9958150225, 5, "Kolkata", 15000.00, 15), hotels(5, "Taj_Bangalore", 9958150226, 5, "Bangalore", 15000.00, 15), hotels(6, "Berlington", 9958150227, 4, "Lucknow", 12000.00, 15), hotels(7, "Oberoi", 9958150228, 4, "Delhi", 12000.00, 15), hotels(8, "Raddision", 9958150229, 3, "Noida", 10000.00, 15), hotels(9, "Swagat", 9958150230, 3, "Kucknow", 10000.00, 15), hotels(10, "Ashoka", 9958150231, 2, "Delhi", 8000.00, 15)};
    package reg_pkg[3] = {package(1, 35000.00, "Delhi", "Bangalore", reg_flight[5], reg_hotel[5]), package(2, 52000.00, "Delhi", "Pune", reg_flight[4], reg_hotel[4]), package(3, 25000.00, "Mumbai", "Lucknow", reg_flight[3], reg_hotel[3])};
    reg_hotel[0].addroom(reg_room[2]);
    reg_hotel[1].addroom(reg_room[1]);
    reg_hotel[1].addroom(reg_room[2]);
    reg_hotel[1].addroom(reg_room[2]);
    reg_hotel[2].addroom(reg_room[1]);
    reg_hotel[2].addroom(reg_room[2]);
    reg_hotel[3].addroom(reg_room[1]);
    reg_hotel[3].addroom(reg_room[2]);
    reg_hotel[4].addroom(reg_room[2]);
    reg_hotel[4].addroom(reg_room[2]);
    reg_hotel[5].addroom(reg_room[1]);
    reg_hotel[5].addroom(reg_room[2]);

    try
    {
       reg_hotel[5].addroom(reg_room[2]);
    }
    catch(int x)
    {
        cout<<"More Rooms Cannot Be added"<<endl;
    }

    switch(ch)
    {
        case 1 : while(1)
                 {
                    printf("\n Enter Your Login Id : ");
                    cin>>id;
                    printf("\n Enter Password : ");
                    c = _getch();
                    while(c != 13 && c != '\b')
                    {
                        password.push_back(c);
                        cout << '*';
                        c = _getch();
                    }
                    for(i = 0; i<10; i++)
                    {
                        if(id == reg_user[i].get_id() && password == reg_user[i].get_pwd())
                        {
                            cout<<endl<<"Successfully Logged in..."<<endl;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 1)
                        break;
                    else
                    {
                        cout<<endl<<"Entered Details are not valid."<<endl;
                        password = "";
                    }
                 }
                 //reg_user[i].user_display();
                 cout<<endl<<endl<<"Enter Your Choice : "<<endl;
                 printf("1. Book Flight\t\t2.Book Hotel\t\t3. Book Holiday Trip\n");

                 cin>>choice;

                 switch(choice)
                 {
                    case 1 : cout<<endl<<"Enter Source : ";
                             cin>>from;
                             cout<<endl<<"Enter Destination : ";
                             cin>>to;
                             cout<<endl<<"Enter Date : ";
                             cin>>date;
                             cout<<endl<<"Enter Number Of Passengers : ";
                             cin>>seats;
                             cout<<endl;
                             for(j = 0; j<10; j++)
                             {
                                if((reg_flight[j].get_seats() >= seats) && (reg_flight[j].get_from() == from) && (reg_flight[j].get_to() == to) && (reg_flight[j].get_date() == date))
                                {
                                    ok = true;
                                    reg_flight[j].flight_display();
                                }
                             }
                             if(ok)
                             {
                                cout<<endl<<"Enter id of flight to book : ";
                                cin>>f_id;
                                reg_user[i].book_flight(reg_flight[f_id-1], seats);
                                double fare = calc_fare(reg_flight[f_id-1], seats);
                                cout<<endl<<fare;
                                reg_flight[f_id-1].print_tkt_flight(fare, seats, reg_user[i].get_name());

                             }
                             else
                                cout<<endl<<"Sorry! No flights Available..";

                             break;

                    case 2 : cout<<endl<<"Enter Place : ";
                             cin>>city;
                             cout<<endl<<"Enter No of Rooms required : ";
                             cin>>NOR;
                             for(j = 0; j<10; j++)
                             {
                                 if((reg_hotel[j].get_room() >= NOR) && (reg_hotel[j].get_city() == city))
                                 {
                                     hotel = true;
                                     reg_hotel[j].hotels_display();
                                 }
                             }

                             if(hotel)
                             {
                                cout<<endl<<"Enter id of hotel to book : ";
                                cin>>h_id;
                                reg_user[i].book_hotel(reg_hotel[h_id-1], NOR);
                                double fare = calc_fare(reg_hotel[h_id-1], NOR);
                                cout<<endl<<fare;
                                reg_hotel[h_id-1].print_tkt_hotel(fare, seats, reg_user[i].get_name());
                             }
                             else
                                cout<<endl<<"Sorry! No result found!";

                             break;

                    case 3 : cout<<endl<<"Select From Our Package Catalogue : "<<endl;
                             for(j = 0; j<3; j++)
                             {
                                 reg_pkg[j].display_package();
                             }
                             while(1)
                             {
                                 cout<<endl<<"Enter Package Id to book your package : ";
                                 cin>>pkg_id;
                                 cout<<endl<<"Enter Number Of Passengers : ";
                                 cin>>no_passengers;
                                 for(j = 0; j<3; j++)
                                 {
                                    if(reg_pkg[j].get_id() == pkg_id)
                                    {
                                        pkg = true;
                                    }
                                 }
                                 if(!pkg)
                                 {
                                    cout<<endl<<"Enter Valid Package id!"<<endl;
                                 }
                                 break;
                             }
                             reg_user[i].book_package(reg_pkg[pkg_id-1]);
                             double fare = calc_fare(reg_pkg[pkg_id-1], no_passengers);
                             cout<<endl<<fare;
                             reg_pkg[pkg_id-1].print_tkt_flight(fare, no_passengers, reg_user[i].get_name());
                             break;
                }
                break;

        case 2 : cout<<endl<<endl<<"Enter Your Details : "<<endl;
                 cout<<"--------------------";
                 cout<<endl<<endl;
                 user obj;
                 cout<<endl<<endl<<"Enter Your Choice : "<<endl;
                 printf("1. Book Flight\t\t2.Book Hotel\t\t3. Book Holiday Trip\n");

                 cin>>choice;

                 switch(choice)
                 {
                    case 1 : cout<<endl<<"Enter Source : ";
                             cin>>from;
                             cout<<endl<<"Enter Destination : ";
                             cin>>to;
                             cout<<endl<<"Enter Date : ";
                             cin>>date;
                             cout<<endl<<"Enter Number Of Passengers : ";
                             cin>>seats;
                             cout<<endl;
                             for(j = 0; j<10; j++)
                             {
                                if((reg_flight[j].get_seats() >= seats) && (reg_flight[j].get_from() == from) && (reg_flight[j].get_to() == to) && (reg_flight[j].get_date() == date))
                                {
                                    ok = true;
                                    reg_flight[j].flight_display();
                                }
                            }
                            if(ok)
                            {
                                cout<<endl<<"Enter id of flight to book : ";
                                cin>>f_id;
                                obj.book_flight(reg_flight[f_id-1], seats);
                                double fare = calc_fare(reg_flight[f_id-1], seats);
                                cout<<endl<<fare;
                                reg_flight[f_id-1].print_tkt_flight(fare, seats, obj.get_name());
                            }
                            else
                                cout<<endl<<"Sorry! No flights Available..";

                            break;

                    case 2 : cout<<endl<<"Enter Place : ";
                             cin>>city;
                             cout<<endl<<"Enter No of Rooms required : ";
                             cin>>NOR;
                             for(j = 0; j<10; j++)
                             {
                                 if((reg_hotel[j].get_room() >= NOR) && (reg_hotel[j].get_city() == city))
                                 {
                                     hotel = true;
                                     reg_hotel[j].hotels_display();
                                 }
                             }

                             if(hotel)
                             {
                                cout<<endl<<"Enter id of hotel to book : ";
                                cin>>h_id;
                                obj.book_hotel(reg_hotel[h_id-1], NOR);
                                double fare = calc_fare(reg_hotel[h_id-1], NOR);
                                cout<<endl<<fare;
                                reg_hotel[h_id-1].print_tkt_hotel(fare, seats, obj.get_name());
                             }
                             else
                                cout<<endl<<"Sorry! No result found!";

                             break;

                    case 3 : cout<<endl<<"Select From Our Package Catalogue : "<<endl;
                             for(j = 0; j<3; j++)
                             {
                                 reg_pkg[j].display_package();
                             }
                             while(1)
                             {
                                 cout<<endl<<"Enter Package Id to book your package : ";
                                 cin>>pkg_id;
                                 cout<<endl<<"Enter Number Of Passengers : ";
                                 cin>>no_passengers;
                                 for(j = 0; j<3; j++)
                                 {
                                    if(reg_pkg[j].get_id() == pkg_id)
                                    {
                                        pkg = true;
                                    }
                                 }
                                 if(!pkg)
                                 {
                                    cout<<endl<<"Enter Valid Package id!"<<endl;
                                 }
                                 break;
                             }
                             obj.book_package(reg_pkg[pkg_id-1]);
                             double fare = calc_fare(reg_pkg[pkg_id-1], no_passengers);
                             cout<<endl<<fare;
                             reg_pkg[pkg_id-1].print_tkt_flight(fare, no_passengers, reg_user[i].get_name());
                             break;
                }
                 break;

    }
    printf("\n");
    printf("*-----------------------------------------------------------------------*");
    printf("\n");
    printf("\t\t*--------------Made By-------------------*\n");
    printf("1. Priyanshu Sinha(14103030)\n2. Chandni Garg(14103003)\n3. Sweta Singh(14103021)\n4. Rishabh Scahdeva(14103032)");
    printf("\n\tTHANK'S FOR USING SUHANA SAFAR");
    return 0;
}
