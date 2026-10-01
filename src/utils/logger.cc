#include "utils/logger.h"

#if _WIN32
#include <windows.h>
void EnableUTF8Console() { SetConsoleOutputCP(CP_UTF8); }
#endif
