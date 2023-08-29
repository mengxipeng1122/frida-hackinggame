

#include <stdio.h>

extern "C" {
    void _frida_log(const char* p);
    void _frida_hexdump(void* p, unsigned int i);
}


//  log stuff
#define LOG_INFOS_WITH_N(N, fmt, args...)                         \
do{                                                               \
    char buff[N];                                                 \
    snprintf(buff, N,  fmt , ##args);                             \
    _frida_log(buff);                                    \
}while(0)

#define LOG_INFOS_WITH_N_FILE_LINE(N, fmt, args...)               \
LOG_INFOS_WITH_N(N, "[%s:%d] " fmt , __FILE__, __LINE__,  ##args);

#define LOG_INFOS(fmt, args...)  LOG_INFOS_WITH_N_FILE_LINE(0x800, fmt, ##args)

#define LOG_HEXDUMP(p, n) do {_frida_hexdump((void*)(p),n);} while(0)


////////////////////////////////////////////////////////////////////////////////
// stuff from libmain.so 

struct VuAssetFactory{
    static VuAssetFactory* mpInterface;
}; 

extern "C" int test(void* base){

    LOG_INFOS(" VuAssetFactory mpInterface %p", VuAssetFactory::mpInterface);

    return 0; 
}

