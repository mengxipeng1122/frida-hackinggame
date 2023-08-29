

all:./modinfos/libmousebot.ts
	./node_modules/frida-compile/bin/compile.js -o _agent.js index.ts

./modinfos/libmousebot.ts:./libs/arm64-v8a/libmousebot.so
	make -C jni
	./utils/so2ts.py -b $^ -o $@
