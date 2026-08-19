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

    cout << "HOW MANY TEAMS: ";
    cin >> team;

    Team** ptrTeam = new Team*[team];

    for(int i = 0; i < team; i++){
        string teamname;

        cout << "TEAM NAME " << i + 1 << "#: ";
        cin >> teamname;

        ptrTeam[i] = new Team(teamname, 0, 0);
    }

    cout << "\nHOW MANY PLAYERS IN TEAM: ";
    cin >> player;

    Player** ptrPlayer = new Player*[player];

    cout << "\nAVAILABLE TEAMS\n";

    for(int i = 0; i < team; i++){
        cout << "[" << i + 1 << "] "
             << ptrTeam[i]->GetTeamName() << endl;
    }

    int choose;

    cout << "\nCHOOSE: ";
    cin >> choose;

    for(int a = 0; a < player; a++){
        string surname, position;
        int jerseynumber;

        cout << "\nPLAYER SURNAME " << a + 1 << "#: ";
        cin >> surname;

        cout << "PLAYER POSITION " << a + 1 << "#: ";
        cin >> position;

        cout << "JERSEY NUMBER " << a + 1 << "#: ";
        cin >> jerseynumber;

        ptrPlayer[a] = new Player(surname,position,0,jerseynumber);
    }

    cout << "\n=======================================" << endl;
    cout << "TEAM [" << choose << "]: "
         << ptrTeam[choose - 1]->GetTeamName() << endl;
    cout << "=======================================" << endl;

    for(int i = 0; i < player; i++){
        ptrPlayer[i]->Showinfo();
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