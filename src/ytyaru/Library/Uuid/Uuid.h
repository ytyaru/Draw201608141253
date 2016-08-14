#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <Windows.h>
#include <tchar.h>
#include <string>

namespace ytyaru {
namespace Library {
namespace Uuid {
	std::basic_string<TCHAR> Get();
}
}
}
