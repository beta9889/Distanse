#include <iostream>
#include <TGUI/TGUI.hpp>
#include <fstream>
void Startpage(tgui::Gui& gui){
    tgui::Button::Ptr New = tgui::Button::create("New Character");
    New-> setSize("25%", "25%");
    New-> setPosition("25%", "50%");
    gui.add(New, "new");
}
void NewStats(tgui::Gui& gui){
    
    tgui::Button::Ptr Submit = tgui::Button::create("Submit");
    Submit->setPosition("43%","60%");
    Submit->setSize("10%", "5%");
    gui.add(Submit); 

    tgui::EditBox::Ptr name = tgui::EditBox::create();
    name -> setDefaultText("Username");
    name->setSize("20%" , "5%");
    name->setPosition("40%","35%"); 
    gui.add(name, "name");
  
    tgui::EditBox::Ptr strenght = tgui::EditBox::create();
    strenght -> setDefaultText("Strenght");
    strenght -> setSize("10%", "5%");
    strenght->setPosition("45%", "40%");
    gui.add(strenght, "str");

    tgui::EditBox::Ptr dexterity = tgui::EditBox::create();
    dexterity-> setDefaultText("Dexterity");
    dexterity-> setSize("10%", "5%");
    dexterity->setPosition("45%","45%");
    gui.add(dexterity, "dex");

}
int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window}; // Create the gui and attach it to the window
    
    try{
    Startpage(gui); 
    }
    catch (const tgui::Exception& e){
	    std::cerr << "something went wrong :" << e.what() << std::endl;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized){

		window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width),
						                static_cast<float>(event.size.height))));
		gui.setView(window.getView());
	
	    //if (event.type ==sf
	    }
            gui.handleEvent(event); // Pass the event to the widgets
        }


        window.clear();
        gui.draw(); // Draw all widgets
        window.display();
    }
    return EXIT_SUCCESS;
}
