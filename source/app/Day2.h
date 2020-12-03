#pragma once
#include <IDay.h>

class Day2 : public IDay
{
public:
    void Run(pybind11::module& PythonHelperModule) override;

private:
    static void RunPart1(pybind11::module& PythonHelperModule);
    static void RunPart2(pybind11::module& PythonHelperModule);
};
