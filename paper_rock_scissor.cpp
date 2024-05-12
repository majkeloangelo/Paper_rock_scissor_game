#include <iostream>
#include <string.h>

using namespace std;

class Player{
    private:
        string name;
        double points = 0;
    public:
        Player(string my_name);
        ~Player(){};
        string GetName();
        double GetPoints();
        void AddPoint();
        void CheckPoint();
};

Player::Player(string my_name){
    name = my_name;
}

string Player::GetName(){
    return name;
}

void Player::AddPoint(){
    points+=1;
}

double Player::GetPoints(){
    return points;
}

void Player::CheckPoint(){
    cout << name << " points: " << points << endl;
}

class Game{
    private:
        string choice_one, choice_two;
        string choice;
    public:
        Game(string first_choice, string second_choice);
        ~Game(){};
        int CheckChoices(string first_choice, string second_choice);
        bool Validation(string choice);

};
Game::Game(string first_choice, string second_choice){
    choice_one = first_choice;
    choice_two = second_choice;
}
int Game::CheckChoices(string first_choice, string second_choice){

    if(first_choice == "paper"){
        if(second_choice == "paper"){
            cout << "draw!" << endl;
        }else if(second_choice == "rock"){
            cout << "first player get point!" << endl;
            return 0;
        }else{
            cout << "second player get point!" << endl;
            return 1;
        }
    }
    if(first_choice == "rock"){
        if(second_choice == "rock"){
            cout << "draw!" << endl;
        }else if(second_choice == "paper"){
            cout << "second player get point!" << endl;
            return 1;
        }else{
            cout << "first player get point!" << endl;
            return 0;
        }
    }
    if(first_choice == "scissors"){
        if(second_choice == "scissors"){
            cout << "draw!" << endl;
        }else if(second_choice == "paper"){
            cout << "first player get point!" << endl;
            return 0;
        }else{
            cout << "second player get point!" << endl;
            return 1;
        }
    }
    return 2;
}

bool Game::Validation(string choice){
    if(choice != "paper" && choice != "rock" && choice != "scissors"){
        cout << "choose paper, rock or scissor please!" << endl;
        return false;
    }
    return true;
}

int main(){

    string name_one, name_two, choice_one, choice_two;

    cout << "Insert player first name" << endl;
    cin >> name_one;
    Player one(name_one);

    cout << "Insert player second name" << endl;
    cin >> name_two;
    Player two(name_two);

    for (int i = 0; i < 10; i++){
        Game game(choice_one, choice_two); 

        cout << "Player one, please choose paper, rock, or scissors" << endl;
        do {
            cin >> choice_one;
        } while (!game.Validation(choice_one));

        cout << "Player two, please choose paper, rock, or scissors" << endl;
        do {
            cin >> choice_two;
        } while (!game.Validation(choice_two));

        int result = game.CheckChoices(choice_one, choice_two);

        if (result == 0){
            one.AddPoint();
        }else{
            two.AddPoint();
        }

        cout << "Points after Round " << i + 1 << ":" << endl;
        one.CheckPoint();
        two.CheckPoint();

    }

    return 0;
}