

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



static const std::type_info& getTypeInfoOfInstance_ndk(void* p)
{
    p = *(void**)p;      
    p = ((void**)p)[-1];  
    return *(std::type_info*)p;
}



static int testContainers()
{
    {
        std::list<void*> v;
        v.push_back(nullptr);
        LOG_INFOS(" sizeof std::list<void*> %ld", sizeof(v));
        LOG_INFOS(" size %ld", v.size());
        LOG_HEXDUMP(&v, sizeof(v));
    }
    {
        std::vector<void*> v;
        v.push_back(nullptr);
        v.push_back(nullptr);
        LOG_INFOS(" sizeof std::vector<void*> %ld", sizeof(v));
        LOG_INFOS(" size %ld", v.size());
        LOG_HEXDUMP(&v, sizeof(v));
    }
    {
        std::set<void*> v;
        v.insert(nullptr);
        v.insert(nullptr);
        v.insert(nullptr);
        LOG_INFOS(" sizeof std::set<void*> %ld", sizeof(v));
        LOG_INFOS(" size %ld", v.size());
        LOG_HEXDUMP(&v, sizeof(v));
    }
    {
        std::map<std::string, void*> v;
        v["test0"] = nullptr;
        v["test1"] = nullptr;
        v["test2"] = nullptr;
        v["test3"] = nullptr;
        LOG_INFOS(" sizeof std::map<std::string, void*> %ld", sizeof(v));
        LOG_INFOS(" size %ld", v.size());
        LOG_HEXDUMP(&v, sizeof(v));
    }
    {
        std::unordered_map<std::string, void*> v;
        v["test0"] = nullptr;
        v["test1"] = nullptr;
        v["test2"] = nullptr;
        v["test3"] = nullptr;
        v["test4"] = nullptr;
        LOG_INFOS(" sizeof std::unordered_map<std::string, void*> %ld", sizeof(v));
        LOG_INFOS(" size %ld", v.size());
        LOG_HEXDUMP(&v, sizeof(v));
    }
    
    return 0;
}

extern "C" int test(void* base){

    // get static VuAssetFactory instance 
    auto* pVuAssetFactory = VuAssetFactory::mpInterface;
    LOG_INFOS(" pVuAssetFactory %p", pVuAssetFactory);

    // get the pointer to VuAssetDB
    auto*  pVuAssetDB = pVuAssetFactory->_vuAssetDB;
    LOG_INFOS(" pVuDB %p", pVuAssetDB);

    // list all asset typeNames
    for( auto it = pVuAssetDB->_assetNames.begin(); it != pVuAssetDB->_assetNames.end(); ++it){
        auto& assetType = it->first;
        auto&  names = it->second;
        for(auto it1=names.begin(); it1!=names.end(); ++it1){
            LOG_INFOS(" %s : %s", assetType.c_str(), it1->c_str());
        }
    }

    // iterate though all loaded asset
    {
        auto& v = pVuAssetFactory->_loadedAssets;
        LOG_INFOS(" 0x78 %ld", v.size());
        LOG_HEXDUMP(&v, 0x30);
        for(auto it = v.begin(); it != v.end(); ++it){
            auto* pAsset = it->second;
            auto& k = it->first;
            auto& assetTypeInfo = getTypeInfoOfInstance_ndk(pAsset);
            const char* assetTypeName = assetTypeInfo.name();
            LOG_INFOS(" %x pAsset %p assetTypeName %s assetName %s", k, pAsset, assetTypeName, pAsset->_name.c_str());
        }
    }

    LOG_INFOS(" test end");

    return 0; 
}






