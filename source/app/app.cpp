#include "PythonInclude.h"
#include <stdio.h>

#include "Day1.h"
#include "Day2.h"

void say_something ()
{
    printf ("Say Something\n");
}

static int COUNTER = 0;

void set_counter (int count)
{
    COUNTER = count;
}

struct MyData
{
    float x;
};

PYBIND11_EMBEDDED_MODULE (embeddedmodule, module)
{
    module.doc () = "Embedded Module";
    module.def ("say_something", &say_something);
    module.def ("set_counter", &set_counter);

    pybind11::class_<MyData>(module, "MyData")
    .def_readwrite ("x", &MyData::x);
}

int main ()
{
    pybind11::scoped_interpreter guard{};
    auto PythonHelperModule = pybind11::module::import ("PythonHelperModule");

    Day1 day1;
    day1.Run(PythonHelperModule);

    Day2 day2;
    day2.Run(PythonHelperModule);
    
    return 0;
    
}
