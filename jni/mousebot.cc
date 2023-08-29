

#include <stdio.h>
#include "libmain.h"

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



extern "C" int test(void* base){

    // std::unordered_map<std::string, void*> m;

    // LOG_INFOS(" m %ld", sizeof(m));


    auto* pVuAssetFactory = VuAssetFactory::mpInterface;
    LOG_INFOS(" pVuAssetFactory %p", pVuAssetFactory);

    LOG_HEXDUMP(pVuAssetFactory, 0x190);

    auto*  vuAssetDB = pVuAssetFactory->_vuAssetDB;
    LOG_HEXDUMP(vuAssetDB, 0xe0);


    return -1;

    auto& assetFactories  = pVuAssetFactory->_assetFactories;
    LOG_INFOS(" assetFactories %ld", assetFactories.size());
    for(auto it=assetFactories.begin(); it!=assetFactories.end(); ++it){
        LOG_INFOS(" %s", it->first.c_str());
    }

//      auto& _mem = vuAssetDB->_assetInfoHashes;
//      LOG_INFOS(" member size %ld", _mem.size());
//      for(auto it=_mem.begin(); it!=_mem.end(); ++it){
          //  LOG_INFOS(" %p", &(it->first));
          // LOG_HEXDUMP(&(it->first), 0x30);
          // LOG_HEXDUMP(&(it->second), 0x30);
//             LOG_INFOS(" %s", it->first.c_str());
 //     }


//     auto& _assetNames = vuAssetDB->_assetNames;
//     LOG_INFOS(" assets %ld", _assetNames.size());
// 
//     for(auto it=_assetNames.begin(); it!=_assetNames.end(); ++it){
//         LOG_INFOS(" %s", it->first.c_str());
//         auto& p = it->second;
//         LOG_INFOS(" p %ld" , p.size());
//         for(auto it1=p.begin(); it1!=p.end(); ++it1){
//             LOG_INFOS(" %s", it1->c_str());
//         }
//     }
// 

    

    return 0; 
}






