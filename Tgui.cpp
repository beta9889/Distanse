#include <iostream>
#include <TGUI/TGUI.hpp>
#include <fstream>
void LoadWidgets( tgui::Gui& gui){
    

}
int main()
{
    sf::RenderWindow window{{800, 600}, "Window"};
    tgui::Gui gui{window}; // Create the gui and attach it to the window
    tgui::Button::Ptr button = tgui::Button::create("Submit");
    tgui::EditBox::Ptr editbox = tgui::EditBox::create();
    gui.add(button);
    gui.add(editbox, "name");
    button->setPosition("45%","60%");
    editbox->setPosition("40%","35%"); 
    button->setSize("10%", "5%");
    editbox->setSize("15%" , "10%");
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized){
		window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width),static_cast<float>(event.size.height))));
		gui.setView(window.getView());
	    }
            gui.handleEvent(event); // Pass the event to the widgets
        }


        window.clear();
        gui.draw(); // Draw all widgets
        window.display();
    }
    return EXIT_SUCCESS;
}
