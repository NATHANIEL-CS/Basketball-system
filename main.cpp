#include <bits/stdc++.h>
using namespace std;

class Basketball{
    private:
        string Player;
        string Team;
    
    public:
    Basketball(string aPlayer, string aTeam){
        SetPlayer(aPlayer);
        SetTeam(aTeam);
    }

    string GetPlayer(){ return Player;}
    string GetTeam(){ return Team;}

    void SetPlayer(string aPlayer){
        Player = aPlayer;
    }

    void SetTeam(string aTeam){
        Team = aTeam;
    }
};

class Player{
    private:
        string Surname;
        string Position;
        int Score = 0;
        int JerseyNumber = 0;
    
    public:
    Player(string aSurname, string aPosition, int aScore, int aJerseyNumber){
        SetSurname(aSurname);
        SetPosition(aPosition);
        SetScore(aScore);
        SetJerseyNumber(aJerseyNumber);
    }

    string GetSurname(){ return Surname;}
    string GetPosition(){ return Position;}
    int GetScore(){ return Score;}
    int GetJerseyNumber(){ return JerseyNumber;}

    void SetSurname(string aSurname){
        Surname = aSurname;
    }

    void SetPosition(string aPosition){
        Position = aPosition;
    }

    void SetScore(int aScore){
        Score = aScore;
    }

    void SetJerseyNumber(int aJerseyNumber){
        JerseyNumber = aJerseyNumber;
    }

    void Showinfo(){
        cout << "\n=======================================" << endl;
        cout << "          PLAYER INFORMATION " << endl;
        cout << "|| [+] SURNAME        : " << GetSurname() << endl;
        cout << "|| [+] POSITION       : " << GetPosition() << endl;
        cout << "|| [+] SCORE          : " << GetScore() << endl;
        cout << "|| [+] JERSEY NUMBER  : " << GetJerseyNumber() << endl;
        cout << "=======================================" << endl;
    }

    void Pass(Player* target){
        cout << GetSurname() << " PASS TO " << target->GetSurname() << endl;
    }

    void Shoot(){
        int chance = rand() % 10 + 1;
        if(chance >= 7){
            cout << "[SHOOT] 3 POINTS!" << endl;
            SetScore(GetScore() + 3);
            Showinfo();
        } else if (chance >= 5){
            cout << "[SHOOT] 2 POINTS" << endl;
            SetScore(GetScore() + 2);
            Showinfo();
        } else if (chance >= 3){
            cout << "[SHOOT] 1 POINT" << endl;
            SetScore(GetScore() + 1);
            Showinfo();
        } else {
            cout << "MISSED!" << endl;
        }
    }
};

class Team{
    private:
        string Teamname;
        int Win;
        int Loss;
    
    public:
    Team(string aTeamname, int aWin, int aLoss){
        SetTeamname(aTeamname);
        SetWin(aWin);
        SetLoss(aLoss);
    }

    string GetTeamName(){ return Teamname;}
    int GetWin(){ return Win;}
    int GetLoss(){ return Loss;}

    void SetTeamname(string aTeamname){
        Teamname = aTeamname;
    }

    void SetWin(int aWin){
        Win = aWin;
    }

    void SetLoss(int aLoss){
        Loss = aLoss;
    }

    void Showinfo(){
        cout << "\n=======================================" << endl;
        cout << "          TEAM INFORMATION " << endl;
        cout << "        --------------------" << endl;
        cout << "|| [+] TEAM NAME  : " << GetTeamName() << endl;
        cout << "|| [+] TEAM WIN   : " << GetWin() << endl;
        cout << "|| [+] TEAM LOSS  : " << GetLoss() << endl;
        cout << "=======================================" << endl;
    }
};

int main()
{
    int team;
    int player;
    srand(time(0));

    while(true){
        cout << "HOW MANY TEAMS (max 3): ";
        cin >> team;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INPUT A NUMBER!" << endl;
        } else if(team <= 0 || team > 3){
            cout << "ENTER 1 TO 3 ONLY!" << endl;
        } else {
            break;
        }
    }

    Team** ptrTeam = new Team*[team];

    for(int i = 0; i < team; i++){
        string teamname;

        cout << "TEAM NAME " << i + 1 << "#: ";
        cin >> teamname;

        ptrTeam[i] = new Team(teamname, 0, 0);
    }

    while(true){
        cout << "\nHOW MANY PLAYERS IN TEAM: ";
        cin >> player;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INPUT A NUMBER!" << endl;
        } else if(player <= 0){
            cout << "PLAYER MUST BE GREATER THAN 0" << endl;
        } else {
            break;
        }
    }

    Player** ptrPlayer = new Player*[player];

    cout << "\nAVAILABLE TEAMS\n";

    for(int i = 0; i < team; i++){
        cout << "[" << i + 1 << "] "
             << ptrTeam[i]->GetTeamName() << endl;
    }

    int choose;
    
    while(true){
        cout << "\nCHOOSE: ";
        cin >> choose;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INPUT A NUMBER!" << endl;
        } else if(choose < 1 || choose > team){
            cout << "INVALID TEAM!" << endl;
        } else {
            break;
        }
    }

    for(int a = 0; a < player; a++){
        string surname, position;
        int jerseynumber;

        cout << "\nPLAYER SURNAME " << a + 1 << "#: ";
        cin >> surname;

        cout << "PLAYER POSITION " << a + 1 << "#: ";
        cin >> position;

        while(true){
            cout << "JERSEY NUMBER " << a + 1 << "#: ";
            cin >> jerseynumber;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "INVALID JERSEY NUMBER!" << endl;
            } else {
                break;
            }
        }

        ptrPlayer[a] = new Player(surname,position,0,jerseynumber);
    }

    cout << "\n=======================================" << endl;
    cout << "TEAM [" << choose << "]: "
         << ptrTeam[choose - 1]->GetTeamName() << endl;
    cout << "=======================================" << endl;

    for(int i = 0; i < player; i++){
        cout << "[" << i + 1 << "]" << endl;
        ptrPlayer[i]->Showinfo();
    }

    int pick;
        while(true){
        cout << "PICK A PLAYER: ";
        cin >> pick;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID PLAYER!" << endl;
        } else if(pick < 1|| pick > player){
            cout << "INVALID PLAYER!" << endl;
        } else {
            break;
        }
    }

    while(true){
        cout << "(1) SHOOT (2) PASS (3) EXIT" << endl;
        cout << "CHOOSE: ";
        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID CHOICES!" << endl;
        } else if(choose == 1){
            ptrPlayer[pick -1]->Shoot();
        } else if(choose ==2){
            int to;
            cout << "\nAVAILABLE PLAYERS:" << endl;

            for(int i = 0; i < player; i++){
                cout << "[" << i + 1 << "]" << ptrPlayer[i]->GetSurname() << endl;
            }

            while(true){
                cout << "PASS TO: ";
                cin >> to;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "INVALID PLAYER!" << endl;
                } else if(to < 1 || to > player) {
                    cout << "INVALID PLAYER!" << endl;
                } else {
                    break;
                }
            }

            if(to == pick){
                cout << "Not allowed to pass yourself!" << endl;
            } else {
                ptrPlayer[pick -1]->Pass(ptrPlayer[to -1]);
            }
        } else if(choose == 3){
            break;
        }
    }

    for(int i = 0; i < player; i++){
        delete ptrPlayer[i];
    }

    delete[] ptrPlayer;

    for(int i = 0; i < team; i++){
        delete ptrTeam[i];
    }

    delete[] ptrTeam;

    return 0;
}