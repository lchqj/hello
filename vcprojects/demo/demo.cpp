// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include <hello/stdint.h>
#include <hello/inttypes.h>
#include <hello/utility/enum_string.h>


HELLO_ENUM_BEGIN(DeviceType)
ATM,
TVM,
OCC,
GAM,
HELLO_ENUM_END()

HELLO_ENUM_STR_BEGIN(DeviceType)
HELLO_ENUM_STR( ATM)
HELLO_ENUM_STR( TVM)
HELLO_ENUM_STR( OCC)
HELLO_ENUM_STR( GAM)
HELLO_ENUM_STR_END()

HELLO_ENUM_STR_IMPL(DeviceType)

int main()
{
    DeviceType::value type(DeviceType::GAM);
    auto s = type.c_str();
    return 0;
}

