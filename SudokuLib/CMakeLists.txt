project(SudokuLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h
        pch.h
        ids.h
        Game.cpp
        GameView.cpp
        Tile.cpp
        Tile.h
        Item.cpp
        Item.h
        VisitorItem.cpp
        VisitorItem.h
        Digit.cpp
        Digit.h
        Timer.cpp
        Timer.h
        Given.cpp
        Given.h
        Background.cpp
        Background.h
        Container.cpp
        Container.h
        Xray.cpp
        Xray.h
        VisitorSparty.cpp
        VisitorSparty.h
        VisitorBackground.cpp
        VisitorBackground.h
        VisitorDigit.cpp
        VisitorDigit.h
        VisitorContainer.cpp
        VisitorContainer.h
        Sparty.cpp
        Sparty.h
)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})