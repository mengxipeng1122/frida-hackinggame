
#pragma once 


#if defined(__cplusplus)
    #include <unordered_map>
    #include <map>
    #include <vector>
    #include <string>
#endif

////////////////////////////////////////////////////////////////////////////////
// stuff from libmain.so 

struct VuAsset
{
};

// size 0xe0
struct VuAssetDB{
    unsigned char _0x0[0x40 ];
#if defined(__cplusplus)
    std::map<std::string, std::vector<std::string>> _assetNames;
#else
    unsigned char _assets[0x18];
#endif
    unsigned char _0x68[0x78 ];
};

// size 0x190
struct VuAssetFactory {
    unsigned char _0x0[0x50 ];

#if defined(__cplusplus)
    std::map<std::string, void*> _assetFactories;
#else
    unsigned char _asssetFactories[0x18];
#endif

    VuAssetDB* _vuAssetDB; // 0x68

    unsigned char_0x6c[0x124];

    static VuAssetFactory* mpInterface;
}; 

