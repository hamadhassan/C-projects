#include <cmath>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <windows.h>
//Add some changing 
using namespace std;
//______________________Data Structure for User Registration__________________
const int maxRecord = 20;
string username[maxRecord];
string firstname[maxRecord];
string lastname[maxRecord];
string email[maxRecord];
long long CNIC[maxRecord];
string password[maxRecord];
string contact[maxRecord];
int usercount = 0;
// Data Structure for Remaining Approval user accounts
string approved_N[maxRecord];

//______________Data Structure for Adding T__________
string productName[maxRecord];
string productNo[maxRecord];
string product_time[maxRecord];
char dayNight[maxRecord];
int product_ind[maxRecord];
int product_house[maxRecord];
int industrial_price[maxRecord];
int household_price[maxRecord];
// Variable for PRODUCT Count
int count_product = 0;
//______DATA STRUCTURES FOR TICKET RESERVATION
int date[maxRecord];
string month[maxRecord];
string pnaam[maxRecord];
int no_industrial[maxRecord];
int no_household[maxRecord];
string products[maxRecord] = {"prod1",  "prod2",  "prod3",  "prod4",  "prod5",
                             "prod6",  "prod7",  "prod8",  "prod9",  "prod10",
                             "prod11", "prod12", "prod13", "prod14", "prod15",
                             "prod16", "prod17", "prod18", "prod19", "prod20"};
string buy_product[maxRecord];
string UserN[maxRecord];
int store = 0;

//_______________DATA STRUCTURES FOR Complain or Suggestion
int suggest_counter = 0;
string suggest[maxRecord];
string complainer[maxRecord];
//_______________DATA STRUCTURES FOR ADMIN REGISTRATION___________________
string admin_name[5];
string admin_pass[5];
string admin_email[5];
int admin_count = 0;
//_______________DATA STRUCTURES FOR ADMIN REGISTER ____________
string admin;
string pass;

int str_to_i(string num);       // Function to Convert string to integer
long long str_to_l(string num); // Function to convert string to long long
void header();                  // Function for a HEADER
void admin_details(string name, string pass,
                   string mail); // Function to store admin Details
void admin_register();           // Function to register admin
bool valid_admin(string name, string password); // Function for admin validation
void admin_login();                             // Function for admin login
void admin_menu();                              // Function for ADMIN MENU
void user_menu();                               // Function for USER MENU
char identity_mode();                           // Function for IDENTITY MODE
void admin_mode();                              // Function for admin mode
void user_mode();                               // Function for user mode
void user_register(string user_name, string first_name, string last_name,
                   string e_mail, long long C_NIC, string pass_word,
                   string con_tact); // Function for a User Register arrays
void user_reg();                     // Function to Register User
void gotoxy(int x, int y) ;
void loading();

//						             				________
//ADMIN MENU   _________
// OPTION 01
void product_details(); // FUNCTION TO ADD PRODUCT DETAIL in ARRAYS
void add_product();

// OPTION 02
int index_returner(string Tname); // Function returning index of PRODUCT to delete
void delete_product(int idx);        // FUNCTION FOR DELETING PRODUCT

// OPTION 03
void view_products(); // FUNCTION TO VIEW PRODUCT DETAILS

// OPTION 04
void modify_product(int idx); // FUNCTION FOR MODIFICATION

// OPTION 05
void buyer_detail(); // FUNCTION View Passenger Details

// OPTION 06
//________DATA STRUCTURES FOR FAQS__________
string questions[10];
string answers[10];
int faq_counter = 0;
void faqs();     // Function to view FAQs
void add_faqs(); // Function to edit FAQS

// OPTION 07
void take_suggest(); // Function for Giving Suggestion or Complain
void suggestion();   // Function to view suggestions

// OPTION 08
void approve_details(); // Function to Approve User Details
int app = 0;            //_to count remaining users for approval

//									 				______________USER
//MODE____________
// OPTION 02
bool valid_user(string name, string pass_word); // Function for user validation
string Uname;
void user_login(); // Function for user login

//											______________________USER
//MENU__________________________
// OPTION 01
void sort_household();  // FUNCTION TO VIEW SORTED SCLASS FARE
void sort_industrial(); // FUNCTION TO VIEW SORTED FCLASS FARE

// OPTION 02
void available_products(char scene); // FUNCTION TO SEE AVAILABLE PRODUCTS

// OPTION 03
void store_in_arrays(); // Store in Arrays
void reserve_product(); // FUNCTION FOR RESERVING A TICKET

// OPTION 04
int index_return(); // Function to return index for user detail who reserve
int payable;
void storage_details(int idx); // Function for see Reservation details

// OPTION 05
void modify_order(); // FUNCTION TO MODIFY RESERVATION

// OPTION 06
void cancel_reservation(); // FUNCTION TO CANCEL RESERVATION

// OPTION 08
void payment(); // FUNCTION FOR PAYMENT

void clearscreen();                        // FUNCTION FOR CLEAR SCREEN
void store_data();                         // FUNCTION TO STORE DATA IN FILE
string parse_data(string word, int field); // FUNCTION FOR PARSING DATA
void load_data();                          // FUNCTION TO LOAD DATA FROM FILE
bool password_validation(string pass);     // Function for Password VALIDATION
bool username_validation(string name);     // Function for Username VALIDATION
bool email_validation(string email);       // Function for Email VALIDATION

//									_______________________________________MAIN
//FUNCTION__________________________________

main() { // start of main
  load_data();
  // Variable for selecting option in user mode
  int word;

  // Variable for selecting user menu
  int number;

  // variable for selecting option within admin mode
  int op;

  while (true) { // start of WHILE LOOP for identity mode
   loading();
    header();
    // Variable for selecting option for identity mode
    char n = identity_mode();

    if (n == 1) // option 1 for identity mode
    {

      while (true) { // Start of WHILE loop for admin mode

        header();
        admin_mode();
        cin >> op;
        if (op == 1) // option 1 for admin mode
        {
          admin_register();
          clearscreen();
        }
        if (op == 2) // option 2 for admin mode
        {
          header();
          admin_login();

          while (true) { // start of WHILE LOOP for admin menu
            store_data();
            header();
            cout << "IDENTIFICATION MODE > Admin Mode > ADMIN" << endl;
            admin_menu();

            // Variable for selecting option in admin menu
            int num;
            cin >> num;
            if (num == 1) // option 1 for admin menu
            {
              system("cls");
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > ADMIN > Add Product"
                   << endl;
              cout << "_____________" << endl << endl;
              add_product();
              clearscreen();
            }

            if (num == 2) // option 2 for admin menu
            {
              header();
              cout
                  << "IDENTIFICATION MODE > Admin Mode > ADMIN > Delete Product"
                  << endl;
              cout << "_____________" << endl << endl;
              view_products();
              // Variable for deleting a PRODUCT

              string dlt;
              cout << "Enter Product Name You Want To Remove:..\nif you've "
                      "changed your mind Press N.";
              cin >> dlt;
              int del_index = index_returner(dlt);
              delete_product(del_index);

              cout << "You Have Successfully deleted " << dlt << endl;
              clearscreen();
            }

            if (num == 3) // option 3 for admin menu
            {
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > ADMIN > View Products"
                   << endl;
              cout << "_____________" << endl << endl;
              view_products();
              clearscreen();
            }

            if (num == 4) // option 4 for admin menu
            {
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > ADMIN > Modfiy "
                      "Product Details"
                   << endl;
              cout << "_____________" << endl;
              view_products();
              // Variable for Entering PRODUCT Name to Modify
              string modify;
              cout << "Enter Product Name to MODIFY: ";
              cin >> modify;
              int mod_ind = index_returner(modify);
              modify_product(mod_ind);
              clearscreen();
            }

            if (num == 5) // option 5 for admin menu
            {
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > ADMIN > View user "
                      "Details"
                   << endl;
              cout << "_____________" << endl;
              buyer_detail();
              clearscreen();
            }

            if (num == 6) // option 6 for admin menu
            {
              system("cls");
              header();
              faqs();
              cout
                  << "If you want to Add More FAQs Press Y or if not Press N: ";
              char Y;
              cin >> Y;
              if (Y == 'Y') {
                add_faqs();
                clearscreen();
              } else {
                clearscreen();
              }
            }

            if (num == 7) { // option 7 for admin menu
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > ADMIN > Respond To "
                      "Issues"
                   << endl;
              cout << "_____________" << endl;
              suggestion();
              clearscreen();
            }

            if (num == 8) { // option 8 for admin menu
              header();
              cout << "IDENTIFICATION MODE > Admin Mode > User Accounts"
                   << endl;
              cout << "_____________" << endl;
              cout << "User IDs" << endl;
              approve_details();
              clearscreen();
            }

            if (num == 9) // option 9 for admin menu
            {
              loading();
              break;
            }
          }
        } else if (op == 3) // option 3 for admin mode
        {
          loading();

          break;
        }

      } // end of while loop for admin mode
    }

    if (n == 2) // option 2 for identity mode
    {

      while (true) { // start of while loop for user mode
        store_data();
        header();
        user_mode();
        cin >> word;

        if (word == 1) // option 1 for user mode
        {
          header();
          cout << "IDENTIFICATION MODE > User Mode > Register" << endl;
          cout << "_____________" << endl << endl;
          user_reg();
          clearscreen();
        }

        if (word == 2) // option 2 for user mode
        {
          system("cls");
          header();
          cout << "IDENTIFICATION MODE > User Mode > Login" << endl;
          cout << "_____________" << endl;
          user_login();

          while (true) { // start of while loop for user menu
            store_data();
            header();
            cout << "IDENTIFICATION MODE > User Mode > " << Uname << endl;
            user_menu();
            // Variable for selecting option in User Menu
            cin >> number;

            if (number == 1) // option 1 for user menu
            {
              system("cls");
              header();
              cout << "IDENTIFICATION MODE > User Mode >" << Uname
                   << " View products " << endl;
              cout << "_____________" << endl << endl;
              view_products();
              cout << "\n\n";
              cout << "To see Industrial products price in order Press any "
                      "key: ";
              getch();
              cout << endl;
              sort_industrial();

              cout << "\n\n";
              cout
                  << "To see Household products price in order Press any key: ";
              getch();
              cout << endl;
              sort_household();
              clearscreen();
            }
            if (number == 2) // option 2 for user menu
            {
              header();
              cout << "IDENTIFICATION MODE > User Mode >" << Uname
                   << " See Available Products " << endl;
              cout << "_____________" << endl << endl;
              cout
                  << "Daily used product enter 'd' otherwise enter 'n' (d/n): ";
              char waqt;
              cin >> waqt;
              available_products(waqt);
              clearscreen();
            }

            if (number == 3) // option 3 for user menu
            {
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > Buy product" << endl;
              cout << "_____________" << endl << endl;
              reserve_product();
              clearscreen();
            }

            if (number == 4) // option 4 for user menu
            {
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > See Reservation Details" << endl;
              cout << "_____________" << endl;
              int index = index_return();
              storage_details(index);
              clearscreen();
            }

            if (number == 5) // option 5 for user menu
            {
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > Modify Order" << endl;
              cout << "_____________" << endl << endl;
              cout << "PREVIOUS RESERVATION" << endl;
              int index = index_return();
              storage_details(index);
              cout << endl;
              modify_order();
              clearscreen();
            }

            if (number == 6) // option 6 for user menu
            {
              system("cls");
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > Cancel Order" << endl;
              cout << "_____________" << endl << endl;
              int index = index_return();
              storage_details(index);
              cout << "If you want to cancel Press Y if not press N: ";
              // Variable for making decision whether cancel reservation or not
              char YN;
              cin >> YN;

              if (YN == 'Y' || YN == 'y') {
                cancel_reservation();
                clearscreen();
              } else if (YN == 'N' || YN == 'n') {
                clearscreen();
              }
            }

            if (number == 7) // option 7 for user menu
            {
              system("cls");
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > Suggestions/Complains" << endl;
              take_suggest();
              clearscreen();
            }

            if (number == 8) // option 8 for user menu
            {
              system("cls");
              header();
              cout << "IDENTIFICATION MODE > User Mode > " << Uname
                   << " > Payment Method" << endl;
              int indx = index_return();
              storage_details(indx);
              payment();
              clearscreen();
            }

            if (number == 9) // option 9 for user menu
            {
              break;
            }

            if (number == 10) // option 10 for user menu
            {
              system("cls");
              header();
              faqs();
              clearscreen();
            }

          } // end of WHILE LOOP for user menu
        }
        if (word == 3) // option 3 for user mode
        {
          break;
        }
      } // end of WHILE LOOP for user mode
    }
    if (n == 3) // option 3 for identity mode
    {
      break;
    }
  } // end of WHILE loop for identity mode
} // end of main

//_______________Function to Convert string to integer

int str_to_i(string num) {
  int sum = 0;
  int count = 0;
  int y;
  for (int i = 0; num[i] != '\0'; i++) {
    count++;
  }
  int check = count;

  for (int i = 0; i < count; i++) {
    y = num[i];
    y = y - 48;
    sum = sum + y * pow(10, check - 1);
    check--;
  }
  return sum;
}

//_______________Function to convert string to long long

long long str_to_l(string num) {
  int sum = 0;
  int count = 0;
  int y;
  for (int i = 0; num[i] != '\0'; i++) {
    count++;
  }
  int check = count;

  for (int i = 0; i < count; i++) {
    y = num[i];
    y = y - 48;
    sum = sum + y * pow(10, check - 1);
    check--;
  }
  return sum;
}

//_______________Function for a HEADER
void header() {

  system("cls");
  const int size = 35;

  cout << "                                          dP                        "
          "                                                                    "
          "                                         dP   "
       << endl;
  Sleep(size);
  cout << "                                          88                        "
          "                                                                    "
          "                                         88   "
       << endl;
  Sleep(size);
  cout << "    dP  dP  dP .d8888b. 88d888b. .d8888b. 88d888b. .d8888b. dP    "
          "dP .d8888b. .d8888b.    88d8b.d8b. .d8888b. 88d888b. .d8888b. "
          ".d8888b. .d8888b. 88d8b.d8b. .d8888b. 88d888b. d8888P "
       << endl;
  Sleep(size);
  cout << "    88  88  88 88'  `88 88'  `88 88ooood8 88'  `88 88'  `88 88    "
          "88 Y8ooooo. 88ooood8    88'`88'`88 88'  `88 88'  `88 88'  `88 88'  "
          "`88 88ooood8 88'`88'`88 88ooood8 88'  `88   88   "
       << endl;
  Sleep(size);
  cout << "    88.88b.88' 88.  .88 88       88.  ... 88    88 88.  .88 88.  "
          ".88       88 88.  ...    88  88  88 88.  .88 88    88 88.  .88 88.  "
          ".88 88.  ... 88  88  88 88.  ... 88    88   88   "
       << endl;
  Sleep(size);
  cout << "    8888P Y8P  `88888P8 dP       `88888P' dP    dP `88888P' "
          "`88888P' `88888P' `88888P'    dP  dP  dP `88888P8 dP    dP `88888P8 "
          "`8888P88 `88888P' dP  dP  dP `88888P' dP    dP   dP   "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "                                                                 "
          ".88                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "                                                             d8888P "
          "                                              "
       << endl;
  Sleep(size);

  cout << "                                                                    "
          "                               dP                                   "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "                               88                                   "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "  .d8888b. dP    dP .d8888b. d8888P .d8888b. 88d8b.d8b.             "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "  Y8ooooo. 88    88 Y8ooooo.   88   88ooood8 88'`88'`88             "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "        88 88.  .88       88   88   88.  ... 88  88  88             "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "  `88888P' `8888P88 `88888P'   dP   `88888P' dP  dP  dP             "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "                .88                                                 "
          "                                              "
       << endl;
  Sleep(size);
  cout << "                                                                    "
          "            d8888P                                                  "
          "                                              "
       << endl;
  Sleep(size);
  cout << "____________________________________________________________________"
          "____________________________________________________________________"
          "_____________________________________________________"
       << endl;
}
//____________________GOTOXY___________________
void gotoxy(int x, int y) {
  COORD coordinates; // coordinates is declared as COORD
  coordinates.X = x; // defining x-axis
  coordinates.Y = y; // defining  y-axis
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//____________________LOADING__________________
void loading() {
  system("cls");
  char ch = 219;
  gotoxy(63, 22);
  cout << "LOADING";
  for (int i = 0; i < 25; i++) {
    gotoxy(71 + i, 22);
    cout << ch;
    if (i > 12) {
      gotoxy(71 + i, 22);
      cout << ch;
      Sleep(20);
    }
    Sleep(35);
  }
}
//____________________Function to store admin Details_____________________
void admin_details(string name, string pass, string mail) {
  admin_name[admin_count] = name;
  admin_pass[admin_count] = pass;
  admin_email[admin_count] = mail;
  admin_count++;
}

//__________________FUNCTION to register admin
void admin_register() {
  system("cls");
  header();
  cout << "\tADMIN REGISTRATION" << endl;
  cout << "Enter Name: ";
  cin >> admin;
  while (!username_validation(admin)) {
    cout << "Must Contain Numbers: ";
    cin >> admin;
  }
  cout << "Enter Password: ";
  cin >> pass;
  while (!password_validation(pass)) {
    cout << "Password at least 8 characters containing number: ";
    cin >> pass;
  }
  cout << "Enter E-mail:  ";
  string email;
  cin >> email;
  while (!email_validation(email)) {
    cout << "Email Should Contain @ character: ";
    cin >> email;
  }
  admin_details(admin, pass, email);
}

//__________________Function for admin validation_______________________

bool valid_admin(string name, string password) {
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    if (name == admin_name[i] && password == admin_pass[i]) {
      flag = true;
    }
  }
  if (flag == true) {
    return true;
  } else if (flag == false) {
    return false;
  }
  return 0;
}

//__________________Function for admin login______________________
void admin_login() {
  string name;
  string password;
  cout << "IDENTIFICATION MODE > ADMIN MODE > LOGIN" << endl;
  cout << "_____________" << endl;
  cout << "       ENTER USERNAME: ";
  cin >> name;
  cout << "       ENTER PASSWORD: ";
  cin >> password;

  while (!(valid_admin(name, password))) {
    header();
    cout << "IDENTITY MODE > ADMIN MODE > LOGIN" << endl;
    cout << "_____________" << endl;
    cout << "Wrong Credentials TYPE AGAIN" << endl;
    cout << "       ENTER USERNAME: ";
    cin >> name;
    cout << "       ENTER PASSWORD: ";
    cin >> password;
  }
}

//__________________________Function for ADMIN MENU________________________
void admin_menu() {
  cout << "_____________" << endl;
  cout << "Choose One of the Following Options " << endl;
  cout << "   1.  Add Products " << endl;
  cout << "   2.  Delete Products" << endl;
  cout << "   3.  View Products Details " << endl;
  cout << "   4.  Modify Product" << endl;
  cout << "   5.  View Buyer Details " << endl;
  cout << "   6.  Edit FAQS for buyers" << endl;
  cout << "   7.  Respond To Problems " << endl;
  cout << "   8.  Manage User Accounts" << endl;
  cout << "   9.  Logout" << endl;
  cout << "YOUR OPTION:.." << endl;
}

//__________________________Function for USER MENU__________________________
void user_menu() {
  cout << "Choose one of the following options" << endl;
  cout << "	1.	View Product Details" << endl;
  cout << "	2.	See Available Products" << endl;
  cout << "	3.	Modify the Order" << endl;
  cout << "	4.	See Storage Details" << endl;
  cout << "	5.	Modify product Details" << endl;
  cout << "	6.	Cancel Order" << endl;
  cout << "	7.	Suggestions/Complains" << endl;
  cout << "	8.	Checkout" << endl;
  cout << "	9.	Logout" << endl;
  cout << "	10.	FAQS" << endl;
  cout << "YOUR OPTION:..";
}


    //__________________________Function for IDENTITY
    //MODE_______________________
    char
    identity_mode() {
  cout << "IDENTIFICATION MODE" << endl;
  cout << "___________________" << endl;
  cout << "Choose One of the Following Option Number " << endl;
  cout << "   1.  Admin Mode" << endl;
  cout << "   2.  User Mode" << endl;
  cout << "Your Option:.. " << endl;
  int n;
  cin >> n;
  return n;
}

//_________________________Function for admin mode___________________________
void admin_mode() {
  cout << "IDENTITY MODE > ADMIN MODE " << endl;
  cout << "_____________" << endl;
  cout << "Choose One of the Following Option Number " << endl;
  cout << "   1.  Register " << endl;
  cout << "   2.  Login" << endl;
  cout << "   3.  Return" << endl;
  cout << "CHOOSE OPTION:  " << endl;
}

//_________________________function for user mode____________________________
void user_mode() {
  cout << "IDENTITY MODE > ADMIN MODE " << endl;
  cout << "_____________" << endl;
  cout << "Choose One of the Following Option Number " << endl;
  cout << "	1.	Register" << endl;
  cout << "	2.	Login" << endl;
  cout << "	3.	Return" << endl;
  cout << "YOUR OPTION:..";
}

//________________________Function for a User Register
//arrays________________________
void user_register(string user_name, string first_name, string last_name,
                   string e_mail, long long C_NIC, string pass_word,
                   string con_tact) {
  username[usercount] = user_name;
  firstname[usercount] = first_name;
  lastname[usercount] = last_name;
  email[usercount] = e_mail;
  CNIC[usercount] = C_NIC;
  password[usercount] = pass_word;
  contact[usercount] = con_tact;
  approved_N[app] = user_name;
  usercount++;
  app++;
}

//___________________Function to Register User_______________
void user_reg() {
  cout << "USERNAME: ";
  string username;
  cin >> username;
  while (!username_validation(username)) {
    cout << "Must Contain Numbers: ";
    cin >> username;
  }
  cout << "FIRST NAME: ";
  string firstname;
  cin >> firstname;
  cout << "LAST NAME: ";
  string lastname;
  cin >> lastname;
  cout << "E-MAIL: ";
  string email;
  cin >> email;
  while (!email_validation(email)) {
    cout << "Email Should Contain @ character: ";
    cin >> email;
  }
  cout << "ENTER CNIC (no dashes): ";
  long long NIC;
  cin >> NIC;
  while (true) {
    int counter = 0;
    for (long long i = NIC; i != 0; i = i / 10) {
      counter++;
    }
    if (counter == 13) {
      break;
    } else {
      cout << "Invalid CNIC" << endl;
      cout << "ENTERr CNIC: ";
      cin >> NIC;
    }
  }
  cout << "Password: ";
  string pass;
  cin >> pass;
  while (!password_validation(pass)) {
    cout << "Password at least 8 char containing numbers: ";
    cin >> pass;
  }
  cout << "Age: ";
  int age;
  cin >> age;
  while (age <= 0) {
    cout << "Invalid Age" << endl;
    cout << "Age: ";
    cin >> age;
  }

  cout << "Gender: ";
  string gender;
  cin >> gender;
  cout << "City: ";
  string city;
  cin >> city;
  cout << "Contact: ";
  string contact;
  cin >> contact;
  user_register(username, firstname, lastname, email, NIC, pass, contact);
}

// ---------- ADMIN MENU----------

// OPTION 01

//________________FUNCTION TO ADD PRODUCT DETAIL in ARRAYS___________________

void product_details(string pnum, string pname, string rtime, char scene,
                     int Fproducts, int Sproducts, int Ffare, int Sfare) {
  productNo[count_product] = pnum;
  productName[count_product] = pname;
  product_time[count_product] = rtime;
  dayNight[count_product] = scene;
  product_ind[count_product] = Fproducts;
  product_house[count_product] = Sproducts;
  industrial_price[count_product] = Ffare;
  household_price[count_product] = Sfare;
  count_product++;
}
//_______________FUNCTION TO ADD PRODUCT__________________

void add_product() {
  cout << "Product No.: ";
  string pnum;
  cin >> pnum;
  cout << "Product Name: ";
  string pname;
  cin >> pname;
  cout << "Recieving Time: ";
  string rtime;
  cin >> rtime;
  cout << "Daily used product 'd' otherwise 'n' (d/n): ";
  char scene;
  cin >> scene;
  cout << "No. of Industrial Products: ";
  int Fproducts;
  cin >> Fproducts;
  cout << "Industrial product price: ";
  int Ffare;
  cin >> Ffare;
  cout << "No. of Household Products: ";
  int Sproducts;
  cin >> Sproducts;
  cout << "Household Product price: ";
  int Sfare;
  cin >> Sfare;
  product_details( pnum, pname, rtime, scene, Fproducts, Sproducts, Ffare, Sfare);
}

// OPTION 02

//___________________FUNCTION FOR DELETING PRODUCT__________________
int index_returner(string Tname) {

  for (int i = 0; i < count_product; i++) {
    if (productName[i] == Tname) {
      return i;
    }
  }
  return 0;
}

void delete_product(int idx) {
  for (int i = idx; i < count_product - 1; i++) {
    productName[i] = productName[i + 1];
    productNo[i] = productNo[i + 1];
    product_time[i] = product_time[i + 1];
    dayNight[i] = dayNight[i + 1];
    product_ind[i] = product_ind[i + 1];
    product_house[i] = product_house[i + 1];
    industrial_price[i] = industrial_price[i + 1];
    household_price[i] = household_price[i + 1];
  }
  count_product--;
}

// OPTION 03
//___________________FUNCTION TO VIEW PRODUCT DETAILS________________
void view_products() {
  if (count_product == 0) {
    cout << "No Product To Show";
  } else {
    cout << "|Product No."
         << "|Product Name"
         << "\t"
         << "|Storing Time"
         << "\t"
         << "|Industrial Prod."
         << "\t"
         << "|Household prod." << endl
         << endl;
    for (int i = 0; i < count_product; i++) {
      cout << "|" << productNo[i] << "\t\t"
           << "|" << productName[i] << "\t\t"
           << "|" << product_time[i] << "\t\t"
           << "|" << industrial_price[i] << "\t\t"
           << "|" << household_price[i] << endl;
    }
  }
}

// OPTION 04
//_______________FUNCTION FOR MODIFICATION__________________________
void modify_product(int idx) {
  cout << "Product No.: ";
  cin >> productNo[idx];
  cout << "Product Name: ";
  cin >> productName[idx];
  cout << "Recieving Time: ";
  cin >> product_time[idx];
  cout << "Day or Night Time (d/n): ";
  cin >> dayNight[idx];
  cout << "No. of industrial products: ";
  cin >> product_ind[idx];
  cout << "Price of industrial product: ";
  cin >> product_house[idx];
  cout << "No. of household or other products: ";
  cin >> industrial_price[idx];
  cout << "Price of household product: ";
  cin >> household_price[idx];
}

// OPTION 05
//_______________FUNCTION View Passeenger Details___________________

void buyer_detail() {
  if (store == 0) {
    cout << "No User found . Therefore, No User Details";
  } else if (store != 0) {
    cout << "|UserName\t\t|Name\t\t\t|NIC\t\t|Contact\t\t|PRODUCT Name\t\t|No. "
            "of products(F/S)\t\t|Ticket Number"
         << endl;
    for (int i = 0; i < store; i++) {
      for (int j = 0; j < usercount; j++) {
        if (UserN[i] == username[j]) {
          cout << "|" << username[j] << "\t\t"
               << "|" << firstname[j] << " " << lastname[j] << "\t\t"
               << "|" << CNIC[j] << "\t\t"
               << "|" << contact[j] << "\t\t"
               << "|" << pnaam[j] << "\t\t"
               << "|" << no_industrial[i] << "/" << no_household[i] << "\t\t"
               << "|" << buy_product[i] << endl;
        }
      }
    }
  }
}

// OPTION 06
//________________Function to edit FAQS____________
void faqs() {
  fstream file;
  string faq;
  file.open("faqs.txt", ios::in);
  while (!file.eof()) {
    getline(file, faq);
    questions[faq_counter] = faq;
    getline(file, faq);
    answers[faq_counter] = faq;
    faq_counter++;
  }
  file.close();
  cout << "---------------  FAQS  --------------" << endl << endl;
  if (faq_counter == 0)
    cout << "There is no FAQs yet";
  if (faq_counter != 0) {
    for (int i = 0; i < faq_counter; i++) {

      cout << questions[i];
      cout << endl;
      cout << endl;
      cout << answers[i];
      cout << endl;
    }
  }
}

void add_faqs() {
  bool flag = 1;
  while (flag) {
    cout << "Add Questions: \n use underscore:\n";
    cin >> questions[faq_counter];
    cout << "Add Answer: \n";
    cin >> answers[faq_counter];
    faq_counter++;
    cout << "Want to add more Press 1 if not 0: ";
    cin >> flag;
  }
}

// OPTION 07
//________________Respong to Issues___________

void take_suggest() {

  cout << "Enter Your Name Here: ";
  cin >> complainer[suggest_counter];
  cout << endl;
  cout << "Enter your suggestion here:" << endl;
  cout << "Use Underscore_ instead of spaces" << endl;
  cin >> suggest[suggest_counter];
  cout << "Thanks for your cooperation" << endl;
  suggest_counter++;
}

void suggestion() {
  if (suggest_counter == 0) {
    cout << "There is no Complains or Suggestions yet";
  } else {
    for (int i = 0; i < suggest_counter; i++) {
      cout << complainer[i] << endl;
      cout << suggest[i] << endl;
    }
  }
}

// OPTION 08
//_______________Function to Approve User Details________

void approve_details() {
  if (app == 0 || approved_N[0] == " ") {
    cout << "There is no user to SHOW" << endl;
    ;
  } else {
    bool dec = 1;
    while (dec) {
      header();
      cout << "IDENTITY MODE > ADMIN MODE > USER ACCOUNT" << endl;
      cout << "_____________" << endl;
      cout << "User IDs" << endl;
      cout << "|USERNAME\t\t\t|E-MAIL\t\t\t\t|PASSWORD" << endl;
      for (int i = 0; i < app; i++) {
        for (int j = 0; j < usercount; j++) {
          if (approved_N[i] == username[j]) {

            cout << "|" << username[j] << "\t\t\t"
                 << "|" << email[j] << "\t\t\t"
                 << "|" << password[j] << endl;
          }
        }
      }

      cout << "Enter USERNAME to approve or Type all to approve all: ";
      string usernaam;
      cin >> usernaam;
      if (usernaam == "all") {
        app = 0;
      } else {
        if (app == 1) {
          approved_N[0] = " ";
          app--;
        } else {
          for (int k = 0; k < app; k++) {
            if (usernaam == approved_N[k]) {
              for (int i = k; i < usercount - 1; i++) {
                approved_N[i] = approved_N[i + 1];
              }
              app--;
              break;
            }
          }
          if (app != 0) {
            cout << "Want to approve more press 1 if not press 0: ";
            cin >> dec;
          } else {
            dec = 0;
          }
        }
      }
    }
  }
}

//__________________________________________________________USER
//MODE__________________________________________________

// OPTION 02

//__________________Function for user validation_______________________
bool valid_user(string name, string pass_word) {
  bool flag = false;
  for (int i = 0; i < usercount; i++) {
    if (name == username[i] && pass_word == password[i]) {
      flag = true;
    }
  }
  if (flag == true) {
    return true;
  } else if (flag == false) {
    return false;
  }
  return 0;
}

//_____________________function for user login_______________
void user_login() {

  string password;
  cout << "       ENTER USERNAME: ";
  cin >> Uname;
  cout << "       ENTER PASSWORD: ";
  cin >> password;

  while (!(valid_user(Uname, password))) {
    header();
    cout << "IDENTIFICATION MODE > ADMIN MODE > LOGIN" << endl;
    cout << "_____________" << endl;
    cout << "Wrong Credentials TYPE AGAIN" << endl;
    cout << "       ENTER USERNAME: ";
    cin >> Uname;
    cout << "       ENTER PASSWORD: ";
    cin >> password;
  }
}

//_____________________________________________USER
//MENU_____________________________

// OPTION 01
//____FUNCTION TO VIEW SORTED SCLASS FARE
void sort_household() {
  int min = 0;
  for (int i = 0; i < count_product; i++) {
    for (int j = i+1; j < count_product; j++) {
      if (household_price[j] <household_price[j] ) {
        min = household_price[i];
       household_price[i]   =household_price[j] ;
        household_price[j] =  min;

        int temp0 = industrial_price[i];
        industrial_price[i] = industrial_price[j];
        industrial_price[j] = temp0;

        string temp1 = productName[i];
        productName[i] = productName[j];
        productName[j] = temp1;

        string temp2 = productNo[i];
        productNo[i] = productNo[j];
        productNo[j] = temp2;

        string temp5 = product_time[i];
        product_time[i] = product_time[j];
        product_time[j] = temp5;

        int temp6 = product_house[i];
        product_house[i] = product_house[j];
        product_house[j] = temp6;

        int temp7 = product_ind[i];
        product_ind[i] = product_ind[j];
        product_ind[j] = temp7;

        char temp8 = dayNight[i];
        dayNight[i] = dayNight[j];
        dayNight[j] = temp8;
      }
    }
  }
  cout << "|Product No."
       << "\t"
       << "|Product Name"
       << "\t"
       << "|Boarding Time"
       << "\t"
       << "|Industry price "
       << "\t\t"
       << "|Household price" << endl
       << endl;
  for (int i = 0; i < count_product; i++) {
    cout << "|" << productNo[i] << "\t\t"
         << "|" << productName[i] << "\t\t"
         << "|" << product_time[i] << "\t\t"
         << "|" << industrial_price[i] << "\t\t"
         << "|" << household_price[i] << endl;
  }
}

//____FUNCTION TO VIEW SORTED FCLASS FARE
void sort_industrial() {
  int min = 0;
  for (int i = 0; i < count_product - 1; i++) {
    for (int j = i+1; j < count_product; j++) {
      if (industrial_price[i] < industrial_price[j]) {
        int temp = household_price[i];
        household_price[i] = household_price[j];
        household_price[j] = temp;

        int temp0 = industrial_price[i];
        industrial_price[i] = industrial_price[j];
        industrial_price[j] = temp0;

        string temp1 = productName[i];
        productName[i] = productName[j];
        productName[j] = temp1;

        string temp2 = productNo[i];
        productNo[i] = productNo[j];
        productNo[j] = temp2;

        string temp5 = product_time[i];
        product_time[i] = product_time[j];
        product_time[j] = temp5;

        int temp6 = product_house[i];
        product_house[i] = product_house[j];
        product_house[j] = temp6;

        int temp7 = product_ind[i];
        product_ind[i] = product_ind[j];
        product_ind[j] = temp7;

        char temp8 = dayNight[i];
        dayNight[i] = dayNight[j];
        dayNight[j] = temp8;
      }
    }
  }
  cout << "|Product No."
       << "\t\t"
       << "|Product Name"
       << "\t"
       << "|Recieving Time"
       << "\t"
       << "|Industrial price"
       << "\t\t"
       << "|Household price" << endl
       << endl;
  for (int i = 0; i < count_product; i++) {
    cout << "|" << productNo[i] << "\t\t"
         << "|" << productName[i] << "\t\t"
         << "|" << product_time[i] << "\t\t"
         << "|" << industrial_price[i] << "\t\t"
         << "|" << household_price[i] << endl;
  }
}

// OPTION 02
//____FUNCTION TO SEE AVAILABLE PRODUCTS

void available_products(char scene) {
  bool a = false;
  if (count_product == 0) {
    cout << "There is no product to show";
  } else {
    cout << "|Product No."
         << "\t"
         << "|Product Name"
         << "\t"
         << "|Storage Time"
         << "\t"
         << "|Industrial price"
         << "\t"
         << "|Household price" << endl
         << endl;
    for (int i = 0; i < count_product; i++) {
      if (dayNight[i] == scene) {
        a = true;
        cout << "|" << productNo[i] << "\t\t"
             << "|" << productName[i] << "|" << product_time[i] << "\t"
             << "|" << industrial_price[i] << "\t"
             << "|" << industrial_price[i] << endl;
      }
    }
  }
  if (a == false) {
    cout << "There is no Product available yet to show";
  }
  cout << endl;
}

// OPTION 03

void store_in_arrays(int date_r, string month_r, string pnaam_r,
                     int no_industrial_r, int no_household_r) {
  date[store] = date_r;
  month[store] = month_r;
  pnaam[store] = pnaam_r;
  no_industrial[store] = no_industrial_r;
  no_household[store] = no_household_r;
  buy_product[store] = products[store];
  UserN[store] = Uname;
  store++;

  for (int i = 0; i < store; i++) {
    for (int j = 0; j < count_product; j++) {
      if (productName[j] == pnaam[i]) {
        cout << "Total Industrial Products: "
             << no_industrial[i] * industrial_price[j] << endl;
        cout << "Total Household Product: "
             << no_household[i] * household_price[j] << endl;
        payable = (no_industrial[i] * industrial_price[j]) +
                  (no_household[i] * household_price[j]);
      }
    }
  }
}

//_____FUNCTION FOR RESERVING A TICKET

void reserve_product() {
  bool check = 0;
  for (int i = 0; i < store; i++) {
    if (Uname == UserN[i]) {
      check = 1;
    }
  }
  if (check == 1) {
    cout << "You have already Stored. To Modify go to Next Option" << endl;
  } else {
    int date;
    string month, pnaam;
    cout << "Enter Product Name: ";
    cin >> pnaam;
    bool t = 0;
    for (int i = 0; i < count_product; i++) {
      if (pnaam == productName[i]) {
        t = 1;
        break;
      }
    }
    while (!t) {
      cout << "There is no such Product availables: ";
      cin >> pnaam;
      for (int i = 0; i < count_product; i++) {
        if (pnaam == productName[i]) {
          t = 1;
          break;
        }
      }
    }
    cout << "Enter Date of Product ordering: ";
    cin >> date;
    cout << "Enter Month of ordering: ";
    cin >> month;
    cout << "Enter No.of Industrial products want to buy: ";
    int N_indus;
    cin >> N_indus;
    cout << "Enter No. of Household products want to buy: ";
    int N_house;
    cin >> N_house;
    cout << "You Have Successfully placed your Order." << endl;
    cout << "To SEE your Order Detail Go to Next Option:" << endl;
    store_in_arrays(date, month, pnaam, N_indus, N_house);
  }
}

// OPTION 04

//__________________Function for see Reservation details_____
int index_return() {
  for (int i = 0; i < usercount; i++) {
    if (Uname == username[i]) {
      return i;
    }
  }
  return 0;
}

void storage_details(int idx) {
  cout << "|UserName\t\t|Name\t\t|NIC\t\t|Contact\t\t|Product "
          "Number\t\t|Industrial prod.\t\t|Household prod."
       << endl;

  for (int i = 0; i < store; i++) {
    if (UserN[i] == Uname) {
      cout << "|" << username[idx] << "\t\t"
           << "|" << firstname[idx] << " " << lastname[idx] << "\t\t"
           << "|" << CNIC[idx] << "\t\t"
           << "|" << contact[idx] << "\t\t"
           << "|" << buy_product[i] << "\t\t"
           << "|" << no_industrial[i] << "\t\t"
           << "|" << no_household[i] << endl;
    }
  }
  for (int i = 0; i < store; i++) {
    for (int j = 0; j < count_product; j++) {
      if (productName[j] == pnaam[i]) {
        cout << endl;
        cout << "Total Industrial product price: "
             << no_industrial[i] * industrial_price[j] << endl;
        cout << "Total Household product price: "
             << no_household[i] * household_price[j] << endl;
        cout << "Total price = " << payable << endl;
      }
    }
  }
}

// OPTION 05
//______FUNCTION TO MODIFY RESERVATION
void modify_order() {

  for (int i = 0; i < store; i++) {
    if (UserN[i] == Uname) {
      cout << "Enter Product Name: ";
      cin >> pnaam[i];
      cout << "Enter Date of Buying product: ";
      cin >> date[i];
      cout << "Enter Month of buying: ";
      cin >> month[i];
      cout << "Enter No. of Industrial product want to buy: ";
      cin >> no_industrial[i];
      cout << "Enter No. of Household product want to buy: ";
      cin >> no_household[i];
    }
  }
}

// OPTION 06
//______FUNCTION TO CANCEL RESERVATION
void cancel_reservation() {
  for (int i = 0; i < store; i++) {
    if (UserN[i] == Uname) {
      for (int j = 1; j < store - 1; j++) {
        pnaam[i] = pnaam[i + 1];
        date[i] = date[i + 1];
        month[i] = month[i + 1];
        no_industrial[i] = no_industrial[i + 1];
        no_household[i] = no_household[i + 1];
        UserN[i] = UserN[i + 1];
        buy_product[i] = buy_product[i + 1];
      }
      store--;
      break;
    }
  }
  payable = 0;
  cout << "Cancelled" << endl;
}

// OPTION 08
//_______________FUNCTION FOR PAYMENT _________
void payment() {
  if (payable == 0) {
    cout << "You Have not yet store ";
    cout << endl << "Reserve Your Seats & then come back";
  } else {
    cout << "Enter Payment Method(cash/card): ";
    string method;
    cin >> method;

    if (method == "card") {
      cout << "Successfully Paid";
    }
    if (method == "cash") {
      cout << endl << "Amount You Paid: ";
      int paid;
      cin >> paid;
      cout << endl << "Balance: ";
      cout << payable - paid;
      cout << endl;
      cout << "Succesfully Done" << endl;
    }
  }
}

//______________________FUNCTION FOR CLEAR SCREEN__________________________
void clearscreen() {
  cout << "Press Any key to continue ";
  getch();
  system("cls");
}

// FUNCTION TO STORE DATA IN FILE

void store_data() {
  fstream file;
  file.open("admin.txt", ios::out);
  for (int i = 0; i < admin_count; i++) {
    if (i != 0)
      file << "\n";
    file << admin_name[i];
    file << ',';
    file << admin_pass[i];
    file << ',';
    file << admin_email[i];
    if (i != admin_count - 2) {
      file << "\n";
    }
  }

  file.close();

  file.open("user.txt", ios::out);
  for (int i = 0; i < usercount; i++) {
    if (i != 0)
      file << "\n";
    file << username[i];
    file << ',';
    file << firstname[i];
    file << ',';
    file << lastname[i];
    file << ',';
    file << email[i];
    file << ',';
    file << CNIC[i];
    file << ',';
    file << password[i];
    file << ',';
    file << contact[i];
    if (i != usercount - 2) {
      file << "\n";
    }
  }
  file.close();

  file.open("approve.txt", ios::out);
  for (int i = 0; i < app; i++) {
    file << approved_N[i];
    file << "\n";
  }
  file.close();

  file.open("product.txt", ios::out);
  for (int i = 0; i < count_product; i++) {
    if (i != 0)
      file << "\n";
    file << productName[i];
    file << ',';
    file << productNo[i];
    file << ',';
    file << product_time[i];
    file << ',';
    file << dayNight[i];
    file << ',';
    file << product_ind[i];
    file << ',';
    file << industrial_price[i];
    file << ',';
    file << product_house[i];
    file << ',';
    file << household_price[i];
    if (i != count_product - 1) {
      file << "\n";
    }
  }
  file.close();

  file.open("faqs.txt", ios::out);
  for (int i = 0; i < faq_counter; i++) {
    file << questions[i];
    file << "\n";
    file << answers[i];
    file << "\n";
  }
  file.close();

  file.open("suggestion.txt", ios::out);
  for (int i = 0; i < suggest_counter; i++) {
    file << complainer[i];
    file << "\n";
    file << suggest[i];
    if (i != suggest_counter - 1) {
      file << "\n";
    }
  }
  file.close();

  file.open("storage.txt", ios::out);
  for (int i = 0; i < store; i++) {
    if (i != 0)
      file << "\n";
    file << UserN[i];
    file << ',';
    file << pnaam[i];
    file << ',';
    file << buy_product[i];
    file << ',';
    file << date[i];
    file << ',';
    file << month[i];
    file << ',';
    file << no_industrial[i];
    file << ',';
    file << no_household[i];
    if (i != store - 1) {
      file << "\n";
    }
  }
  file.close();
}
//_______FUNCTION For PARSING DATA
string parse_data(string word, int field) {
  int comma = 1;
  string item;
  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == ',') {
      comma++;
    } else if (comma == field) {
      item = item + word[i];
    }
  }
  return item;
}

// FUNCTION TO LOAD DATA FROM FILE

void load_data() {
  fstream file;
  string word;
  file.open("admin.txt", ios::in);
  while (!file.eof()) {
    getline(file, word);
    if (word[0] != ',' && word[0] == '\0') {
      admin_name[admin_count] = parse_data(word, 1);
      admin_pass[admin_count] = parse_data(word, 2);
      admin_email[admin_count] = parse_data(word, 3);
      admin_count++;
    } else {
      continue;
    }
  }
  admin_count--;
  cout << admin_count;
  getch();
  file.close();

  file.open("approve.txt", ios::in);
  string letter;
  while (!file.eof()) {
    getline(file, letter);
    approved_N[app] = letter;
    app++;
  }

  file.open("user.txt", ios::in);
  string alphabet;
  while (!file.eof()) {
    getline(file, alphabet);
    if (alphabet[0] != ',' && alphabet[0] != ' ') {
      username[usercount] = parse_data(alphabet, 1);
      firstname[usercount] = parse_data(alphabet, 2);
      lastname[usercount] = parse_data(alphabet, 3);
      email[usercount] = parse_data(alphabet, 4);
      CNIC[usercount] = str_to_l(parse_data(alphabet, 5));
      password[usercount] = parse_data(alphabet, 6);
      contact[usercount] = parse_data(alphabet, 7);
      usercount = usercount + 1;
    } else {
      continue;
    }
  }
  file.close();
  cout << usercount;
  getch();

  file.open("product.txt", ios::in);
  string product;
  while (!file.eof()) {
    getline(file, product);
    if (product[0] != ',' && product[0] != '\0') {
      productName[count_product] = parse_data(product, 1);
      productNo[count_product] = parse_data(product, 2);
      product_time[count_product] = parse_data(product, 3);
      string time = parse_data(product, 4);
      dayNight[count_product] = time[0];
      product_ind[count_product] = str_to_i(parse_data(product, 5));
      industrial_price[count_product] = str_to_i(parse_data(product, 6));
      product_house[count_product] = str_to_i(parse_data(product, 7));
      household_price[count_product] = str_to_i(parse_data(product, 8));
      count_product++;
    } else {
      continue;
    }
  }
  file.close();
  cout << count_product;
  getch();

  file.open("suggestion.txt", ios::in);
  string suggesty;
  while (!file.eof()) {
    getline(file, suggesty);
    complainer[suggest_counter] = suggesty;
    getline(file, suggesty);
    suggest[suggest_counter] = suggesty;
    suggest_counter++;
  }
  file.close();

  file.open("storage.txt", ios::in);
  string place;
  while (!file.eof()) {
    getline(file, place);
    if (place[0] != ',' && place[0] != '0') {
      UserN[store] = parse_data(place, 1);
      pnaam[store] = parse_data(place, 2);
      buy_product[store] = parse_data(place, 3);
      date[store] = str_to_i(parse_data(place, 4));
      month[store] = parse_data(place, 5);
      no_industrial[store] = str_to_i(parse_data(place, 6));
      no_household[store] = str_to_i(parse_data(place, 7));
      store++;
    }
  }
  file.close();
  store--;
  cout << store;
  getch();
}

//___________________________Function for Password VALIDATION________________
bool password_validation(string pass) {

  bool t = 1;
  int passer = 0;
  for (int i = 0; pass[i] != '\0'; i++) {
    passer++;
    int y = pass[i];
    if (y >= 48 && y <= 57) {
      t = 0;
    }
  }
  if (t == 0 && passer >= 8) {
    return 1;
  } else {
    return 0;
  }
}
//___________________________Function for Username VALIDATION________________
bool username_validation(string name) {
  bool a = true;
  for (int i = 0; name[i] != '\0'; i++) {
    int y = name[i];
    if (y >= 48 && y <= 57) {
      a = false;
      break;
    }
  }
  if (a) {
    return 0;
  } else {
    return 1;
  }
}

bool email_validation(string email) {
  int mail = 0;
  for (int i = 0; email[i] != '\0'; i++) {
    if (email[i] == '@') {
      return true;
      break;
    }
  }
  return false;
}