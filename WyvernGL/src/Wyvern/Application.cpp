#include "Application.h"
#include "EntryPoint.h"
#include "Core.h"

#include "Wyvern.h"
#include "Wyvern/render/Shader.h"
#include "Wyvern/voxel/cube.h"
#include "Wyvern/render/VertexBufferLayout.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


namespace Wyvern {
    // Member, or non-static functions are slightly different than static functions as they have one more
    // implicit agument: this. The this "argument" is a pointer to the instance use to call the function.
    // In order for us to create an std::function out of a member function, we need to bind the function
    // with an instance of a class that the member function belongs to. (in this case its "this" because we are in the class of the member function)
    // We also need to use placeholders for any explicit parameters defined in the member function we are defining.
    // Now, c++ can call the function because it knows what instance it belongs to and what explicit parameters exist.
    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Wyvern::Application::Application()
        :m_running(true)
	{
        s_Instance = this; // For singleton
        m_gameWindow = new GameWindow(); // Using default params
        m_gameWindow->setVSync(true);
        m_gameWindow->setEventCallback(BIND_EVENT_FN(Application::onEvent));
        //m_camera = new Camera(glm::vec3(0, 0, 0), 0.1f);
        m_player = new Player();
        // Setup default keymap
        UserInput::setDefaultKeyBindings();
	}

	Wyvern::Application::~Application()
	{
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_gameWindow->getGLFWWindow());
        glfwTerminate();

        delete m_player;
		//delete m_camera;
		delete m_gameWindow;
        delete m_renderer;
	}

    void Application::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
        dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT_FN(Application::onMouseMoved));
        dispatcher.dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::onKeyPressed));
        dispatcher.dispatch<KeyReleasedEvent>(BIND_EVENT_FN(Application::onKeyReleased));
    }

    bool Application::onWindowClose(WindowCloseEvent& e)
    {
        m_running = false;
        return true; // Handled
    }

    bool Application::onMouseMoved(MouseMovedEvent& e)
    {
        m_player->getCamera()->processMouseInput(e.getXPos(), e.getYPos());
        return true; // Handled
    }

    bool Application::onKeyPressed(KeyPressedEvent& e)
    {
        Input keyboundInputType = UserInput::getKeyBinding(e.getKeycode());
        m_player->handleInput(keyboundInputType);
        return true;
    }

    bool Application::onKeyReleased(KeyReleasedEvent& e)
    {
        return true;
    }

    void generateMesh(std::vector<Cube>& cubes, float* outPositions) {
        std::vector<float>* finalAttributes = new std::vector<float>;
        std::cout << cubes.size();
        for (Cube c : cubes) {
            std::vector<float> cubeMesh = c.generateCubeMesh();
            finalAttributes->insert(finalAttributes->end(), cubeMesh.begin(), cubeMesh.end());
        }
        std::copy(finalAttributes->begin(), finalAttributes->end(), outPositions);
        delete finalAttributes;
    }

    void generateCubeIndexBuffer(long size, unsigned long* outIndices) {
        std::vector<unsigned long>* finalIndices = new std::vector<unsigned long>;
        for (long i = 0; i < size; i++) {
            std::vector<unsigned long> indices{
                //front
                0, 1, 2,
                2, 1, 3,
                //back 
                4, 5, 6,
                6, 5, 7,
                //top
                8, 9, 10,
                10, 9, 11,
                //bottom
                12, 13, 14,
                14, 13, 15,
                //left
                16, 17, 18,
                18, 17, 19,
                //right
                20, 21, 22,
                22, 21, 23,
            };
            std::for_each(indices.begin(), indices.end(), [i](unsigned long& d) { d += 24 * i; });
            finalIndices->insert(finalIndices->end(), indices.begin(), indices.end());
        }
        std::copy(finalIndices->begin(), finalIndices->end(), outIndices);
        delete finalIndices;
    }

    std::vector<Cube> getCubesFlat(int areaSideLength) {
        std::vector<Cube> cubes;
        long quarter = glm::floor(areaSideLength / 2);
        for (long x = -quarter; x <= quarter; x++) {
            for (long z = -quarter; z <= quarter; z++) {
                long yfunc = glm::round((5 * glm::sin(0.1 * x)) * (5 * glm::sin(0.1 * z)));
                float color = std::max(0.3f, std::min((float)(abs(x + (z % 2)) % 2), 0.5f));
                //cubes.push_back(Cube(glm::vec3(x, yfunc, z), glm::vec4(color, color, color, 1.0)));
                cubes.push_back(Cube(glm::vec3(x, 0, z), glm::vec4(1.0, 1.0, 1.0, 1.0)));
            }
        }
        return cubes;
    }

	void Application::run()
	{
        while (m_running) {
            //================
            // 3D RENDERING  
            //================
            const unsigned long areaSideLength = 101;
            const unsigned long cubeCount = glm::pow(areaSideLength, 2);

            std::vector<Cube> cubes = getCubesFlat(areaSideLength);



            float linePositions[] = {

                // -x
                -50.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f,
                // +x
                50.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 255.0f,

                // -z
                0.0f, 0.0f, -50.0f, 0.0f, 0.0f, 255.0f,
                0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 255.0f,
                // +z
                0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 255.0f,
                0.0f, 0.0f, 50.0f, 0.0f, 255.0f, 255.0f,

                // -y
                0.0f, -5.0f, 0.0f, 0.0f, 255.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f, 255.0f, 0.0f,
                // +y
                0.0f, 0.0f, 0.0f, 255.0f, 255.0f, 0.0f,
                0.0f, 5.0f, 0.0f, 0.0f, 255.0f, 0.0f
            };

            // Lighting
            // Generate Cube
            int lightingCubeCount = 1;
            glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
            glm::vec3 lightPosition = glm::vec3(0.0, 0.0, 0.0);
            std::vector<Cube> lightingCubes = { Cube(lightPosition, glm::vec4(lightColor, 1.0f)) };

            VertexArray lightingVA;
            float* lightingMesh = new float[lightingCubeCount * 24 * 10];
            unsigned long* lightingIndexBuffer = new unsigned long[lightingCubeCount * 36];
            generateMesh(lightingCubes, lightingMesh);
            generateCubeIndexBuffer(lightingCubeCount, lightingIndexBuffer);

            VertexBuffer lightingVB(lightingMesh, lightingCubes.size() * 24 * 10 * sizeof(float));
            VertexBufferLayout lightLayout;

            lightLayout.Push<float>(3);
            lightLayout.Push<float>(3);
            lightLayout.Push<float>(4);
            lightingVA.AddBuffer(lightingVB, lightLayout);
            // Index buffer for cubes
            IndexBuffer lightingIB(lightingIndexBuffer, lightingCubeCount * 36);
            Shader lightingShader("res/shaders/static.shader");





            // X Y Z lines
            VertexArray lineVA;
            VertexBuffer lineVB(linePositions, 6 * 12 * sizeof(float));
            VertexBufferLayout lineBufferLayout;

            lineBufferLayout.Push<float>(3);
            lineBufferLayout.Push<float>(3);
            lineVA.AddBuffer(lineVB, lineBufferLayout);





            // Cubes
            VertexArray cubeVA;             //verts // attributes
            float* mesh = new float[cubeCount * 24 * 10];
            unsigned long* indexBuffer = new unsigned long[cubeCount * 36];
            generateMesh(cubes, mesh);
            generateCubeIndexBuffer(cubeCount, indexBuffer);

            VertexBuffer cubeVB(mesh, cubes.size() * 24 * 10 * sizeof(float));
            VertexBufferLayout layout;

            layout.Push<float>(3);
            layout.Push<float>(3);
            layout.Push<float>(4);
            cubeVA.AddBuffer(cubeVB, layout);
            // Index buffer for cubes
            IndexBuffer cubeIB(indexBuffer, cubeCount * 36);

            glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)16 / (float)9, 0.1f, 1000.0f);

            // Bind 3D shader
            Shader shader("res/shaders/scene.shader");

            //=========================
            // 2D RENDERING (CROSSHAIR)
            //=========================

            float crosshairPositions[] = {
                -0.05, 0,
                0.05, 0,
                0, -0.05,
                0,  0.05
            };

            VertexArray chva; // CrossHair va
            VertexBuffer chvb(crosshairPositions, 2 * 4 * sizeof(float));
            VertexBufferLayout crosshairBufferLayout;
            crosshairBufferLayout.Push<float>(2);
            chva.AddBuffer(chvb, crosshairBufferLayout);

            Shader shader2D("res/shaders/overlay.shader");
            glm::mat4 orthoProj = glm::ortho(-8.0f, 8.0f, -4.5f, 4.5f); // 2d orthographic proj with 16:9

            // IMGUI init
            const char* glslVersion = "#version 430";
            ImGui::CreateContext();
            ImGui_ImplGlfw_InitForOpenGL(m_gameWindow->getGLFWWindow(), true);
            ImGui_ImplOpenGL3_Init(glslVersion);
            ImGui::StyleColorsDark();

            float r = 0.0f;
            float increment = 0.005f;

            glm::vec3 translationA(0, 0, 0);
            glm::vec3 translationB(0, 0, 0);
            GLenum drawType = GL_TRIANGLES;
            bool wireframeEnable = false;
            bool mxaaEnable = true;
            bool tildeDown = false;

            m_player->getCamera()->movementSpeed(20.0f);
            /* Loop until the user closes the window */
            while (!glfwWindowShouldClose(m_gameWindow->getGLFWWindow()))
            {
                m_gameWindow->updateDeltaTime();
                //if (m_camera->canMove()) {
                //    m_camera->processKeyboardInput(m_gameWindow->getGLFWWindow(), m_gameWindow->deltaTime());
                //}


                glm::mat4 view = m_player->getCamera()->getViewMatrix();


                /* Render here */
                m_renderer->Clear();
                m_renderer->ClearDepthBuffer();

                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();

                shader.Bind();
                shader.SetUniform4f("u_LightColor", lightColor.r, lightColor.g, lightColor.b, 1.0f); // sets color of light cube specified in the lightingVA
                shader.SetUniform4f("u_LightPos", lightPosition.x, lightPosition.y, lightPosition.z, 1.0f); // sets color of light cube specified in the lightingVA
                glm::vec3 cameraPos = m_player->getCamera()->position();
                shader.SetUniform4f("u_ViewPos", cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
                cubeVA.Bind();
                {
                    glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
                    glm::mat4 mvp = proj * view * model;
                    shader.SetUniformMat4f("u_MVP", mvp);
                    shader.SetUniformMat4f("u_Model", model);
                    m_renderer->DrawIndices(cubeVA, cubeIB, shader, drawType);
                }
                //gridlines
                lineVA.Bind();
                {
                    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
                    glm::mat4 mvp = proj * view * model;
                    shader.SetUniformMat4f("u_MVP", mvp);
                    shader.SetUniformMat4f("u_Model", model);
                    m_renderer->DrawArrays(lineVA, shader, GL_LINES);
                }
                lightingShader.Bind();
                lightingVA.Bind();
                {
                    glm::mat4 model = glm::translate(glm::mat4(1.0f), lightPosition);
                    glm::mat4 mvp = proj * view * model;
                    lightingShader.SetUniformMat4f("u_MVP", mvp);
                    m_renderer->DrawIndices(lightingVA, lightingIB, lightingShader, drawType);
                }
                //crosshair
                shader2D.Bind();
                chva.Bind();
                {
                    shader2D.SetUniformMat4f("u_Ortho", orthoProj);
                    m_renderer->DrawArrays(chva, shader2D, GL_LINES);
                }


                //IMGui movement controls
                {
                    ImGui::SliderFloat("Camera Movement Speed", m_player->getCamera()->movementSpeed(), 10.0f, 100.0f);
                    ImGui::SliderFloat3("Light Position", &lightPosition.x, -250.0f, 250.0f);
                    ImGui::ColorEdit3("Light Color", &lightColor.x);
                    ImGui::Checkbox("Toggle Wireframe", &wireframeEnable);
                    ImGui::Checkbox("MXAA", &mxaaEnable);
                    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                }
                if (wireframeEnable) {
                    drawType = GL_LINES;
                }
                else
                {
                    drawType = GL_TRIANGLES;
                }

                if (mxaaEnable) {
                    GLCall(glEnable(GL_MULTISAMPLE));
                }
                else
                {
                    GLCall(glDisable(GL_MULTISAMPLE));
                }

                m_player->handleInput(Input::POLL_MOVEMENT); // Poll for movement every frame
                m_player->updateCamera();
                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
                m_gameWindow->onUpdate();
                m_player->decreaseVelocity(0.05f);
            }

        }
    }    
}


Wyvern::Application* Wyvern::createApplication()
{
	return new Application();
}



