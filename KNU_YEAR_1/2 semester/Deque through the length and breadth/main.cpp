#include <iostream>

#include "Application.h"

int main()
{
    Application app;

    switch (Application::choice("Mode", 3, "Demo", "Interactive", "Benchmark"))
    {
        case 1 :
        {
            app.DemoMode();
            break;
        }
        case 2 :
        {
            app.InteractiveMode();
            break;
        }
        case 3 :
        {
            app.BenchmarkMode();
            break;
        }
        default:
        {
            exit(0);
        }
    }

    return 0;
}
