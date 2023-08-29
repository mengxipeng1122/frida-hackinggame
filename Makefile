

all:
	./node_modules/frida-compile/bin/compile.js -o _agent.js index.ts
