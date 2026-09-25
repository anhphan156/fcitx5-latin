add_library(latin SHARED latin.cpp)
target_link_libraries(latin PRIVATE Fcitx5::Core)
set_target_properties(latin PROPERTIES PREFIX "")
install(TARGETS latin DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

configure_file(latin-addon.conf.in latin-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/latin-addon.conf" RENAME latin.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

install(FILES "latin.conf" DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")
