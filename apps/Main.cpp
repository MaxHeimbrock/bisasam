#include "crow.h"
// #include "../extern/Crow/include/crow.h" for using extern header include folder

int main()
{
    crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/test/")([](){
        return "Hello Max from Crow";
    });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}