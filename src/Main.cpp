#include <Core/System.hpp>
#include <Graphic/Window.hpp>
#include <Nodes/SceneTree.hpp>

#include <Global.hpp>

#include <Graphic/Material.hpp>
#include <Core/Ressource.hpp>

#include <Types.hpp>

using std::array;
using std::vector;

SceneTree tree;

int main()
{
    uvec2 windowSize = config->windowSize();
    Window window(windowSize.x, windowSize.y, config->gameTitle());
    window.init_window();

    tree.init();

    const double FRAME_RATE = config->fps();
    const double FRAME_TIME = 1.0f / FRAME_RATE;

    double time_start = System::getTime();
    double time_previous = time_start;

    float last_second = System::getTime();

    while (!window.isClosing())
    {
        double current_time = System::getTime();
        double elapsed_time = current_time - time_previous;
        window.processInput();
        if (elapsed_time >= FRAME_TIME)
        {
            tree.delta = elapsed_time;
            time_previous = current_time;

            tree.mainUpdate();
            tree.physikUpdate();
            tree.renderUpdate();
            window.swapBuffers();
        }

        window.pollEvents();
    }
    window.terminate();
    return 0;
}
