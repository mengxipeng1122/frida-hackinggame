
ifndef NDKPATH
    $(error NDKPATH not set)
endif

all: build_android

build_android:
	${NDKPATH}/ndk-build V=1

clean:
	${NDKPATH}/ndk-build clean

