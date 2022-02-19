#include"nepch.h"
#include "Application.h"

namespace Ngine {

    /*
    * CONSTRUCTOR/DESTRUCTOR
    */
	Application::Application()
	{
        this->InitWindow();
        this->InitStates();

        NE_CORE_INFO("WINDOW INITIALIZED");
	}

	Application::~Application()
	{
        delete this->window;
        while (!this->states.empty())
        {
            delete this->states.top();
            this->states.pop();
        }  
	}

    /*
    * INITIALIZERS
    */
    void Application::InitWindow()
    {
        /*Initialize Window with window.ini settings*/
        std::ifstream ifs("conf/window.ini");
        std::string title = "None";
        sf::VideoMode window_bounds(800, 600);
        unsigned framerate_limit = 120;
        bool vertical_sync_enabled = false;
        if (ifs.is_open())
        {
            std::getline(ifs, title);
            ifs >> window_bounds.width >> window_bounds.height;
            ifs >> framerate_limit;
            ifs >> vertical_sync_enabled;
        }
        ifs.close();

        /*Implement window settings*/
        this->window = new sf::RenderWindow(window_bounds, title);
        this->window->setFramerateLimit(framerate_limit);
        this->window->setVerticalSyncEnabled(vertical_sync_enabled);
    }

    void Application::InitStates()
    {
        this->states.push(new GameState(this->window));
    }

    /*
    * FUNCTIONS
    */
	void Application::Run()
	{
        while (this->window->isOpen())
        {
            UpdateDt();
            Update();
            Render();
        }
	}

    void Application::UpdateDt()
    {
        /*Updates delta time with time taken to update/render 1 frame*/
        dt = dtClock.restart().asSeconds();

    }

    void Application::Update()
    {
        UpdateSFMLEvents();

        // If state stack is not empty then call update func on top element
        if (!this->states.empty())
        {
            this->states.top()->Update(this->dt);
            // Check if quitting app
            if (this->states.top()->isQuitting())
            {
                this->states.top()->EndState();
                delete this->states.top();
                this->states.pop();
            }
        }
        else
        {
            // Exit App
            this->EndApp();
            this->window->close();
        }
    }

    void Application::UpdateSFMLEvents()
    {
        while (this->window->pollEvent(sfEvent))
        {
            if (sfEvent.type == sf::Event::Closed)
            {
                this->window->close();
            }
        }
    }

    void Application::Render()
    {
        this->window->clear();

        /***Render***/

        // If state stack is not empty then call render func on top element
        if (!this->states.empty())
        {
            this->states.top()->Render();
        }

        this->window->display();
    }

    void Application::EndApp()
    {
        NE_CORE_WARN("Shutting Down...");
    }
}
