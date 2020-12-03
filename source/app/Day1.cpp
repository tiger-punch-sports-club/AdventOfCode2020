#include "Day1.h"
#include "PythonInclude.h"

void Day1::Run(pybind11::module& PythonHelperModule)
{
    // Read file
    const std::function<pybind11::object(const char*)> load_file = PythonHelperModule.attr("load_file");
    const auto result = load_file("Day1.txt");
    auto file_content = result.cast<std::vector<std::string>>();

    {   
        // Convert to numbers
        // vector and sort
        int* numbers = static_cast<int*>(malloc(file_content.size() * sizeof(int)));
        int numbers_count = 0;
        for (auto& number_str : file_content)
        {
            numbers[numbers_count++] = std::stoi(number_str);
        }
        
        int expenses = 0;
        bool done = false;
        for (int i = 0; i < numbers_count && !done; ++i)
        {
            for (int j = i + 1; j < numbers_count; ++j)
            {
                int num1 = numbers[i];
                int num2 = numbers[j];
                if (num1 + num2 == 2020)
                {
                    expenses = num1 * num2;
                    done = true;
                    break;
                }
            }

            done = i == numbers_count;
        }
    
        free(numbers);

        printf("expenses: %d \n", expenses);
    }
}
