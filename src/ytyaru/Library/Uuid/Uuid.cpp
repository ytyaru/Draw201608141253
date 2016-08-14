#include "Uuid.h"

using std::basic_string;

namespace ytyaru {
namespace Library {
namespace Uuid {
basic_string<TCHAR> Get()
{
	// 文字セットにより型を変更する
	#if defined(_UNICODE) || defined(UNICODE)
	RPC_WSTR p;
	#else
	RPC_CSTR p;
	#endif
			
	UUID uuid;
	RPC_STATUS res;
			
	// UUID生成
	res = ::UuidCreate(&uuid);
	if (res == RPC_S_OK) {}
	else if (res == RPC_S_UUID_LOCAL_ONLY) { throw "::UuidCreate関数失敗。RPC_S_UUID_LOCAL_ONLY。"; }
	else if (res == RPC_S_UUID_NO_ADDRESS) { throw "::UuidCreate関数失敗。RPC_S_UUID_NO_ADDRESS。"; }
	else {}

	// UUIDを文字列にする
	res = ::UuidToString(&uuid, &p);
	if (res == RPC_S_OK) {}
	else if (res == RPC_S_OUT_OF_MEMORY) { throw "::UuidToString関数失敗。RPC_S_OUT_OF_MEMORY。"; }
	else {}
			
	// 文字セットにより型をキャストする
	// とくにMBCSの場合、RPC_CSTRはunsigned char*である。
	// MBCSの場合、TCHARはcharになるため、char型にキャストする必要がある。
	#if defined(_UNICODE) || defined(UNICODE)
	basic_string<TCHAR> str = reinterpret_cast<WCHAR*>(p);
	#else
	basic_string<TCHAR> str = reinterpret_cast<CHAR*>(p);
	#endif
			
	::RpcStringFree(&p);

	return str;
}
}
}
}
