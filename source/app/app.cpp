#if defined(_DEBUG)
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif
#include <functional>
#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <stdio.h>

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
    const auto test_python = pybind11::module::import ("test");

    const std::function<pybind11::object(const char*)> load_file = test_python.attr("load_file");
    const auto result = load_file("test.txt");

    auto file_content = result.cast<std::vector<std::string>>();

    int* numbers = static_cast<int*>(malloc(file_content.size() * sizeof(int)));
    int numbers_count = 0;
    for (auto& number_str : file_content)
    {
        numbers[numbers_count++] = std::stoi(number_str);
    }
    

    // {
    //     std::function<void(int)> XxX = std::function<void(int)>(load_file);
    //     std::function<void(const char*)> yyy = std::function<void(const char*)>(load_file);
    //     std::function<pybind11::object(int)> zzz = std::function<pybind11::object(int)>(load_file);
    //
    //     XxX(5);
    //     yyy("hip hip hura");
    //     auto res = zzz(55).cast<int>();
    //     printf("RES: %d\n", res);    
    //     auto result = load_file("Hello World!!");
    //     auto test = pybind11::str(result);
    //     std::string tt(test);
    //     printf ("Result: %s \n", tt.c_str());
    // }

    free(numbers);
    return 0;
}
