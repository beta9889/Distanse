
#include <iostream>
#include <string>
#include <TGUI/TGUI.hpp>
#ifndef Character_H
#define Character_H
using namespace std;
class Character
{
public :
    string name;
    void setstats(string chara, int str, int dex);
    void changehealth(int dmg, tgui::Gui& gui);
    void showstats();
private :
    int health;
    int strenght;
    int dexterity;

    void gameover(tgui::Gui& gui);
};

#endif
