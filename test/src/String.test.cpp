#include <Core/String.hpp>
#include <Core/Log.hpp>
#include <Test.hpp>

bool test_split()
{
    return true;
}

bool test_compare()
{
    String a = "Hallo";
    String b = "Hallo";

    RET_IF_CMP_FAIL(a, b)
    RET_IF_NOT_CMP_FAIL(a, String("Hallo2"))

    RET_IF_CMP_FAIL(a, "Hallo")
    RET_IF_NOT_CMP_FAIL(a, "Hallo2")

    Log::info("test_compare is ok");
    return true;
}

bool test_replace()
{
    String str = "Hallo=";
    RET_IF_CMP_FAIL(str.contain(" "), false)
    str = str.replace("=", " ");    
    RET_IF_CMP_FAIL(str.contain(" "), true)
    RET_IF_CMP_FAIL(str.contain("A"), false)
    str = str.replace(" ", "A");    
    RET_IF_CMP_FAIL(str.contain("A"), true)
    
    Log::info("test_replace is ok");
    return true;
}

bool test_contain()
{

    Log::info("test_contain is ok");
    return true;
}

bool test_assignment()
{

    String a = "Hallo Welt";
    RET_IF_CMP_FAIL(a, "Hallo Welt")

    String b = "";
    RET_IF_CMP_FAIL(b, "")

    b = a;
    RET_IF_CMP_FAIL(b, "Hallo Welt")
    RET_IF_CMP_FAIL(b, a)

    String c = "Hallo";
    RET_IF_CMP_FAIL(c, "Hallo")
    c = c + " Welt";
    RET_IF_CMP_FAIL(c, "Hallo Welt")
    c = c + '.';
    RET_IF_CMP_FAIL(c, "Hallo Welt.")

    String d = "Hallo";
    RET_IF_CMP_FAIL(d, "Hallo")
    d += " Welt";
    RET_IF_CMP_FAIL(d, "Hallo Welt")

    String concat = "I try";
    concat += String(" to concat") + " the text";
    RET_IF_CMP_FAIL(concat, "I try to concat the text")
    RET_IF_NOT_CMP_FAIL(concat, "i try to concat the text")

    Log::info("test_assigment is ok");
    return true;
}

int main_String(const char *type)
{

    Log::info("====================");
    Log::info(type);
    Log::info("====================");
    assert(test_compare());
    assert(test_assignment());
    assert(test_split());
    assert(test_replace());
    assert(test_contain());

    Log::info(type);
    Log::info("Test ends successful");
    return 0;
}