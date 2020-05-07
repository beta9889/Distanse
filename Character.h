#ifndef Character
#define Character
#include <iostream>
#include <string>
class Character{
public:
    string name;
    void setstats(string chara, int str, int dex);
    void changehealth(int dmg, tgui::Gui& gui);
    void showstats();
private:
    int health;
    int strenght;
    int dexterity;

    void gameover(tgui::Gui& gui);
};

#endif
