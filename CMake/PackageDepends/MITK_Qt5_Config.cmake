find_package(Qt5Core COMPONENTS ${Qt5_REQUIRED_COMPONENTS_BY_MODULE} REQUIRED QUIET)
qt5_use_modules(${MODULE_NAME} ${Qt5_REQUIRED_COMPONENTS_BY_MODULE})