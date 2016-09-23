CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# 指定该项目工程的名称
PROJECT (Gems)

# 指定编译类型，默认为Debug
set (CMAKE_BUILD_TYPE Debug)

# 添加编译参数
add_definitions ("-Wall -g")

# add the include path to find the .h
include_directories("src")

# 指定源文件
set (SOURCES
	src/main.cpp
	src/Engine.cpp
	src/Vector2D.cpp
	src/LoaderParams.cpp
	src/TextureManager.cpp
	src/InputHandler.cpp
	src/SoundManager.cpp
	src/Objects/AnimatedGraphics.cpp
	src/Objects/Board.cpp
	src/Objects/GameObjectFactory.cpp
	src/Objects/StandardGameObject.cpp
	src/Objects/MenuButton.cpp
	src/Objects/Gem.cpp
	src/Objects/Gems.cpp
	src/States/GameOverState.cpp
	src/States/MainMenuState.cpp
	src/States/PauseState.cpp
	src/States/StateParser.cpp
	src/States/GameStateMachine.cpp
	src/States/MenuState.cpp
	src/States/PlayState/PlayState.cpp
	src/States/PlayState/PlayAddState.cpp
	src/States/PlayState/PlayDestoryState.cpp
	src/States/PlayState/PlayPlayState.cpp
	src/States/PlayState/PlaySwapState.cpp
	)

# 添加一个需要cmake的程序
add_executable (Gems ${SOURCES})

# 指定程序的输出路径
set_target_properties (Gems PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# 列出程序所须的库文件
TARGET_LINK_LIBRARIES (Gems SDL2 SDL2_image SDL2_mixer tinyxml)
