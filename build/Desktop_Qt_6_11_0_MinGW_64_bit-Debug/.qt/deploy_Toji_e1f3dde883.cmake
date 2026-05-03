include("C:/Users/DELL/Desktop/Toji/build/Desktop_Qt_6_11_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Toji-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/DELL/Desktop/Toji/build/Desktop_Qt_6_11_0_MinGW_64_bit-Debug/Toji.exe"
    GENERATE_QT_CONF
)
