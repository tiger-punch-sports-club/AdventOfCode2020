#pragma once

namespace pybind11 {
    class module;
}

class IDay
{
public:
    virtual ~IDay() = default;
    virtual void Run(pybind11::module& PythonHelperModule) = 0;
};
