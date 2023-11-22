
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;


    
//Array displayer
void printinventory(string array[])
{
    cout <<"Inventory"<<endl;
    for(int i=0; i<6;i++)
    {
        cout << "Slot " << i+1<< ": " << array[i] << endl;
    }
    system("pause");
    system("cls");

}

//The following function adds an item to a string array if an empty slot exists. Is called upon using knapsack and an element from items as arguements.   
void additem(string array[], string item){
    bool add = false;
    for(int i=0; i<6;i++)
    {
        if(array[i]==""){
            array[i]=item;
            add=true;
            break;
        }
    }
    if(add==false){
        cout << "There isn't any space in you're inventory." << endl;
    }
    else{
        
        cout << "You have chosen to pick up a "<<  item << "." << endl;
    }
    system("pause");
    system("cls");
    
}

int attack(string animal, string inven[]){
    if(animal=="bear"){
        int user_health = 400, bear_health=100;
        string choice;
    
        cout<<"You have encountered a wild bear. Mistaking you for an attacker, it begins to attack you in order to protect it's cubsʔ" << endl;
        
        while(true){
            system("cls");
            cout << "Do you wish to attack or run away(attack/run)?" << endl;
            cin >> choice;
            
            if(choice=="run"){
                cout << "You have attempted to outrun a fully grown grizzly bear. You are immediately mauled to death, what where you thinking?" << endl;
                system("pause");
                system("cls");
                return 0;
            }
            else if(choice=="attack"){
                cout << "What weapon do you want to use?(unarmed is an option)" << endl;
                for(int i=0;i<6;i++){
                    cout << i+1 <<". " << inven[i] << endl;
                }
                cin >> choice;
                
                if(choice=="unarmed"){
                    bear_health-=20;
                    user_health-=50;
                    if(user_health<=0)return 0;
                    if(bear_health<=0)return 1;
                    cout << "You have dealt 20 damage to the bear. It's health is now " << bear_health << "." << endl;
                    cout << "The Bear has struck back and has dealt 50 damage. You're health is now " << user_health << "."<< endl;
                    system("pause");
                    
                }
                else if(choice=="sword"){
                    bear_health-=80;
                    user_health-=50;
                    if(user_health<=0)return 0;
                    if(bear_health<=0)return 1;
                    cout << "You have dealt 50 damage to the bear. It's health is now " << bear_health << "." << endl;
                    cout << "The Bear has struck back and has dealt 50 damage. You're health is now " << user_health << "."<< endl;
                    system("pause");
                    
                }
                else if(choice=="axe"){
                    bear_health-=120;
                    user_health-=50;
                    if(user_health<=0)return 0;
                    if(bear_health<=0)return 1;
                    cout << "You have dealt 80 damage to the bear. It's health is now " << bear_health << "." << endl;
                    cout << "The Bear has struck back and has dealt 50 damage. You're health is now " << user_health << "."<< endl;
                    system("pause");
                    
                }
        }
        }
    }
    cout << "You have struck a blow dealing serious damage(DAS A LOT OF DAMAGE)" << endl;
    system("pause");
    system("cls");
    return 0;
}


int move(string direction, int steps, string inv[])
    {
         while(true){
                        cout << "In what direction did you travel?"<<endl;
                        cin>> direction;
                        if(direction=="north"|| direction=="south" || direction=="east" || direction=="west"){
                            system("cls");
                            break;
                        }
                        else{
                            cout<<"Please enter a north, south, east, west as a direction!" << endl;
                            system("pause");
                            system("cls");
                        }
                    }

                    while(true){
                        cout << "How many steps have you taken weary traveler"<<endl;
                        cin>> steps;
                        if(steps>=0){
                            break;
                        }
                        else{
                            cout<<"Please enter a positive number!" << endl;
                        }
                    }
                    if(direction=="north" && steps>=50){
                        if(attack("bear", inv)<=0)return 0;
                        else return 1;
                        
                    }
                    system("pause");
                    system("cls");
                return 0;
                    
    }
    

void game_over(){
    cout << "GAME OVER! You've chosen to quit." << endl;
    system("pause");
    system("cls");
}
int main()
{
    
    int steps4;// assignment 4 variables 
    string direction4;
    const double forest = 50;
    const double dungeon = 100;
    const double house = 4000;
    const double maze = 6000;

    // assignment 3 variables
    string direction;
    int steps;
    float kilometer;
    const float stepsPermile=2000; 
    //assignment 3 code
    int choice=0;
    
    string Knapsack [6] = {"sword", "", "", "","", ""}; 
    
    string items [6] = {"Sword", "Axe", "Shield", "Health-Potion","Sandwich", "Beartrap"}; 
    
    
    
    
    while(true){
        cout<<"What is you're next move?" << endl;
        cout<<"1.Move"<<endl;
        cout<<"2.Attack"<<endl;
        cout<<"3.Pick up Item"<<endl;
        cout<<"4.Display Inverntory"<<endl;
        cout<<"5.Quit"<<endl;
        cin>>choice;


        //The following statements sort the contents of the knapsack array alphabetically. 
        int n = sizeof(Knapsack) / sizeof(Knapsack[0]);
        sort(Knapsack, Knapsack + n);

        //The following statements generate a random number inbetween 0 and 5.
        srand(time(NULL));
        int temp = rand() % 6;
        
        if(choice>0 && choice<5){
            switch(choice){
                case 1:
                    system("cls");
                    if(move(direction, steps, Knapsack)==0){
                        cout << "Game Over, Thanks for Playing" << endl;
                        system("pause");
                        system("cls");
                        return 0;
                    }
                    else{
                        cout << "The Bear has been defeated. It has dropped a bearskin that has been droped in you're inventory." << endl;
                        additem(Knapsack, "Bearskin");
                    }
                    break;
                case 2:
                    //attack();
                    break;
                case 3:
                    additem(Knapsack, items[temp]);
                    break;
                case 4:
                    printinventory(Knapsack);
                    break;
                case 5:
                    game_over();
                    break;
                    }
        //break;
        }
        else{
            cout<<"Please select a menu number!"<<endl;
            system("pause");
            system("cls");
        }
    }

        

    float miles = steps / stepsPermile;
    kilometer = 1.60934 * miles;
    //start of asssignment 4 code
    cout<<"You have walked a distance of "<< miles <<" miles"<<endl;
    cout<<"This is equal to "<< kilometer << " Kilometer(s)"<<endl;
    cout<<"The direction you walked in is "<<direction4<<endl;
    cout << "How many steps have you taken weary traveler"<<endl;
    cin>> steps4;
    cout << " In which direction have you been travelling"<<endl;
    cin>> direction4;

    if (steps4 >= forest && direction4 == "north")
    cout<< "You have entered the forest"<<endl;

    if (steps4 >= dungeon && direction4 == "south")
    cout<<"You have entered the dungeon"<<endl;

    if (steps4 >= house && direction4 == "east")
    cout<<"You have entered the house"<<endl;

    if (steps4 >= forest && direction == "west")
    cout<<"You have entered the maze"<<endl;


    return 0;
}