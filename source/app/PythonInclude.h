#pragma once

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