#include "nepch.h"
#include "Ngine/Core/Application.h"
#include "Ngine/Core/Log.h"

namespace Ngine {

#pragma region CONSTRUCTOR/DESTRUCTOR

	Application::Application()
	{
        this->InitVariables();
        this->InitWindow();
        this->InitKeys();
        this->InitStates();        
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

#pragma endregion

#pragma region INITIALIZERS

    void Application::InitVariables()
    {
        this->window = nullptr;
        this->fullscreen = false;
        this->dt = 0.f;
    }

    void Application::InitWindow()
    {
        /*Initialize Window with window.ini settings*/
        std::ifstream ifs("conf/window.ini");
        this->videoModes = sf::VideoMode::getFullscreenModes();

        std::string title = "None";
        sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();

        bool fullscreen = false;
        unsigned framerate_limit = 120;
        bool vertical_sync_enabled = false;
        unsigned antialiasing_level = 0;

        if (ifs.is_open())
        {
            std::getline(ifs, title);
            ifs >> window_bounds.width >> window_bounds.height;
            ifs >> fullscreen;
            ifs >> framerate_limit;
            ifs >> vertical_sync_enabled;
            ifs >> antialiasing_level;
        }
        ifs.close();

        /*Implement window settings*/
        this->fullscreen = fullscreen;
        this->windowSettings.antialiasingLevel = antialiasing_level;

        if (this->fullscreen)
        {
            this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
        }
        else 
        {
            this->window = new sf::RenderWindow(window_bounds, "", sf::Style::Titlebar | sf::Style::Close, windowSettings);
        }

        this->window->setFramerateLimit(framerate_limit);
        this->window->setVerticalSyncEnabled(vertical_sync_enabled);

        NE_CORE_WARN("WINDOW INITIALIZED");
    }

    void Application::InitStates()
    {
        // Push new state to the stack with required inputs
        this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));

        NE_CORE_WARN("STATES INITIALIZED");
    }

    void Application::InitKeys()
    {
        /*Pull supported keys from config file*/
        std::ifstream ifs("conf/supported_keys.ini");

        if (ifs.is_open())
        {
            std::string key = "";
            int keyValue = 0;
            while (ifs >> key >> keyValue)
            {
                this->supportedKeys[key] = keyValue;
            }   
        }
        ifs.close();
        /**************************************/

        NE_CORE_WARN("KEYS INITIALIZED");
    }

#pragma endregion

#pragma region FUNCTIONS

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

#pragma endregion

}
