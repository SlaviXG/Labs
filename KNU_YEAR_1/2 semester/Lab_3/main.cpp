#include <iostream>

#include "App.h"

int main()
{
    App app;

    switch (App::choice("Mode", 2, "Demo", "Benchmark"))
    {
        case 1 :
        {
            app.DemoMode();
            break;
        }
        case 2 :
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