#pragma once
#include "IDay.h"

class Day1 : public IDay
{
public:
    void Run(pybind11::module& PythonHelperModule) override;
};
