#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <sstream>

#include "GLCore/Renderer.h"
#include "GLCore/GLObject.h"
#include "GLCore/GLErrorManager.h"
#include "GLCore/Camera.h"

#include "util/Status.h"
#include "util/Logger.h"

#include "util/helper/GLFWHelper.h"
#include "util/helper/ImGuiHelper.h"
#include "util/WindowInfo.h"

Camera* cam = nullptr;

int main(void)
{
    STATUS status;
    GLFWwindow* window = InitialiseGLFWWindow(status);

    if (status == ERR)
    {
        glfwTerminate();
        return -1;
    }

    //glfwSetCursorPosCallback(window, mouse_callback);
    //glfwSetScrollCallback(window, scroll_callback);

    {
        ImGuiHelper::initImGui(window);

        Logger::Logger logger;
        logger.log("Initialised Log");

        cam = new Camera{ window };

        Renderer r;
        WindowInformation wi{};

        float deltaTime = 0.0f;	// Time between current frame and last frame
        float lastFrame = 0.0f; // Time of last frame

        while (!glfwWindowShouldClose(window))
        {
            float currentFrame = (float)glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            wi.UpdateFps(deltaTime);
            r.Clear();

            ImGuiHelper::beginFrame();
            ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

            cam->processKeyboardInput(deltaTime);
            cam->updateImGui();

            wi.ShowInformation();

            logger.showLog();

            ImGuiHelper::endFrame();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    ImGuiHelper::terminateImGui();

    glfwTerminate();
    return 0;
}
