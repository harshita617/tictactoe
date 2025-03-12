#include<iostream>
#include<ctime>
using namespace std;

void drawboard(char *spaces);
void playermove(char *spaces, char player);
void computermove(char *spaces, char comp);
bool checkwinner(char *spaces, char player, char comp);
bool checktie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player='X';
    char comp='O';
    bool running = true;

    //Game started
    drawboard(spaces);

    while(running){
        playermove(spaces,player);
        drawboard(spaces);

        if(checkwinner(spaces, player, comp)){
            running = false;
            break;
        }
        else if(checktie(spaces)){
            running = false;
            break;
        }

        cout << "COMPUTER'S MOVE!" <<"\n";

        computermove(spaces,comp);
        drawboard(spaces);

        if(checkwinner(spaces, player, comp)){
            running = false;
            break;
        }
        else if(checktie(spaces)){
            running = false;
            break;
        }
    }

    return 0;
}

void drawboard(char *spaces){
    cout << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << "\n";
    cout << "     |     |     " << "\n";
    cout << "\n";


}
void playermove(char *spaces, char player){
    int number;
    do
    {
        cout << "Enter a number to place the X : ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number <8);
    

}
void computermove(char *spaces, char comp){
    int number;
    srand(time(0));
    
    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = comp;
            break;
        }
    }

}
bool checkwinner(char *spaces, char player, char comp){

    // Rows

    if(spaces[0]!=' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }

    else if(spaces[3]!=' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }
    else if(spaces[6]!=' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }

    //Columns

    else if(spaces[0]!=' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }
    else if(spaces[1]!=' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }
    else if(spaces[2]!=' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }

    //Diagonals

    else if(spaces[0]!=' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }
    else if(spaces[2]!=' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "YOU WIN!:)\n" : cout << "YOU LOSE!:(\n";
    }
    else{
        return false;
    }

    return true;

}
bool checktie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    cout << "IT'S A TIE!:|" << "\n";

}