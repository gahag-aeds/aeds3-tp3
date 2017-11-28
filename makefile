SrcDir = src

CompilationUnits = $(shell find $(SrcDir) -name '*.c')

Default-OutputFile = default
Block-OutputFile = block


Build    = gcc
Standard = -std=c99 -pedantic
Warnings = -Wall -Wextra -Werror
Optimize = -O2 -flto

BuildFlags  = $(Standard)   \
              $(Warnings)   \
              $(Optimize)   \
              -I $(SrcDir)  \
              -o $(1)

DebugFlags = -g

ReleaseFlags = -DNDEBUG

BlockFlag = -DBLOCK



all: release-default release-block


build-default: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Default-OutputFile)) $(DebugFlags) $(CompilationUnits)

build-block: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Block-OutputFile)) $(DebugFlags) $(BlockFlag) $(CompilationUnits)


release-default: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Default-OutputFile)) $(ReleaseFlags) $(CompilationUnits)

release-block: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Block-OutputFile)) $(ReleaseFlags) $(BlockFlag) $(CompilationUnits)


clean:
	rm $(Default-OutputFile)
	rm $(Heur-OutputFile)
