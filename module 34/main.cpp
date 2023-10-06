#include <iostream>
#include <type_traits>
#include <concepts>
#include <string>
template <typename T>
concept ComplexConcept = !std::has_virtual_destructor<T>::value &&
                         requires(const T val) {
                             {
                                 val.hash()
                             }
                             -> std::convertible_to<long>;
                             {
                                 val.toString()
                             }
                             -> std::convertible_to<std::string>;
                         };
struct User
{
    int num{0};

    long hash() const
    {
        return (long)num;
    }

    std::string toString() const
    {
        return std::to_string(num);
    }

};

struct User1
{
    int num{0};
    long hash() const
    {
        return (long)num;
    }
    virtual ~User1(){};
};

struct User2
{
    int num{0};
    long hash() const
    {
        return (long)num;
    }
    std::string toString() const
    {
        return std::to_string(num);
    }
    virtual ~User2(){};
};

struct User3
{
    int num{0};

    std::string toString() const
    {
        return std::to_string(num);
    }
    virtual ~User3(){};
};

void testFunction(ComplexConcept auto &val)
{
    std::cout << val.hash() << "\n";
    std::cout << val.toString() << "\n";
}

int main(int argc, char *argv[])

{
    User us;
    User1 us1;
    User2 us2;
    User3 us3;
    us.num = 15;
    testFunction(us);
    return 0;
}
