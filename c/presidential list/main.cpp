#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;
void Disaster (int Disasterroll, int &DisasterEffect, char Party, double DisasterChance);
void Y1992 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y1996 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y2000 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y2004 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y2008 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y2012 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
void Y2016 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber);
int main(){
    srand( time(0));
    string President;
    char Party;
    double Wank, DisasterChance, Radicalism; //Stats
    int TermLimit;
    int TermNumber;
    cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "- - ALTERNATE US ELECTION LIST GENERATOR - " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << endl;
    cout << "Alternate US Presidential Election List Generator 1.0" << endl;
    cout << "Coded by Augenis" << endl;
    cout << "(NOTE: This program is self-aware and it is haunted by the ghost of FDR, and as such the term limit system doesn't work no matter the amount of effort put into patching it. I'm considering calling an exorcist now)" << endl;
    cout << endl;
    cout << "Set stats for this simulation" << endl;
    cout << "Political Ideology Wank (-1 for maximum liberalism wank, 0 for standard setup, 1 for maximum conservatism wank): "; cin >> Wank;
    cout << "Disaster Event Chance (0 for no disasters, 1 for standard, 2 for maximum): "; cin >> DisasterChance;
    cout << "Innate Radicalism (0 for only moderate candidates, 20 for standard, 50 for only radical candidates): "; cin >> Radicalism;
    cout << "Term Limit (2 is standard): "; cin >> TermLimit;
    cout << endl;
    cout << "* * * * * * * * * * * * * * * * * *" << endl;
    cout << " * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;
    cout << "LIST OF U.S. PRESIDENTS FROM 1992 TO 2017:" << endl;
    cout << endl;
    Y1992(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y1996(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y2000(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y2004(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y2008(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y2012(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    cout << endl;
    Y2016(President, Party, Wank, DisasterChance, Radicalism, TermLimit, TermNumber);
    return 0;
}
void Disaster (int Disasterroll, int &DisasterEffect, char Party, double DisasterChance){
    srand( time(0));
    //Disaster chance
    Disasterroll = rand() % 100;
    if (Disasterroll < 25*DisasterChance){
        cout << "DISASTER EVENT: ";
        if (Party == 'R'){
            DisasterEffect = -1;
        }
        else {
            if (Party == 'D'){
                DisasterEffect = 1;
            }
            else DisasterEffect = 0;
        }
        int DisasterChoice = rand() % 5;
        if (DisasterChoice == 1){
            cout << "RECESSION" << endl;
            cout << endl;
        }
        else {
            if (DisasterChoice == 2){
                cout << "QUAGMIRE WAR" << endl;
                cout << endl;
            }
            else {
                if (DisasterChoice == 3){
                    cout << "NATURAL DISASTER" << endl;
                    cout << endl;
                }
                else {
                    if (DisasterChoice == 4){
                        cout << "OIL CRISIS" << endl;
                        cout << endl;
                    }
                    else {
                        cout << "PRESIDENTIAL SCANDAL" << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
    else { DisasterEffect = 0; }
}
void Y1992 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection;
    //Democratic Primary
    int DemPrimary = rand() % 100 + 1;
    if (DemPrimary < Radicalism - 20*Wank){
        DemCandidate = "Jerry Brown/Tom Harkin";
    }
    else {
            if (DemPrimary > 100 - Radicalism - 20*Wank && DisasterChance > 1){
                DemCandidate = "Mario Cuomo/Al Gore";
            }
            else {
                    if (DemPrimary > 100 - Radicalism - 20*Wank && DisasterChance <= 1){
                        DemCandidate = "Bob Kerrey/Joe Lieberman";
                    }
                    else {
                        DemCandidate = "Bill Clinton/Al Gore";
                    }
            }
    }
    //Republican Primary
    int RepPrimary = rand() % 100 + 1;
    if (RepPrimary < Radicalism - 20*Wank){
        RepCandidate = "Ron Paul/Lew Rockwell";
    }
    else {
        if (RepPrimary > 100 - Radicalism - 20*Wank){
            RepCandidate = "Pat Buchanan/Eloza B. Foster";
        }
        else {
           RepCandidate = "George H.W. Bush/Dan Quayle";
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism*2){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Ross Perot/James Stockdale";
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank){
            cout << "1993-1997: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
            if (RepCandidate == "George H.W. Bush/Dan Quayle"){
                TermNumber = 2;
            }
            else {
                TermNumber = 1;
            }
        }
        else {
            if (TheElection < 46 - 20*Wank){
                cout << "1993-1997: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
                TermNumber = 1;
            }
            else {
                cout << "1993-1997: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
                TermNumber = 1;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank){
            cout << "1993-1997: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            if (RepCandidate == "George H.W. Bush/Dan Quayle"){
                TermNumber = 2;
            }
            else {
                TermNumber = 1;
            }
        }
        else {
            cout << "1993-1997: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
            TermNumber = 1;
        }
    }
}
void Y1996 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true; //No president
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Jerry Brown/Tom Harkin";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "Bob Casey/Joe Lieberman";
                }
                else {
                    DemCandidate = "Bill Clinton/Al Gore";
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank){
            RepCandidate = "Steve Forbes/Lamar Alexander";
        }
        else {
            if (RepPrimary > 100 - Radicalism - 20*Wank){
                RepCandidate = "Pat Buchanan/Eloza B. Foster";
            }
            else {
                if (DisasterEffect = 1){
                    RepCandidate = "Dan Quayle/Bob Dole";
                }
                else {
                    if (DisasterEffect = -1){
                        RepCandidate = "Colin Powell/Dick Cheney";
                    }
                    else {
                        RepCandidate = "Bob Dole/Jack Kemp";
                    }
                }
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Ross Perot/Pat Choate";
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "1997-2001: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "1997-2001: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "1997-2001: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "1997-2001: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "1997-2001: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
void Y2000 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    //Disaster chance
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true; //No president
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Paul Wellstone/Bill Bradley";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "Bill Bradley/Paul Wellstone";
                }
                else {
                    if (Party == 'R'){
                        DemCandidate = "Bob Kerrey/Dick Gephardt";
                    }
                    else {
                        if (Party == 'T'){
                            DemCandidate = "Donald Trump/Nancy Pelosi";
                        }
                        else {
                            DemCandidate = "Al Gore/Joe Lieberman";
                        }
                    }
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank){
            RepCandidate = "John McCain/Gary Bauer";
        }
        else {
            if (RepPrimary > 100 - Radicalism - 20*Wank){
                RepCandidate = "Pat Buchanan/Eloza B. Foster";
            }
            else {
                if (RepPrimary < Radicalism - 20*Wank && Party == 'R'){
                    RepCandidate = "Alan Keyes/Herman Cain";
                }
                else {
                    if (Party == 'R'){
                        RepCandidate = "Dan Quayle/Alan Keyes";
                    }
                    else {
                        RepCandidate = "George W. Bush/Dick Cheney";
                    }
                }
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Donald Trump/Oprah Winfrey";
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2001-2005: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2001-2005: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2001-2005: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2001-2005: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2001-2005: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
void Y2004 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    //Disaster chance
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true; //No president
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Howard Dean/Tom Harkin";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "Wesley Clark/John Edwards";
                }
                else {
                    DemCandidate = "John Kerry/John Edwards";
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank){
            RepCandidate = "Lincoln Chaffee/Michael Bloomberg";
        }
        else {
            if (RepPrimary > 100 - Radicalism - 20*Wank){
                RepCandidate = "Tom Tancredo/Pat Buchanan";
            }
            else {
                RepCandidate = "Dick Cheney/Robert B. Abrams";
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Michael Badnarik/Richard Campagna";
    }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2005-2009: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2005-2009: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                cout << "2005-2009: " << ThirdCandidate << " (Independent)" << endl;
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2005-2009: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2005-2009: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
void Y2008 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    //Disaster chance
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true;
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Al Gore/Joe Biden";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "John Kerry/John Edwards";
                }
                else {
                    if (DemPrimary < Radicalism - 20*Wank && Party == 'R'){
                        DemCandidate = "Barack Obama/Joe Biden";
                    }
                    else {
                        DemCandidate = "Hillary Clinton/John Kerry";
                    }
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank){
            RepCandidate = "Rudolph Giuliani/Alan Keyes";
        }
        else {
            if (RepPrimary > 100 - Radicalism - 20*Wank){
                RepCandidate = "Ron Paul/Douglas Wead";
            }
            else {
                RepCandidate = "John McCain/Sarah Palin";
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Michael Badnarik/Richard Campagna";
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2009-2013: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2009-2013: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2009-2013: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2009-2013: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2009-2013: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
void Y2012 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    //Disaster chance
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true;
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Bernie Sanders/Elizabeth Warren";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "John Wolfe Sr./Randall Terry";
                }
                else {
                    DemCandidate = "Hillary Clinton/Chris Dodd";
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank && Party != 'R'){
            RepCandidate = "Michele Bachmann/Fred Karger";
        }
        else {
            if (RepPrimary > 100 - Radicalism - 20*Wank){
                RepCandidate = "Newt Gingrich/Rick Perry";
            }
            else {
                if (DisasterEffect == -1){
                    RepCandidate = "Rick Santorum/Buddy Roemer";
                }
                else {
                    RepCandidate = "Mitt Romney/Paul Ryan";
                }
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        ThirdCandidate = "Gary Johnson/Jim Gray";
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2013-2017: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2013-2017: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2013-2017: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2013-2017: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2013-2017: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
void Y2016 (string &President, char &Party, double Wank, double DisasterChance, double Radicalism, int TermLimit, int &TermNumber){
    string DemCandidate, RepCandidate, ThirdCandidate;
    bool IsThirdPartyRunning;
    int TheElection, Disasterroll, DisasterEffect;
    bool NoPresident;
    //Disaster chance
    Disaster (Disasterroll, DisasterEffect, Party, DisasterChance);
    //Term check
    if (TermNumber < TermLimit){
        bool NoPresident = true;
    }
    else {
        NoPresident = false;
        TermNumber = 0;
    }
    //Democratic Primary
    if (Party == 'D' && NoPresident){
        DemCandidate = (string)President;
    }
    else {
        int DemPrimary = rand() % 100 + 1;
        if (DemPrimary < Radicalism - 20*Wank){
            DemCandidate = "Bernie Sanders/Elizabeth Warren";
        }
        else {
                if (DemPrimary > 100 - Radicalism - 20*Wank){
                    DemCandidate = "Martin O'Malley/Randall Terry";
                }
                else {
                    if (DisasterChance == 1){
                        DemCandidate = "Nancy Pelosi/Julian Castro";
                    }
                    else {
                        DemCandidate = "Hillary Clinton/Tim Kaine";
                    }
                }
        }
    }
    //Republican Primary
    if (Party == 'R' && NoPresident){
        RepCandidate = President;
    }
    else {
        int RepPrimary = rand() % 100 + 1;
        if (RepPrimary < Radicalism - 20*Wank && Party == 'R'){
            RepCandidate = "Marco Rubio/Jim Gilmore";
        }
        else {
            if (RepPrimary < Radicalism - 20*Wank && Party != 'R'){
                RepCandidate = "Carly Fiorina/Jim Gilmore";
            }
            else {
                if (RepPrimary > 100 - Radicalism - 20*Wank && DisasterEffect == 1){
                    RepCandidate = "Rand Paul/Mike Pence";
                }
                else {
                    if (RepPrimary > 100 - Radicalism - 20*Wank){
                        RepCandidate = "Ted Cruz/Chris Christie";
                    }
                    else {
                        if (Party == 'R'){
                            RepCandidate = "John Kasich/Lindsey Graham";
                        }
                        else {
                            RepCandidate = "Donald Trump/Mike Pence";
                        }
                    }
                }
            }
        }
    }
    //Third Party Selection
    int ThirdParty = rand() % 100 + 1;
    if (ThirdParty < Radicalism + 20*abs(DisasterEffect)){
        IsThirdPartyRunning = true;
        if (DemCandidate != "Bernie Sanders/Elizabeth Warren"){
            ThirdCandidate = "Bernie Sanders/Xavier Becerra";
        }
        else {
            ThirdCandidate = "Gary Johnson/William Weld";
        }
    }
    else { IsThirdPartyRunning = false; }
    //The Election
    if (IsThirdPartyRunning){
        TheElection = rand() % 100 + 1;
        if (TheElection > 54 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2017-: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
            cout << "          " << ThirdCandidate << " (Independent)" << endl;
        }
        else {
            if (TheElection < 46 - 20*Wank - 20*DisasterEffect){
                if (President == DemCandidate){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2017-: " << DemCandidate << " (Democratic)" << endl;
                President = DemCandidate;
                Party = 'D';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << ThirdCandidate << " (Independent)" << endl;
            }
            else {
                if (Party == 'T'){ TermNumber++; }
                else { TermNumber = 1; }
                cout << "2017-: " << ThirdCandidate << " (Independent)" << endl;
                President = ThirdCandidate;
                Party = 'T';
                cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
                cout << "          " << DemCandidate << " (Democratic)" << endl;
            }
        }
    }
    else {
        TheElection = rand() % 100 + 1;
        if (TheElection > 50 - 20*Wank - 20*DisasterEffect){
            if (President == RepCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2017-: " << RepCandidate << " (Republican)" << endl;
            President = RepCandidate;
            Party = 'R';
            cout << "Defeated: " << DemCandidate << " (Democratic)" << endl;
        }
        else {
            if (President == DemCandidate){ TermNumber++; }
            else { TermNumber = 1; }
            cout << "2017-: " << DemCandidate << " (Democratic)" << endl;
            President = DemCandidate;
            Party = 'D';
            cout << "Defeated: " << RepCandidate << " (Republican)" << endl;
        }
    }
}
