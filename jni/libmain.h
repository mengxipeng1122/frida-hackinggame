
#pragma once 


#if defined(__cplusplus)
    #include <unordered_map>
    #include <map>
    #include <set>
    #include <list>
    #include <vector>
    #include <string>
#endif

////////////////////////////////////////////////////////////////////////////////
// stuff from libmain.so 

// VuAsset
struct VuAsset
{
    void * _vtab;
#if defined(__cplusplus)
    std::string _name;
#else
    unsigned char _name[0x18];
#endif

};

#if defined(__cplusplus)
    static_assert(offsetof(VuAsset, _name) == 0x08);
#endif



// VuTextureData size 0x14
struct VuTextureData
{
    unsigned char _0x0[0x0c ];
    int _levels;
    unsigned char _0x10[0x04 ];

#if defined(__cplusplus)
    int getTotalSize();
    int getLevelWidth(int);
    int getLevelSize(int);
    int getLevelHeight(int);
#endif
};

#if defined(__cplusplus)
    static_assert(offsetof(VuTextureData, _levels) == 0x0c);
    static_assert(sizeof(VuTextureData) == 0x14);
#endif

// VuTextureAsset
struct VuTextureAsset
{
    unsigned char _0x0[0x38 ];
    VuTextureData* _vuTextureData;
#if defined(__cplusplus)
    VuTextureData* getBaseTexture() const;
#endif
};

// VuAssetPackFileReader   size 0x38
struct VuAssetPackFileReader{
    unsigned char _0x0[0x38 ];
};

static_assert(sizeof(VuAssetPackFileReader) == 0x38);

// VuAssetDB  size 0xe0
struct VuAssetDB{

    unsigned char _0x0[0x40 ];

#if defined(__cplusplus)
    std::map<std::string, std::vector<std::string>> _assetNames;
#else
    unsigned char _assets[0x18];
#endif

    unsigned char _0x58[0x18 ];

    VuAssetPackFileReader _vuAssetPackFileReader0; // 0x70
    VuAssetPackFileReader _vuAssetPackFileReader1; // 0xa8
};

#if defined(__cplusplus)
    static_assert(sizeof(VuAssetDB) == 0xe0);
    static_assert(offsetof(VuAssetDB, _assetNames) == 0x40);
    static_assert(offsetof(VuAssetDB, _vuAssetPackFileReader0) == 0x70);
    static_assert(offsetof(VuAssetDB, _vuAssetPackFileReader1) == 0xa8);
#endif

// VuAssetFactory size 0x190
struct VuAssetFactory {
    unsigned char _0x0[0x38 ];

#if defined(__cplusplus)
    std::vector<std::string> _assetTypeNames;
    std::map<std::string, void*> _assetTypeInfos;
#else
    unsigned char _asssetTypeNames[0x18];
    unsigned char _asssetTypeInfos[0x18];
#endif

    VuAssetDB* _vuAssetDB; // 0x68

    unsigned char _0x70[0x8];

#if defined(__cplusplus)
    std::unordered_map<unsigned int, VuAsset*> _loadedAssets;
#else
    unsigned char _asssetTypeNames[0x28];
#endif

    unsigned char _0xa0[0x18];

#if defined(__cplusplus)
    std::map<std::string, void*> _assetTypePriorities;
#else
    unsigned char _asssetTypePriorities[0x18];
#endif

    unsigned char _0xd0[0xc0];

#if defined(__cplusplus)
    static VuAssetFactory* mpInterface;

    VuAsset* findAsset(char const*, char const*);
#endif
}; 


#if defined(__cplusplus)
    static_assert(offsetof(VuAssetFactory, _assetTypeNames) == 0x38);
    static_assert(offsetof(VuAssetFactory, _assetTypeInfos) == 0x50);
    static_assert(offsetof(VuAssetFactory, _vuAssetDB) == 0x68);
    static_assert(offsetof(VuAssetFactory, _loadedAssets) == 0x78);
    static_assert(offsetof(VuAssetFactory, _assetTypePriorities) == 0xb8);
    static_assert(sizeof(VuAssetFactory) == 0x190);
#endif

