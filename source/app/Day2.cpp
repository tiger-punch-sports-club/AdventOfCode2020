#include "Day2.h"

#include <functional>
#include <pybind11/pybind11.h>

void Day2::Run(pybind11::module& PythonHelperModule)
{
    RunPart1(PythonHelperModule);
    RunPart2(PythonHelperModule);
}

void Day2::RunPart1(pybind11::module& PythonHelperModule)
{
    printf("Day2: RunPart1\n");

    const std::function<pybind11::object(const char*)> LoadFile = PythonHelperModule.attr("load_file");
    const auto Result = LoadFile("Day2.txt");
    auto FileContent = Result.cast<std::vector<std::string>>();

    // Parse file content

    int NumValidPasswords = 0;
    for(auto& Line : FileContent)
    {
        int Minimum;
        int Maximum;
        char SpecialChar;

        constexpr short MaxPasswordLength = 2049;
        char Password[MaxPasswordLength];
        memset(&Password, 0, MaxPasswordLength * sizeof(SpecialChar));

        sscanf(Line.c_str(), "%d-%d %c: %s\n", &Minimum, &Maximum, &SpecialChar, &Password);
        assert(Password[MaxPasswordLength - 1] == '\0' && "Password longer than MaxPasswordLength");

        int SpecialCharCount = 0;
        for(char* Char = &Password[0]; *Char != '\0'; Char++)
        {
            // if
            SpecialCharCount += *Char == SpecialChar; 
        }

        // if
        NumValidPasswords += SpecialCharCount >= Minimum && SpecialCharCount <= Maximum;
    }

    printf("Num valid passwords: %d\n", NumValidPasswords);
}

void Day2::RunPart2(pybind11::module& PythonHelperModule)
{
    printf("Day2: RunPart2\n");

    const std::function<pybind11::object(const char*)> LoadFile = PythonHelperModule.attr("load_file");
    const auto Result = LoadFile("Day2.txt");
    auto FileContent = Result.cast<std::vector<std::string>>();

    // Parse file content

    int NumValidPasswords = 0;
    for(auto& Line : FileContent)
    {
        int Minimum;
        int Maximum;
        char SpecialChar;

        constexpr short MaxPasswordLength = 2049;
        char Password[MaxPasswordLength];
        memset(&Password, 0, MaxPasswordLength * sizeof(SpecialChar));

        sscanf(Line.c_str(), "%d-%d %c: %s\n", &Minimum, &Maximum, &SpecialChar, &Password);
        assert(Password[MaxPasswordLength - 1] == '\0' && "Password longer than MaxPasswordLength");

        const bool SpecialCharAtMin = Password[Minimum - 1] == SpecialChar; 
        const bool SpecialCharAtMax = Password[Maximum - 1] == SpecialChar;

        // if
        NumValidPasswords += SpecialCharAtMin != SpecialCharAtMax;
    }

    printf("Num valid passwords: %d\n", NumValidPasswords);
}
