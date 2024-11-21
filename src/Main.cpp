#include <Core/System.hpp>
#include <Graphic/Window.hpp>
#include <Nodes/SceneTree.hpp>

#include <Global.hpp>
#include <Graphic/Material.hpp>
#include <Core/Resource.hpp>
#include <Types.hpp>

using std::array;
using std::vector;

SceneTree *sceneTree;
Window *window;

int main(int argc, char **argv)
{
    sceneTree = new SceneTree();
    uvec2 windowSize = config->windowSize();
    window = new Window(windowSize.x, windowSize.y, config->gameTitle());

    window->setViewportUpdateCallback([](uint16_t x, uint16_t y, uint16_t w, uint16_t h)
                                      { 
                                          sceneTree->viewportUpdate(x, y, w, h);
                                      });
    window->init_window();

    sceneTree->init();

    const double FRAME_RATE = config->fps();
    const double FRAME_TIME = 1.0f / FRAME_RATE;

    double time_start = System::getTime();
    double time_previous = time_start;

    float last_second = System::getTime();

    while (!window->isClosing())
    {
        double current_time = System::getTime();
        double elapsed_time = current_time - time_previous;
        window->processInput();
        if (elapsed_time >= FRAME_TIME)
        {
            sceneTree->delta = elapsed_time;
            time_previous = current_time;

            sceneTree->mainUpdate();
            sceneTree->physikUpdate();
            sceneTree->renderUpdate();
            window->swapBuffers();
        }

        window->pollEvents();
    }
    window->terminate();
    return 0;
}
