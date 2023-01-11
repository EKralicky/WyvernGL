#include "GameWindow.h"
#include "render/Renderer.h"
#include "event/Event.h"
#include "Wyvern/event/KeyEvent.h"
#include "Wyvern/event/MouseEvent.h"
#include "event/ApplicationEvent.h"

namespace Wyvern {

    GameWindow::GameWindow(const GameWindowConfiguration& config)
    {
        initWindow(config);
    }

    GameWindow::~GameWindow()
    {
    }

    void GameWindow::initWindow(const GameWindowConfiguration& config)
    {
        // Initialize window data -- this can be retrieved in GLFW callbacks with the glfwGetWindowUserPointer
        // Make sure to cast to WindowData&
        windowData.windowName = config.windowName;
        windowData.windowWidth = config.windowWidth;
        windowData.windowHeight = config.windowHeight;
        windowData.verticalSyncEnabled = true; // defualts to true

        /* Initialize the library */
        if (!glfwInit()) {
            std::cout << "Unable to initialize GLFW";
            ASSERT(false);
        }

        // GLFW version 3.3 (major.minor)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Multisampling (MSAA antialiasing)
        glfwWindowHint(GLFW_SAMPLES, 4);

        /* Create a windowed mode window and its OpenGL context */
        m_window = glfwCreateWindow(windowData.windowWidth, windowData.windowHeight, windowData.windowName, NULL, NULL);
        if (!m_window)
        {
            glfwTerminate();
            std::cout << "Unable to initialize Window";
            ASSERT(false);
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &windowData);
        setVSync(true);

        // Setup GLFW callbacks
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.eventCallbackFn(event);
            });

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowResizeEvent event(width, height);
                data.windowWidth = width;
                data.windowHeight = height;
                data.eventCallbackFn(event);
            });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) 
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseMovedEvent event(xpos, ypos);
                data.eventCallbackFn(event);
            });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseScrolledEvent event(xoffset, yoffset);
                data.eventCallbackFn(event);
            });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                
                switch (action)
                {

                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, false); // not repeated by default
                    data.eventCallbackFn(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.eventCallbackFn(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true); // repeating
                    data.eventCallbackFn(event);
                    break;
                }
                default:
                    throw std::runtime_error("Invalid Key Action: " + action);
                }
            });

        initGlew();
    }

    void GameWindow::updateDeltaTime()
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        m_deltaTime = currentFrame - m_lastFrameTime;
        m_lastFrameTime = currentFrame;
    }

    void GameWindow::setVSync(bool enabled)
    {
        glfwSwapInterval(enabled);
        windowData.verticalSyncEnabled = enabled;
    }

    void GameWindow::onUpdate()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    void GameWindow::initGlew() {
        if (glewInit() != GLEW_OK)
        {
            std::cout << "Unable to initialize GLEW";
            ASSERT(false);
        }

        GLCall(glEnable(GL_DEPTH_TEST));
        GLCall(glEnable(GL_MULTISAMPLE));
        GLCall(glEnable(GL_CULL_FACE));
        GLCall(glCullFace(GL_BACK));
        GLCall(glFrontFace(GL_CW)); // clockwise = shown
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }
    
    /// <summary>
    /// Valid Parameters:<para />
    /// GLFW_CURSOR_DISABLED<para />
    /// GLFW_CURSOR_NORMAL<para />
    /// </summary>
    /// <param name="mode"></param>
    void GameWindow::setCursorMode(int mode)
    {
        glfwSetInputMode(m_window, GLFW_CURSOR, mode);
    }

}


