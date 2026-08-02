#include<iostream>
#include "includes/datatypes/RString.hpp"

int
main ()
{
    RString s ("I am raunit") ;
    RString ss ("Shrivastava");
    RString res;

    res = s + ss;

    std::cout << s.GetPointer() << std::endl;

    s.SetString ("Now I am not");

    std::cout << s.GetPointer() << std::endl;

    std::cout << res.GetPointer() << std::endl;

    return 0;
}