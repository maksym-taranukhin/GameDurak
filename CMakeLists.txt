cmake_minimum_required(VERSION 2.8) 

project(GameDurak)

set(SOURCE_DIR private)

set(HEADERS 
	AdditionalDefinitions.h
	Algorithm.h
	Card.h
	GameDurak.h
	HumanMovementController.h
	IMovementController.h
	Player.h
	PlayerAI.h
	PlayerHuman.h)

set(SOURCE 
	${SOURCE_DIR}/Algorithm.cpp
	${SOURCE_DIR}/Card.cpp
	${SOURCE_DIR}/GameDurak.cpp
	${SOURCE_DIR}/HumanMovementController.cpp
	${SOURCE_DIR}/IMovementController.cpp
	${SOURCE_DIR}/Player.cpp
	${SOURCE_DIR}/PlayerAI.cpp
	${SOURCE_DIR}/PlayerHuman.cpp)
	
add_executable(main main.cpp ${SOURCE} ${HEADERS})