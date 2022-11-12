#include <algorithm>
#include <iostream>

std::string convert(std::string const& text)
{
    std::string result_text;
    result_text.resize(text.size());

    result_text[0] = '(';
    for (size_t i = 1; i < text.size(); i++)
    {
        result_text[i] = '(';
        for (size_t j = i - 1; j != SIZE_MAX; j--)
        {
            if (tolower(text[j]) == tolower(text[i]))
            {
                result_text[j] = ')';
                result_text[i] = ')';
                break;
            }
        }
    }

    return result_text;
}

void test(std::string const& text, std::string const& test_result)
{
    const std::string result = convert(text);

    std::cout << text << std::endl;
    std::cout << result << std::endl;
    std::cout << (result == test_result ? "Success" : "Fail") << std::endl;
    std::cout << "----------------" << std::endl;
}

int main(int argc, char* argv[])
{
    test("din", "(((");
    test("recede", "()()()");
    test("Success", ")())())");
    test("(( @", "))((");

    return 0;
}
